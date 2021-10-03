#include <cstdio>
#include <math.h>
#include <iostream>

enum Color {
    RED,
    ORANGE,
    YELLOW,
    GREEN,
    LIGHT_BLUE,
    BLUE,
    VIOLET,
};

std::string colorToString(Color color) {
    switch (color) {
        case RED:
            return "RED";
        case ORANGE:
            return "ORANGE";
        case YELLOW:
            return "YELLOW";
        case GREEN:
            return "GREEN";
        case LIGHT_BLUE:
            return "LIGHT_BLUE";
        case BLUE:
            return "BLUE";
        case VIOLET:
            return "VIOLET";
        default:
            return "NOT A COLOR!";
    }
}

Color stringToColor(std::string color_string) {
    if (color_string == "RED")
        return RED;
    if (color_string == "ORANGE")
        return ORANGE;
    if (color_string == "YELLOW")
        return YELLOW;
    if (color_string == "GREEN")
        return GREEN;
    if (color_string == "LIGHT_BLUE")
        return LIGHT_BLUE;
    if (color_string == "BLUE")
        return BLUE;
    if (color_string == "VIOLET")
        return VIOLET;
    return RED;
}

class Figure {
public:
    Color color;

    virtual double perimeter() {};

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

class Circle : virtual public Figure {
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

    static Circle read() {
        Circle result = Circle();
        std::string color_string;
        scanf("%d %d %lg %s", &result.centre.x, &result.centre.y, &result.radius, &color_string[0]);
        result.color = stringToColor(color_string);
        return result;
    }
};

class Rectangle : virtual public Figure {
public:
    Point left_up, right_down;

    Rectangle() {
        left_up = Point();
        right_down = Point();
    }

    Rectangle(Point _left_up, Point _right_down, Color _color) {
        left_up = _left_up;
        right_down = _right_down;
        color = _color;
    }

    double perimeter() override {
        return 2 * (abs(left_up.x - right_down.x) + abs(left_up.y - right_down.y));
    }

    static Rectangle read() {
        Rectangle result = Rectangle();
        std::string color_string;
        scanf("%d %d %d %d %s", &result.left_up.x, &result.left_up.y, &result.right_down.x, &result.right_down.y,
              &color_string[0]);
        result.color = stringToColor(color_string);
        return result;
    }
};

class Triangle : virtual public Figure {
public:
    Point a, b, c;

    Triangle() {
        a = Point();
        b = Point();
        c = Point();
    }

    Triangle(Point _a, Point _b, Point _c, Color _color) {
        a = _a;
        b = _b;
        c = _c;
        color = _color;
    }

    double perimeter() override {
        return Point::distance(a, b) + Point::distance(b, c) + Point::distance(c, a);
    }

    static Triangle read() {
        Triangle result = Triangle();
        std::string color_string;
        scanf("%d %d %d %d %d %d %s", &result.a.x, &result.a.y, &result.b.x, &result.b.y, &result.c.x, &result.c.y,
              &color_string[0]);
        result.color = stringToColor(color_string);
        return result;
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
        scanf("%s", &figure_type[0]);
        if (figure_type == "Circle") {
            figures[i] = Circle::read();
        }
        else if (figure_type == "Rectangle") {
            figures[i] = Rectangle::read();
        }
        else if (figure_type == "Triangle") {
            figures[i] = Triangle::read();
        }
    }
}
