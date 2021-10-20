#ifndef GEOMETRY_RECTANGLE_H
#define GEOMETRY_RECTANGLE_H
#include "Point.h"
#include "Figure.h"

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

    void read() {
        std::string color_string;
        scanf("%d %d %d %d %s", &left_up.x, &left_up.y, &right_down.x, &right_down.y, &color_string[0]);
        color = stringToColor(color_string);
    }

    void print() override {
        printf("Rectangle(");
        left_up.print();
        printf(", ");
        right_down.print();
        printf(") ");
        printf("Perimeter: %f\n", perimeter());
    }
};

#endif //GEOMETRY_RECTANGLE_H
