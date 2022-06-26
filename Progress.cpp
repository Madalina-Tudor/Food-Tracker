#include "Progress.h"
#include "User.h"

void Progress::setConsum_Calorii_Real(int consum_calorii) { this->consum_calorii = consum_calorii; }

int Progress::getConsum_cal() {
	return consum_calorii;}

void Progress::setConsum_Calorii_Expected(User user) {
	this->consum_calorii = user.calculateBMR();
}

void Progress::set_Consum_Cal(int a) {
	consum_calorii = a;
}
void Progress::setCarbs(double carbs) {
	this->carbs = carbs;
}
double Progress::getCarbs() { return carbs; }

void Progress::setProteine(double proteine) {
	this->proteine = proteine;
}

double Progress::getProteine() { return proteine; }

void Progress::setGrasimi(double grasimi) {
	this->grasimi = grasimi;
}
double Progress::getGrasimi() {
	return grasimi;
}

Progress operator%(Progress p, int a) {

	p.set_Consum_Cal(p.getConsum_cal() * a/ 100);
	return p;
}