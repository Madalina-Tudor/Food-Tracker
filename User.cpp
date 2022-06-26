#include "User.h"
#include<string>
#include <iostream>
#include <fstream>
using namespace std;

void User:: setNume(string nume) { nume; }
string User::getNume() { return nume; }

void User::setVarsta(int varsta) { this->varsta = varsta; }
int User::getVarsta() { return varsta; }

void User::setInaltime(double inaltime) { this->inaltime = inaltime; }
double User::getInaltime() { return inaltime; }


void User:: setGreutate(double Greutate) { this->greutate = greutate; }
double User::getGreutate() { return greutate; }



void User::setScop(int Scop) { this->scop = scop; }
int User::getScop() { return scop; }


void User::setMetabolism(int Metabolism) { this->metabolism = metabolism; }
int User::getMetabolism() { return metabolism ; }


void User::setTip_activitate_fizica(int Tip_activitate_fizica) { this-> tip_activitate_fizica = tip_activitate_fizica; }
int  User::getTip_activitate_fizica() { return tip_activitate_fizica; }

void User::setgreutate_dorita(int greutate_dorita) { this->greutate_dorita = greutate_dorita; }
int  User:: getgreutate_dorita() { return greutate_dorita ; }

void User::setSex(int Sex) { Sex = 1; }
int User::getSex() { return sex; }

//READ DATA
void User::read_data() {
    string line;
    ofstream file2;
    file2.open("User.txt");
        cout << "Nume: ";
        cin.ignore();
        getline(cin, line);
        file2 << "Nume: " + line;

        cout << "Varsta: ";
        cin >> line;
        file2 << '\n' << "Varsta: " + line;

        cout << "Inaltime: ";
        cin >> line;
        file2 << '\n' << "Inaltime: " + line;


        cout << "Greutate: ";
        cin >> line;
        file2 << '\n' << "Greutate: " + line<<endl;
      
        cout << endl<<"Scop: "<<endl;
        cout << "1.Scadere\n2.Mentinere\n3.Crestere" << endl;
        do {
            cin >> line;
            switch (stoi(line))
            {
            case 1:
                file2 << "Scop: Scadere" << endl;
                break;
            case 2:
                file2 << "Scop: Mentinere" << endl;
                break;

            case 3:
                file2 << "Scop: Crestere" << endl;
                break;
            default:
                cout << "ERRORRRR" << endl;
                break;
            }
        } 
        while (stoi(line) > 3);

        cout << endl<<"Metabolism: "<<endl;
        cout << "1.Rapid\n2.Normal\n3.Lent" << endl;
        do {
            cin >> line;
            switch (stoi(line))
            {
            case 1:
                file2 << "Metabolism: Rapid" << endl;
                break;
            case 2:
                file2 << "Metabolism: Normal" << endl;
                break;

            case 3:
                file2 << "Metabolism: Lent" << endl;
                break;
            default:
                cout << "ERRORRRR" << endl;
                break;
            }
        } while (stoi(line) > 3);


        cout <<endl<< "Tip activitate fizica: "<<endl;
        cout << "1.Sedentara\n2.Usoara\n3.Moderata\n4.Intensa"<<endl;
        do {
            cin >> line;
            switch (stoi(line))
            {
            case 1:
                file2 << "Tip activitate fizica: Sedentara";
                break;
            case 2:
                file2 << "Tip activitate fizica: Usoara";
                break;

            case 3:
                file2 << "Tip activitate fizica: Moderata" ;
                break;
            case 4:
                file2 << "Tip activitate fizica: Intensa";
                break;
            default:
                cout << "ERRORRRR";
                break;
            }
        } while (stoi(line) > 4);


        cout <<endl<< "Greutatea Dorita: ";
        cin >> line;
        file2 <<endl<<"Greutatea Dorita: " + line<<endl;

        cout << "Sex: " << endl;
        cout << "1.Male" << endl << "2.Female" << endl;

        do {
            cin >> line;
            if (stoi(line) == 1) {
                file2 << "Sex: Male" << endl;
            }
            else
            {
                if (stoi(line) == 2)
                {
                    file2 << "Sex: Female" << endl;

                }
            }
        } while (stoi(line) >= 3);
        file2<< "***************************************"<<endl;
        file2.close();

}

