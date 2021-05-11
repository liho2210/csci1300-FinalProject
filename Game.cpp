// CS1300 Spring 2019
// Author: Liam Hollins
// Recitation: 203 - Dhanendra Soni
// Cloud9 Workspace Editor Link: https://ide.c9.io/liamhollins/csci1300_lh
// Project 3

#include <string>
#include <iostream>
#include <fstream>
#include <cmath>
#include "Game.h"
#include "Heroes.cpp"
#include "Warriors.cpp"
#include "Cities.cpp"
#include "Tile.cpp"
using namespace std;

// split function
int split(string input, char delimiter, string subStrings[], int arrayPlace)
{
    int splitter = 0;
    int splitCount = 0;

    string newInput;

    for (int i = 0; i < input.length(); i++)
    {
        if (input[i] != delimiter)
        {
            newInput = input.substr(i, (input.length() - i));
            break;
        }
    }
    
    for (int i = 0; i < newInput.length(); i++)
    {
        if ((newInput[i] == delimiter) && (newInput[i-1] != delimiter))
        {
            subStrings[arrayPlace] = newInput.substr(splitter, (i - splitter));
                
            arrayPlace++;
            splitCount++;
            splitter = (i + 1);
        }   
        
        if ((i == (newInput.length() - 1)) && (newInput[i] != delimiter))
        {
            subStrings[arrayPlace] = newInput.substr(splitter, (newInput.length() - splitter));
            arrayPlace++;
            splitCount++;
        }
        
        if ((newInput[i] == delimiter) && (newInput[i-1] == delimiter))
        {
            splitter++;
        }
    }

    return splitCount;
}

// default constructor
Game::Game()
{
    for (int i = 0; i < 7; i++)
    {
        heroArr[i] = Heroes();
    }
    
    for (int i = 0; i < 14; i++)
    {
        warriorArr[i] = Warriors();
    }
    
    for (int i = 0; i < 26; i++)
    {
        cityArr[i] = Cities();
    }
    
    for (int i = 0; i < 25; i++)
    {
        for (int b = 0; b < 16; b++)
        {
            tileArr[i][b] = Tile();
        }
    }
}

// parameterized constructor
Game::Game(int newPlayerPoints, int newTurnCount)
{
    playerPoints = newPlayerPoints;
    turnCount = newTurnCount;
}

