#pragma once
#include <iostream>
using namespace std;
#include <vector>
#include <string>
#include <stdio.h>
#include "Run.h"
class Race
{
public:
	int id;
	int winner;
	string type;
	float a_time;
	float b_time;

	int idrr;
	vector <Run> Runs;

	Race();
	Race(int);
	Race(int, int, string, float, float, int);
	~Race();

	void opisz();
	void opisz_lista();
	void wypisz_r();
	void statystyka();
};

