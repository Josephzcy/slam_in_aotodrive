
#include <iostream>
int main(int argc, char *argv[]) {
  std::cout << "chaptet2 hello world" << std::endl;
  if (argc > 1) {
    for (auto i = 1; i < argc; i++) {
      std::cout << argv[i] << std::endl;
    }
  }
  return 0;
}