// function to import data from text files
void Game::readData()
{
    // **READ MAP**
    
    ifstream myFile;
    
    myFile.open("mapGOT.txt");
    
    if (myFile.is_open())
    {
        string line = "";
        int rowCount = 0;
        
        while (getline(myFile, line))
        {
            if (line != "")
            {
                int colCount = 0;
                for (int i = 0; i < 31; i++)
                {
                    switch (line[i])
                    {
                        case 'w':
                        tileArr[rowCount][colCount] = Tile("~", "", false, "", true, false);
                        i++;
                        colCount++;
                        break;
                        
                        case 'p':
                        tileArr[rowCount][colCount] = Tile("*", "", false, "", false, false);
                        i++;
                        colCount++;
                        break;
                        
                        case 'A':
                        tileArr[rowCount][colCount] = Tile("A", "Castle Black", false, "", false, false);
                        i++;
                        colCount++;
                        break;
                        
                        case 'B':
                        tileArr[rowCount][colCount] = Tile("B", "Eastwatch by the Sea", false, "", false, false);
                        i++;
                        colCount++;
                        break;
                        
                        case 'C':
                        tileArr[rowCount][colCount] = Tile("C", "Deepwood Motte", false, "", false, false);
                        i++;
                        colCount++;
                        break;
                        
                        case 'D':
                        tileArr[rowCount][colCount] = Tile("D", "Winterfell", false, "", false, false);
                        i++;
                        colCount++;
                        break;
                        
                        case 'E':
                        tileArr[rowCount][colCount] = Tile("E", "White Harbor", false, "", false, false);
                        i++;
                        colCount++;
                        break;
                        
                        case 'F':
                        tileArr[rowCount][colCount] = Tile("F", "The Twins", false, "", false, false);
                        i++;
                        colCount++;
                        break;
                        
                        case 'G':
                        tileArr[rowCount][colCount] = Tile("G", "The Eyrie", false, "", false, false);
                        i++;
                        colCount++;
                        break;
                        
                        case 'H':
                        tileArr[rowCount][colCount] = Tile("H", "Pyke", false, "", false, false);
                        i++;
                        colCount++;
                        break;
                        
                        case 'I':
                        tileArr[rowCount][colCount] = Tile("I", "Riverrun", false, "", false, false);
                        i++;
                        colCount++;
                        break;
                        
                        case 'J':
                        tileArr[rowCount][colCount] = Tile("J", "Dragonstone", false, "", false, false);
                        i++;
                        colCount++;
                        break;
                        
                        case 'K':
                        tileArr[rowCount][colCount] = Tile("K", "Casterly Rock", false, "", false, false);
                        i++;
                        colCount++;
                        break;
                        
                        case 'L':
                        tileArr[rowCount][colCount] = Tile("L", "King's Landing", false, "", false, false);
                        i++;
                        colCount++;
                        break;
                        
                        case 'M':
                        tileArr[rowCount][colCount] = Tile("M", "Storm's End", false, "", false, false);
                        i++;
                        colCount++;
                        break;
                        
                        case 'N':
                        tileArr[rowCount][colCount] = Tile("N", "Highgarden", false, "", false, false);
                        i++;
                        colCount++;
                        break;
                        
                        case 'O':
                        tileArr[rowCount][colCount] = Tile("O", "Old Town", false, "", false, false);
                        i++;
                        colCount++;
                        break;
                        
                        case 'P':
                        tileArr[rowCount][colCount] = Tile("P", "Sunspear", false, "", false, false);
                        i++;
                        colCount++;
                        break;
                        
                        case 'Q':
                        tileArr[rowCount][colCount] = Tile("Q", "Horn Hill", false, "", false, false);
                        i++;
                        colCount++;
                        break;
                        
                        case 'R':
                        tileArr[rowCount][colCount] = Tile("R", "Myr", false, "", false, false);
                        i++;
                        colCount++;
                        break;
                        
                        case 'S':
                        tileArr[rowCount][colCount] = Tile("S", "Volantis", false, "", false, false);
                        i++;
                        colCount++;
                        break;
                        
                        case 'T':
                        tileArr[rowCount][colCount] = Tile("T", "Meereen", false, "", false, false);
                        i++;
                        colCount++;
                        break;
                        
                        case 'U':
                        tileArr[rowCount][colCount] = Tile("U", "Yoonkai", false, "", false, false);
                        i++;
                        colCount++;
                        break;
                        
                        case 'V':
                        tileArr[rowCount][colCount] = Tile("V", "Astapor", false, "", false, false);
                        i++;
                        colCount++;
                        break;
                        
                        case 'W':
                        tileArr[rowCount][colCount] = Tile("W", "Vaes Dothrak", false, "", false, false);
                        i++;
                        colCount++;
                        break;
                        
                        case 'X':
                        tileArr[rowCount][colCount] = Tile("X", "Qohor", false, "", false, false);
                        i++;
                        colCount++;
                        break;
                        
                        case 'Y':
                        tileArr[rowCount][colCount] = Tile("Y", "Pentos", false, "", false, false);
                        i++;
                        colCount++;
                        break;
                        
                        case 'Z':
                        tileArr[rowCount][colCount] = Tile("Z", "Braavos", false, "", false, false);
                        i++;
                        colCount++;
                        break;
                    }
                }
                rowCount++;
            }
        }
        
        myFile.close();
    }
    else
    {
        cout << "ERROR";
    }
    
    // **READ WARRIORS**
    
    myFile.open("warriorsGOT.txt");
    
    if (myFile.is_open())
    {
        string line = "";
        string tempArray[7];
        int lineidx = 0;
        
        while (getline(myFile, line))
        {
            if (line != "")
            {
                split(line, ',', tempArray, 0);
                
                warriorArr[lineidx].setNumber(lineidx + 1);
                
                warriorArr[lineidx].setName(tempArray[0]);
                warriorArr[lineidx].setStrength(stoi(tempArray[1]));
                warriorArr[lineidx].setLoyalty(stoi(tempArray[2]));
                warriorArr[lineidx].setMorale(stoi(tempArray[3]));
                
                if (tempArray[4] == "yes")
                {
                    warriorArr[lineidx].setFreedom(true);
                }
                else
                {
                    warriorArr[lineidx].setFreedom(false);
                }
                if (tempArray[5] == "yes")
                {
                    warriorArr[lineidx].setShip(true);
                }
                else
                {
                    warriorArr[lineidx].setShip(false);
                }
                if (tempArray[6] == "yes\r")
                {
                    warriorArr[lineidx].setGlass(true);
                }
                else
                {
                    warriorArr[lineidx].setGlass(false);
                }
                
                lineidx++;
            }
        }
        
        myFile.close();
    }
    else
    {
        cout << "ERROR";
    }
    
    // **READ CITIES**
    
    myFile.open("citiesGOT.txt");
    
    if (myFile.is_open())
    {
        string line = "";
        string tempArray[5];
        int lineidx = 0;
        string tempString;
        
        while (getline(myFile, line))
        {
            if (line != "")
            {
                split(line, ',', tempArray, 0);
                
                tempString = tempArray[0]; 
                cityArr[lineidx].setLetter(tempString[0]);
                cityArr[lineidx].setName(tempArray[1]);
                cityArr[lineidx].setMoney(stoi(tempArray[2]));
                cityArr[lineidx].setArmySize(stoi(tempArray[3]));
                cityArr[lineidx].setPoints(stoi(tempArray[4]));
                
                lineidx++;
            }
        }
        
        myFile.close();
    }
    else
    {
        cout << "ERROR";
    }
    
    // **READ HEROES**
    
    myFile.open("heroesGOT.txt");
    
    if (myFile.is_open())
    {
        string line = "";
        string tempArray[11];
        int lineidx = 0;
        
        while (getline(myFile, line))
        {
            if (line != "")
            {
                split(line, ',', tempArray, 0);
                
                heroArr[lineidx].setName(tempArray[0]);
                heroArr[lineidx].setMoney(stoi(tempArray[1]));
                heroArr[lineidx].setInfluence(stoi(tempArray[2]));
                heroArr[lineidx].setArmySize(stoi(tempArray[3]));
                
                if (tempArray[4] != "NULL")
                {
                    for (int i = 0; i < 14; i++)
                    {
                        if (tempArray[4] == warriorArr[i].getName())
                        {
                            int tempInt = (warriorArr[i].getNumber() - 1);
                            heroArr[lineidx].setWarriors(tempInt, 0);
                        }
                    }
                    heroArr[lineidx].setNumWarriors(1);
                }
                
                if (tempArray[5] != "NULL")
                {
                    for (int i = 0; i < 14; i++)
                    {
                        if (tempArray[5] == warriorArr[i].getName())
                        {
                            int tempInt = (warriorArr[i].getNumber() - 1);
                            heroArr[lineidx].setWarriors(tempInt, 1);
                        }
                    }
                    heroArr[lineidx].setNumWarriors(2);
                }
                
                if (tempArray[6] != "NULL")
                {
                    for (int i = 0; i < 14; i++)
                    {
                        if (tempArray[6] == warriorArr[i].getName())
                        {
                            int tempInt = (warriorArr[i].getNumber() - 1);
                            heroArr[lineidx].setWarriors(tempInt, 2);
                        }
                    }
                    heroArr[lineidx].setNumWarriors(3);
                }
                
                if (tempArray[7] != "NULL")
                {
                    for (int i = 0; i < 14; i++)
                    {
                        if (tempArray[7] == warriorArr[i].getName())
                        {
                            int tempInt = (warriorArr[i].getNumber() - 1);
                            heroArr[lineidx].setWarriors(tempInt, 3);
                        }
                    }
                    heroArr[lineidx].setNumWarriors(4);
                }
                
                
                heroArr[lineidx].setLocationRow(stoi(tempArray[8]));
                heroArr[lineidx].setLocationColumn(stoi(tempArray[9]));

                if (tempArray[10] == "yes\r")
                {
                    heroArr[lineidx].setShip(true);
                }
                else
                {
                    heroArr[lineidx].setShip(false);
                }
                
                lineidx++;
            }
        }
        
        myFile.close();
    
    }
    else
    {
        cout << "ERROR";
    }
}

