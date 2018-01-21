#pragma once
#include <iostream>
using namespace std;
#include <vector>
#include <string>
#include <stdio.h>
class Run
{
public:
	int id;
	int race_id;
	int user_id;
	float time;
	Run();
	Run(int,int,int);
	Run(int, int, int, float);
	~Run();

	void opisz_lista();
};

