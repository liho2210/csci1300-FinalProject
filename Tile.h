// CS1300 Spring 2019
// Author: Liam Hollins
// Recitation: 203 - Dhanendra Soni
// Cloud9 Workspace Editor Link: https://ide.c9.io/liamhollins/csci1300_lh
// Project 3

#include <string>
#ifndef TILE_H
#define TILE_H
using namespace std;

class Tile
{
    // private data members
    private:
    string tileSymbol;
    string cityLocation;
    bool dragonGlass;
    string currentOccupant;
    bool waterTile;
    bool tileUsed;
    
    // public member functions
    public:
    // default constructor
    Tile();
    
    // parameterized constructor
    Tile(string tileSymbol, string cityLocation, bool dragonGlass, string currentOccupant, bool waterTile, bool tileUsed);
    
    // **getters**
    
    string getTileSymbol();
    
    string getCityLocation();
    
    bool getIsDragonGlass();
    
    string getCurrentOccupant();
    
    bool getIsWaterTile();
    
    bool getTileUsed();
    
    // **setters**
    
    void setTileSymbol(string input);
    
    void setCityLocation(string input);
    
    void setIsDragonGlass(bool input);
    
    void setCurrentOccupant(string input);
    
    void setIsWaterTile(bool input);
    
    void setTileUsed(bool input);
};

#endif