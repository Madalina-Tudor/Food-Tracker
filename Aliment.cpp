#include<string>
#include <iostream>
#include "User.h"
#include "Aliment.h"
#include <fstream>
#include "Functii.h"
using namespace std;


void Aliment::setNume_aliment(string nume_aliment) {this-> nume_aliment= nume_aliment;}
string Aliment:: getNume_aliment() { return nume_aliment; }

void Aliment::setVal_energetica(double val_energ) {this->val_energ = val_energ;}
double Aliment::getVal_energetica() {return val_energ ;}


void Aliment::setGrasimi(double grasimi) { this->grasimi = grasimi; }
double Aliment::getGrasimi() { return grasimi; }

void Aliment::setAc_grasi(double ac_grasi) { this->ac_grasi = ac_grasi; }
double Aliment:: getAc_grasi() { return ac_grasi; }

void Aliment:: setGlucide(double glucide) { this->glucide = glucide; }
double Aliment::getGlucide() { return glucide; }

void  Aliment:: setZaharuri(double zaharuri) { this->zaharuri = zaharuri; }
double Aliment:: getZaharuri() { return zaharuri; }

void Aliment:: setFibre(double fibre) { this-> fibre= fibre; }
double Aliment::getFibre() { return fibre; }

void Aliment::setProteine(double proteine) { this->proteine = proteine; }
double Aliment::getProteine() { return proteine; }

void Aliment::setSare(double sare) { this->sare = sare; }
double Aliment:: getSare() { return sare; }

void Aliment:: setCantitate(double cantitate) { this->cantitate = cantitate; }
double Aliment:: getCantitate() { return cantitate; }

void Aliment::read_aliment() {

    string line;
    ofstream file2;
    ifstream file;
    bool check = false;
    int a = 0;

    //DE LUCRAT LA ESTETICA
    cout << "Ce fel masa este? " << endl;
    cout << "1.Mic dejun" << endl;
    cout << "2.Pranz" << endl;
    cout << "3.Cina" << endl;
    cout << "4.Gustari" << endl;
    cin >> line;

    a = stoi(line);


    if (stoi(line) == 1) {
        file2.open("Mic_dejun.txt", fstream::app);
    }
    else if (stoi(line) == 2) {
        file2.open("Pranz.txt", fstream::app);    
    }
    else if (stoi(line) == 3) {
        file2.open("Cina.txt", fstream::app);     
    }
    else if (stoi(line) == 4) {
        file2.open("Gustari.txt", fstream::app);       
    }
    line.clear();
Begin:
    system("cls");
    if (check) {
        cout << "ALERTTTTTTAAA RETARDATULE ALIMENTUL EXISTA" << endl;
        cout << "\a";
    }
    cout << "Nume aliment: ";
    cin.ignore();
    getline(cin, line);
    if (verify_product(a, line)) {
        check = true;
        goto Begin;
    }
    
    file2 << "Nume aliment: " + line;

    cout << "Valoare energetica: ";
    cin >> line;
    file2 << '\n' << "Valoare energetica: " + line;

    cout << "Grasimi: ";
    cin >> line;
    file2 << '\n' << "Grasimi: " + line;


    cout << "Din care acizi grasi saturati: : ";
    cin >> line;
    file2 << '\n' << "Din care acizi grasi saturati: " + line;


    cout << "Glucide: " << endl;
    cin >> line;
    file2 << '\n' << "Glucide: " + line;
    
    cout << "Zaharuri: " << endl;
    cin >> line;
    file2 << '\n' << "Zaharuri:  " + line;

    cout << "Fibre: " << endl;
    cin >> line;
    file2 << '\n' << "Fibre: " + line;

    cout << "Proteine: " << endl;
    cin >> line;
    file2 << '\n' << "Proteine: " + line;

    cout << "Sare: " << endl;
    cin >> line;
    file2 << '\n' << "Sare: " + line;

    cout << "Cantitate: " << endl;
    cin >> line;
    file2 << '\n' << "Cantitate: " + line;


    file2 << endl<<"***************************************" << endl << endl;
    file2.close();
    file.close();
}

void Aliment::set_stats(string nume , ifstream& file) {
    string line;
    char c = ' ';
    line = nume;
    nume = "Nume aliment: " + line;
    line.clear();
    bool check = false;
    while (getline(file, line)) {
        if (line == nume) {
            check = true;
            break;
        }
    }
    line.clear();
    if (check) {
        while (file.get(c)) {
            line.push_back(c);
            if (line == "Valoare energetica: ") {
                getline(file, line);
                val_energ = stoi(line);
                line.clear();
                continue;
            }
            if (line == "Grasimi: ") {
                getline(file, line);
                grasimi = stoi(line);
                line.clear();
                continue;
            }
            if (line == "Din care acizi grasi saturati: ") {
                getline(file, line);
                ac_grasi = stoi(line);
                line.clear();
                continue;
            }
            if (line == "Glucide: ") {
                getline(file, line);
                glucide = stoi(line);
                line.clear();
                continue;
            }
            if (line == "Zaharuri:  ") {
                getline(file, line);
                zaharuri = stoi(line);
                line.clear();
                continue;
            }
            if (line == "Fibre: ") {
                getline(file, line);
                fibre = stoi(line);
                line.clear();
                continue;
            }
            if (line == "Proteine: ") {
                getline(file, line);
                proteine = stoi(line);
                line.clear();
                continue;
            }
            if (line == "Sare: ") {
                getline(file, line);
                sare = stoi(line);
                line.clear();
                continue;
            }
            if (line == "Cantitate: ") {
                getline(file, line);
                cantitate = stoi(line);
                line.clear();
                continue;
            }

        }
    }


   
}

void Aliment::printProduct() {
    string line;
    ifstream file2;
    ifstream file;

    int a = 0;

    //DE LUCRAT LA ESTETICA
    cout << "Ce fel masa este? " << endl;
    cout << "1.Mic dejun" << endl;
    cout << "2.Pranz" << endl;
    cout << "3.Cina" << endl;
    cout << "4.Gustari" << endl;
    cin >> a;

    if (a == 1) {
        file2.open("Mic_dejun.txt", fstream::app);
    }
    else if (a == 2) {
        file2.open("Pranz.txt", fstream::app);
    }
    else if (a == 3) {
        file2.open("Cina.txt", fstream::app);
    }
    else if (a == 4) {
        file2.open("Gustari.txt", fstream::app);
    }

    while (getline(file2, line)) {
        cout << line << endl;
    }
}


int Aliment::calculCaloriProdus(double cantitate) {
    int calori;
    double calcul_proteine;
    double calcul_grasimi;
    double calcult_glucide;

    calcul_proteine = proteine * (cantitate / 100);
    calcul_grasimi = grasimi * (cantitate / 100);
    calcult_glucide = glucide * (cantitate / 100);


    calcul_proteine = calcul_proteine * 4;
    calcul_grasimi = calcul_grasimi * 9;
    calcult_glucide = calcult_glucide * 4;
    calori = calcul_proteine + calcul_grasimi + calcult_glucide;


    return calori;
}