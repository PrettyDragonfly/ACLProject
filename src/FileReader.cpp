#include <iostream>
#include <fstream>
#include "model/map/Map.h"

using namespace std;

int readFile(Map* map) {
    string fileName = "map.txt";
    char a;
    int i, j;

    ifstream flux(fileName);
    if(flux) {
        for(i=0; i<map->getSize(); i++) {
            for (j=0; j<map->getSize(); j++) {

            }
        }
        while (flux.get(a)) {
            switch(a) {
                case '0':
                    cout <<"SOL ";
                    break;
                case '1':
                    cout << "MUR ";
                    break;
                case '2':
                    cout << "MUR INCASSABLE ";
                    break;
                default:
                    cout << "NOTHING" << endl;
                    break;
            }
        }
        flux.close();
    }
    else {
        cout << "c'est la merde" << endl;
    }
    return 0;
}