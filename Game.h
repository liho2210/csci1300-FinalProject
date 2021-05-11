// CS1300 Spring 2019
// Author: Liam Hollins
// Recitation: 203 - Dhanendra Soni
// Cloud9 Workspace Editor Link: https://ide.c9.io/liamhollins/csci1300_lh
// Project 3

#include <string>
#include "Heroes.h"
#include "Warriors.h"
#include "Cities.h"
#include "Tile.h"
#ifndef GAME_H
#define GAME_H
using namespace std;

class Game
{
    // private data members
    private:
    int playerPoints;
    int turnCount;
    Heroes heroArr[7];
    Warriors warriorArr[14];
    Cities cityArr[26];
    Tile tileArr[25][16];

    // public member functions
    public:
    // default constructor
    Game();
    
    // parameterized constructor
    Game(int playerPoints, int turnCount);
    
    void readData();
        // fill class arrays from text files with loop and fstream
    
    void randGlass();
        // update Tile array with random dragon glass
        
    void randFreeWarriors();
    
    void warriorLocation();
    
    void heroSelect();
    
    void customHero();
    
    string printHeroName(int heroIndex);
    
    int getPlayerPoints(int index);
    
    void setPlayerPoints(int heroIndex); // parameterized with amount added/subtracted?
    
    void printLocalTile(int heroIndex);
    
    void printStats(int heroIndex);
    
    // UPDATE NEW POSITION/ STAT CHANGES
    
    void updateHeroes();
    
    void heroTravel(int heroIndex);
    
    void heroRest(int heroIndex);
     
    void heroConsult(int heroIndex);
    // PROCESS POTENTIAL ENCOUNTERS --- IF YES THEN RUN GAMERUN.ENCOUNTER()
    
    void simCompHeroes(int playerIndex);
    
    void simFreeWarriors();
    
    void encounterCheck(int playerIndex);
    
    // END TURN EVENTS ------- DROUGHT DESERTERS JACKPOT KINDNESS
    void endTurn();      // CHECKS TURN COUNT FOR PRESET EVENTS*** DRAGONS DEMONS ARYA JAMIE
                            // WHITE WALKERS----------->
    void endGameResults();
};

#endif