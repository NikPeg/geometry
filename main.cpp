#include <cstdio>
#include <math.h>
#include <iostream>

enum Color{
    RED,
    ORANGE,
    YELLOW,
    GREEN,
    LIGHT_BLUE,
    BLUE,
    VIOLET,
};

class Figure {
public:
    Color color;
    virtual double perimeter();
    virtual void read();
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
    Circle() {
        centre = Point();
        radius = 0;
        color = RED;
    }
    Circle(Point _centre, double _radius, Color _color) {
        centre = _centre;
        radius = _radius;
        color = _color;
    }
    double perimeter() override {
        return 2 * M_PI * radius;
    }
    void read() {
        Circle result = Circle();
        scanf("%d %d %lg %u", &result.centre.x, &result.centre.y, &result.radius, &result.color);
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
    int figures_count;
    scanf("%d", &figures_count);
    Figure figures[figures_count];
    std::string figure_type, color;
    for (int i = 0; i < figures_count; ++i) {
        scanf("%s", &figure_type);
        if (figure_type == "Circle") {
            figures[i] = Circle.read();
        }
    }
}
