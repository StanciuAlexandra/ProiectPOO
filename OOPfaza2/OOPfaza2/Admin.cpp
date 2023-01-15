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
#include "Admin.h"
using namespace std;

Admin::Admin() {
	nrEvenimente = 0;
	evenimente = nullptr;

	nrBilete = 0;
	bilete = nullptr;
}

Admin::~Admin() {
	delete[]evenimente;
	delete[]bilete;
}
void Admin::setNrEvenimente(int nrEvenimente) {
	this->nrEvenimente = nrEvenimente;
}
void Admin::setNrBilete(int nrBilete) {
	this->nrBilete = nrBilete;
}

void Admin::setEvenimente(Eveniment* evenimente, int nrEvenimente) {
	if (evenimente != nullptr && nrEvenimente > 0) {
		if (this->evenimente != nullptr) {
			delete[]this->evenimente;
		}
		this->nrEvenimente = nrEvenimente;
		this->evenimente = new Eveniment[nrEvenimente];
		for (int i = 0; i < nrEvenimente; i++) {
			this->evenimente[i] = evenimente[i];
		}
	}
}
void Admin::addEveniment(Eveniment e) {
	if (evenimente != nullptr && nrEvenimente > 1) {
		Eveniment* copie = new Eveniment[nrEvenimente];
		for (int i = 0; i < nrEvenimente - 1; i++) {
			copie[i] = evenimente[i];
		}
		copie[nrEvenimente - 1] = e;
		setEvenimente(copie, nrEvenimente);
	}
	else {
		Eveniment* copie = new Eveniment[nrEvenimente];
		copie[0] = e;
		setEvenimente(copie, 1);
	}
}

void Admin::setBilete(Bilet* bilete, int nrBilete) {
	if (bilete != nullptr && nrBilete > 0) {
		if (this->bilete != nullptr) {
			delete[]this->bilete;
		}
		this->nrBilete = nrBilete;
		this->bilete = new Bilet[nrBilete];
		for (int i = 0; i < nrBilete; i++) {
			this->bilete[i] = bilete[i];
		}
	}
}
void Admin::addBilet(Bilet b) {
	if (bilete != nullptr && nrBilete > 1) {
		Bilet* copie = new Bilet[nrBilete];
		for (int i = 0; i < nrBilete - 1; i++) {
			copie[i] = bilete[i];
		}
		copie[nrBilete - 1] = b;
		setBilete(copie, nrBilete);
	}
	else {
		Bilet* copie = new Bilet[nrBilete];
		copie[0] = b;
		setBilete(copie, 1);
	}
}

void Admin::afiseazaE() {
	cout << endl;
	cout << setfill('-') << setw(40) << "" << endl;
	cout << setfill(' ') << setw(12) << "" << "LISTA EVENIMENTE" << setfill(' ') << setw(12) << "" << endl;
	cout << endl;
	for (int i = 0; i < nrEvenimente; i++) {
		cout << i << ". " << evenimente[i].getDenumire() << endl;
	}
	cout << setfill('-') << setw(40) << "" << endl;
}
void Admin::start() {

	int choice;
	Eveniment e;
	Bilet b;

	do {
		cout << endl << setfill(' ') << setw(7) << " " << "MENIU" << endl;
		cout << endl;
		cout << " 1. Adauga un eveniment" << endl;
		cout << " 2. Vizualizeaza evenimente" << endl;
		cout << " 3. Cumpara bilet" << endl;
		cout << " 4. Afiseaza detalii bilet" << endl;
		cout << " 5. Iesi din aplicatie" << endl;
		cin >> choice;
		cin.ignore();
		switch (choice) {
		case 1:

			evenimentNou(e);
			addEveniment(e);
			break;

		case 2:
			afiseazaE();
			break;
		case 3:
			cumparaBilet(b);
			addBilet(b);
			break;
		case 4:
			cautaBilet();
			break;
		default:cout << "Invalid! Alegeti o optiune valida" << endl;
		}
	} while (choice != 5);
}

