#pragma once
#include <iostream>
#include <string>
#include <iomanip>
#include <random>
#include <regex>
using namespace std;

class Zona {
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
	Zona() {
		denumire = nullptr;
		nrColoane = 0;
		nrRanduri = 0;
		nrLocuri = 0;
		pretBilet = 0;
		chosenRow = -1;
		chosenCol = -1;
		rezervari = nullptr;
	}
	Zona(const char* denumire, int nrRanduri, int nrColoane, int pretBilet) {
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
	Zona(const Zona& z) {
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

	~Zona() {
		delete[]denumire;
		delete[]rezervari;

	}

	Zona& operator=(const Zona& z) {
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

	char* getDenumire() {
		if (denumire != nullptr)
		{
			char* copy = new char[strlen(denumire) + 1];
			strcpy_s(copy, strlen(denumire) + 1, denumire);
			return copy;
		}
		return nullptr;
	}

	void setDenumire(const char* denumire) {
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

	int getNrColoane() {
		return nrColoane;
	}
	void setNrColoane(int nrColoane) {
		if (nrColoane > 0) {
			this->nrColoane = nrColoane;
		}
		else {
			this->nrColoane = 0;
		}
	}
	int getNrRanduri() {
		return nrRanduri;
	}
	void setNrRanduri(int nrRanduri) {
		if (nrRanduri > 0) {
			this->nrRanduri = nrRanduri;
		}
		else {
			this->nrRanduri = nrRanduri;
		}
	}

	int getNrLocuri() {
		return nrLocuri;
	}
	void setNrLocuri(int nrColoane, int nrRanduri) {
		this->nrLocuri = nrRanduri * nrColoane;
	}

	bool* getRezervari() {
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
	void setRezervari(bool* rezervari, int nrLocuri) {
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
	bool scaunRezervat(int nrRanduri, int nrColoane) {
		if (nrRanduri < 0 || nrRanduri >= this->nrRanduri || nrColoane < 0 || nrColoane >= this->nrColoane) {
			return false;
		}
		return rezervari[nrRanduri * this->nrColoane + nrColoane];
	}

	void rezervaScaun(Zona& zona, int nrRanduri, int nrColoane) {
		rezervari[nrRanduri * this->nrColoane + nrColoane] = true;
		zona.setChosenRow(nrRanduri);
		zona.setChosenCol(nrColoane);
	}

	void setChosenRow(int nrRanduri) {
		this->chosenRow = nrRanduri;
	}
	int getChosenRow() {
		return chosenRow;
	}

	void setChosenCol(int nrColoane) {
		this->chosenCol = nrColoane;
	}
	int getChosenCol() {
		return chosenCol;
	}
	int getPretBilet() {
		return pretBilet;
	}
	void setPretBilet(int pretBilet) {
		this->pretBilet = pretBilet;
	}

	void printZona() {
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
	bool operator[](int index) {
		if (rezervari != nullptr && index >= 0 && index < nrLocuri) {
			return rezervari[index];
		}
		else {
			return charInvalid;
		}
	}
	bool operator!() {
		return !rezervari;
	}
	friend ostream& operator<<(ostream&, Zona);
	friend istream& operator>>(istream&, Zona&);
};
char Zona::charInvalid = -1;

ostream& operator<<(ostream& out, Zona z) {
	cout << "Denumire zona: ";
	out << z.denumire << endl;
	cout << "Nr. randuri: ";
	out << z.nrRanduri << endl;
	cout << "Nr. coloane: ";
	out << z.nrColoane << endl;
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

class Locatie {
private:
	int nrZone;
	string denumire;
	Zona* zone;
public:
	Locatie() {
		nrZone = 0;
		zone = nullptr;
		denumire = "N/A";
	}
	Locatie(string denumire, int nrZone, Zona* zone) {
		this->denumire = denumire;
		this->nrZone = nrZone;
		this->zone = new Zona[nrZone];
		for (int i = 0; i < nrZone; i++) {
			this->zone[i] = zone[i];
		}
	}
	Locatie(const Locatie& l) {
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
	Locatie& operator=(const Locatie& l) {
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
	~Locatie() {
		if (zone != nullptr) {
			delete[] zone;
		}
	}

	int getNrZone() {
		return nrZone;
	}
	void setNrZone(int nrZone) {
		if (nrZone > 0) {
			this->nrZone = nrZone;
		}
		else {
			this->nrZone = 0;
		}
	}
	string getDenumire() {
		return denumire;
	}
	void setDenumire(string denumire) {
		if (denumire.length() > 0) {
			this->denumire = denumire;
		}
		else {
			this->denumire = "N/A";
		}
	}
	Zona* getZone() {
		if (zone != nullptr) {
			Zona* copie = new Zona[nrZone];
			for (int i = 0; i < nrZone; i++) {
				copie[i] = zone[i];
			}
			return copie;
		}
	}
	void setZone(int nrZone, Zona* zone) {
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

	bool operator==(const Locatie& other) const {
		return denumire == other.denumire && nrZone == other.nrZone;
	}

	friend ostream& operator<<(ostream&, Locatie);
	friend istream& operator>>(istream&, Locatie&);
};
ostream& operator<<(ostream& out, Locatie l) {
	cout << "Denumire locatie: ";
	out << l.denumire << endl;
	cout << "Nr. Zone: ";
	out << l.nrZone << endl;

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


class Eveniment {
private:
	string Denumire;
	string Data;
	string Ora;
	Locatie l;
public:
	Eveniment() {
		Denumire = "N/A";
		Data = "N/A";
		Ora = "N/A";
	}
	Eveniment(string Denumire, string Data, string Ora) {
		this->Denumire = Denumire;
		this->Data = Data;
		this->Ora = Ora;
	}
	Eveniment(const Eveniment& e) {
		this->Denumire = e.Denumire;
		this->Data = e.Data;
		this->Ora = e.Ora;
	}
	Eveniment& operator=(const Eveniment& e) {
		this->Denumire = e.Denumire;
		this->Data = e.Data;
		this->Ora = e.Ora;
		return *this;
	}
	~Eveniment() {

	}
	string getDenumire() {
		return Denumire;
	}
	void setDenumire(string Denumire) {
		if (Denumire.length() > 0) {
			this->Denumire = Denumire;
		}
		else {
			this->Denumire = "N/A";
		}
	}
	string getData() {
		return Data;
	}
	void setData(string Data) {
		if (isValidData(Data)) {
			this->Data = Data;
		}
		else {
			this->Data = "N/A";
		}
	}
	string getOra() {
		return Ora;
	}
	void setOra(string Ora) {
		if (isValidOra(Ora)) {
			this->Ora = Ora;
		}
		else {
			this->Ora = "N/A";
		}
	}

	bool isValidData(string Data) {
		regex dateRegex{ "^\\d{2}/\\d{2}/\\d{4}$" };
		return regex_match(Data, dateRegex);
	}

	bool isValidOra(string Ora) {
		regex timeRegex{ "^\\d{2}:\\d{2}$" };
		return regex_match(Ora, timeRegex);
	}

	explicit operator string() {
		return Denumire;
	}

	void evenimentNou(Eveniment&);
	void cumparaBilet(const Eveniment&);
	friend ostream& operator<<(ostream&, Eveniment);
	friend istream& operator>>(istream&, Eveniment&);
};
ostream& operator<< (ostream& out, Eveniment e) {
	cout << "Denumirea evenimentului: ";
	out << e.Denumire << endl;

	cout << "Data si ora desfasurarii: ";
	out << e.Data << ", " << e.Ora << endl;

	return out;
}

istream& operator>>(istream& in, Eveniment& e) {
	cout << "Denumirea evenimentului: ";
	getline(in, e.Denumire);
	cout << "Data (dd/mm/yyyy): ";
	in >> e.Data;
	while (e.isValidData(e.Data) == false) {
		cout << "Data invalida! Scrieti data sub forma 12/12/2022." << endl;
		cout << "Data (dd/mm/yyyy): ";
		in >> e.Data;
	}
	cout << "Ora (hh:mm): ";
	in >> e.Ora;
	while (e.Ora.length() != 5) {
		cout << "Format ora invalid! Scrieti ora sub forma 12:15." << endl;
		cout << "Ora (hh:mm): ";
		in >> e.Ora;
	}
	return in;
}


class Bilet {

private:

	string cod;
	Zona zona;
	Locatie locatie;
	Eveniment eveniment;

	int chosenRow;
	int chosenCol;
	int pretBilet;

public:
	Bilet() {

	}
	Bilet(Zona& zona, Locatie locatie, Eveniment eveniment, int chosenRow, int chosenCol, int pretBilet)
		: zona(zona), locatie(locatie), eveniment(eveniment)
	{
		random_device rd;
		mt19937 gen(rd());
		uniform_int_distribution<int> dis(10000000, 99999999);
		cod = to_string(dis(gen));

		this->chosenRow = chosenRow;
		this->chosenCol = chosenCol;
		this->pretBilet = pretBilet;
	}

	string getCod()
	{
		return cod;
	}
	int getChosenCol() {
		return chosenCol;
	}
	int getChosenRow() {
		return chosenRow;
	}
	int getPretBilet() {
		return pretBilet;
	}
	void afiseazaInformatii()
	{
		cout << endl;
		cout << setfill('-') << setw(70) << " " << endl;
		cout << endl;
		cout << setfill(' ') << setw(10) << " " << "Denumirea evenimentului: " << eveniment.getDenumire() << endl;
		cout << setfill(' ') << setw(10) << " " << "Data si ora desfasurarii: " << eveniment.getData() << ", " << eveniment.getOra() << endl;
		cout << setfill(' ') << setw(10) << " " << "Locatie: " << locatie.getDenumire() << endl;
		cout << setfill(' ') << setw(10) << " " << "Zona: " << zona.getDenumire() << endl;
		cout << setfill(' ') << setw(10) << " " << "Randul " << getChosenRow() << ", " << "locul " << getChosenCol() << endl;
		cout << endl;
		cout << setfill(' ') << setw(30) << " " << "Codul biletului: " << cod << endl;
		cout << setfill(' ') << setw(30) << " " << "Pret bilet: " << getPretBilet() << " lei" << endl;
		cout << setfill('-') << setw(70) << " " << endl;
		cout << endl;
	}
	Bilet operator+(int valoare) {
		if (valoare > 0) {
			Bilet copie = *this;
			copie.pretBilet += valoare;
			return copie;
		}
		else {
			throw 15;
		}
	}
	Bilet operator++() {
		this->pretBilet++;
		return *this;
	}
	Bilet operator++(int i) {
		Bilet copie = *this;
		this->pretBilet++;
		return copie;
	}
	friend ostream& operator<<(ostream& out, const Bilet& bilet) {
		cout << "Eveniment: ";
		out << bilet.eveniment << endl;
		cout << "Locatie: ";
		out << bilet.locatie << endl;
		cout << "Zona: ";
		out << bilet.zona << endl;
		cout << "Rand: ";
		out << bilet.chosenRow << endl;
		cout << "Loc: ";
		out << bilet.chosenCol << endl;
		cout << "Cod bilet: ";
		out << bilet.cod << endl;
		cout << "Pret bilet: ";
		out << bilet.pretBilet << endl;

		return out;
	}
	friend istream& operator>>(istream& in, Bilet& bilet) {
		in >> bilet.eveniment >> bilet.locatie >> bilet.zona >> bilet.chosenRow >> bilet.chosenCol >> bilet.pretBilet;
		return in;
	}
};