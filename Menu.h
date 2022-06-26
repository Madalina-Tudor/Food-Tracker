#pragma once
#include "Progress.h"
#include <vector>
#include "Produs.h"
class Menu
{
private:
    Progress expected;
    Progress real;
    vector<Produs> alimente_consumate;
    vector<Produs> alimente_recommandated;
public:

    void setExpecte(Progress);
    Progress getExpecte();

    void setReal(Progress);
    Progress getReal();

    void setAlimenteConsumate(vector<Produs>);
    vector<Produs> getAlimenteConsumate();

    void setAlimenteRecommendated(vector<Produs>);
    vector<Produs> getAlimentRecommendated();
};

