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

int main() {
	Zona* z1;
	z1 = new Zona[3];
	z1[0] = Zona("Tribuna A", 7, 7, 75);
	z1[1] = Zona("Tribuna B", 8, 8, 70);
	z1[2] = Zona("Peluza", 7, 6, 60);
	Locatie l1("Arena Nationala", 3, z1);
	Eveniment e1("Meci Steaua vs Dinamo", "12/03/2023", "19:30", l1);

	Zona* z2;
	z2 = new Zona[2];
	z2[0] = Zona("VIP", 3, 5, 60);
	z2[1] = Zona("Normal", 8, 8, 30);
	Locatie l2("Cinema City Mega Mall", 2, z2);
	Eveniment e2("Film - Avatar 2", "28/01/2023", "17:00", l2);

	Zona* z3;
	z3 = new Zona[3];
	z3[0] = Zona("Categoria 1", 4, 4, 140);
	z3[1] = Zona("Categoria 2", 6, 6, 120);
	z3[2] = Zona("Loja", 6, 7, 100);
	Locatie l3("Teatrul National Marin Sorescu", 3, z3);
	Eveniment e3("Piesa de teatru - Creatorul de teatru", "16/02/2023", "19:00", l3);

	Bilet* b;
	b = new Bilet[10];
	b[0] = Bilet(z1[0], l1, e1, 1, 1, e1.l.zone[0].getPretBilet());
	b[1] = Bilet(z1[1], l1, e1, 1, 0, e1.l.zone[1].getPretBilet());
	b[2] = Bilet(z2[1], l2, e2, 2, 2, e2.l.zone[1].getPretBilet());
	b[3] = Bilet(z2[0], l2, e2, 3, 4, e2.l.zone[0].getPretBilet());
	b[4] = Bilet(z2[0], l2, e2, 1, 2, e2.l.zone[0].getPretBilet());
	b[5] = Bilet(z3[0], l3, e3, 2, 4, e3.l.zone[0].getPretBilet());
	b[6] = Bilet(z3[1], l3, e3, 3, 4, e3.l.zone[1].getPretBilet());
	b[7] = Bilet(z3[1], l3, e3, 1, 1, e3.l.zone[1].getPretBilet());
	b[8] = Bilet(z3[1], l3, e3, 0, 0, e3.l.zone[1].getPretBilet());
	b[9] = Bilet(z1[2], l1, e1, 1, 0, e1.l.zone[0].getPretBilet());

	e1.l.zone[0].rezervaScaun(z1[0], 1, 1);
	e1.l.zone[1].rezervaScaun(z1[1], 1, 0);
	e1.l.zone[2].rezervaScaun(z1[2], 1, 0);
	e2.l.zone[1].rezervaScaun(z2[1], 2, 2);
	e2.l.zone[0].rezervaScaun(z2[0], 3, 4);
	e2.l.zone[0].rezervaScaun(z2[0], 1, 2);
	e3.l.zone[0].rezervaScaun(z3[0], 2, 4);
	e3.l.zone[1].rezervaScaun(z3[1], 3, 4);
	e3.l.zone[1].rezervaScaun(z3[1], 1, 1);
	e3.l.zone[1].rezervaScaun(z3[1], 0, 0);


	Admin a;

	ifstream file;
	file.open("evenimente.txt", ios::in);
	file >> a;
	file.close();

	a.setNrEvenimente(1);
	a.addEveniment(e1);

	a.setNrEvenimente(2);
	a.addEveniment(e2);

	a.setNrEvenimente(3);
	a.addEveniment(e3);

	a.setNrBilete(10);
	for (int i = 0; i < 10; i++) {
		a.addBilet(b[i]);
	}

	a.start();
	ofstream file2;
	file2.open("evenimente.txt", ios::out);
	file2 << a;
	file2.close();

}