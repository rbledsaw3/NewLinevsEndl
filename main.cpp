#include <iostream>
#include <string.h>

bool isInt(const char* arg) {
  std::string s = arg;
  for (char c : s) {
    if (!isdigit(c)) {
      return false;
    }
  }
  return true;
}

bool isLessThanMax(const char* arg) {
  std::string s = arg;
  if (s.length() > 10) {
    return false;
  } else if (s.length() == 10) {
    std::string max = "4294967295";
    for (long unsigned int i = 0; i < s.length(); i++) {
      if (s[i] > max[i]) {
        return false;
      }
    }
  }
  return true;
}

// cout usage as expected input is "main <integer> <newline or endl>"
void usage() {
  std::cout << "Usage: main <positive integer> <newline or endl>" << std::endl;
}

int main(int argc, char* argv[]) {
  if (argc != 3) {
    usage();
    return 1;
  }

  if (!isInt(argv[1]) || !isLessThanMax(argv[1])) {
    usage();
    return 1;
  }

  unsigned int n = strtoul(argv[1], nullptr, 10);

  if (strcmp(argv[2], "endl") == 0) {
    for (unsigned int i = 0; i < n; i++) {
      std::cout << i + 1 << ": Hello World!" << std::endl;
    }
  } else if (strcmp(argv[2], "newline") == 0) {
    for (unsigned int i = 0; i < n; i++) {
      std::cout << i + 1 << ": Hello World!"
                << "\n";
    }
  } else {
    usage();
    return 1;
  }

  return 0;
}