//PRINT USER
void User::printUser() {
    ifstream file_in;//folosim pentru ca citi din fisier
    file_in.open("User.txt");
    string line;
    int i = 1;
    while (getline(file_in, line)) {
        if (line == "***************************************") {
            break;
        }
        cout <<i<<"->" <<line << endl;
        i++;
    }
    file_in.close();
}

//BMI
void User::calculareBMI() {
    double result;
    double height = (inaltime * inaltime)/2;
    result = greutate / height;

    if (result < 18.5) {
        cout << "Greutate underweight" << endl;
    }
    if ((result >= 18.5) && (result <= 24.8)) {
        cout << "Greutate normala" << endl;
    }
    if ((result >= 25) && (result <= 29.9)) {
        cout << "Greutate overweight" << endl;
    }
    if ((result >= 30) && (result <= 34.9)) {
        cout << "Greutate obese" << endl;
    }
    if (result>35) {
        cout << "Greutate obese xtreme" << endl;

    }
}

//BMR
int User::calculateBMR() {
   
    int bmr{};
    if (scop == 2) {
        if (sex == 1) {
            bmr = 88.362 + (13.397 * greutate) + (4.799 * inaltime) - (5.667 * varsta);

        }
        else if (sex == 2) {
            bmr = 447.593 + (9.247 * greutate) + (3.098 * inaltime) - (4.330 * varsta);

        }
        if (tip_activitate_fizica == 1) {
            return bmr * 1.2;
        }
        else if (tip_activitate_fizica == 2) {
            return bmr * 1.375;
        }
        else if (tip_activitate_fizica == 3) {
            return bmr * 1.55;
        }
        else if (tip_activitate_fizica == 4) {
            return bmr * 1.725;
        }

    }
    else
    {
        if (sex == 1) {
            bmr = 88.362 + (13.397 * greutate_dorita) + (4.799 * inaltime) - (5.667 * varsta);
        }
        else if (sex == 2) {
            bmr = 447.593 + (9.247 * greutate_dorita) + (3.098 * inaltime) - (4.330 * varsta);
        }
        if (tip_activitate_fizica == 1) {
            return bmr * 1.2;
        }
        else if (tip_activitate_fizica == 2) {
            return bmr * 1.375;
        }
        else if (tip_activitate_fizica == 3) {
            return bmr * 1.55;
        }
        else if (tip_activitate_fizica == 4) {
            return bmr * 1.725;
        }
    }


    return 0;
}  

