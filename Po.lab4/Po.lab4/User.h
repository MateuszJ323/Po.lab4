#pragma once
#include <iostream>
using namespace std;
#include <vector>
#include <string>
#include <stdio.h>
#include "Race.h"

class User
{
public:
	int id;
	string login;
	string password;
	string name;
	string surname;

	User();
	User(int);
	User(int,string,string,string,string);
	~User();

	void opisz();
	void opisz_lista();
	void start(vector<Race> &);
	void wypisz_r(vector<Race> &);
	void opisz_r(vector<Race> &, int);
};

