#include <iostream>
#include "../src/model/entities/Bomb.h"
#include "../src/model/map/Map.h"

int main() {
    Map m;
    Bomb b(1, 2, &m);
}
