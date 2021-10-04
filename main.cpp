#include <cstdio>
#include <cmath>
#include <iostream>
#include <variant>

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
    std::cin >> result.centre.x >> result.centre.y >> result.radius >> color_string;
    result.color = stringToColor(color_string);
    return result;
}

void print(Circle c) {
    printf("Circle(");
    print(c.centre);
    printf(", %f) ", c.radius);
    printf("Perimeter: %f\n", perimeter(c));
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
    printf(") ");
    printf("Perimeter: %f\n", perimeter(r));
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
    std::cin >> result.a.x >> result.a.y >> result.b.x >> result.b.y >> result.c.x >> result.c.y >> color_string;
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
    printf(") ");
    printf("Perimeter: %f\n", perimeter(t));
}

using Figure = std::variant<Circle, Triangle, Rectangle>;

void print(Figure f) {
    try {
        print(std::get<Circle>(f));
        return;
    }
    catch (std::bad_variant_access const &ex) {}
    try {
        print(std::get<Rectangle>(f));
        return;
    }
    catch (std::bad_variant_access const &ex) {}
    print(std::get<Triangle>(f));
}

double perimeter(Figure f) {
    try {
        return perimeter(std::get<Circle>(f));
    }
    catch (std::bad_variant_access const &ex) {}
    try {
        return perimeter(std::get<Rectangle>(f));
    }
    catch (std::bad_variant_access const &ex) {}
    return perimeter(std::get<Triangle>(f));
}

void sort(Figure figures[], int n) {
    for (int i = 0; i < n; ++i) {
        double mx = -1;
        int mxj;
        for (int j = i; j < n; ++j) {
            if (perimeter(figures[j]) > mx) {
                mx = perimeter(figures[j]);
                mxj = j;
            }
        }
        std::swap(figures[i], figures[mxj]);
    }
}

int main(int argc, char *argv[]) {
    std::freopen(argv[1], "r", stdin);
    std::freopen(argv[2], "w", stdout);
    int figures_count;
    std::cin >> figures_count;
    Figure figures[figures_count];
    std::string figure_type, color;
    for (int i = 0; i < figures_count; ++i) {
        std::cin >> figure_type;
        if (figure_type == "Circle") {
            figures[i] = readCircle();
        } else if (figure_type == "Rectangle") {
            figures[i] = readRectangle();
        } else if (figure_type == "Triangle") {
            figures[i] = readTriangle();
        }
    }
    sort(figures, figures_count);
    for (int i = 0; i < figures_count; ++i) {
        print(figures[i]);
    }
}
