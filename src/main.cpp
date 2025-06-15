#include <iostream>
#include <string>

int main() {
  // Flush after every std::cout / std:cerr
  std::cout << std::unitbuf;
  std::cerr << std::unitbuf;

  // Uncomment this block to pass the first stage
  std::cout << "$ ";

  std::string input;
  while (std::getline(std::cin, input)) {
    if (input == "exit 0") exit(0);
    else if (input.substr(0, 4) == "echo") std::cout << input.substr(5) << std::endl;
    else if (input.substr(0, 4) == "type") {
      std::string param = input.substr(5);
      if (param == "echo" || param == "type" || param == "exit") std::cout << param << " is a shell builtin" << std::endl;
      else std::cout << param << ": not found" << std::endl;
    }
    else {
      std::cout << input << ": command not found" << std::endl;
    }
    std::cout << "$ ";
  }
}