// function to randomize dragon glass locations
void Game::randGlass()
{
    // update Tile array with random dragon glass
    
    for (int i = 0; i < 5; i++)
    {
        int randRow = 1;
        int randCol = 16;
        while (tileArr[(randRow - 1)][(randCol - 1)].getTileSymbol() != "*")
        {
            randRow = random() % 25 + 1;
            randCol = random() % 16 + 1;
        }
            
        tileArr[(randRow - 1)][(randCol - 1)].setIsDragonGlass(true);
    }
}

// function to randomize free warrior locations
void Game::randFreeWarriors()
{
    for (int i = 0; i < 14; i++)
    {
        if (warriorArr[i].getFreedom() == true)
        {
            int randRow = 1;
            int randCol = 16;
            while (tileArr[(randRow - 1)][(randCol - 1)].getTileSymbol() != "*")
            {
                randRow = random() % 25 + 1;
                randCol = random() % 16 + 1;
            }
                
            warriorArr[i].setLocationRow(randRow - 1);
            warriorArr[i].setLocationColumn(randRow - 1);
        }
    }
}

// function to assign warrior location
void Game::warriorLocation()
{
    for (int i = 0; i < 6; i++)
    {
        for (int b = 0; b < heroArr[i].getNumWarriors(); b++)
        {
            for (int n = 0; n < 14; n++)
            {
                if ((heroArr[i].getWarriorAtIndex(b) + 1) == warriorArr[n].getNumber())
                {
                    warriorArr[n].setLocationRow(heroArr[i].getLocationRow());
                    warriorArr[n].setLocationColumn(heroArr[i].getLocationColumn());
                }
            }
            
        }
    }
}

