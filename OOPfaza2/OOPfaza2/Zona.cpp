#include "Zona.h"

#include <iostream>
#include <string>
#include <iomanip>
#include <random>
#include <regex>
#include <fstream>

using namespace std;

Zona::Zona() {
	denumire = nullptr;
	nrColoane = 0;
	nrRanduri = 0;
	nrLocuri = 0;
	pretBilet = 0;
	chosenRow = -1;
	chosenCol = -1;
	rezervari = nullptr;
}

Zona::Zona(const char* denumire, int nrRanduri, int nrColoane, int pretBilet) {
	if (denumire != nullptr) {
		this->denumire = new char[strlen(denumire) + 1];
		strcpy_s(this->denumire, strlen(denumire) + 1, denumire);
	}
	else {
		this->denumire = nullptr;
	}
	this->pretBilet = pretBilet;
	this->nrRanduri = nrRanduri;
	this->nrColoane = nrColoane;
	nrLocuri = nrRanduri * nrColoane;
	rezervari = new bool[nrRanduri * nrColoane];
	for (int i = 0; i < nrRanduri * nrColoane; i++) {
		rezervari[i] = false;
	}

	this->chosenRow = chosenRow;
	this->chosenCol = chosenCol;
}
Zona::Zona(const Zona& z) {
	if (z.denumire != nullptr) {
		this->denumire = new char[strlen(z.denumire) + 1];
		strcpy_s(this->denumire, strlen(z.denumire) + 1, z.denumire);
	}
	else {
		this->denumire = nullptr;
	}
	this->pretBilet = z.pretBilet;
	this->nrRanduri = z.nrRanduri;
	this->nrColoane = z.nrColoane;
	this->nrLocuri = z.nrLocuri;
	rezervari = new bool[z.nrRanduri * z.nrColoane];
	memcpy(rezervari, z.rezervari, nrRanduri * nrColoane * sizeof(bool));

	this->chosenRow = z.chosenRow;
	this->chosenCol = z.chosenCol;
}

Zona::~Zona() {
	delete[]denumire;
	delete[]rezervari;

}

Zona& Zona::operator=(const Zona& z) {
	if (this != &z) {

		if (z.denumire != nullptr) {
			if (denumire != nullptr) {
				delete[]denumire;
			}
			this->denumire = new char[strlen(z.denumire) + 1];
			strcpy_s(this->denumire, strlen(z.denumire) + 1, z.denumire);
		}

		if (rezervari != nullptr) {
			delete[]rezervari;
		}

		this->pretBilet = z.pretBilet;
		this->nrColoane = z.nrColoane;
		this->nrRanduri = z.nrRanduri;

		this->nrLocuri = z.nrLocuri;
		rezervari = new bool[z.nrRanduri * z.nrColoane];
		memcpy(rezervari, z.rezervari, nrRanduri * nrColoane * sizeof(bool));

		this->chosenRow = z.chosenRow;
		this->chosenCol = z.chosenCol;
	}
	return *this;
}

char*Zona:: getDenumire() {
	if (denumire != nullptr)
	{
		char* copy = new char[strlen(denumire) + 1];
		strcpy_s(copy, strlen(denumire) + 1, denumire);
		return copy;
	}
	return nullptr;
}

void Zona::setDenumire(const char* denumire) {
	if (denumire != nullptr)
	{
		if (this->denumire != nullptr)
		{
			delete[] this->denumire;
		}
		this->denumire = new char[strlen(denumire) + 1];
		strcpy_s(this->denumire, strlen(denumire) + 1, denumire);
	}
}

int Zona::getNrColoane() {
	return nrColoane;
}
void Zona::setNrColoane(int nrColoane) {
	if (nrColoane > 0) {
		this->nrColoane = nrColoane;
	}
	else {
		this->nrColoane = 0;
	}
}
int Zona::getNrRanduri() {
	return nrRanduri;
}
void Zona::setNrRanduri(int nrRanduri) {
	if (nrRanduri > 0) {
		this->nrRanduri = nrRanduri;
	}
	else {
		this->nrRanduri = nrRanduri;
	}
}

int Zona::getNrLocuri() {
	return nrLocuri;
}
void Zona::setNrLocuri(int nrColoane, int nrRanduri) {
	this->nrLocuri = nrRanduri * nrColoane;
}

