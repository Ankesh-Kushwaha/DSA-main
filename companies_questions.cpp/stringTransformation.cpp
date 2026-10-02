#include<bits/stdc++.h>
using namespace std;
/*
   the idea is to find the two blocks
   1. Y XXXX Y this contributes two points
      because change YX => YZ and XY=> ZY    [YZ] XX [ZY] rest X got separated from Y no point can be made;

   2. XXXX  Y XXXX   this also contribute to 2 points as [XX] ZYZ [XX] again X got separated no further points possible;
*/
int solve(string &s){
  int ans = 0;
  int n = s.length();

  for (int i = 0; i < n;)
  {

    if(s[i]=='y'){
      i++;
      continue;  
    }

    int j = i;
    //find a X block
    while(j<n && s[j]=='x')
      j++;

    int len = j - i; //length of the X block

    //now check if left side there exist any string
    int left = i > 0 ? s[i-1] == 'y' : 0;
    int right = j < n ? s[j] == 'y' : 0;

    ans += min(len, left + right);

    i = j; //start for the next section
  }

  return ans;
}

int main(){
  string s;
  cin >> s;

  cout << solve(s) << endl;
  return 0;
}

/*
### Problem: Maximum Points from String Transformations

You are given a string `s` consisting only of the characters **`x`** and **`y`**.

You can perform the following operation any number of times:

1. Choose a substring **`xy`** and replace it with **`zy`**.
2. Choose a substring **`yx`** and replace it with **`yz`**.

Each time you perform either operation, you earn **1 point**.

You may continue performing operations until no more valid operations are possible.

Your task is to determine the **maximum number of points** you can earn.

### Examples

**Example 1:**

```text
Input:
xy

Output:
1
```

Explanation:

```text
xy → zy
```

We perform one operation, so the maximum score is `1`.

---

**Example 2:**

```text
Input:
yxxxy

Output:
2
```

Explanation:

The string contains:

```text
y xxx y
```

We can use the `y` on the left with one `x` and the `y` on the right with another `x`, giving two operations.

Therefore, the maximum score is `2`.

---

**Example 3:**

```text
Input:
xxxyxxx

Output:
2
```

Explanation:

```text
xxx y xxx
```

The middle `y` can interact with at most one `x` on its left and one `x` on its right.

Thus, the maximum number of operations is `2`.

### Constraints

* `1 ≤ |s| ≤ 10^5`
* `s` contains only the characters `x` and `y`.

### Function Signature

```cpp
int maximumPoints(string s);
```

Return the maximum number of points that can be obtained.

*/