// function that prints each hero name
void Game::heroSelect()
{
    string tempName;
    for (int i = 0; i < 6; i++)
    {
        tempName = heroArr[i].getName();
        cout << "   " << (i + 1) << ". " << tempName << endl;
    }
            
    cout << endl <<"(1-6)?: ";
}

// function to process custom hero stat selection
void Game::customHero()
{
    int tempVar;
    string tempVar2;
    bool tempVar3;
    
    cout << "Please choose a name for your Hero: " << endl;
    cin >> tempVar2;
    heroArr[6].setName(tempVar2);
    cout << endl;
    
    cout << "Please choose a monetary value between 0 and 1000: " << endl;
    cin >> tempVar;
    heroArr[6].setMoney(tempVar);
    cout << endl;
    
    cout << "Please choose a influence value between 0 and 1000: " << endl;
    cin >> tempVar;
    heroArr[6].setInfluence(tempVar);
    cout << endl;
    
    cout << "Please choose a starting row between 1 and 25: " << endl;
    cin >> tempVar;
    tempVar = (tempVar - 1);
    heroArr[6].setLocationRow(tempVar);
    cout << endl;
    
    cout << "Please choose a starting column between 1 and 16: " << endl;
    cin >> tempVar;
    tempVar = (tempVar - 1);
    heroArr[6].setLocationColumn(tempVar);
    cout << endl;
    
    cout << "Please choose if your Hero will start with a ship (true/false): " << endl;
    cin >> tempVar3;
    heroArr[6].setShip(tempVar3);
    cout << endl;
}

// function that imports user points into driver
int Game::getPlayerPoints(int playerIndex)
{
    return heroArr[playerIndex].getHeroPoints();
}

// function to print local tile map
void Game::printLocalTile(int heroIndex)
{
    // declare temporary variables
    int tempRow;
    int tempCol;
    
    // assign temp row and column starting in the top left corner from hero location
    tempRow = (heroArr[heroIndex].getLocationRow() - 4);
    tempCol = (heroArr[heroIndex].getLocationColumn() - 4);
    
    cout << endl;
    
    // loops to cycle through each tile that will print
    for (int i = 0; i < 7; i++)
    {
        for (int b = 0; b < 7; b++)
        {
            cout << tileArr[(tempRow + i)][(tempCol + b)].getTileSymbol() << "     ";
        }
        
        cout << endl << endl;
    }
}

