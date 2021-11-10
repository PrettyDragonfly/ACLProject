#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <map>

using std::cout; using std::cerr;
using std::endl; using std::string;
using std::ifstream; using std::ostringstream;
using std::istringstream;

string readFileIntoString(const string& path) {
    auto ss = ostringstream{};
    ifstream input_file(path);
    if (!input_file.is_open()) {
        cerr << "Could not open the file - '"
             << path << "'" << endl;
        exit(EXIT_FAILURE);
    }
    ss << input_file.rdbuf();
    return ss.str();
}

int readCSV() {
    string filename("map.csv");
    string file_contents;
    std::map<int, std::vector<string>> csv_contents;
    char delimiter = ',';

    file_contents = readFileIntoString(filename);

    istringstream sstream(file_contents);
    std::vector<string> items;
    string record;

    std::cout << file_contents << std::endl;
    int nbLine = 0;
    int counter = 0;
    while (std::getline(sstream, record)) {
        istringstream line(record);
        while (std::getline(line, record, delimiter)) {
            items.push_back(record);
        }

        csv_contents[counter] = items;
        items.clear();
        counter += 1;
    }
    nbLine = counter;
    std::cout << counter << std::endl;

   /** for (int i=0; i<counter; i++) {
        for(int j=0; j <nbLine; i++) {
            std::cout << (char)csv_contents[i] << std::endl;
        }
    }**/
}

/**
using namespace std;

void CSVReader() {
    ifstream fichier("map.csv", ios::in);  // on ouvre le fichier en lecture

    if(fichier)  // si l'ouverture a réussi
    {
        // instructions
        fichier.close();  // on ferme le fichier
    }
    else  // sinon
        cerr << "Impossible d'ouvrir le fichier !" << strerror(errno) << endl;
}**/