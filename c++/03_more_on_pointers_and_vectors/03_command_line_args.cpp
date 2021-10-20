#include <iostream>
#include <sstream>
#include <string>

int main(int argc, char* argv[]) {
  for (auto i = 0; i < argc; ++i)
    std::cout << "argv[" << i << "] = " << argv[i] << std::endl;

  unsigned int a;
  {
    std::istringstream s{argv[1]};
    s >> a;
  }
  std::cout << "a is " << a << std::endl;

  // std::stoi
  // std::stol
  // std::stoll
  // std::stof
  // std::stod
  // std::stoull
  a = std::stoul(argv[1]);
  std::cout << "a is " << a << std::endl;
  return 0;
}
