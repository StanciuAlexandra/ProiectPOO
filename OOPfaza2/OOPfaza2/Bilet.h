#pragma once
#include <iostream>
#include <string>
#include <iomanip>
#include <random>
#include <regex>
#include <fstream>

#include"Zona.h"
#include "Locatie.h"
#include "Eveniment.h"

using namespace std;

class Bilet
{
private:

	string cod;
	Zona zona;
	Locatie locatie;
	Eveniment eveniment;

	int chosenRow;
	int chosenCol;
	int pretBilet;

public:
	Bilet();
	Bilet(Zona& zona, Locatie locatie, Eveniment eveniment, int chosenRow, int chosenCol, int pretBilet);
	string getCod();
	int getChosenCol();
	int getChosenRow();
	int getPretBilet();
	void afiseazaInformatii();
	Bilet operator+(int valoare);
	Bilet operator++();
	Bilet operator++(int i);
	friend ostream& operator<<(ostream&, const Bilet&);
	friend istream& operator>>(istream&, Bilet&);
};