// function to print hero stats each turn
void Game::printStats(int heroIndex)
{
    cout << "------" << heroArr[heroIndex].getName() << "------" << endl;
    cout << "MONEY: " << heroArr[heroIndex].getMoney() << endl;
    cout << "INFLUENCE: " << heroArr[heroIndex].getInfluence() << endl;
    cout << "ARMY SIZE: " << heroArr[heroIndex].getArmySize() << endl;
    cout << "NUMBER OF WARRIORS: " << heroArr[heroIndex].getNumWarriors() << endl;
    cout << "POINTS: " << heroArr[heroIndex].getHeroPoints() << endl;
    if (heroArr[heroIndex].getShip() == true)
    {
        cout << "SHIP: YES" << endl << endl;
    }
    else
    {
        cout << "SHIP: NO" << endl << endl;
    }
}

// function to update hero changes in stats/location
void Game::updateHeroes()
{
    // loop to cycle through all heroes
    for (int i = 0; i < 6; i++)
    {
        // declare temporary variables
        int tempRow;
        int tempCol;
        string tempCity;
        string tempTile;
        int tempMoney = 0;
        int tempArmy = 0;
        int tempPoints = 0;
        
        // import current hero location
        tempRow = heroArr[i].getLocationRow();
        tempCol = heroArr[i].getLocationColumn();
        
        //update temporary variables
        tempCity = tileArr[(tempRow - 1)][(tempCol - 1)].getCityLocation();
        tempTile = tileArr[(tempRow - 1)][(tempCol - 1)].getTileSymbol();
        
        // loop to cycle through each heroes warriors
        for (int b = 0; b < heroArr[i].getNumWarriors(); b++)
        {
            // import warrior index
            int tempNum = 0;
            tempNum = heroArr[i].getWarriorAtIndex(b);
            
            // conditional to update ship status based on warriors ship status
            if (warriorArr[tempNum].getShip() == true)
            {
                heroArr[i].setShip(true);
                break;
            }
            else
            {
                heroArr[i].setShip(false);
            }
        }
        
        // conditional to update plunder on water tiles
        if ((tempTile == "~")&&(tileArr[(tempRow - 1)][(tempCol - 1)].getTileUsed() == false))
        {
            heroArr[i].setMoney(heroArr[i].getMoney() + 10);
            tileArr[(tempRow - 1)][(tempCol - 1)].setTileUsed(true);
        }
        
        // conditional to update plunder on land tiles
        if ((tempTile == "*")&&(tileArr[(tempRow - 1)][(tempCol - 1)].getTileUsed() == false))
        {
            heroArr[i].setMoney(heroArr[i].getMoney() + 20);
            heroArr[i].setArmySize(heroArr[i].getArmySize() + 10);
            tileArr[(tempRow - 1)][(tempCol - 1)].setTileUsed(true);
        }
        
        // conditional to check if current location is a city
        if (tempCity != "")
        {
            // loop to cycle through city names for match
            for (int b = 0; b < 26; b++)
            {
                // conditional to update city plunder
                if ((tempCity == cityArr[b].getName())&&(tileArr[(tempRow - 1)][(tempCol - 1)].getTileUsed() == false))
                {
                    tempMoney = (cityArr[b].getMoney() + heroArr[i].getMoney());
                    heroArr[i].setMoney(tempMoney);
                    
                    tempArmy = (cityArr[b].getArmySize() + heroArr[i].getArmySize());
                    heroArr[i].setArmySize(tempArmy);
                    
                    tempPoints = (cityArr[b].getPoints() + heroArr[i].getHeroPoints());
                    heroArr[i].setHeroPoints(tempPoints);
                    
                    tileArr[(tempRow - 1)][(tempCol - 1)].setTileUsed(true);
                    break;
                }
            }
        }
    }
}

