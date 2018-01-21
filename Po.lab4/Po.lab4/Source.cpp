#include <iostream>
using namespace std;
#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include <ctime>
#include <algorithm>
#include <stdio.h>
#include "User.h"
#include "Admin.h"

int idu = 1, idr = 1;

//--------------------//

void add_u(vector<User> &k, int &n, string &n2, string &n3, string &n4, string &n5) {
	k.push_back(User(n, n2, n3, n4, n5));
	if (idu <= n) { idu = n + 1; }
}

void add_r(vector<Race> &k, int &n, int &n2, string &n3, float &n4, float &n5, int &n6) {
	k.push_back(Race(n, n2, n3, n4, n5, n6));
	if (idr <= n) { idr = n + 1; }
}

void add_s(vector<Race> &k, int &n, int &n2, int &n3, float &n4) {
	for (size_t i = 0;i < k.size();i++) {
		if (k[i].id == n2) {
			k[i].Runs.push_back(Run(n, n2, n3, n4));
		}
	}
}

//--------------------//

void zapisz(vector<User> &k, vector<Race> &k2) {
	ofstream plik;
	string nazwa = "Po_lab4.txt";
	plik.open(nazwa, std::ios::out);
	if (plik.good()) {
		size_t p = 0;
		int E = 0;
		if (k.size() != p) {
			for (size_t i = 0; i < k.size(); i++) {
				plik << "U " << k[i].id << " " << k[i].login << " " << k[i].password 
					<< " " << k[i].name << " " << k[i].surname << "\n";
				E++;
			}
		}
		if (k2.size() != p) {
			for (size_t i = 0; i < k2.size(); i++) {
				plik << "R " << k2[i].id << " " << k2[i].winner << " " << k2[i].type
					<< " " << k2[i].a_time << " " << k2[i].b_time << " " << k2[i].idrr << "\n";
				E++;
				for (size_t i2 = 0; i2 < k2[i].Runs.size(); i2++) {
					plik << "S " << k2[i].Runs[i2].id << " " << k2[i].Runs[i2].race_id 
						<< " " << k2[i].Runs[i2].user_id << " " << k2[i].Runs[i2].time << "\n";
					E++;
				}
			}
		}

		plik << "E : " << E;
		plik.close();
	}
	else {
		cout << "\n\nPlik nie zostal wczytany\n";
	}
}

//--------------------//

void wczytaj(vector<User> &k, vector<Race> &k2) {
	ifstream plik;
	string nazwa = "Po_lab4.txt";
	plik.open(nazwa, std::ios::in);
	if (plik.good()) {
		while (!plik.eof()) {
			char rodzaj;
			plik >> rodzaj;
			int n, r1, r2;
			float f1, f2;
			string s1, s2, s3, s4;
			switch (rodzaj) {
			case 'U':
				plik >> n >> s1 >> s2 >> s3 >> s4;
				add_u(k, n, s1, s2, s3, s4);
				break;
			case 'R':
				plik >> n >> r1 >> s1 >> f1 >> f2 >> r2;
				add_r(k2, n, r1, s1, f1, f2, r2);
				break;
			case 'S':
				plik >> n >> r1 >> r2 >> f1;
				add_s(k2, n, r1, r2, f1);
				break;
			case 'E':
				break;
			}
		}
		plik.close();
	}
	else {
		cout << "\n\nPlik nie zostal wczytany\n";
	}
}

//--------------------//

int main() {
	vector <User> Users;
	vector <Race> Races;
	Admin A = Admin();

	wczytaj(Users, Races);

	int f = 0;
	while (f == 0) {
		cout << "\nPodaj login: ";
		string login;
		cin >> login;

		if (login == "0") {
			f = 1;
		}
		else {

			if (login == "admin") {}
			else {
				for (size_t i = 0; i < Users.size(); i++) {
					if (Users[i].login == login) {
					}
					else {
						//cout << "\nNie ma takiego uzytkownika!\n";
					}
				}
			}

			cout << "\nPodaj haslo: ";
			string haslo;
			cin >> haslo;

			if (login == "admin") {
				if (A.password == haslo) {
					A.start(Users, Races, idu, idr);
					f = 1;
				}
				else {
					//cout << "\nPodano bledne haslo!\n";
				}
			}
			else {
				for (size_t i = 0; i < Users.size(); i++) {
					if (Users[i].login == login) {
						if (Users[i].password == haslo) {
							Users[i].start(Races);
							f = 1;
						}
					}
					else {
						//cout << "\nPodano bledne haslo!\n";
					}
				}
			}

		}
	}

	cout << "\nZapisywanie do pliku...\n\n";
	zapisz(Users, Races);

	system ("pause");
	return 0;
}