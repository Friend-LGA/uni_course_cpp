// https://en.cppreference.com/w/cpp/language/operators
// https://docs.microsoft.com/en-us/cpp/cpp/operator-overloading

#include <iostream>
#include <sstream>
#include <string>
#include <vector>

class IntVectorWrapper {
 public:
  IntVectorWrapper(const std::vector<int>& vector) : vector_(vector) {}

  int sum() const {
    int result = 0;
    for (const auto& item : vector_) {
      result += item;
    }
    return result;
  }

  size_t size() const { return vector_.size(); }

  std::string str() const {
    std::stringstream result;
    result << "[";
    const auto& last = vector_.end() - 1;
    for (auto it = vector_.begin(); it != vector_.end(); it++) {
      result << *it;
      if (it != last) {
        result << ", ";
      }
    }
    result << "], size: " << size() << ", sum: " << sum();
    return result.str();
  }

  // this + other
  IntVectorWrapper operator+(const IntVectorWrapper& other) {
    std::vector<int> result;
    for (size_t i = 0; i < other.vector_.size(); i++) {
      if (vector_.size() > i) {
        result.push_back(vector_[i] + other.vector_[i]);
      } else {
        result.push_back(other.vector_[i]);
      }
    }
    return IntVectorWrapper(result);
  }

  // this < other
  bool operator<(const IntVectorWrapper& other) { return sum() < other.sum(); }

  // this[i]
  int operator[](int i) { return vector_[i]; }

 private:
  std::vector<int> vector_;
};

// ostream << IntVectorWrapper
// As we don't have access to `std::ostream` class, we need to define this
// operator in global space
std::ostream& operator<<(std::ostream& os, const IntVectorWrapper& vec) {
  return os << vec.str();
}

int main() {
  auto vec1 = IntVectorWrapper({0, 1, 2, 3, 4, 5});
  std::cout << "vec1 = " << vec1 << std::endl;
  std::cout << "vec1[0] = " << vec1[0] << std::endl << std::endl;

  auto vec2 = IntVectorWrapper({2, 2, 2, 2, 2, 2, 2, 2});
  std::cout << "vec2 = " << vec2 << std::endl;
  std::cout << "vec2[7] = " << vec2[7] << std::endl << std::endl;

  std::cout << "vec1 + vec2 = " << (vec1 + vec2) << std::endl << std::endl;

  std::cout << "vec1 < vec2 == " << (vec1 < vec2 ? "true" : "false")
            << std::endl;

  return 0;
}
