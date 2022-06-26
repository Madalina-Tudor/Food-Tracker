#include "Meal.h"
#include"Progress.h"
#include "Aliment.h"


void Meal:: setMic_dejun(Aliment mic_dejun) { this->mic_dejun = mic_dejun; }
Aliment Meal::getMic_dejun() { return mic_dejun; }

void Meal::setPranz(Aliment pranz) { this->pranz = pranz; }
Aliment Meal::getPranz() { return pranz; }


void Meal::setCina(Aliment cina){ this-> cina= cina; }
Aliment Meal::getCina() { return cina; }
void Meal::setExpected(int expec) {
	expected.set_Consum_Cal(expec);
}
Progress Meal::getExpected() {
	return expected;
}
void Meal::setReal(int rl) {
	real.set_Consum_Cal(rl);
}
Progress Meal::getReal() {
	return real;
}
void  Meal::setExpected(Progress expected) {
	this->expected = expected;
}
void  Meal::setReal(Progress real) {
	this->real = real;
}