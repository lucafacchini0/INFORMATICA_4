#include <iostream>
#include <string>

void print(std::string s, int n = 1) {
    for (int i = 0; i < n; i++) {
        std::cout << s << std::endl;
    }
}

int main() {
    print("Hello");
    print("World", 5);
    return 0;
}