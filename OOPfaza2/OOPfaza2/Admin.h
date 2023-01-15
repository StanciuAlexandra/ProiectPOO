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
#include "Bilet.h"

using namespace std;

class Admin
{
private:
	int nrEvenimente;
	Eveniment* evenimente;

	int nrBilete;
	Bilet* bilete;
public:
	Admin();
	~Admin();
	void setNrEvenimente(int nrEvenimente);
	void setNrBilete(int nrBilete);
	void setEvenimente(Eveniment* evenimente, int nrEvenimente);
	void addEveniment(Eveniment e);
	void setBilete(Bilet* bilete, int nrBilete);
	void addBilet(Bilet b);
	void afiseazaE();
	void start();
	void evenimentNou(Eveniment&);
	void cumparaBilet(Bilet&);
	void cautaBilet();
	friend ofstream& operator<<(ofstream&, Admin&);
	friend ifstream& operator>>(ifstream&, Admin&);
};

