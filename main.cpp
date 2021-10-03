#include <iostream>
#include <math.h>


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
    static double distance(Point a, Point b) {
        return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
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
    double perimeter() override {
        return 2 * M_PI * radius;
    }
};

class Rectangle: virtual public Figure {
public:
    Point left_up, right_down;
    Rectangle(Point _left_up, Point _right_down) {
        left_up = _left_up;
        right_down = _right_down;
    }
    double perimeter() override {
        return 2 * (abs(left_up.x - right_down.x) + abs(left_up.y - right_down.y));
    }
};

class Triangle: virtual public Figure {
public:
    Point a, b, c;
    Triangle(Point _a, Point _b, Point _c) {
        a = _a;
        b = _b;
        c = _c;
    }
    double perimeter() override {
        return Point::distance(a, b) + Point::distance(b, c) + Point::distance(c, a);
    }
};

int main(int argc, char *argv[]) {
    std::cout << argv[1] << " " << argv[2];
}
