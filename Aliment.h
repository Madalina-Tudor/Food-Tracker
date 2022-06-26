#pragma once
#include<string>
using namespace std;
class Aliment
{
private:

	string nume_aliment;
	double val_energ;
	double grasimi;
	double ac_grasi;
	double glucide;
	double zaharuri;
	double fibre;
	double proteine;
	double sare;
	double cantitate;

public:
	void read_aliment();
	void set_stats(string,ifstream&);
	void setNume_aliment(string);

	string getNume_aliment();

	void setVal_energetica(double);
	double getVal_energetica();

	void setGrasimi(double);
	double getGrasimi();

	void setAc_grasi(double);
	double getAc_grasi();

	void setGlucide(double);
	double getGlucide();

	void setZaharuri(double);
	double getZaharuri();

	void setFibre(double);
	double getFibre();

	void setProteine(double);
	double getProteine();

	void setSare(double);
	double getSare();

	void setCantitate(double);
	double getCantitate();

	void printProduct();

	int calculCaloriProdus(double);

};

