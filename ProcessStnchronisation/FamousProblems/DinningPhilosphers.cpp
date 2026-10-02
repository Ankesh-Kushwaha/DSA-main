#include <iostream>
#include <thread>
#include <vector>
#include <chrono>
#include <condition_variable>
#include <mutex>

#define N 5 // Number of philosophers

class Semaphore
{
public:
  void acquire()
  {
    std::unique_lock<std::mutex> lock(mutex);
    condition.wait(lock, [this] { return permits > 0; });
    --permits;
  }

  void release()
  {
    {
      std::lock_guard<std::mutex> lock(mutex);
      ++permits;
    }
    condition.notify_one();
  }

private:
  int permits = 1;
  std::mutex mutex;
  std::condition_variable condition;
};

Semaphore chopstick[N]; // One semaphore for each chopstick

void philosopher(int id)
{
  while (true)
  {
    std::cout << "Philosopher " << id << " is thinking...\n";
    std::this_thread::sleep_for(std::chrono::seconds(1));

    // Pick up left chopstick
    chopstick[id].acquire();

    // Pick up right chopstick
    chopstick[(id + 1) % N].acquire();

    std::cout << "Philosopher " << id << " is eating...\n";
    std::this_thread::sleep_for(std::chrono::seconds(2));

    // Put down left chopstick
    chopstick[id].release();

    // Put down right chopstick
    chopstick[(id + 1) % N].release();

    std::cout << "Philosopher " << id << " finished eating and put down chopsticks.\n";
  }
}

int main()
{
  std::vector<std::thread> threads(N);

  // Create philosopher threads
  for (int i = 0; i < N; i++)
  {
    threads[i] = std::thread(philosopher, i);
  }

  // Join threads (never ends in this example)
  for (auto &th : threads)
  {
    if (th.joinable())
    {
      th.join();
    }
  }

  return 0;
}