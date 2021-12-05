#include <iostream>
#include <fstream>
#include "FileReader.h"

using namespace std;

int readFile(Map* map) {
    string fileName = "map.txt";
    char a;
    int i, j;

    ifstream flux(fileName);
    if(flux) {
        for(i=0; i<map->get_size(); i++) {
            if (i!=0) {
                flux.get(a);
            }
            for (j=0; j<map->get_size(); j++) {
                if(flux.get(a)) {
                    map->setTile(i,j,a);
                }
            }
        }
        flux.close();
    }
    else {
        cout << "Can't open the file" << endl;
    }
    return 0;
}