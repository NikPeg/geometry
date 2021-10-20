#ifndef GEOMETRY_CONTAINER_H
#define GEOMETRY_CONTAINER_H
#include "Triangle.h"
#include "Rectangle.h"
#include "Circle.h"
#include "Figure.h"

class Container {
private:
    static const int MAXSIZE = 10000;
    int figures_count;
    Figure *figures[MAXSIZE];
public:
    void read() {
        std::cin >> figures_count;
        std::string figure_type, color;
        for (int i = 0; i < figures_count; ++i) {
            std::cin >> figure_type;
            if (figure_type == "Circle") {
                auto *c = new Circle();
                c->read();
                figures[i] = c;
            }
            else if (figure_type == "Rectangle") {
                auto *r = new Rectangle();
                r->read();
                figures[i] = r;
            }
            else if (figure_type == "Triangle") {
                auto *t = new Triangle();
                t->read();
                figures[i] = t;
            }
        }
    }

    void print() {
        for (int i = 0; i < figures_count; ++i) {
            figures[i]->print();
        }
    }

    void sort() {
        for (int i = 0; i < figures_count; ++i) {
            double mx = -1;
            int mxj;
            for (int j = i; j < figures_count; ++j) {
                if (figures[j]->perimeter() > mx) {
                    mx = figures[j]->perimeter();
                    mxj = j;
                }
            }
            std::swap(figures[i], figures[mxj]);
        }
    }
};

#endif //GEOMETRY_CONTAINER_H
