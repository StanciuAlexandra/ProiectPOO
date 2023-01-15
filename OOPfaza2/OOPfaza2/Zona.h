#pragma once
#include <iostream>
#include <string>
#include <iomanip>
#include <random>
#include <regex>
#include <fstream>

using namespace std;

class Zona
{
private:
	char* denumire;

	int nrRanduri;
	int nrColoane;
	bool* rezervari;
	int nrLocuri;
	int pretBilet;
	int chosenCol;
	int chosenRow;
	static char charInvalid;

public:
	Zona();
	Zona(const char* denumire, int nrRanduri, int nrColoane, int pretBilet);
	Zona(const Zona& z);
	~Zona();
	Zona& operator=(const Zona& z);

	char* getDenumire();
	void setDenumire(const char* denumire);
	int getNrColoane();
	void setNrColoane(int nrColoane);
	int getNrRanduri();
	void setNrRanduri(int nrRanduri);
	int getNrLocuri();
	void setNrLocuri(int nrColoane, int nrRanduri);
	bool* getRezervari();
	void setRezervari(bool* rezervari, int nrLocuri);

	bool scaunRezervat(int nrRanduri, int nrColoane);
	void rezervaScaun(Zona& zona, int nrRanduri, int nrColoane);

	void setChosenRow(int nrRanduri);
	int getChosenRow();
	void setChosenCol(int nrColoane);
	int getChosenCol();
	int getPretBilet();
	void setPretBilet(int pretBilet);

	void printZona();

	bool operator[](int index);
	bool operator!();

	friend ostream& operator<<(ostream&, Zona);
	friend istream& operator>>(istream&, Zona&);
	friend ofstream& operator<<(ofstream&, Zona&);
	friend ifstream& operator>>(ifstream&, Zona&);
};

