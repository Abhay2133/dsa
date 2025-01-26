#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <type_traits>

namespace dsa
{

  // Base case: toString for all built-in data types (int, double, char, etc.)
  std::string toString(int value)
  {
    return std::to_string(value);
  }

  std::string toString(double value)
  {
    return std::to_string(value);
  }

  std::string toString(float value)
  {
    return std::to_string(value);
  }

  std::string toString(char value)
  {
    return std::string(1, value);
  }

  std::string toString(bool value)
  {
    return value ? "true" : "false";
  }

  std::string toString(const std::string &value)
  {
    return "\"" + value + "\"";
  }

  // Recursive case: toString for a vector
  template <typename T>
  std::string toString(const std::vector<T> &vec)
  {
    std::ostringstream oss;
    oss << "[";

    for (size_t i = 0; i < vec.size(); ++i)
    {
      oss << toString(vec[i]); // Recursive call
      if (i != vec.size() - 1)
      {
        oss << ", ";
      }
    }

    oss << "]";
    return oss.str();
  }

  // end of namespace
}
