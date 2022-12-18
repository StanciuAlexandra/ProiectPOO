#include <iostream>
#include <string>
#include <iomanip>
#include <random>
#include <regex>
#include "Clase.h"

using namespace std;


int main() {
	cout << "\nAdauga un eveniment nou: \n" << endl;
	Eveniment e;
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
	int cz;

	Bilet* bilete;
	bilete = new Bilet[100];
	int nrBilete = 0;

	int choice;
	int nrr, nrc;
	do {
		cout << "\n Alegeti o zona: ";
		cin >> cz;

		z[cz - 1].printZona();
		cout << "\n Alegeti numarul randului si numarul coloanei: \n (ex. 3 5)";
		cin >> nrr >> nrc;
		while (nrr < 0 || nrr >= z[cz - 1].getNrRanduri() || nrc < 0 || nrc >= z[cz - 1].getNrColoane()) {
			cout << "Numar rand/coloana invalid!";
			cin >> nrr >> nrc;
		}
		if (z[cz - 1].scaunRezervat(nrr, nrc)) {
			cout << "\n Scaun deja rezervat. " << endl;
		}
		else {
			z[cz - 1].rezervaScaun(z[cz - 1], nrr, nrc);
			bilete[nrBilete] = Bilet(z[cz - 1], l, e, z[cz - 1].getChosenRow(), z[cz - 1].getChosenCol(), z[cz - 1].getPretBilet());
			cout << "\n Scaun rezervat cu succes." << endl;

			bilete[nrBilete].afiseazaInformatii();
			nrBilete++;
		}
		cout << "\n Vrei sa mai cumperi alt bilet?\n 1 - DA\n 2 - NU ";
		cin >> choice;
	} while (choice == 1);
	int choice2 = 0;
	cout << "\n Vrei sa vizualizezi biletul dupa cod?\n 1 - DA\n 2 - NU";
	cin >> choice2;
	if (choice2 != 1) {
		return 0;
	}
	else {
		do {

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
			cout << "\n Vrei sa vrei sa vizualizezi alt cod?\n 1 - DA\n 2 - NU";
			cin >> choice2;
		} while (choice2 == 1);
	}

	delete[]bilete;
	delete[] z;
}