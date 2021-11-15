// https://en.wikipedia.org/wiki/Concurrency_(computer_science)
// https://en.wikipedia.org/wiki/Parallel_computing
//
// https://isocpp.github.io/CppCoreGuidelines/CppCoreGuidelines#cp-concurrency-and-parallelism
//
// - Race condition
// - Deadlock

#include <atomic>
#include <chrono>
#include <future>
#include <iostream>
#include <mutex>
#include <string>
#include <thread>
#include <vector>

class Resource {
 public:
  void replace1(size_t pos, int value) {
    // You will have to manually unlock
    vector_mutex_.lock();
    if (pos >= vector_.size()) {
      vector_mutex_.unlock();  // 1
      throw std::out_of_range("Position is out of range!!!");
    }
    vector_[pos] = value;
    vector_mutex_.unlock();  // 2
  }

  void replace2(size_t pos, int value) {
    // Will be automatically unlocked when goes out of scope.
    // Use `std::scoped_lock` for multiple mutexes.
    // Always name the lock with variable, othervise it will be destroyed
    // immediately.
    // https://en.cppreference.com/w/cpp/thread/lock_guard
    // https://en.cppreference.com/w/cpp/thread/scoped_lock
    std::lock_guard lock(vector_mutex_);
    if (pos >= vector_.size()) {
      throw std::out_of_range("Position is out of range!!!");
    }
    vector_[pos] = value;
  }

  int get_id() { return id_; }

  void increase_id() { id_++; }

  void produce_deadlock() {
    // As we lock the same mutex recursively, thread will wait forever for mutex
    // to be unlocked
    // std::lock_guard lock(vector_mutex_);  // expect DEADLOCK!!!
    replace2(0, 128);
  }

  // Don't lock entire execution, lock only what is necessary.
  void multiple_operation(int number) {
    // .. do something
    int x = number + 16;
    {
      std::lock_guard lock(vector_mutex_);
      vector_[0] = x;
    }
    // some other work ...
  }

 private:
  std::vector<int> vector_ = {0, 1, 2};

  // Suspends current thread, swith context overhead.
  // https://en.cppreference.com/w/cpp/thread/mutex
  std::mutex vector_mutex_;

  // Don't suspend thread, keep asking if it is unlocked.
  // Use only with fundamental types, which `atomic` designed to work with.
  // If you will have, for example, atomic vector, then it will just make
  // assignement operation thread safe, but any vector-related operation will
  // not be safe.
  // https://en.cppreference.com/w/cpp/atomic/atomic
  std::atomic<int> id_ = 0;
};

// Observe race condition, most likely
static void print_string(const std::string& string) {
  std::this_thread::sleep_for(std::chrono::milliseconds(500));
  std::cout << string << std::endl;
}

static int sum(int a, int b) {
  std::this_thread::sleep_for(std::chrono::milliseconds(500));
  return a + b;
}

int main() {
  // Terminates application `std::terminate` in destructor if not
  // `join()` or `detach()`.
  std::thread thread1(print_string, "Hello World, Thread 1");
  std::thread thread2(print_string, "Hello World, Thread 2");

  // Current thread isn't waiting for threads to finish and continue its
  // execution. If program terminates (i.e. `main()` reaches the end), threads
  // are suspended.
  // https://en.cppreference.com/w/cpp/thread/thread/detach
  thread1.detach();

  // Current thread is waiting for threads to finish.
  // https://en.cppreference.com/w/cpp/thread/thread/join
  thread2.join();

  // `std::future` high level concept of executing concurrent tasks.
  // https://en.cppreference.com/w/cpp/thread/future

  // https://en.cppreference.com/w/cpp/thread/async
  std::future future1 = std::async(sum, 2, 4);
  std::cout << "Future 1: " << future1.get() << std::endl;

  // https://en.cppreference.com/w/cpp/thread/packaged_task
  std::packaged_task<int(int, int)> task(sum);
  std::future<int> future2 = task.get_future();
  std::thread(std::move(task), 4, 8).detach();
  std::cout << "Future 2: " << future2.get() << std::endl;

  // https://en.cppreference.com/w/cpp/thread/promise
  std::promise<int> promise;
  std::future<int> future3 = promise.get_future();
  std::thread([&promise]() { promise.set_value(sum(8, 16)); }).detach();
  std::cout << "Future 3: " << future3.get() << std::endl;

  // You can make thread sleep for speific time.
  std::this_thread::sleep_for(std::chrono::seconds(1));

  auto resource = Resource();
  resource.produce_deadlock();

  return 0;
}
