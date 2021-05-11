// CS1300 Spring 2019
// Author: Liam Hollins
// Recitation: 203 - Dhanendra Soni
// Cloud9 Workspace Editor Link: https://ide.c9.io/liamhollins/csci1300_lh
// Project 3

#include <string>
#include "Tile.h"
using namespace std;

// default constructor
Tile::Tile()
{
	tileSymbol = "";
    cityLocation = "";
    dragonGlass = false;
    currentOccupant = "";
    waterTile = false;
    tileUsed = false;
}

// parameterized constructor
Tile::Tile(string newTileSymbol, string newCityLocation, bool newDragonGlass, string newCurrentOccupant, bool newWaterTile, bool newTileUsed)
{
    tileSymbol = newTileSymbol;
    cityLocation = newCityLocation;
    dragonGlass = newDragonGlass;
    currentOccupant = newCurrentOccupant;
    waterTile = newWaterTile;
    tileUsed = newTileUsed;
}

string Tile::getTileSymbol()
{
    return tileSymbol;
}

string Tile::getCityLocation()
{
	return cityLocation;
}

bool Tile::getIsDragonGlass()
{
	return dragonGlass;
}

string Tile::getCurrentOccupant()
{
	return currentOccupant;
}

bool Tile::getIsWaterTile()
{
	return waterTile;
}

bool Tile::getTileUsed()
{
	return tileUsed;
}

// **setters**

void Tile::setTileSymbol(string input)
{
	tileSymbol = input;
}

void Tile::setCityLocation(string input)
{
	cityLocation = input;
}

void Tile::setIsDragonGlass(bool input)
{
	dragonGlass = input;
}

void Tile::setCurrentOccupant(string input)
{
	currentOccupant = input;
}

void Tile::setIsWaterTile(bool input)
{
	waterTile = input;
}

void Tile::setTileUsed(bool input)
{
	tileUsed = input;
}