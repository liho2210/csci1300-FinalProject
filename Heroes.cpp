// CS1300 Spring 2019
// Author: Liam Hollins
// Recitation: 203 - Dhanendra Soni
// Cloud9 Workspace Editor Link: https://ide.c9.io/liamhollins/csci1300_lh
// Project 3

#include <string>
#include "Heroes.h"
using namespace std;

// default constructor
Heroes::Heroes()
{
    heroPoints = 0;
    heroName = "";
    heroMoney = 0;
    heroInfluence = 0;
    heroArmySize = 0;
    numWarriors = 0;
    
    for (int i = 0; i < 4; i++)
    {
        warriorArr[i] = -1;
    }
    
    heroLocationRow = 0;
    
    heroLocationColumn = 0;
    
    heroShip = false;
}

// parameterized constructor
Heroes::Heroes(int newHeroPoints, string newHeroName, int newHeroMoney, int newHeroInfluence, int newHeroArmySize, int newNumWarriors, int newWarriorArr[], int newHeroLocationRow, int newHeroLocationColumn, bool newHeroShip)
{
    heroPoints = newHeroPoints;
    heroName = newHeroName;
    heroMoney = newHeroMoney;
    heroInfluence = newHeroInfluence;
    heroArmySize = newHeroArmySize;
    numWarriors = newNumWarriors;
    
    for (int i = 0; i < 4; i++)
    {
        warriorArr[i] = newWarriorArr[i];
    }
    
    heroLocationRow = newHeroLocationRow;
    heroLocationColumn = newHeroLocationColumn;
    
    heroShip = newHeroShip;
}

// **getters**

int Heroes::getHeroPoints()
{
    return heroPoints;
}

string Heroes::getName()
{
    return heroName;
}

int Heroes::getMoney()
{
    return heroMoney;
}

int Heroes::getInfluence()
{
    return heroInfluence;
}

int Heroes::getArmySize()
{
    return heroArmySize;
}

int Heroes::getNumWarriors()
{
    return numWarriors;
}

int Heroes::getWarriorAtIndex(int index)
{
    return warriorArr[index];
}

int Heroes::getLocationRow()
{
    return heroLocationRow;
}

int Heroes::getLocationColumn()
{
    return heroLocationColumn;
}

bool Heroes::getShip()
{
    return heroShip;
}

// **setters**

void Heroes::setNumWarriors(int input)
{
    numWarriors = input;
}

void Heroes::setHeroPoints(int input)
{
    heroPoints = input;
}

void Heroes::setName(string input)
{
    heroName = input;
}

void Heroes::setMoney(int input)
{
    heroMoney = input;
}

void Heroes::setInfluence(int input)
{
    heroInfluence = input;
}

void Heroes::setArmySize(int input)
{
    heroArmySize = input;
}

void Heroes::setWarriors(int warriorNumber, int index)
{
    warriorArr[index] = warriorNumber;
}

void Heroes::setLocationRow(int input)
{
    heroLocationRow = input;
}

void Heroes::setLocationColumn(int input)
{
    heroLocationColumn = input;
}

void Heroes::setShip(bool input)
{
    heroShip = input;
}