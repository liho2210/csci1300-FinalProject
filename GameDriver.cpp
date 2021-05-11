// CS1300 Spring 2019
// Author: Liam Hollins
// Recitation: 203 - Dhanendra Soni
// Cloud9 Workspace Editor Link: https://ide.c9.io/liamhollins/csci1300_lh
// Project 3

#include <iostream>
#include <string>
#include "Game.cpp"
using namespace std;

int main()
{
    string replayLoop = "yes";
    
    // MASTER LOOP FOR REPLAYS
    while (replayLoop == "yes")
    {
        // declare variables and create Game object
        Game gameRun;
        gameRun = Game();
        string playerName;
        char heroChoice;
        int turnChoice;
        int playerIndex = 10;
        
        // load text files
        gameRun.readData();
        gameRun.randGlass();
        gameRun.randFreeWarriors();
        gameRun.warriorLocation();
        
        // welcome message and player name choice
        cout << "Welcome to the G A M E of T H R O N E S!" << endl << endl;
        
        cout << "State your name, Your Grace: ";
        
        getline(cin, playerName);
        cout << endl;
        
        // prompt user to choose hero or create their own
        while ((heroChoice != 'Y')&&(heroChoice != 'y')&&(heroChoice != 'N')&&(heroChoice != 'n'))
        {
            cout << "Would you like to choose a hero " << playerName << ", Your Grace? (Y/N): ";
            cin >> heroChoice;
        }
        
        // user picks which hero they want to play as
        if ((heroChoice == 'Y')||(heroChoice == 'y'))
        {
            while ((playerIndex != 0)&&(playerIndex != 1)&&(playerIndex != 2)&&(playerIndex != 3)&&(playerIndex != 4)&&(playerIndex != 5))
            {
                cout << "Please choose from the following heroes:" << endl << endl;
                
                // function to display hero options
                gameRun.heroSelect();
                
                cin >> playerIndex;
                playerIndex = (playerIndex - 1);
            }
        }
        
        // user creates custom hero
        if ((heroChoice == 'N')||(heroChoice == 'n'))
        {
            playerIndex = 6;
            
            cout << endl << "Your Grace " << playerName << ", you have chosen to go on this journey alone." << endl;
            cout << endl << "Please provide starting values for your adventure." << endl;
            
            // function for user to choose custom stats
            gameRun.customHero();
        }
        
        // turn sequence starts here
        while (gameRun.getPlayerPoints(playerIndex) < 400)
        {
                // function to print local map
                gameRun.printLocalTile(playerIndex);
                
                // function to update hero stats each turn
                gameRun.updateHeroes();
                
                // function to print user hero stats
                gameRun.printStats(playerIndex);
                
                // loop to ensure user picks appropriate options
                while ((turnChoice != 1)&&(turnChoice != 2)&&(turnChoice != 3))
                {
                    // PLAYER CHOICES
                    cout << "Would you like to:" << endl << endl;
                    cout << "   1. TRAVEL" << endl;
                    cout << "   2. REST" << endl;
                    cout << "   3. CONSULT THE GODS" << endl;
                    cout << endl << "(1-3)?: ";
                    
                    cin >> turnChoice;
                }
                
                // conditionals for different user turn options
                if (turnChoice == 1)
                {
                    // function to process user travel
                    gameRun.heroTravel(playerIndex);
                }
                
                if (turnChoice == 2)
                {
                    // function to process user rest
                    gameRun.heroRest(playerIndex);
                }
                
                if (turnChoice == 3)
                {
                    // function to process user consult
                    gameRun.heroConsult(playerIndex);
                }
                
                // function to simulate CPU heroes movement/stats
                gameRun.simCompHeroes(playerIndex);
                
                // function to simulate free warriors movement/stats
                gameRun.simFreeWarriors();
                
                // function to check for/process potential encounters
                gameRun.encounterCheck(playerIndex);
                
                // function to process actions at the end of each turn
                gameRun.endTurn();

                // turn choice variable resets for loop
                turnChoice = -1;
        }
        
        // UPDATE RESULTS TEXT
        gameRun.endGameResults();
        
        // end game message/replay option
        cout << "GAME OVER" << endl << "Would you like to play again?" << endl;
        cout << "(yes to keep playing, any other key to exit): " << endl;
        cin >> replayLoop;
    }
    
    // exit message
    cout << "Thanks for playing!" << endl;
}