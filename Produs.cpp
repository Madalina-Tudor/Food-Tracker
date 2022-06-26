#include "Produs.h"


void Produs::setAliment(Aliment aliment) {
	this->aliment = aliment;

}
Aliment Produs::getAlimet(){
	return aliment;
}

void Produs::setCantitate(double) {

}
double Produs::getCantitate() {
	return cantitate;
}

void Produs::setPortie(int portie) {
	this->portie = portie;

}
int Produs::getPortie() {
	return portie;
}
