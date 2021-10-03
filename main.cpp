#include <cstdio>
#include <math.h>
#include <iostream>

enum Color{
    red,
    orange,
    yellow,
    green,
    light_blue,
    blue,
    violet
};

class Figure {
public:
    Color color;
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
    Circle(Point _centre, double _radius, Color _color) {
        centre = _centre;
        radius = _radius;
        color = _color;
    }
    double perimeter() override {
        return 2 * M_PI * radius;
    }
};

class Rectangle: virtual public Figure {
public:
    Point left_up, right_down;
    Rectangle(Point _left_up, Point _right_down, Color _color) {
        left_up = _left_up;
        right_down = _right_down;
        color = _color;
    }
    double perimeter() override {
        return 2 * (abs(left_up.x - right_down.x) + abs(left_up.y - right_down.y));
    }
};

class Triangle: virtual public Figure {
public:
    Point a, b, c;
    Triangle(Point _a, Point _b, Point _c, Color _color) {
        a = _a;
        b = _b;
        c = _c;
        color = _color;
    }
    double perimeter() override {
        return Point::distance(a, b) + Point::distance(b, c) + Point::distance(c, a);
    }
};

int main(int argc, char *argv[]) {
    std::freopen(argv[1], "r", stdin);
    std::freopen(argv[2], "w", stdout);
    int a;
    scanf("%d", &a);
    std::cout << a;
}
