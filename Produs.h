#pragma once
#include "Aliment.h"

class Produs
{
private:
    Aliment aliment;
    double cantitate;
    int portie;

public:

    void setAliment(Aliment);
    
    Aliment getAlimet();

    void setCantitate(double);
    double getCantitate();

    void setPortie(int);
    int getPortie();

};

