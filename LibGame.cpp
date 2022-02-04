#include "LibGame.h"
//Include standard libraries
#include <iostream>
#include <sstream>
//Use standard namespace
using namespace std;
//Define custom namespace
namespace BuildSpace
{
	//Utility function for generating random integer in a range
    int rangedRandom(int intMin, int intMax)
    {
		//Determine range of random numbers
        int intRange = intMax - intMin + 1;
		/*
		  Generate random numbers in range from 0 then offset by
		  minimum value.
		*/
        return rand() % intRange + intMin;
    }
	//Utility function for testing if a coordinate is valid
    bool isInWorld(int intRow, int intCol)
    {
		//A coordinate is valid if it is between 0 and size - 1
        if(intRow < 0) return false;
        if(intCol < 0) return false;
        if(intRow >= NUM_ROWS) return false;
        if(intCol >= NUM_COLS) return false;

        return true;
    }
	//Utility function for finding an open square next to player to plant bomb
    void init(GameWorld aryWorld, int intPR, int intPC)
    {
        int Material=0;

		//Loop through game world
		for(int c = 0; c < NUM_COLS; c++)
        {
            Material = rangedRandom(0, NUM_ROWS-1);
            aryWorld[Material][c] = RUBBLE;
            for(int r = 0; r < NUM_ROWS; r++)
            {
                //Otherwise place space
                if(aryWorld[c][r] != RUBBLE)
                    aryWorld[c][r] = SPACE;

            }
        }
        if(aryWorld[intPR][intPC] == RUBBLE)
        {
            int intPR=rangedRandom(0,NUM_ROWS-1);
            int intPC=rangedRandom(0,NUM_COLS-1);
            aryWorld[intPR][intPC] = PLAYER;
        }
        else
        {
            aryWorld[intPR][intPC] = PLAYER;
        }
		//Place player in given location
		aryWorld[intPR][intPC] = PLAYER;

    }
	//Display game world
    void show(GameWorld aryWorld)
    {
		//Loop through world
        for(int r = 0; r < NUM_ROWS; r++)
        {
            for(int c = 0; c < NUM_COLS; c++)
            {
				//Print symbol using symbol array
                cout << ARY_SYMBOLS[aryWorld[r][c]] << " ";
            }
			//End of row is end of line
            cout << endl;
        }

    }

    void findPlayer(GameWorld aryWorld, int& intPR, int& intPC)
    {
		//Loop through world
        for(intPR = 0; intPR < NUM_ROWS; intPR++)
        {
            for(intPC = 0; intPC < NUM_COLS; intPC++)
            {
				//If player is found stop
                if(aryWorld[intPR][intPC] == PLAYER)
                    return; //Location given via ref params
            }
        }
    }

    int movePlayer(GameWorld aryWorld, int intDir,int intCount)
    {
		//Decrease counters
       	//Find player
        int intPR = -1;
        int intPC = -1;
        findPlayer(aryWorld, intPR, intPC);
		//Determine target coordinates
        int intTR = intPR;
        int intTC = intPC;
        switch(intDir)
        {
            case DIR_UP:
                intTR--;
            break;
            case DIR_DOWN:
                intTR++;
            break;
            case DIR_LEFT:
                intTC--;
            break;
            case DIR_RIGHT:
                intTC++;
            break;
        }
		//If target coordinates are in world
        if(isInWorld(intTR, intTC))
        {
			//And contain a space
            if(aryWorld[intTR][intTC] == SPACE)
            {
				//Player leaves old location
                aryWorld[intPR][intPC] = SPACE;
				//And arrives in new location
                aryWorld[intTR][intTC] = PLAYER;
            }
            else if(aryWorld[intTR][intTC] = RUBBLE)
            {
                intCount--;
                aryWorld[intPR][intPC] = SPACE;
				//And arrives in new location
                aryWorld[intTR][intTC] = PLAYER;
            }
        }
        return intCount;
    }

    void PlaceMaterial(GameWorld aryWorld, int intMDir)
    {
        int intPR = -1;
        int intPC = -1;
        findPlayer(aryWorld, intPR, intPC);
        int intMR = intPR;
        int intMC = intPC;

        switch(intMDir)
        {
            case MAT_EAST:
                intMC++;
            break;
            case MAT_NORTH:
                intMR--;
            break;
            case MAT_NORTH_EAST:
                intMC++;
                intMR--;
            break;
            case MAT_SOUTH:
                intMR++;
            break;
            case MAT_WEST:
                intMC--;
            break;
            case MAT_SOUTH_EAST:
                intMC++;
                intMR++;
            break;
            case MAT_SOUTH_WEST:
                intMC--;
                intMR++;
            break;
            case MAT_NORTH_WEST:
                intMR--;
                intMC--;
            break;
        }

        if(isInWorld(intMR, intMC))
        {
			//And contain a space
            if(aryWorld[intMR][intMC] == SPACE)
            {
				//Player leaves old location
                //aryWorld[intPR][intPC] = PLAYER;
				//And arrives in new location
                aryWorld[intMR][intMC] = RUBBLE;
            }
        }
    }

}
