#pragma once
#include <iostream>
using namespace std;
#include <vector>
#include <string>
#include <stdio.h>
#include "Race.h"
#include "User.h"
class Admin
{
public:
	string password;
	int idu, idr;
	Admin();
	~Admin();

	void start(vector<User> &, vector<Race> &, int, int);
	void add_user(vector<User> &);
	void add_race(vector<Race> &, vector<User> &);
	template <class Type> void wypisz(Type &);
	template <class Type> void opisz(Type &, int);
};

template<class Type>
inline void Admin::wypisz(Type &k)
{
	size_t p = 0;
	if (k.size() == p)
		cout << "\nWektor jest pusty\n";
	else
		for (size_t i = 0;i < k.size();i++) {
			k[i].opisz_lista();
		}
}

template<class Type>
inline void Admin::opisz(Type &k, int n)
{
	size_t p = 0;
	if (k.size() == p)
		cout << "\nWektor jest pusty\n";
	else
		for (size_t i = 0;i < k.size();i++) {
			if (k[i].id == n) {
				k[i].opisz();
			}
		}
}
