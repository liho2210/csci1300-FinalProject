// CS1300 Spring 2019
// Author: Liam Hollins
// Recitation: 203 - Dhanendra Soni
// Cloud9 Workspace Editor Link: https://ide.c9.io/liamhollins/csci1300_lh
// Project 3

#include <string>
#ifndef HEROES_H
#define HEROES_H
using namespace std;

class Heroes
{
    // private data members
    private:
    int heroPoints;
    string heroName;
    int heroMoney;
    int heroInfluence;
    int heroArmySize;
    int numWarriors;
    int warriorArr[4];
    int heroLocationRow;
    int heroLocationColumn;
    bool heroShip;
    
    // public member functions
    public:
    // default constructor
    Heroes();
    
    // parameterized constructor
    Heroes(int heroPoints, string heroName, int heroMoney, int heroInfluence, int heroArmySize, int numWarriors, int warriorArr[], int heroLocationRow, int heroLocationColumn, bool heroShip);
    
    // **getters**
    
    int getHeroPoints();
    
    string getName();
    
    int getMoney();
    
    int getInfluence();
    
    int getArmySize();
    
    int getNumWarriors();
    
    int getWarriorAtIndex(int index);
    
    int getLocationRow();
    
    int getLocationColumn();
    
    bool getShip();
    
    // **setters**
    void setNumWarriors(int input);
    
    void setHeroPoints(int input);
    
    void setName(string input);
    
    void setMoney(int input);
    
    void setInfluence(int input);
    
    void setArmySize(int input);
    
    void setWarriors(int warriorNumber, int index);
    
    void setLocationRow(int row);
    
    void setLocationColumn(int column);
    
    void setShip(bool input);
};

#endif