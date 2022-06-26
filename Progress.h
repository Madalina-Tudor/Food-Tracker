#pragma once
#include "User.h"
#include "Aliment.h"


class Progress
{
private:
	int consum_calorii;
	double carbs;
	double proteine;
	double grasimi;

public:
	int getConsum_cal();

	void setConsum_Calorii_Real(int);
	
	
	void setConsum_Calorii_Expected(User); 
	void set_Consum_Cal(int);


	void setCarbs(double);
	double getCarbs();

	void setProteine(double);
	double getProteine();

	void setGrasimi(double);
	double getGrasimi();

	friend Progress operator%(Progress, int);
};