ofstream& operator<<(ofstream& file, Admin& a) {
	for (int i = 0; i < a.nrEvenimente; i++) {
		file << a.evenimente[i] << endl;
	}
	return file;
}
ifstream& operator>>(ifstream& file, Admin& a) {
	for (int i = 0; i < a.nrEvenimente; i++) {
		file >> a.evenimente[i];
	}
	return file;
}
void Admin::evenimentNou(Eveniment& e) {
	cout << "\nAdauga un eveniment nou: \n" << endl;

	cin >> e;
	cout << endl;
	Locatie l;
	cin >> l;

	int nrRanduri, nrColoane, pretBilet;
	char buffer[100];

	Zona* z = new Zona[l.getNrZone()];
	for (int i = 0; i < l.getNrZone(); i++) {
		cout << "\nDenumire: ";

		cin >> ws;
		cin.getline(buffer, 99);
		char* denumire = new char[strlen(buffer) + 1];
		strcpy_s(denumire, strlen(buffer) + 1, buffer);

		cout << "Nr Randuri: ";
		cin >> nrRanduri;

		cout << "Nr Coloane: ";
		cin >> nrColoane;
		cout << "Pret bilet: ";
		cin >> pretBilet;
		z[i] = Zona(denumire, nrRanduri, nrColoane, pretBilet);
		z[i].printZona();
	}
	Locatie loc(l.getDenumire(), l.getNrZone(), z);
	e.setLocatie(loc);
	nrEvenimente++;

}
void Admin::cumparaBilet(Bilet& b) {
	afiseazaE();
	cout << "\n Alegeti un eveniment: " << endl;
	int nrEv = 0;
	cin >> nrEv;
	while (nrEv<0 || nrEv>nrEvenimente - 1) {
		cout << "Numar invalid! Alegeti altul. " << endl;
		cin >> nrEv;
	}
	cout << evenimente[nrEv];
	int cz;

	int nrr, nrc;

	cout << "\n Alegeti o zona: ";
	cin >> cz;
	while (cz<0 || cz>evenimente[nrEv].l.getNrZone()) {
		cout << "Numar invalid!" << endl;
		cin >> cz;
	}

	evenimente[nrEv].l.zone[cz - 1].printZona();
	cout << "\n Alegeti numarul randului si numarul coloanei: \n (ex. 3 5)";
	cin >> nrr >> nrc;
	while (nrr < 0 || nrr >= evenimente[nrEv].l.zone[cz - 1].getNrRanduri() || nrc < 0 || nrc >= evenimente[nrEv].l.zone[cz - 1].getNrColoane()) {
		cout << "Numar rand/coloana invalid!";
		cin >> nrr >> nrc;
	}
	if (evenimente[nrEv].l.zone[cz - 1].scaunRezervat(nrr, nrc)) {
		cout << "\n Scaun deja rezervat. " << endl;
	}
	else {
		evenimente[nrEv].l.zone[cz - 1].rezervaScaun(evenimente[nrEv].l.zone[cz - 1], nrr, nrc);
		b = Bilet(evenimente[nrEv].l.zone[cz - 1], evenimente[nrEv].l, evenimente[nrEv], evenimente[nrEv].l.zone[cz - 1].getChosenRow(), evenimente[nrEv].l.zone[cz - 1].getChosenCol(), evenimente[nrEv].l.zone[cz - 1].getPretBilet());
		cout << "\n Scaun rezervat cu succes." << endl;

		b.afiseazaInformatii();
		nrBilete++;
	}
}
void Admin::cautaBilet() {
	cout << "Introduceti codul biletului: ";
	string cod;
	cin >> cod;
	bool found = false;
	for (int i = 0; i < nrBilete; i++) {
		if (cod == bilete[i].getCod()) {
			bilete[i].afiseazaInformatii();
			found = true;
			break;
		}
	}
	if (!found) {
		cout << "\n Cod inexistent!";
	}
}