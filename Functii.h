#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <fstream>

using namespace std;

inline bool verify_product(int a, string line) {
    string line_2;  
    ifstream file;
    char c = ' ';
    if (a == 1) {       
        file.open("Mic_dejun.txt");
    }
    else if (a == 2) { 
        file.open("Pranz.txt");
    }
    else if (a == 3) {       
        file.open("Cina.txt");
    }
    else if (a == 4) {
        file.open("Gustari.txt");
    }

	while (file.get(c)) {

        line_2.push_back(c);
        if (line_2 == "Nume aliment: ") {
            line_2.clear();
            getline(file, line_2);
            if (line_2 == line) {
                file.close();
                return true;
            }
        }
		
	}
    file.close();
	return false;
}