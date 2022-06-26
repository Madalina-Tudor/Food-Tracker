#pragma once
#include<string>
using namespace std;

class User
{private:
	string nume;
	int varsta;
	double inaltime;
	double greutate; 
	int sex;
	int scop;
	int metabolism;
	int tip_activitate_fizica;
	int greutate_dorita;
public:
	void setNume(string);
	void setVarsta(int);
	void setInaltime(double);
	void setGreutate(double);
	void setSex(int);
	void setScop(int);
	void setMetabolism(int);
	void setTip_activitate_fizica(int);
	void setgreutate_dorita( int);
	void read_data();


	string getNume();
	int getVarsta();
	double getInaltime();
	double getGreutate();
	int getSex();
	int getScop();
	int getMetabolism();
	int getTip_activitate_fizica();
	int getgreutate_dorita();

	void printUser();

	void calculareBMI();
	int calculateBMR();

	void editUser(int);

	void setUser();
};

