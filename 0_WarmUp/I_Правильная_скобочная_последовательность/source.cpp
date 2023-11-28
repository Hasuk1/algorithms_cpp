#include <iostream>
#include <stack>
#include <string>

bool isBalanced(const std::string& sequence) {
  std::stack<char> brackets;

  for (char bracket : sequence) {
    if (bracket == '(' || bracket == '[' || bracket == '{') {
      brackets.push(bracket);
    } else if (bracket == ')' || bracket == ']' || bracket == '}') {
      if (brackets.empty()) {
        return false;
      }
      char openBracket = brackets.top();
      brackets.pop();

      if ((bracket == ')' && openBracket != '(') ||
          (bracket == ']' && openBracket != '[') ||
          (bracket == '}' && openBracket != '{')) {
        return false;
      }
    }
  }

  return brackets.empty();
}

int main() {
  std::string sequence;
  std::cin >> sequence;

  if (isBalanced(sequence)) {
    std::cout << "yes" << std::endl;
  } else {
    std::cout << "no" << std::endl;
  }

  return 0;
}
