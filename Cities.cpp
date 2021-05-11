// CS1300 Spring 2019
// Author: Liam Hollins
// Recitation: 203 - Dhanendra Soni
// Cloud9 Workspace Editor Link: https://ide.c9.io/liamhollins/csci1300_lh
// Project 3

#include <string>
#include "Cities.h"
using namespace std;

// default constructor
Cities::Cities()
{
    cityLetter = ' ';
    cityName = "";
    cityMoney = 0;
    cityArmySize = 0;
    cityPoints = 0;
}

// parameterized constructor
Cities::Cities(char newCityLetter, string newCityName, int newCityMoney, int newCityArmySize, int newCityPoints)
{
    cityLetter = newCityLetter;
    cityName = newCityName;
    cityMoney = newCityMoney;
    cityArmySize = newCityArmySize;
    cityPoints = newCityPoints;
}

// **getters**

char Cities::getLetter()
{
    return cityLetter;
}

string Cities::getName()
{
    return cityName;
}

int Cities::getMoney()
{
    return cityMoney;
}

int Cities::getArmySize()
{
    return cityArmySize;
}

int Cities::getPoints()
{
    return cityPoints;
}

// **setters**

void Cities::setLetter(char input)
{
    cityLetter = input;
}

void Cities::setName(string input)
{
    cityName = input;
}

void Cities::setMoney(int input)
{
    cityMoney = input;
}

void Cities::setArmySize(int input)
{
    cityArmySize = input;
}

void Cities::setPoints(int input)
{
    cityPoints = input;
}