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

Bilet::Bilet() {

}
Bilet::Bilet(Zona& zona, Locatie locatie, Eveniment eveniment, int chosenRow, int chosenCol, int pretBilet)
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

string Bilet::getCod()
{
	return cod;
}
int Bilet::getChosenCol() {
	return chosenCol;
}
int Bilet::getChosenRow() {
	return chosenRow;
}
int Bilet::getPretBilet() {
	return pretBilet;
}
void Bilet::afiseazaInformatii()
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
Bilet Bilet::operator+(int valoare) {
	if (valoare > 0) {
		Bilet copie = *this;
		copie.pretBilet += valoare;
		return copie;
	}
	else {
		throw 15;
	}
}
Bilet Bilet::operator++() {
	this->pretBilet++;
	return *this;
}
Bilet Bilet::operator++(int i) {
	Bilet copie = *this;
	this->pretBilet++;
	return copie;
}
ostream& operator<<(ostream& out, const Bilet& bilet) {
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
istream& operator>>(istream& in, Bilet& bilet) {
	in >> bilet.eveniment >> bilet.locatie >> bilet.zona >> bilet.chosenRow >> bilet.chosenCol >> bilet.pretBilet;
	return in;
}
