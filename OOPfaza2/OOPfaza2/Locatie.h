#pragma once
#include <iostream>
#include <string>
#include <iomanip>
#include <random>
#include <regex>
#include <fstream>

#include "Zona.h"

using namespace std;

class Locatie
{
private:
	int nrZone;
	string denumire;

public:
	Zona* zone;
	Locatie();
	Locatie(string denumire, int nrZone, Zona* zone);
	Locatie(const Locatie& l);
	Locatie& operator=(const Locatie& l);
	~Locatie();

	int getNrZone();
	void setNrZone(int nrZone);
	string getDenumire();
	void setDenumire(string denumire);
	Zona* getZone();
	void setZone(int nrZone, Zona* zone);
	bool operator==(const Locatie& other) const;


	friend ostream& operator<<(ostream&, Locatie);
	friend istream& operator>>(istream&, Locatie&);
	friend ofstream& operator<<(ofstream&, Locatie&);
	friend ifstream& operator>>(ifstream&, Locatie&);
};

