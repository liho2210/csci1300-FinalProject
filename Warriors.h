// CS1300 Spring 2019
// Author: Liam Hollins
// Recitation: 203 - Dhanendra Soni
// Cloud9 Workspace Editor Link: https://ide.c9.io/liamhollins/csci1300_lh
// Project 3

#include <string>
#ifndef WARRIORS_H
#define WARRIORS_H
using namespace std;

class Warriors
{
    // private data members
    private:
    int warriorNumber;
    string warriorName;
    int warriorStrength;
    int warriorLoyalty;
    int warriorMorale;
    bool warriorFreedom;
    bool warriorShip;
    bool warriorGlass;
    int warriorRow;
    int warriorColumn;
    
    // public member functions
    public:
    // default constructor
    Warriors();
    
    // parameterized constructor
    Warriors(int warriorNumber, string warriorName, int warriorStrength, int warriorLoyalty, int warriorMorale, bool warriorFreedom, bool warriorShip, bool warriorGlass);
    
    // **getters**
    int getNumber();
    
    string getName();
    
    int getStrength();
    
    int getLoyalty();
    
    int getMorale();
    
    bool getFreedom();
    
    bool getShip();
    
    bool getGlass();
    
    int getLocationRow();
    
    int getLocationColumn();
    
    // **setters**
    void setNumber(int input);
    
    void setName(string warriorName);
    
    void setStrength(int warriorStrength);
    
    void setLoyalty(int warriorLoyalty);
    
    void setMorale(int warriorMorale);
    
    void setFreedom(bool warriorFreedom);
    
    void setShip(bool warriorShip);
    
    void setGlass(bool warriorGlass);
    
    void setLocationRow(int input);
    
    void setLocationColumn(int input);
};

#endif