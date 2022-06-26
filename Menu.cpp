#include "Menu.h"

void Menu::setExpecte(Progress expected) {
	this->expected = expected;
}
Progress Menu::getExpecte() {
	return expected;
}

void Menu::setReal(Progress real) {
	this->real = real;
}
Progress Menu::getReal() {
	return real;
}

void Menu::setAlimenteConsumate(vector<Produs> alimenteConsumate) {
	alimenteConsumate = alimente_consumate;
}
vector<Produs> Menu::getAlimenteConsumate() {
	return alimente_consumate;
}

void Menu::setAlimenteRecommendated(vector<Produs> alimenteRecommandated) {

	alimenteRecommandated = alimente_recommandated;

}

vector<Produs> Menu::getAlimentRecommendated() {
	return alimente_recommandated;
}