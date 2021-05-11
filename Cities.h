// CS1300 Spring 2019
// Author: Liam Hollins
// Recitation: 203 - Dhanendra Soni
// Cloud9 Workspace Editor Link: https://ide.c9.io/liamhollins/csci1300_lh
// Project 3

#include <string>
#ifndef CITIES_H
#define CITIES_H
using namespace std;

class Cities
{
    // private data members
    private:
    char cityLetter;
    string cityName;
    int cityMoney;
    int cityArmySize;
    int cityPoints;
    
    // public member functions
    public:
    // default constructor
    Cities();
    
    // parameterized constructor
    Cities(char cityLetter, string cityName, int cityMoney, int cityArmySize, int cityPoints);
    
    // **getters**
    
    char getLetter();
    
    string getName();
    
    int getMoney();
    
    int getArmySize();
    
    int getPoints();
    
    // **setters**
    
    void setLetter(char input);
    
    void setName(string input);
    
    void setMoney(int input);
    
    void setArmySize(int input);
    
    void setPoints(int input);
};

#endif