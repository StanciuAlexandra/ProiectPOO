#include <iostream>
#include <string>
#include <iomanip>
#include <random>
#include <regex>
#include <fstream>

#include "Locatie.h"
#include "Zona.h"
using namespace std;

Locatie::Locatie() {
	nrZone = 0;
	zone = nullptr;
	denumire = "N/A";
}
Locatie::Locatie(string denumire, int nrZone, Zona* zone) {
	this->denumire = denumire;
	this->nrZone = nrZone;
	this->zone = new Zona[nrZone];
	for (int i = 0; i < nrZone; i++) {
		this->zone[i] = zone[i];
	}
}
Locatie::Locatie(const Locatie& l) {
	if (l.denumire.length() > 0) {
		this->denumire = l.denumire;
	}
	else {
		this->denumire = "N/A";
	}
	this->nrZone = l.nrZone;
	if (l.nrZone > 0 && l.zone != nullptr) {
		this->nrZone = l.nrZone;
		this->zone = new Zona[l.nrZone];
		for (int i = 0; i < l.nrZone; i++) {
			this->zone[i] = l.zone[i];
		}
	}
	else {
		this->zone = nullptr;
		this->nrZone = 0;
	}
}
Locatie& Locatie::operator=(const Locatie& l) {
	if (l.denumire.length() > 0) {
		this->denumire = l.denumire;
	}
	else {
		this->denumire = "N/A";
	}
	if (zone != nullptr) {
		delete[]zone;
	}
	if (l.nrZone > 0 && l.zone != nullptr) {
		this->nrZone = l.nrZone;
		this->zone = new Zona[l.nrZone];
		for (int i = 0; i < l.nrZone; i++) {
			this->zone[i] = l.zone[i];
		}
	}
	else {
		this->zone = nullptr;
		this->nrZone = 0;
	}
	return *this;
}
Locatie::~Locatie() {
	if (zone != nullptr) {
		delete[] zone;
	}
}

int Locatie::getNrZone() {
	return nrZone;
}
void Locatie::setNrZone(int nrZone) {
	if (nrZone > 0) {
		this->nrZone = nrZone;
	}
	else {
		this->nrZone = 0;
	}
}
string Locatie::getDenumire() {
	return denumire;
}
void Locatie::setDenumire(string denumire) {
	if (denumire.length() > 0) {
		this->denumire = denumire;
	}
	else {
		this->denumire = "N/A";
	}
}
Zona* Locatie::getZone() {
	if (zone != nullptr) {
		Zona* copie = new Zona[nrZone];
		for (int i = 0; i < nrZone; i++) {
			copie[i] = zone[i];
		}
		return copie;
	}
}
void Locatie::setZone(int nrZone, Zona* zone) {
	if (nrZone > 0) {
		this->nrZone = nrZone;
		this->zone = new Zona[nrZone];
		for (int i = 0; i < nrZone; i++) {
			this->zone[i] = zone[i];
		}
	}
	else {
		this->nrZone = 0;
		this->zone = nullptr;
	}
}

bool Locatie::operator==(const Locatie& other) const {
	return denumire == other.denumire && nrZone == other.nrZone;
}

ostream& operator<<(ostream& out, Locatie l) {
	cout << "Denumire locatie: ";
	out << l.denumire << endl;
	cout << "Nr. Zone: ";
	out << l.nrZone << endl;
	for (int i = 0; i < l.nrZone; i++) {
		cout << l.zone[i] << endl;
	}

	return out;
}
istream& operator>>(istream& in, Locatie& l) {
	cout << "Denumire locatie: ";
	in >> ws;
	getline(in, l.denumire);
	while (l.denumire.length() < 1) {
		cout << "Denumire locatie: ";
		in >> l.denumire;
	}
	while (l.nrZone < 1) {
		cout << "Nr. zone: ";
		in >> l.nrZone;
	}
	return in;
}

ofstream& operator<<(ofstream& file, Locatie& l) {
	file << l.denumire << endl;
	file << l.nrZone << endl;
	for (int i = 0; i < l.nrZone; i++) {
		file << l.zone[i] << endl;
	}
	return file;
}
ifstream& operator>>(ifstream& file, Locatie& l) {
	file >> l.denumire;
	file >> l.nrZone;
	for (int i = 0; i < l.nrZone; i++) {
		file >> l.zone[i];
	}
	return file;
}