// function to update location and stats when user chooses to travel
void Game::heroTravel(int heroIndex)
{
    // declare temporary variables
    int tempRow;
    int tempCol;
    int looperVar;
    
    // conditional to set loop constraint based on if user hero has a ship
    if (heroArr[heroIndex].getShip() == true)
    {
        looperVar = -1;
    }
    else
    {
        looperVar = -2;
    }
    
    // import user hero location
    tempRow = (heroArr[heroIndex].getLocationRow() - 1);
    tempCol = (heroArr[heroIndex].getLocationColumn() - 1);
    
    // conditional to process travel when user hero has a ship
    if (looperVar == -1)
    {
        // declare temporary string
        string tempString = "";
        
        // loop to ensure proper direction is entered
        while ((tempString != "north")&&(tempString != "south")&&(tempString != "east")&&(tempString != "west"))
        {
            // prompt user to pick which direction to travel
            cout << "Please choose a direction to TRAVEL: " << endl;
            cin >> tempString;
            
            // hero moves north
            if (tempString == "north")
            {
                heroArr[heroIndex].setLocationRow(tempRow);
                break;
            }
            
            // hero moves south
            if (tempString == "south")
            {
                heroArr[heroIndex].setLocationRow(tempRow + 2);
                break;
            }
            
            // hero moves east
            if (tempString == "east")
            {
                heroArr[heroIndex].setLocationColumn(tempCol + 2);
                break;
            }
            
            // hero moves west
            if (tempString == "west")
            {
                heroArr[heroIndex].setLocationColumn(tempCol);
                break;
            }
        }
    }
    // process travel when user hero has no ship
    else
    {
        // loop to prevent user hero without ship from traveling on water
        while (looperVar == -2)
        {
            // prompt user to pick direction
            string tempString = "";
            cout << "Please choose a direction to TRAVEL: " << endl;
            cin >> tempString;
            
            // hero moves north
            if ((tempString == "north")&&(tileArr[(tempRow - 1)][tempCol].getTileSymbol() != "~"))
            {
                heroArr[heroIndex].setLocationRow(tempRow);
                break;
            }
            
            // hero moves south
            if ((tempString == "south")&&(tileArr[(tempRow + 1)][tempCol].getTileSymbol() != "~"))
            {
                heroArr[heroIndex].setLocationRow(tempRow + 2);
                break;
            }

            // hero moves east
            if ((tempString == "east")&&(tileArr[tempRow][(tempCol + 1)].getTileSymbol() != "~"))
            {
                heroArr[heroIndex].setLocationColumn(tempCol + 2);
                break;
            }
            
            // hero moves west
            if ((tempString == "west")&&(tileArr[tempRow][(tempCol - 1)].getTileSymbol() != "~"))
            {
                heroArr[heroIndex].setLocationColumn(tempCol);
                break;
            }
            
            // output message if hero has no ship
            if ((tempString == "north")||(tempString == "south")||(tempString == "east")||(tempString == "west"))
            {
                cout << endl << "You must have a SHIP to travel on water. " << endl << endl;
            }
        }
    }
}

// function to update strength when user chooses to rest
void Game::heroRest(int heroIndex)
{
    // loop to cycle through each warrior the user hero has
    for (int i = 0; i < heroArr[heroIndex].getNumWarriors(); i++)
    {
        // import warrior index from hero array
        int warriorIndex;
        warriorIndex = heroArr[heroIndex].getWarriorAtIndex(i);
        
        // reset warrior strength with proper index
        int tempStrength;
        tempStrength = warriorArr[warriorIndex].getStrength();
        warriorArr[warriorIndex].setStrength(tempStrength + 1);
    }
    
    // conditional to print confirmation message if user has any warriors to update
    if (heroArr[heroIndex].getNumWarriors() != 0)
    {
        cout << endl << "All warriors STRENGTH raised by 1!" << endl;
    }
    else
    {
        cout << endl << "Hero has no warriors." << endl;
    }
}

// function to update morale when user chooses to consult the gods
void Game::heroConsult(int heroIndex)
{
    // loop to cycle through each warrior the user hero has
    for (int i = 0; i < heroArr[heroIndex].getNumWarriors(); i++)
    {
        // import warrior index from hero array
        int warriorIndex;
        warriorIndex = heroArr[heroIndex].getWarriorAtIndex(i);
        
        // reset warrior morale with proper index
        int tempMorale;
        tempMorale = warriorArr[warriorIndex].getMorale();
        warriorArr[warriorIndex].setMorale(tempMorale + 1);
    }
    
    // conditional to print confirmation message if user has any warriors to update
    if (heroArr[heroIndex].getNumWarriors() != 0)
    {
        cout << endl << "All warriors MORALE raised by 1!" << endl;
    }
    else
    {
        cout << endl << "Hero has no warriors." << endl;
    }
}

