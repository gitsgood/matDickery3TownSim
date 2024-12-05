#include "Town.h"

#pragma region Getters and Setters
int Inhabitant::getAge()
{
    return age;
}

void Inhabitant::setAge(int newAge)
{
    age = newAge;
}

bool Inhabitant::getGender()
{
    return gender;
}

void Inhabitant::setGender(bool newGender)
{
    gender = newGender;
}

#pragma endregion

#pragma region Print Functions
int population(vector<Inhabitant> town)
{
    return town.size();
}

void printPopulationByGender(vector<Inhabitant> town)
{
    int malePopulation = 0;
    int femalePopulation = 0;

    for (int i = 0; i < town.size(); i++) {
        if (town[i].getGender() == true) {
            malePopulation++;
        }
        else
            femalePopulation++;
    }
    cout << "There are " << femalePopulation << " female inhabitants.\n";
    cout << "There are " << malePopulation << " male inhabitants.\n";
}

void printPopulationByAge(vector<Inhabitant> town)
{
    int youngPopulation = 0;//ages 0-25
    int maturePopulation = 0;//ages 26-50
    int aboutToDiePopulation = 0;//ages 51-75

    for (int i = 0; i < town.size(); i++) {
        if (town[i].getAge() < 26) {
            youngPopulation++;
        }
        if (town[i].getAge() < 51 && town[i].getAge() > 25) {
            maturePopulation++;
        }
        if (town[i].getAge() > 50) {
            aboutToDiePopulation++;
        }
    }
    cout << "There are " << youngPopulation << " 0-25 year olds.\n";
    cout << "There are " << maturePopulation << " 26-50 year olds.\n";
    cout << "There are " << aboutToDiePopulation << " 51-75 year olds.\n";
}

void printAll(vector<Inhabitant> town, int year)
{
    cout << "The town on the year " << year << ":\n";
    cout << "There are " << population(town) << " total inhabitants.\n";
    cout << "Among them, \n";
    printPopulationByAge(town);
    printPopulationByGender(town);
}

#pragma endregion

bool genderAssignment()
{
    int genderRandomFactor = rand() % 2;//values can be 0 or 1
    if (genderRandomFactor == 0)
        return true;
    else
        return false;
}

void populationDecrease(vector<Inhabitant>& town)
{
    int populationBeforeDeaths = town.size();
    vector<int> theUnluckyFew;

    for (int i = 0; i < populationBeforeDeaths; i++) {
        if (town[i].getAge() >= 75) {
            theUnluckyFew.push_back(i);
        }
    }
    for (int i = theUnluckyFew.size(); i > 0; i--) {
        town.erase(town.begin() + theUnluckyFew[i - 1]);
    }
}

void populationIncrease(vector<Inhabitant>& town)
{
    int populationBeforeIncrease = town.size() * 2;
    for (int i = 0; i < populationBeforeIncrease; i++) {
        town.push_back(Inhabitant(0, genderAssignment()));
    }   
}

void yearPassing(int years, vector<Inhabitant>& town)
{
    for (int i = 0; i < years; i++) {
        for (int i = 0; i < town.size(); i++) {
            town[i].setAge(town[i].getAge() + 1);
        }
        populationIncrease(town);
        populationDecrease(town);
    }
}

void scrollingText(string text)
{
    for (int i = 0; i < text.length(); i++) {
        cout << text[i];
        int wait = rand() % 100 + 1;
        //cout << wait;
        this_thread::sleep_for(chrono::milliseconds(wait));
    }
}


