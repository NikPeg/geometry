#ifndef GEOMETRY_TRIANGLE_H
#define GEOMETRY_TRIANGLE_H
#include "Point.h"
#include "Figure.h"

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

    void read() {
        std::string color_string;
        std::cin >> a.x >> a.y >> b.x >> b.y >> c.x >> c.y >> color_string;
        color = stringToColor(color_string);
    }

    void print() override {
        printf("Triangle(");
        a.print();
        printf(", ");
        b.print();
        printf(", ");
        c.print();
        printf(") ");
        printf("Perimeter: %f\n", perimeter());
    }
};

#endif //GEOMETRY_TRIANGLE_H
