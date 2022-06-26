#include <iostream>
#include <fstream>
#include "User.h"
#include "Aliment.h"
#include "Progress.h"
#include "Meal.h"
#include "Functii.h"

using namespace std;

#define CREATE_USER 1
#define ACCESS_USER 2
#define EDIT_USER   3

#define USER 1
#define LOG  2
#define DATA 3

#define MIC_DEJUN 30
#define PRANZ 40
#define CINA 20
#define GUSTARI 10

bool check_data = false;

int MENU_STATE = USER;


void log_menu() {
    Aliment aliment;
    string data;
    string line;
    ofstream file;
    ifstream file2;
    cout << "--- LOG[2] --" << endl;
    cout << "Introduceti numarul corespunzator pentru avansare in meniu:" << endl;
    cout << "1. Vizualizare alimente" << endl;
    cout << "2. Introducere alimente" << endl;
    cout << "3. Vizualizare date" << endl;
    cout << "4. Back" << endl;
    cout << "5. Iesire aplicatie" << endl;

    int STATE_LOG;
    cin >> STATE_LOG;

    switch (STATE_LOG)
    {
    case 1:
        aliment.printProduct();
       
        break;
    case 2:
        aliment.read_aliment();
      
        break;
    case 3:
        cout << "Introduce data de astazi in formatul \" dd/mm/yyyy \" " << endl;
        cin >> data;
        file2.open("Data.txt");
        getline(file2, line);
        if (data == line) {
            check_data = true;
            file2.close();
        }
        else {
            check_data = false;
            file.open("Data.txt");
            file << data << endl;
            file.close();
        }
        MENU_STATE = DATA;
        
        break;
    case 4:
        MENU_STATE = USER;
        break;
    case 5:
        exit(0);
        break;
    default:
        MENU_STATE = LOG;
        break;
    }
}


