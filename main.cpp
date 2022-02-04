#include <iostream>
#include <ctime>
#include "LibGame.h"

using namespace std;
using namespace BuildSpace;

int main()
{
    srand(time(0));
    GameWorld aryWorld = {0};
    int intPR=rangedRandom(0,NUM_ROWS-1);
    int intPC=rangedRandom(0,NUM_COLS-1);
    int intCount=NUM_COLS;
    int intCountMat=NUM_COLS;

    init(aryWorld, intPR, intPC);
	//Create loop control variable for menu
    bool blnContinue = true;

    do
    {
        //Clear screen
        system("cls");
		//Display game world
        show(aryWorld);
		//Prompt user
        cout << "w) Up a) Left s) Down d) Right x) Exit" << endl
             << "Remaining Material: " << intCount << " Deposits Remaining: " << intCountMat << endl
             << "Select move: "<<endl;
            char chOption = '\0';
            char chSelect = '\0';

        if(intCount==0 && intCountMat>=0)
             {
                 cout << "1)Place Material East" << endl
                      << "2)Place Material West" << endl
                      << "3)Place Material South" << endl
                      << "4)Place Material North-West" << endl
                      << "5)Place Material South-East" << endl
                      << "6)Place Material South-West" << endl
                      << "7)Place Material North-East" << endl
                      << "8)Place Material North" << endl;
                        //Capture selection
                  cin >> chSelect;
        switch(chSelect)
        {
            case 'w':
            case 'W':
                intCount=movePlayer(aryWorld, DIR_UP ,intCount);
            break;
			//Move left
            case 'a':
            case 'A':
                intCount=movePlayer(aryWorld, DIR_LEFT,intCount);
            break;
			//Move down
            case 's':
            case 'S':
                intCount=movePlayer(aryWorld, DIR_DOWN,intCount);
            break;
			//Move right
            case 'd':
            case 'D':
                intCount=movePlayer(aryWorld, DIR_RIGHT,intCount);
            break;
            case 'x':
            case 'X':
                blnContinue = false;
            break;
			//Invalid selection
            case '1':
                PlaceMaterial(aryWorld, MAT_EAST);
                intCountMat--;
            break;
			//Move left
            case '2':
                PlaceMaterial(aryWorld, MAT_WEST);
                intCountMat--;
            break;
			//Move down
            case '3':
                PlaceMaterial(aryWorld, MAT_SOUTH);
                intCountMat--;
            break;
			//Move right
            case '4':
                PlaceMaterial(aryWorld, MAT_NORTH_WEST);
                intCountMat--;
            break;
			//Place bomb
            case '5':
                PlaceMaterial(aryWorld, MAT_SOUTH_EAST);
                intCountMat--;
            break;
            case '6':
                PlaceMaterial(aryWorld, MAT_SOUTH_WEST);
                intCountMat--;
            break;
            case '7':
                PlaceMaterial(aryWorld, MAT_NORTH_EAST);
                intCountMat--;
            break;
            case '8':
                PlaceMaterial(aryWorld, MAT_NORTH);
                intCountMat--;
            break;
			//Quit
			default:
                cerr << "Invalid option " << chOption << endl;
                system("pause");
                  }
            if(intCountMat==0)
            {
                for(int i=0; i<NUM_COLS; i++)
                {
                    if(aryWorld[i][i]==RUBBLE)
                    {
                        cout << "YOU WON !!!" << endl;
                        system("pause");
                        exit(EXIT_SUCCESS);
                    }
                    else
                    {
                        cout << "YOU LOSS !!!: Place the Materials in the Diagonal of the Grid" << endl;
                        system("pause");
                        exit(EXIT_FAILURE);
                    }
                }
             }
            }
             else
             {
                 cin >> chOption;
        switch(chOption) //Call functions based on option
        {
			//Move up
            case 'w':
            case 'W':
                intCount=movePlayer(aryWorld, DIR_UP ,intCount);
            break;
			//Move left
            case 'a':
            case 'A':
                intCount=movePlayer(aryWorld, DIR_LEFT,intCount);
            break;
			//Move down
            case 's':
            case 'S':
                intCount=movePlayer(aryWorld, DIR_DOWN,intCount);
            break;
			//Move right
            case 'd':
            case 'D':
                intCount=movePlayer(aryWorld, DIR_RIGHT,intCount);
            break;
			//Quit
            case 'x':
            case 'X':
                blnContinue = false;
            break;
			//Invalid selection
            default:
                cerr << "Invalid option " << chOption << endl;
                system("pause");
         }
        }

    } while(blnContinue);

    return EXIT_SUCCESS;
}
