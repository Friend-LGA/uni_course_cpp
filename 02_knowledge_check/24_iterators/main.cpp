// https://en.wikipedia.org/wiki/Iterator
//
// https://en.cppreference.com/w/cpp/iterator/iterator

#include <array>
#include <iostream>
#include <iterator>
#include <string>
#include <unordered_set>
#include <vector>

template <typename T>
void print_elements(const std::string& prefix, const T& collection) {
  std::cout << prefix;
  for (auto iter = collection.begin(); iter != collection.end(); iter++) {
    std::cout << *iter << " ";
  }
  std::cout << std::endl;
}

template <typename T>
class MyCollection {
 public:
  // https://en.cppreference.com/w/cpp/iterator/iterator_tags
  class Iterator : public std::iterator<std::input_or_output_iterator, T> {
   public:
    explicit Iterator(const MyCollection& collection, size_t pos) : collection_(collection), pos_(pos) {}

    Iterator operator++(int) {
      pos_++;
      return *this;
    }

    Iterator operator+(int value) {
      pos_ = pos_ + value;
      return *this;
    }

    Iterator operator--(int) {
      pos_--;
      return *this;
    }

    Iterator operator-(int value) {
      pos_ = pos_ - value;
      return *this;
    }

    bool operator==(const Iterator& other) const { return (collection_ == other.collection_ && pos_ == other.pos_); }
    bool operator!=(const Iterator& other) const { return !(*this == other); }
    const T& operator*() const { return collection_[pos_]; }

   private:
    const MyCollection& collection_;
    size_t pos_ = 0;
  };

  size_t size() const { return vector_.size(); }
  const T& at(size_t pos) const { return vector_.at(pos); }
  const T& operator[](size_t pos) const { return vector_[pos]; }

  void append(const T& item) { vector_.push_back(item); }

  Iterator begin() const { return Iterator(*this, 0); }
  Iterator end() const { return Iterator(*this, size()); }

  bool operator==(const MyCollection& other) const { return vector_ == other.vector_ && pos_ == other.pos_; }

 private:
  std::vector<T> vector_ = {};
  size_t pos_ = 0;
};

int main() {
  auto a = std::array<int, 6>({0, 1, 2, 3, 4, 5});
  auto b = std::vector<int>({0, 2, 4, 6, 8, 10});
  auto c = std::unordered_set<int>({0, 2, 4, 8, 16, 32});
  auto d = MyCollection<int>();

  d.append(0);
  d.append(128);
  d.append(512);

  std::array<int, 8>::iterator a_iter_begin = a.begin();
  std::vector<int>::iterator b_iter_begin = b.begin();
  std::unordered_set<int>::iterator c_iter_begin = c.begin();
  MyCollection<int>::Iterator d_iter_begin = d.begin();

  std::array<int, 8>::iterator a_iter_end = a.end();
  std::vector<int>::iterator b_iter_end = b.end();
  std::unordered_set<int>::iterator c_iter_end = c.end();
  MyCollection<int>::Iterator d_iter_end = d.end();

  std::cout << "Array Begin, First: " << *a_iter_begin << std::endl;
  std::cout << "Array (End - 1), Last: " << *(a_iter_end - 1) << std::endl << std::endl;

  std::cout << "Array (Begin + 1): " << *(a_iter_begin + 1) << std::endl;
  std::cout << "Array (End - 2): " << *(a_iter_end - 2) << std::endl << std::endl;

  std::cout << "Array (Begin - 1), Out of Range: " << *(a_iter_begin - 1) << std::endl;
  std::cout << "Array End, Out of Range: " << *a_iter_end << std::endl << std::endl;

  print_elements("Array: ", a);
  print_elements("Vector: ", b);
  print_elements("Unordered Set: ", c);
  print_elements("MyCollection: ", d);

  return 0;
}
