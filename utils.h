#ifndef GEOMETRY_UTILS_H
#define GEOMETRY_UTILS_H

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

Color stringToColor(const char color_char) {
    if (color_char == 'R')
        return RED;
    if (color_char == 'O')
        return ORANGE;
    if (color_char == 'Y')
        return YELLOW;
    if (color_char == 'G')
        return GREEN;
    if (color_char == 'L')
        return LIGHT_BLUE;
    if (color_char == 'B')
        return BLUE;
    if (color_char == 'V')
        return VIOLET;
    return RED;
}

#endif //GEOMETRY_UTILS_H
