#include "Admin.h"



Admin::Admin()
{
	this->password = "admin";
}


Admin::~Admin()
{
}

void Admin::start(vector<User> &u, vector<Race> &r, int iu, int ir) {
	this->idu = iu;
	this->idr = ir;
	char x = 'x';
	int n = 0;
	while (x != '0') {
		system("cls");
		cout << "\nAdmin : Instrukcja Obslugi:";
		cout << "\nDodaj : zawodnika  (1) wyscig  (2)";
		cout << "\nWypisz: zawodnikow (3) wyscigi (4)";
		cout << "\nDane  : zawodnika  (5) wyscigu (6)";
		cout << "\n\nAdmin : Podaj wybrany numer akcji: ";
		cin >> x;
		system("cls");
		switch (x) {
		//----------//
		case '1':
			this->add_user(u);
			break;
		case '2':
			this->add_race(r,u);
			break;
		//----------//
		case '3':
			cout << "\nAdmin : Zawodnicy:";
			this->wypisz(u);
			break;
		case '4':
			cout << "\nAdmin : Wyscigi:";
			this->wypisz(r);
			break;
		//----------//
		case '5':
			cout << "\nAdmin : Zawodnicy:";
			this->wypisz(u);
			cout << "\n\nAdmin : Podaj ID zawodnika: ";
			cin >> n;
			system("cls");
			this->opisz(u,n);
			break;
		case '6':
			cout << "\nAdmin : Wyscigi:";
			this->wypisz(r);
			cout << "\n\nAdmin : Podaj ID wyscigu: ";
			cin >> n;
			system("cls");
			this->opisz(r, n);
			break;
		}
		cout << "\n\n";
		system("pause");
	}
}

void Admin::add_user(vector<User> &u)
{
	u.push_back(User(this->idu));
	this->idu++;
}

void Admin::add_race(vector<Race> &r, vector<User> &u)
{
	r.push_back(Race(this->idr));


	size_t p = 0;
	if (u.size() == p)
		cout << "\nWektor jest pusty\n";
	else {
		cout << "\nAdmin : Czy zawodnik bral udzial w biegu?\nTak (1) Nie (0)\n";
		for (size_t i = 0;i < u.size();i++) {
			u[i].opisz_lista();
			char y = 'y';
			cout << "\nAdmin : Podaj wybrany numer akcji: ";
			cin >> y;
			if (y != '0') {
				r[this->idr-1].Runs.push_back(Run(r[this->idr-1].idrr, r[this->idr-1].id, u[i].id));
				r[this->idr - 1].idrr++;
			}
		}
	}
	r[idr - 1].statystyka();
	this->idr++;
}