#include <cstdio>
#include <iostream>
#include "Container.h"

int main(int argc, char *argv[]) {
    std::freopen(argv[1], "r", stdin);
    std::freopen(argv[2], "w", stdout);
    Container c = Container();
    c.read();
    c.sort();
    c.print();
}
