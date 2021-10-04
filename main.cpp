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

struct Point {
    int x, y;
};

double distance(Point a, Point b) {
    return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}

void print(Point p) {
    printf("(%d, %d)", p.x, p.y);
}

struct Circle {
    Point centre;
    double radius;
    Color color;
};

double perimeter(Circle c) {
    return 2 * M_PI * c.radius;
}

Circle readCircle() {
    Circle result = Circle();
    std::string color_string;
    scanf("%d %d %lg %s", &result.centre.x, &result.centre.y, &result.radius, &color_string[0]);
    result.color = stringToColor(color_string);
    return result;
}

void print(Circle c) {
    printf("Circle(");
    print(c.centre);
    printf(", %f)", c.radius);
}

struct Rectangle {
    Point left_up, right_down;
    Color color;
};

double perimeter(Rectangle r) {
    return 2 * (abs(r.left_up.x - r.right_down.x) + abs(r.left_up.y - r.right_down.y));
}

Rectangle readRectangle() {
    Rectangle result = Rectangle();
    std::string color_string;
    scanf("%d %d %d %d %s", &result.left_up.x, &result.left_up.y, &result.right_down.x, &result.right_down.y,
          &color_string[0]);
    result.color = stringToColor(color_string);
    return result;
}

void print(Rectangle r) {
    printf("Rectangle(");
    print(r.left_up);
    printf(", ");
    print(r.right_down);
    printf(")");
}

struct Triangle {
    Point a, b, c;
    Color color;
};

double perimeter(Triangle t) {
    return distance(t.a, t.b) + distance(t.b, t.c) + distance(t.c, t.a);
}

Triangle readTriangle() {
    Triangle result = Triangle();
    std::string color_string;
    scanf("%d %d %d %d %d %d %s", &result.a.x, &result.a.y, &result.b.x, &result.b.y, &result.c.x, &result.c.y,
          &color_string[0]);
    result.color = stringToColor(color_string);
    return result;
}

void print(Triangle t) {
    printf("Triangle(");
    print(t.a);
    printf(", ");
    print(t.b);
    printf(", ");
    print(t.c);
    printf(")");
}

int main(int argc, char *argv[]) {
    std::freopen(argv[1], "r", stdin);
    std::freopen(argv[2], "w", stdout);
    int figures_count;
    scanf("%d", &figures_count);
    const int MAX_COUNT = 10000;
    Triangle triangles[MAX_COUNT];
    Circle circles[MAX_COUNT];
    Rectangle rectangles[MAX_COUNT];
    int last_triangle = 0, last_circle = 0, last_rectangle = 0;
    std::string figure_type, color;
    for (int i = 0; i < figures_count; ++i) {
        scanf("%s", &figure_type[0]);
        if (figure_type == "Circle") {
            circles[last_circle++] = readCircle();
        }
        else if (figure_type == "Rectangle") {
            rectangles[last_rectangle++] = readRectangle();
        }
        else if (figure_type == "Triangle") {
            triangles[last_triangle++] = readTriangle();
        }
    }
    for (int i = 0; i < last_circle; ++i) {
        print(circles[i]);
    }
    for (int i = 0; i < last_rectangle; ++i) {
        print(rectangles[i]);
    }
    for (int i = 0; i < last_triangle; ++i) {
        print(triangles[i]);
    }
}
