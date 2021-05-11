// CS1300 Spring 2019
// Author: Liam Hollins
// Recitation: 203 - Dhanendra Soni
// Cloud9 Workspace Editor Link: https://ide.c9.io/liamhollins/csci1300_lh
// Project 3

#include <string>
#include "Warriors.h"
using namespace std;

// default constructor
Warriors::Warriors()
{
    warriorNumber = 0;
    warriorName = "";
    warriorStrength = 0;
    warriorLoyalty = 0;
    warriorMorale = 0;
    warriorFreedom = false;
    warriorShip = false;
    warriorGlass = false;
    warriorRow = 0;
    warriorColumn = 0;
}

// parameterized constructor
Warriors::Warriors(int newWarriorNumber, string newWarriorName, int newWarriorStrength, int newWarriorLoyalty, int newWarriorMorale, bool newWarriorFreedom, bool newWarriorShip, bool newWarriorGlass)
{
    warriorNumber = newWarriorNumber;
    warriorName = newWarriorName;
    warriorStrength = newWarriorStrength;
    warriorLoyalty = newWarriorLoyalty;
    warriorMorale = newWarriorMorale;
    warriorFreedom = newWarriorFreedom;
    warriorShip = newWarriorShip;
    warriorGlass = newWarriorGlass;
}

// **getters**
int Warriors::getNumber()
{
    return warriorNumber;
}

string Warriors::getName()
{
    return warriorName;
}

int Warriors::getStrength()
{
    return warriorStrength;
}

int Warriors::getLoyalty()
{
    return warriorLoyalty;
}

int Warriors::getMorale()
{
    return warriorMorale;
}

bool Warriors::getFreedom()
{
    return warriorFreedom;
}

bool Warriors::getShip()
{
    return warriorShip;
}

bool Warriors::getGlass()
{
    return warriorGlass;
}

int Warriors::getLocationRow()
{
    return warriorRow;
}

int Warriors::getLocationColumn()
{
    return warriorColumn;
}

// **setters**

void Warriors::setNumber(int input)
{
    warriorNumber = input;
}

void Warriors::setName(string input)
{
    warriorName = input;
}

void Warriors::setStrength(int input)
{
    warriorStrength = input;
}

void Warriors::setLoyalty(int input)
{
    warriorLoyalty = input;
}

void Warriors::setMorale(int input)
{
    warriorMorale = input;
}

void Warriors::setFreedom(bool input)
{
    warriorFreedom = input;
}

void Warriors::setShip(bool input)
{
    warriorShip = input;
}

void Warriors::setGlass(bool input)
{
    warriorGlass = input;
}

void Warriors::setLocationRow(int input)
{
    warriorRow = input;
}

void Warriors::setLocationColumn(int input)
{
    warriorColumn = input;
}