#include <iostream>

class Shape {
public:
    virtual double perimeter();
    bool operator<(Shape other) {
        return perimeter() < other.perimeter();
    }
    bool operator==(Shape other) {
        return perimeter() == other.perimeter();
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