//EDIT USER
void User::editUser(int choice) {
    ofstream file;
    string line;
    string input;
    if (choice == 1) {
        cout << "Nume: ";
        cin.ignore();
        getline(cin, line);
        nume = line;
    }
    if (choice == 2) {
        cout << "Varsta: ";
        cin >> line;
        varsta = stoi(line);
    }
    if (choice == 3) {
        cout << "Inaltime: ";
        cin >> line;
        inaltime = stoi(line);
    }
    if (choice == 4) {
        cout << "Greutate: ";
        cin >> line;
        greutate = stoi(line);
    }
    if (choice == 5) {
        cout << "Scopul" << endl;
        cout << "1.Scadere\n2.Mentinere\n3.Crestere" << endl;
        cin >> line;
        scop = stoi(line);
    }
    if (choice == 6) {
        cout << "Metabolism" << endl;
        cout << "1.Rapid\n2.Normal\n3.Lent" << endl;
        cin >> line;
        metabolism = stoi(line);
    }
    if (choice == 7) {
        cout << "Activitate Fizica" << endl;
        cout << "1.Sedentar\n2.Usoara\n3.Moderata\n4.Intensa" << endl;
        cin >> line;
        tip_activitate_fizica = stoi(line);
    }
    if (choice == 8) {
        cout << "Greutate dorita: ";
        cin >> line;
        greutate_dorita = stoi(line);
    }
    if (choice == 9) {
        cout << "Sex: " << endl;
        cout << "1.Male\n2.Female" << endl;
        cin >> line;
        sex = stoi(line);
    }

    file.open("User.txt");
    if (!file) {
        cout << "Error" << endl;
    }
    else {
        //Nume
        input = nume;
        line = "Nume: " + input;
        file << line;
        input.clear();
        line.clear();
        system("cls");

        //Varsta
        input = to_string(varsta);
        line = "Varsta: " + input;
        file << endl << line;
        input.clear();
        line.clear();
        system("cls");

        //Inaltime
        input = to_string(inaltime);
        line = "Inaltime: " + input;
        file << endl << line;
        input.clear();
        line.clear();
        system("cls");

        //Greutate
        input = to_string(greutate);
        line = "Greutate: " + input;
        file << endl << line;
        input.clear();
        line.clear();
        system("cls");

        //Scop
        input = to_string(scop);
        if (stoi(input) == 1) {
            line = "Scop: Scadere";
            file << endl << line;
            line.clear();
        }
        if (stoi(input) == 2) {
            line = "Scop: Mentinere";
            file << endl << line;
            line.clear();
        }
        if (stoi(input) == 3) {
            line = "Scop: Crestere";
            file << endl << line;
            line.clear();
        }
        system("cls");

        //Metabolism
        input = to_string(metabolism);
        if (stoi(input) == 1) {
            line = "Metabolism: Rapid";
            file << endl << line;
            line.clear();
        }
        if (stoi(input) == 2) {
            line = "Metabolism: Normal";
            file << endl << line;
            line.clear();
        }
        if (stoi(input) == 3) {
            line = "Metabolism: Lent";
            file << endl << line;
            line.clear();
        }
        system("cls");

        //Tip Activitate Fizica
        input = to_string(tip_activitate_fizica);
        if (stoi(input) == 1) {
            line = "Activitate Fizica: Sedentar";
            file << endl << line;
            line.clear();
        }
        if (stoi(input) == 2) {
            line = "Activitate Fizica: Usoara";
            file << endl << line;
            line.clear();
        }
        if (stoi(input) == 3) {
            line = "Activitate Fizica: Moderata";
            file << endl << line;
            line.clear();
        }
        if (stoi(input) == 4) {
            line = "Activitate Fizica: Intensa";
            file << endl << line;
            line.clear();
        }
        system("cls");
        //Greutate Dorita
        input = to_string(greutate_dorita);
        line = "Greutate Dorita: " + input;
        file << endl << line;
        input.clear();
       line.clear();
        system("cls");

        //Sex
        input = to_string(sex);
        if (stoi(input) == 1) {
            line = "Sex: Male";
            file << endl << line;
            line.clear();
        }
        else if (stoi(input) == 2) {
            line = "Sex: Female";
            file << endl << line;
            line.clear();
        }
        file << endl << "*********************************************" << endl;
        input.clear();
        line.clear();
        system("cls");
    }
    file.close();
}

//SET USER-pt init date user din fisier 
void User::setUser() {
    ifstream file;
    file.open("User.txt");
    string line;
    char c = ' ';
    int i=0;
    while (file.get(c)) {
        if (c == '\n') {
            line.clear();
            continue;
        }
        line.push_back(c);
        if (line == "Nume: ") {
            getline(file, line);
            nume = line;
            line.clear();
            continue;
        }
        if (line == "Varsta: ") {
            getline(file, line);
            varsta = stoi(line);
            line.clear();
            continue;
        }
        if (line == "Inaltime: ") {
            getline(file, line);
            inaltime = stoi(line);
            line.clear();
            continue;
        }
        if (line == "Greutate: ") {
            getline(file, line);
            greutate = stoi(line);
            line.clear();
            continue;
        }
        if (line == "Sex: ") {
            getline(file, line);
            if (line == "Male") {
                sex = 1;
            }
            else {
                sex = 2;
            }

            line.clear();
            continue;
        }
        if (line == "Scop: ") {
            getline(file, line);
            if (line == "Scadere") {
                scop = 1;
           }
            if (line == "Mentinere") {
               scop = 2;
           }
            if (line == "Crestere") {
               scop = 3;
           }

            line.clear();
            continue;
        }
        if (line == "Metabolism: ") {
            getline(file, line);
           
        if (line == "Lent") {
            metabolism = 1;
        }
        if (line == "Normal") {
            metabolism = 2;
        }
        if (line == "Rapid") {
            metabolism = 3;
        }
       


            line.clear();
            continue;
        }
        if (line == "Tip activitate fizica: ") {
          

                if (line == "Sedentara") {
                    tip_activitate_fizica = 1;
                }
                if (line == "Usoara") {
                    tip_activitate_fizica = 2;
                }
                if (line == "Moderata") {
                    tip_activitate_fizica = 3;
                }
                if (line == "Intensa") {
                    tip_activitate_fizica = 4;
                }

           
            line.clear();
            continue;
        }
        if (line == "Greutatea Dorita: ") {
            getline(file, line);
            greutate_dorita = stoi(line);
            line.clear();
            continue;
        }

    }

}