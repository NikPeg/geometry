#ifndef GEOMETRY_POINT_H
#define GEOMETRY_POINT_H
#include <math.h>

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

    void print() const {
        printf("(%d, %d)", x, y);
    }
};

#endif //GEOMETRY_POINT_H
