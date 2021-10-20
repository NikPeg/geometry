#ifndef GEOMETRY_CIRCLE_H
#define GEOMETRY_CIRCLE_H
#include "Figure.h"
#include "Point.h"

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

    void read() {
        char color_char;
        scanf("%d %d %lg %s", &centre.x, &centre.y, &radius, &color_char);
        color = stringToColor(color_char);
    }

    void print() override {
        printf("Circle(");
        centre.print();
        printf(", %f) ", radius);
        printf("Perimeter: %f\n", perimeter());
    }
};

#endif //GEOMETRY_CIRCLE_H
