#include <fstream>
#include <iostream>

namespace dsa
{
  void appendFile(const std::string &fileName, const std::string &line)
  {
    std::ofstream file(fileName, std::ios::app);
    if (!file.is_open())
    {
      std::cerr << "Error: Could not open the file " << fileName << " for appending." << std::endl;
      return;
    }
    file << line << std::string("\n");
    file.close();
  }
}
