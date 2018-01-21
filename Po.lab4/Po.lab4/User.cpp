#include "User.h"



User::User()
{
}

User::User(int idu)
{
	this->id = idu;
	cout << "\nUser ID : " << this->id << "\nPodaj login: ";
	cin >> this->login;
	cout << "\nPodaj haslo: ";
	cin >> this->password;
	cout << "\nPodaj imie: ";
	cin >> this->name;
	cout << "\nPodaj nazwisko: ";
	cin >> this->surname;
}

User::User(int idu, string s1, string s2, string s3, string s4)
{
	this->id = idu;
	this->login = s1;
	this->password = s2;
	this->name = s3;
	this->surname = s4;
}


User::~User()
{
}

void User::opisz()
{
	cout << "\nID: " << this->id << "\nImie: " << this->name << "\nNazwisko: " << this->surname 
		<< "\nLogin: " << this->login << "\nHaslo: " << this->password;
}

void User::opisz_lista()
{
	cout << "\nID: " << this->id << "\tImie: " << this->name << "\tNazwisko: " << this->surname;
}

void User::start(vector<Race> &r)
{
	char x = 'x';
	int n = 0;
	while (x != '0') {
		system("cls");
		cout << "\nUser : Instrukcja Obslugi:";
		cout << "\nMoje dane (1)";
		cout << "\nWypisz wyscigi (2)";
		cout << "\nInformacje o wyscigu (3)";
		cout << "\n\nAdmin : Podaj wybrany numer akcji: ";
		cin >> x;
		system("cls");
		switch (x) {
			//----------//
		case '1':
			cout << "\nUser : Twoje dane:";
			this->opisz();
			break;
		case '2':
			cout << "\nUser : Twoje wyscigi:";
			this->wypisz_r(r);
			break;
			//----------//
		case '3':
			cout << "\nUser : Twoje wyscigi:";
			this->wypisz_r(r);
			cout << "\n\nUser : Podaj ID wyscigu: ";
			cin >> n;
			system("cls");
			this->opisz_r(r, n);
			break;
		}
		cout << "\n\n";
		system("pause");
	}
}

void User::wypisz_r(vector<Race>&k)
{
	size_t p = 0;
	if (k.size() == p)
		cout << "\nWektor jest pusty\n";
	else
		for (size_t i = 0;i < k.size();i++) {
			for (size_t j = 0;j < k[i].Runs.size();j++) {
				if (k[i].Runs[j].user_id == this->id) {
					k[i].opisz_lista();
				}
			}
		}
}

void User::opisz_r(vector<Race>& k, int n)
{
	size_t p = 0;
	if (k.size() == p)
		cout << "\nWektor jest pusty\n";
	else
		for (size_t i = 0;i < k.size();i++) {
			if (k[i].id == n) {
				for (size_t j = 0;j < k[i].Runs.size();j++) {
					if (k[i].Runs[j].user_id == this->id)cout << "\nTwoj wynik: " << k[i].Runs[j].time << "\n";
				}
				k[i].opisz();
			}
		}
}