bool* Zona::getRezervari() {
	if (rezervari != nullptr) {
		bool* copie = new bool[nrLocuri];
		for (int i = 0; i < nrLocuri; i++) {
			copie[i] = rezervari[i];
		}
		return copie;
	}
	else {
		return nullptr;
	}
}
void Zona::setRezervari(bool* rezervari, int nrLocuri) {
	if (rezervari != nullptr && nrLocuri > 0) {
		this->nrLocuri = nrLocuri;
		if (this->rezervari != nullptr) {
			delete[] this->rezervari;
		}
		this->rezervari = new bool[nrLocuri];
		for (int i = 0; i < nrLocuri; i++) {
			this->rezervari[i] = rezervari[i];
		}
	}
}
bool Zona::scaunRezervat(int nrRanduri, int nrColoane) {
	if (nrRanduri < 0 || nrRanduri >= this->nrRanduri || nrColoane < 0 || nrColoane >= this->nrColoane) {
		return false;
	}
	return rezervari[nrRanduri * this->nrColoane + nrColoane];
}

void Zona::rezervaScaun(Zona& zona, int nrRanduri, int nrColoane) {
	rezervari[nrRanduri * this->nrColoane + nrColoane] = true;
	zona.setChosenRow(nrRanduri);
	zona.setChosenCol(nrColoane);
}

void Zona::setChosenRow(int nrRanduri) {
	this->chosenRow = nrRanduri;
}
int Zona::getChosenRow() {
	return chosenRow;
}

void Zona::setChosenCol(int nrColoane) {
	this->chosenCol = nrColoane;
}
int Zona::getChosenCol() {
	return chosenCol;
}
int Zona::getPretBilet() {
	return pretBilet;
}
void Zona::setPretBilet(int pretBilet) {
	this->pretBilet = pretBilet;
}

void Zona::printZona() {
	cout << endl << setfill(' ') << setw(10) << "" << denumire << endl;
	cout << endl << setfill(' ') << setw(10) << "" << "Coloana" << endl << setfill(' ') << setw(8) << "";
	for (int i = 0; i < nrColoane; i++) {
		cout << setw(3) << i;
	}
	cout << endl;
	for (int i = 0; i < nrRanduri; i++) {
		cout << "Rand " << setw(2) << i << " ";
		for (int j = 0; j < nrColoane; j++) {
			if (scaunRezervat(i, j)) {
				cout << setw(3) << " X";
			}
			else {
				cout << setw(3) << " -";
			}

		}
		cout << endl;
	}
}
bool Zona::operator[](int index) {
	if (rezervari != nullptr && index >= 0 && index < nrLocuri) {
		return rezervari[index];
	}
	else {
		return charInvalid;
	}
}
bool Zona::operator!() {
	return !rezervari;
}
char Zona::charInvalid = -1;

ostream& operator<<(ostream& out, Zona z) {
	cout << endl;
	cout << "Denumire zona: ";
	out << z.denumire << endl;
	cout << "Nr. randuri: ";
	out << z.nrRanduri << endl;
	cout << "Nr. coloane: ";
	out << z.nrColoane << endl;
	cout << "Pret bilet: ";
	out << z.pretBilet << endl;
	cout << endl;
	cout << endl << setfill(' ') << setw(10) << "" << z.denumire << endl;
	cout << endl << setfill(' ') << setw(10) << "" << "Coloana" << endl << setfill(' ') << setw(8) << "";
	for (int i = 0; i < z.nrColoane; i++) {
		cout << setw(3) << i;
	}
	cout << endl;
	for (int i = 0; i < z.nrRanduri; i++) {
		cout << "Rand " << setw(2) << i << " ";
		for (int j = 0; j < z.nrColoane; j++) {
			if (z.scaunRezervat(i, j)) {
				cout << setw(3) << " X";
			}
			else {
				cout << setw(3) << " -";
			}

		}
		cout << endl;
	}

	return out;
}

istream& operator>>(istream& in, Zona& z) {
	char buffer[100];
	while (strlen(z.denumire) + 1 < 2) {
		cout << "Denumire: ";

		in >> ws;
		in.getline(buffer, 99);
		z.denumire = new char[strlen(buffer) + 1];
		strcpy_s(z.denumire, strlen(buffer) + 1, buffer);
	}
	while (z.nrColoane < 1) {
		cout << "Nr. coloane: ";
		in >> z.nrColoane;
	}
	while (z.nrRanduri < 1) {
		cout << "Nr. randuri: ";
		in >> z.nrRanduri;
	}
	cout << "Pret bilet: ";
	in >> z.pretBilet;

	return in;

}

ofstream& operator<< (ofstream& file, Zona& z) {
	file << z.denumire << endl;
	file << z.nrRanduri << endl;
	file << z.nrColoane << endl;
	file << z.pretBilet << endl;
	return file;
}

ifstream& operator>>(ifstream& file, Zona& z) {
	delete[]z.denumire;
	file >> z.denumire;
	char aux[50];
	file >> aux;
	z.denumire = new char[strlen(aux) + 1];
	strcpy_s(z.denumire, strlen(aux) + 1, aux);
	file >> z.nrRanduri;
	file >> z.nrColoane;
	return file;
}