// function to simulate CPU heroes
void Game::simCompHeroes(int playerIndex)
{
    // declare temporary variables
    int tempRow = 0;
    int tempCol = 0;
    int randMod;
    
    // loop to cycle through each hero
    for (int i = 0; i < 6; i++)
    {
        // conditional to exclude user hero
        if (i != playerIndex)
        {
            // randomize variable between 1 and 4
            randMod = random() % 4 + 1;
            
            // import hero location for reference
            tempRow = heroArr[i].getLocationRow();
            tempCol = heroArr[i].getLocationColumn();
            
            // hero moves north
            if (randMod == 1)
            {
                heroArr[i].setLocationRow(tempRow - 1);
            }
            
            // hero moves south
            if (randMod == 2)
            {
                heroArr[i].setLocationRow(tempRow + 1);
            }
            
            // hero moves west
            if (randMod == 3)
            {
                heroArr[i].setLocationColumn(tempCol - 1);
            }
            
            // hero moves east
            if (randMod == 4)
            {
                heroArr[i].setLocationColumn(tempCol + 1);
            }
        }
    }
}

// function to simulate free warriors
void Game::simFreeWarriors()
{
    // declare temporary variables
    int tempRow = 0;
    int tempCol = 0;
    int randMod;
    
    // loop to cycle through all warriors
    for (int i = 0; i < 14; i++)
    {
        // conditional to check if given warrior is free
        if (warriorArr[i].getFreedom() == true)
        {
            // randomize number between 1 and 4
            randMod = random() % 4 + 1;
            
            // import warrior location for reference
            tempRow = warriorArr[i].getLocationRow();
            tempCol = warriorArr[i].getLocationColumn();
            
            // warrior moves north
            if (randMod == 1)
            {
                warriorArr[i].setLocationRow(tempRow - 1);
            }
            
            // warrior moves south
            if (randMod == 2)
            {
                warriorArr[i].setLocationRow(tempRow + 1);
            }
            
            // warrior moves west
            if (randMod == 3)
            {
                warriorArr[i].setLocationColumn(tempCol - 1);
            }
            
            // warrior moves east
            if (randMod == 4)
            {
                warriorArr[i].setLocationColumn(tempCol + 1);
            }
        }
    }
}
 
// function to process potential encounters
void Game::encounterCheck(int playerIndex)
{
    // declare temporary variables
    int tempRow = 0;
    int tempCol = 0;
    int encounterChoice;
    
    // loop to cycle through heroes
    for (int i = 0; i < 6; i++)
    {
        // conditional to check if CPU heroes are within 2 spaces to user
        if ((i != playerIndex)&&(abs(tempRow - heroArr[playerIndex].getLocationRow()) <= 2)&&(abs(tempCol - heroArr[playerIndex].getLocationColumn()) <= 2))
        {
            // temp row and column set from user location
            tempRow = heroArr[i].getLocationRow();
            tempCol = heroArr[i].getLocationColumn();
            
            // encounter option text
            cout << "You have encountered the HERO " << heroArr[i].getName() << ", Would you like to:" << endl << endl;
            cout << "   1. GIVE A SPEECH" << endl;
            cout << "   2. BUY THEM OUTRIGHT" << endl;
            cout << "   3. BATTLE" << endl;
            cout << endl << "(1-3)?: ";
            
            cin >> encounterChoice;
            
            // switch statement to process encounters based on user option
            switch (encounterChoice)
            {
                case 1:
                // (1 - (oppFirstWarriorMorale/100))*(heroArr[playerIndex].getInfluence()/1600)
                // if win - keep losers warriors(choose up to 4...), money, influence, army size
                // if lose - hero escapes, lose half influence
                break;
                
                case 2:
                // (1 - (oppFirstWarriorLoyalty/100))*(heroArr[playerIndex].getMoney()/17800)
                // if win - keep losers warriors(choose up to 4...), money, influence, army size
                // if lose - hero escapes, lose half money
                break;
                
                case 3:
                //
                break;
            }
        }
    }
}

// function to process end of turn actions
void Game::endTurn()
{ 

}

// function to update results
void Game::endGameResults()
{
    
}