#include "Race.h"



Race::Race()
{
}

Race::Race(int idr)
{
	this->id = idr;
	this->idrr = 1;
	this->winner = 0;
	this->a_time = 0;
	this->b_time = 0;
	cout << "\nRace ID : " << this->id << "\nPodaj typ wyscigu: ";
	cin >> this->type;
}

Race::Race(int n1, int n2, string s1, float f1, float f2, int n3)
{
	this->id = n1;
	this->winner = n2;
	this->type = s1;
	this->a_time = f1;
	this->b_time = f2;
	this->idrr = n3;
}


Race::~Race()
{
}

void Race::opisz()
{
	cout << "\nID: " << this->id << "\tTyp: " << this->type << "\tZwyciezca: " << this->winner
		<< "\nNajlepszy wynik: " << this->b_time << "\tSredni wynik: " << this->a_time
		<< "\n\nUczestnicy: ";
	for (size_t i = 0;i < Runs.size();i++) {
		this->Runs[i].opisz_lista();
	}
}

void Race::opisz_lista()
{
	cout << "\nID: " << this->id << "\tTyp: " << this->type << "\tZwyciezca: " << this->winner;
}

void Race::wypisz_r()
{
	size_t p = 0;
	if (this->Runs.size() == p)
		cout << "\nWektor jest pusty\n";
	else
		for (size_t i = 0;i < this->Runs.size();i++) {
			this->Runs[i].opisz_lista();
		}
}

void Race::statystyka()
{
	float pom = 0;
	this->b_time = this->Runs[0].time;
	this->winner = this->Runs[0].user_id;
	for (size_t i = 0;i < this->Runs.size();i++) {
		pom += this->Runs[i].time;
		if (this->b_time > this->Runs[i].time) {
			this->b_time = this->Runs[i].time;
			this->winner = this->Runs[i].user_id;
		}
	}
	int pom2 =(int)((pom / this->Runs.size()) * 1000);
	pom = (float)pom2;
	this->a_time = pom / 1000;
}