void data_menu() {
Begin:
    int STATE_USER;
    ofstream file;
    ifstream file2;
    string line;
    Aliment aliment;
    Progress expected;
    Progress real;

    Meal meal;
    Meal mic_dejun{};
    Meal pranz{};
    Meal cina{};
    Meal gustari{};

    User user;
    user.setUser();
    expected.set_Consum_Cal(user.calculateBMR());
    mic_dejun.setExpected(expected % MIC_DEJUN);
    pranz.setExpected(expected % PRANZ);
    cina.setExpected(expected % CINA);
    gustari.setExpected(expected % GUSTARI);

    if (check_data) {
        int i = 0;
        file2.open("Progres real.txt");
        while (getline(file2, line)) {
            if (i == 0) {
                real.set_Consum_Cal(stoi(line));
                i++;
                continue;
            }
            if (i == 1) {
                mic_dejun.setReal(stoi(line));
                i++;
                continue;
            }
            if (i == 2) {
                pranz.setReal(stoi(line));
                i++;
                continue;
            }
            if (i == 3) {
                cina.setReal(stoi(line));
                i++;
                continue;
            }
            if (i == 4) {
                gustari.setReal(stoi(line));
                i++;
                continue;
            }
        }
        file2.close();
    }
    else
    {
        file.open("Progres real.txt");
        real.set_Consum_Cal(expected.getConsum_cal());

        mic_dejun.setReal(mic_dejun.getExpected().getConsum_cal());
        pranz.setReal(pranz.getExpected().getConsum_cal());
        cina.setReal(cina.getExpected().getConsum_cal());
        gustari.setReal(gustari.getExpected().getConsum_cal());
        file << real.getConsum_cal() << endl;
        file << mic_dejun.getReal().getConsum_cal()<<endl;
        file << pranz.getReal().getConsum_cal() << endl;
        file << cina.getReal().getConsum_cal() << endl;
        file << gustari.getReal().getConsum_cal() << endl;

        file.close();

    }

    cout << "1.Vizualizare Progres" << endl;
    cout << "2.Introduce aliment consumat" << endl;
    cout << "3.Vizualizeaza alimente consumate" << endl;
    cout << "4.Inapoi" << endl;
    cout << "5.Exit" << endl;



    cin >> STATE_USER;
    switch (STATE_USER)
    {
    case 1:
        cout << "1->Progres expect" << endl;
        cout << "2->Progres real" << endl;
        cin >> STATE_USER;
        if (STATE_USER == 1) {
            cout << "Progres expected: " << expected.getConsum_cal()<<endl;
            cout << "    -Mic dejun: " << mic_dejun.getExpected().getConsum_cal() << endl;
            cout << "    -Pranz: " << pranz.getExpected().getConsum_cal() << endl;
            cout << "    -Cina: " << cina.getExpected().getConsum_cal() << endl;
            cout << "    -Gustari: " << gustari.getExpected().getConsum_cal() << endl;
        }
        if (STATE_USER == 2) {
            cout << "Progres real: " << real.getConsum_cal() << endl;
            cout << "    -Mic dejun: " << mic_dejun.getReal().getConsum_cal() << endl;
            cout << "    -Pranz: " << pranz.getReal().getConsum_cal() << endl;
            cout << "    -Cina: " << cina.getReal().getConsum_cal() << endl;
            cout << "    -Gustari: " << gustari.getReal().getConsum_cal() << endl;
        }
        break;
    case 2:
       
        cout << "Din masa face parte alimentul consumat" << endl;
        cout << "1.Mic dejun" << endl;
        cout << "2.Pranz" << endl;
        cout << "3.Cina" << endl;
        cout << "4.Gustari" << endl;
        cin >> STATE_USER;
        if (STATE_USER == 1) {
            cout << "Cum se numeste alimentul consumat" << endl;
            cin >> line;
            if (verify_product(STATE_USER, line)) {
                file2.open("Mic_dejun.txt");
                aliment.set_stats(line, file2);
                cout << "Cantitatea consumata" << endl;
                int cantitate;
                cin >> cantitate;
                mic_dejun.setReal(mic_dejun.getReal().getConsum_cal() - aliment.calculCaloriProdus(cantitate));
                real.set_Consum_Cal(real.getConsum_cal() - aliment.calculCaloriProdus(cantitate));

                file.open("Progres real.txt");
                file << real.getConsum_cal() << endl;
                file << mic_dejun.getReal().getConsum_cal() << endl;
                file << pranz.getReal().getConsum_cal() << endl;
                file << cina.getReal().getConsum_cal() << endl;
                file << gustari.getReal().getConsum_cal() << endl;
                file.close();

            }
            else {
                cout << "Produsul nu exista" << endl;
                goto Begin;
            }  

        }
        if (STATE_USER == 2) {
            cout << "Cum se numeste alimentul consumat" << endl;
            cin >> line;
            if (verify_product(STATE_USER, line)) {
                file2.open("Pranz.txt");
                aliment.set_stats(line, file2);
                cout << "Cantitatea consumata" << endl;
                int cantitate;
                cin >> cantitate;
                pranz.setReal(pranz.getReal().getConsum_cal() - aliment.calculCaloriProdus(cantitate));
                real.set_Consum_Cal(real.getConsum_cal() - aliment.calculCaloriProdus(cantitate));

                file.open("Progres real.txt");
                file << real.getConsum_cal() << endl;
                file << mic_dejun.getReal().getConsum_cal() << endl;
                file << pranz.getReal().getConsum_cal() << endl;
                file << cina.getReal().getConsum_cal() << endl;
                file << gustari.getReal().getConsum_cal() << endl;
                file.close();
            }
            else {
                cout << "Produsul nu exista" << endl;
                goto Begin;
            }
        }
        if (STATE_USER == 3) {
            cout << "Cum se numeste alimentul consumat" << endl;
            cin >> line;
            if (verify_product(STATE_USER, line)) {
                file2.open("Cina.txt");
                aliment.set_stats(line, file2);
                cout << "Cantitatea consumata" << endl;
                int cantitate;
                cin >> cantitate;
                cina.setReal(cina.getReal().getConsum_cal() - aliment.calculCaloriProdus(cantitate));
                real.set_Consum_Cal(real.getConsum_cal() - aliment.calculCaloriProdus(cantitate));

                file.open("Progres real.txt");
                file << real.getConsum_cal() << endl;
                file << mic_dejun.getReal().getConsum_cal() << endl;
                file << pranz.getReal().getConsum_cal() << endl;
                file << cina.getReal().getConsum_cal() << endl;
                file << gustari.getReal().getConsum_cal() << endl;
                file.close();
            }
            else {
                cout << "Produsul nu exista" << endl;
                goto Begin;
            }
        }
        if (STATE_USER == 4) {
            cout << "Cum se numeste alimentul consumat" << endl;
            cin >> line;
            if (verify_product(STATE_USER, line)) {
                file2.open("Gustari.txt");
                aliment.set_stats(line, file2);
                cout << "Cantitatea consumata" << endl;
                int cantitate;
                cin >> cantitate;
                gustari.setReal(gustari.getReal().getConsum_cal() - aliment.calculCaloriProdus(cantitate));
                real.set_Consum_Cal(real.getConsum_cal() - aliment.calculCaloriProdus(cantitate));

                file.open("Progres real.txt");
                file << real.getConsum_cal() << endl;
                file << mic_dejun.getReal().getConsum_cal() << endl;
                file << pranz.getReal().getConsum_cal() << endl;
                file << cina.getReal().getConsum_cal() << endl;
                file << gustari.getReal().getConsum_cal() << endl;
                file.close();
            }
            else {
                cout << "Produsul nu exista" << endl; 
                goto Begin;
            }
        }
        
        break;
    case 3:
        break;
    case 4:
        MENU_STATE = LOG;
        break;
    case 5:
        exit(0);
        break;

    default:
        break;
    }
}


void user_menu() {
    User user;
    cout << "Introduceti numarul corespunzator pentru avansare in meniu:" << endl;
    cout << CREATE_USER << ". Creare utilizator" << endl;
    cout << ACCESS_USER << ". Accesare utilizator" << endl;
    cout << EDIT_USER << ". Editare utilizator" << endl;
    cout << "4.Next" << endl;
    cout << "5.Exit" << endl;

    int STATE_USER;

    cin >> STATE_USER;

    switch (STATE_USER)
    {
    case CREATE_USER:
        user.read_data();
        
        break;
    case ACCESS_USER:
        user.printUser();
        user.setUser();
        cout << "**************************" << endl;
        user.calculareBMI();
        cout << "**************************" << endl;
        cout << "BMR: " << user.calculateBMR() << endl;
       
        break;
    case EDIT_USER:
        user.printUser();
        user.setUser();
        cin >> STATE_USER;
        user.editUser(STATE_USER);
      
        break;
    case 4:
        MENU_STATE = LOG;
        break;
    case 5:
        exit(0);
        break;
    default:
        MENU_STATE = USER;
        break;
    }
}


int main()
{
    cout << "Hello world!"<<endl<<endl;
    while (true) {
        switch (MENU_STATE)
        {
        case USER:
            user_menu();
            break;
        case LOG:
            log_menu();
            break;
        case DATA:
            data_menu();
            break;
        }
    }

    return 0;
}