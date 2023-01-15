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

Eveniment::Eveniment() {
	Denumire = "N/A";
	Data = "N/A";
	Ora = "N/A";
}
Eveniment::Eveniment(string Denumire, string Data, string Ora) {
	this->Denumire = Denumire;
	this->Data = Data;
	this->Ora = Ora;
}
Eveniment::Eveniment(string Denumire, string Data, string Ora, Locatie l) :Eveniment(Denumire, Data, Ora) {
	this->l = l;
	nrEvenimente++;
}
Eveniment::Eveniment(const Eveniment& e) {
	this->Denumire = e.Denumire;
	this->Data = e.Data;
	this->Ora = e.Ora;
	this->l = e.l;
}
Eveniment& Eveniment::operator=(const Eveniment& e) {
	this->Denumire = e.Denumire;
	this->Data = e.Data;
	this->Ora = e.Ora;
	this->l = e.l;
	return *this;
}
Eveniment::~Eveniment() {

}
string Eveniment::getDenumire() {
	return Denumire;
}
void Eveniment::setDenumire(string Denumire) {
	if (Denumire.length() > 0) {
		this->Denumire = Denumire;
	}
	else {
		this->Denumire = "N/A";
	}
}
string Eveniment::getData() {
	return Data;
}
void Eveniment::setData(string Data) {
	if (isValidData(Data)) {
		this->Data = Data;
	}
	else {
		this->Data = "N/A";
	}
}
string Eveniment::getOra() {
	return Ora;
}
void Eveniment::setOra(string Ora) {
	if (isValidOra(Ora)) {
		this->Ora = Ora;
	}
	else {
		this->Ora = "N/A";
	}
}
void Eveniment::setLocatie(Locatie l) {
	this->l = l;
}
Locatie Eveniment::getLocatie() {
	return this->l;
}

bool Eveniment::isValidData(string Data) {
	regex dateRegex{ "^\\d{2}/\\d{2}/\\d{4}$" };
	return regex_match(Data, dateRegex);
}

bool Eveniment::isValidOra(string Ora) {
	regex timeRegex{ "^\\d{2}:\\d{2}$" };
	return regex_match(Ora, timeRegex);
}

Eveniment::operator string() {
	return Denumire;
}
int Eveniment::nrEvenimente = 0;
ostream& operator<< (ostream& out, Eveniment e) {
	cout << endl;
	cout << "Denumirea evenimentului: ";
	out << e.Denumire << endl;

	cout << "Data si ora desfasurarii: ";
	out << e.Data << ", " << e.Ora << endl;

	cout << e.l << endl;

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


ofstream& operator<<(ofstream& file, Eveniment& e) {
	file << e.Denumire << endl;
	file << e.Data << endl;
	file << e.Ora << endl;
	file << e.l << endl;
	return file;

}
ifstream& operator>>(ifstream& file, Eveniment& e) {
	file >> e.Denumire;
	file >> e.Data;
	file >> e.Ora;
	file >> e.l;
	return file;
}
