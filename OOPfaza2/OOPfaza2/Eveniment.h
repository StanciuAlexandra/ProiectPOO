#pragma once
#include <iostream>
#include <string>
#include <iomanip>
#include <random>
#include <regex>
#include <fstream>

#include"Zona.h"
#include "Locatie.h"

using namespace std;
class Eveniment
{
private:
	string Denumire;
	string Data;
	string Ora;


	static int nrEvenimente;
public:
	Locatie l;
	Eveniment();
	Eveniment(string Denumire, string Data, string Ora);
	Eveniment(string Denumire, string Data, string Ora, Locatie l);
	Eveniment(const Eveniment& e);
	Eveniment& operator=(const Eveniment& e);
	~Eveniment();
	string getDenumire();
	void setDenumire(string Denumire);
	string getData();
	void setData(string Data);
	string getOra();
	void setOra(string Ora);
	void setLocatie(Locatie l);
	Locatie getLocatie();
	bool isValidData(string Data);
	bool isValidOra(string Ora);
	explicit operator string();

	friend ostream& operator<<(ostream&, Eveniment);
	friend istream& operator>>(istream&, Eveniment&);
	friend ofstream& operator<<(ofstream&, Eveniment&);
	friend ifstream& operator>>(ifstream&, Eveniment&);
};

