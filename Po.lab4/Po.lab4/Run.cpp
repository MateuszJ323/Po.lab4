#include "Run.h"



Run::Run()
{
}

Run::Run(int n1, int n2, int n3)
{
	this->id = n1;
	this->race_id = n2;
	this->user_id = n3;
	cout << "\nPodaj czas: ";
	cin >> this->time;
}

Run::Run(int n1, int n2 , int n3, float f1)
{
	this->id = n1;
	this->race_id = n2;
	this->user_id = n3;
	this->time = f1;
}


Run::~Run()
{
}

void Run::opisz_lista()
{
	cout << "\nZawodnik: " << this->user_id << "\tCzas: " << this->time;
}
