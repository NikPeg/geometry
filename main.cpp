#include <iostream>

class Figure {
public:
    virtual double perimeter();
    bool operator<(Figure other) {
        return perimeter() < other.perimeter();
    }
    bool operator==(Figure other) {
        return perimeter() == other.perimeter();
    }
};

class Point {
public:
    int x, y;
    Point() {
        x = 0;
        y = 0;
    }
    Point(int _x, int _y) {
        x = _x;
        y = _y;
    }
};

class Circle: virtual public Figure {
public:
    Point centre;
    double radius;
    Circle(Point _centre, double _radius) {
        centre = _centre;
        radius = _radius;
    }

};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
