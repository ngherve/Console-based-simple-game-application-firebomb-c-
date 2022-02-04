#ifndef LIBGAME_H_INCLUDED
#define LIBGAME_H_INCLUDED
#include <cstdlib>
//Include standard string
#include <string>
//Include standard namespace
using namespace std;
//int intCount=0;
//Define custom namespace
namespace BuildSpace
{
	//Dimensions of fixed length 2D array
    const int NUM_ROWS = 7;
    const int NUM_COLS = 7;
	//Create type for 2D integers arrays of given size
    typedef int GameWorld[NUM_ROWS][NUM_COLS];
	//Constants for things in game world
    const int SPACE = 0;
    const int PLAYER = 1;
    const int RUBBLE = 2;
    const int EMPTY_VALUE=0;
    const int PLAYER_VALUE=2;
    //const int BOMB_TIMER_0 = 3;
    //const int BOMB_TIMER_1 = 4;
    //const int BOMB_TIMER_2 = 5;
    //const int BOMB_TIMER_3 = 6;
    //const int EXPLOSION = 7;
	/*
		Constant array for printable symbols of game world
		contents. Each constant previously is the correct index
		into this array for its symbol. You could of course just
		use a switch / if statement as in the previous tutorials
	*/
    const char ARY_SYMBOLS[] = {'.','P','#','!'};
	//Constants for moves (including placing of bombs)
    const int DIR_UP = 1;
    const int DIR_DOWN = 2;
    const int DIR_LEFT = 3;
    const int DIR_RIGHT = 4;
    const int MAT_NORTH=5;
    const int MAT_SOUTH=6;
    const int MAT_WEST=7;
    const int MAT_EAST=8;
    const int MAT_NORTH_EAST=9;
    const int MAT_NORTH_WEST=10;
    const int MAT_SOUTH_EAST=11;
    const int MAT_SOUTH_WEST=12;
    //const int PLACE_BOMB = 5;
	//Percentage chance for rubble to occur in a square
    //const int RUBBLE_CHANCE = 10;
	//Constants for error codes
    const int ERROR_CONVERSION = 1;
    const int ERROR_CMD_ARG_COUNT = 2;
	//Conversion function between string and integers
    int convertToInt(string strNumber);
    int rangedRandom(int intMin, int intMax);
	//Initialisation function for game world
    void init(GameWorld aryWorld, int intPR, int intPC);
	//Display function for game world
    void show(GameWorld aryWorld);
    void PlaceMaterial(GameWorld aryWorld, int intMDir);
	//Movement function for player
    int movePlayer(GameWorld aryWorld, int intDir,int intCount);

}

#endif // LIBGAME_H_INCLUDED
