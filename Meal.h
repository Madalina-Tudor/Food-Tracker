#pragma once
#include "Progress.h"
#include "Aliment.h"
#include <string>
using namespace std;

class Meal
{
private:
	Progress expected{};
	Progress real{};
	Aliment mic_dejun;
	Aliment pranz;
	Aliment cina;
	Aliment gustari;

	// data de unde sa caute progressul
public:
	void setExpected(int);
	Progress getExpected();

	void setReal(int);
	Progress getReal();


	void setMic_dejun(Aliment);
    Aliment getMic_dejun();

	void setPranz(Aliment);
	Aliment getPranz();

	void setCina(Aliment);
	Aliment getCina();

	void setGustari(Aliment);
	Aliment getGustari();

	void setExpected(Progress);
	void setReal(Progress);
	
	
};

