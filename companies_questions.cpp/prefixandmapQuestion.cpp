#include <bits/stdc++.h>
using namespace std;

int main()
{

  int t;
  cin >> t;

  while (t--)
  {

    long long N, P;
    cin >> N >> P;

    vector<long long> arr(N);

    for (int i = 0; i < N; i++)
    {
      cin >> arr[i];
    }

    /*
        freq stores:

        key   = prefix sum % P
        value = how many times this remainder has appeared

        We initially have prefix sum = 0 before the array starts.

        This represents an empty prefix and is necessary for
        subarrays starting from index 0.
    */
    map<long long, long long> freq;
    freq[0] = 1;

    long long prefix = 0;

    // Maximum subarray score found so far
    long long maxSum = -1;

    // Number of subarrays having maxSum
    long long count = 0;

    for (auto &x : arr)
    {

      /*
          Calculate current prefix sum modulo P.

          We keep prefix in the range [0, P-1].

          The +P handles the case where x can be negative.
      */
      prefix = ((prefix + x) % P + P) % P;

      /*
          CASE 1:
          Find the smallest previous remainder greater than
          the current prefix remainder.

          Suppose:

              current remainder = prefix
              previous remainder = y

          If y > prefix:

              score = (prefix - y + P) % P

          To maximize this score, we want the SMALLEST
          y that is greater than prefix.

          upper_bound(prefix) gives exactly that value.
      */
      auto it = freq.upper_bound(prefix);

      if (it != freq.end())
      {

        long long y = it->first;

        // Since y > prefix, adding P makes the difference positive.
        long long score = prefix - y + P;

        /*
            it->second tells us how many previous prefix positions
            had this remainder.

            Therefore, all of those positions create subarrays
            having the same score.
        */
        if (score > maxSum)
        {
          maxSum = score;
          count = it->second;
        }
        else if (score == maxSum)
        {
          count += it->second;
        }
      }

      /*
          CASE 2:
          There is no previous remainder greater than prefix,
          or we want to consider the non-wrapping case.

          We take the SMALLEST previous remainder.

          If y <= prefix:

              score = prefix - y

          To maximize this score, we need the smallest y.

          Since map is sorted, freq.begin() gives the smallest
          prefix remainder.
      */
      if (!freq.empty())
      {

        auto mini = freq.begin();

        long long y = mini->first;

        long long score = prefix - y;

        if (score > maxSum)
        {
          maxSum = score;
          count = mini->second;
        }
        else if (score == maxSum)
        {
          count += mini->second;
        }
      }

      /*
          Add the current prefix remainder to the map.

          We add it AFTER querying because the current prefix
          cannot be used as the starting prefix for the same
          subarray.
      */
      freq[prefix]++;
    }

    // Print:
    // maxSum = maximum possible score
    // count  = number of subarrays having that score
    cout << maxSum << " " << count << '\n';
  }

  return 0;
}
/*the question is given as there is a array of N numbers. the score is defined as  we need to choose the consecutive subsequence and mod them with a Number P(not always be prime). Now return two integers one is MaxScore and other is number of such score exist. */