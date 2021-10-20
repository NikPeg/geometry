#ifndef GEOMETRY_FIGURE_H
#define GEOMETRY_FIGURE_H
#include "utils.h"

class Figure {
public:
    Color color = RED;

    virtual double perimeter() = 0;

    virtual void print() = 0;

    bool operator<(Figure *other) {
        return perimeter() < other->perimeter();
    }

    bool operator==(Figure *other) {
        return perimeter() == other->perimeter();
    }
};

#endif //GEOMETRY_FIGURE_H
