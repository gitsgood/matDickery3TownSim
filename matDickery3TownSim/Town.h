#pragma once
#ifndef Town_h
#define Town_h

#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <chrono>
#include <thread>

using namespace std;

class Inhabitant
{
private:
	int age;
	bool gender;
public:
	Inhabitant (const int& newAge=0, const bool& newGender=true)
		:age(newAge), gender(newGender){}

	int getAge();
	void setAge(int newAge);

	bool getGender();
	void setGender(bool newGender);

};

int population(vector<Inhabitant> town);
void printPopulationByGender(vector<Inhabitant> town);
void printPopulationByAge(vector<Inhabitant> town);
void printAll(vector<Inhabitant> town, int year);
bool genderAssignment();
void populationDecrease(vector<Inhabitant>& town);
void populationIncrease(vector<Inhabitant>& town);
void yearPassing(int years, vector<Inhabitant>& town);


static string introduction = "Welcome settler! You are welcome to witness the creation and growth of your own little town...\n";
static string invitation = "As you can see, this town is kinda sad, if not non-existent, but no worries! You have the power the change that with your godly powers...\n";
static string explanation = "To start the town, like the abrahamic God, we start with 2 primogenitors...\n";
static string inputBait = "Now... how many years do you wish to see pass you by?\n";

void scrollingText(string text);




#endif // !Town_h