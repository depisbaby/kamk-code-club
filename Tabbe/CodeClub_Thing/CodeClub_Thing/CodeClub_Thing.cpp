// CodeClub_Thing.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <cstdlib>

char spot1 = '1';
char spot2 = '2';
char spot3 = '3';
char spot4 = '4';
char spot5 = '5';
char spot6 = '6';
char spot7 = '7';
char spot8 = '8';
char spot9 = '9';

int playerSelection;
int botSelection;
bool runInputWhile = false;
bool isAvailable = true;
bool isRunning = true;



static void CheckForAvailability() 
{
    isAvailable = false;
    if (spot1 == '1')
    {
        isAvailable = true;
    }
    if (spot2 == '2')
    {
        isAvailable = true;
    }
    if (spot3 == '3')
    {
        isAvailable = true;
    }
    if (spot4 == '4')
    {
        isAvailable = true;
    }
    if (spot5 == '5')
    {
        isAvailable = true;
    }
    if (spot6 == '6')
    {
        isAvailable = true;
    }
    if (spot7 == '7')
    {
        isAvailable = true;
    }
    if (spot8 == '8')
    {
        isAvailable = true;
    }
    if (spot9 == '9')
    {
        isAvailable = true;
    }

    isRunning = isAvailable;
}
static void CheckIfSame(char char1, char char2, char char3) 
{
    if (char1 == char2 && char2 == char3)
    {
        isRunning = false;
    }
}
static void CheckForWin() 
{
    // Victories including spot 1
    CheckIfSame(spot1, spot2, spot3);
    CheckIfSame(spot1, spot4, spot8);
    CheckIfSame(spot1, spot5, spot9);
    // Victories including spot 2
    CheckIfSame(spot2, spot5, spot8);
    // Victories including spot 3
    CheckIfSame(spot3, spot5, spot7);
    CheckIfSame(spot3, spot6, spot9);
    // Victories including spot 4
    CheckIfSame(spot4, spot5, spot6);
    // Victories including spot 5
    // None Left
    // Victories including spot 6
    // None left
    // Victories including spot 7
    CheckIfSame(spot7, spot8, spot9);
    // Victories including spot 8
    // None Left
    // Victories including spot 9
    // None left


    CheckIfSame(spot1, spot2, spot3);
}
static void ShowBoard() 
{
    std::cout << "\n";
    std::cout << "   " << spot7 << " | " << spot8 << " | " << spot9 << "\n";
    std::cout << "  ------------ \n";
    std::cout << "   " << spot4 << " | " << spot5 << " | " << spot6 << "\n";
    std::cout << "  ------------ \n";
    std::cout << "   " << spot1 << " | " << spot2 << " | " << spot3 << "\n";
}

static void ChangeCharToX(char& newchar, char number)
{
    if (newchar == number)
    {
        std::cout << "Space is available\n";
        runInputWhile = false;
        newchar = 'X';
    }
    else
    {
        std::cout << "Space is not available.\n Try again. \n";
    }
}
static void ChangeCharToO(char& newchar, char number)
{
    if (newchar == number)
    {
        runInputWhile = false;
        newchar = 'O';
    }
}

static void GiveXInput() 
{
    std::cout << "\n You are X \n Where would you like to place it? \n Type the number in the console: ";
    runInputWhile = true;

    while (runInputWhile)
    {
        playerSelection = NULL;
        std::cin >> playerSelection;
        switch (playerSelection)
        {
        case 1:
            ChangeCharToX(spot1, '1');
            break;
        case 2:
            ChangeCharToX(spot2, '2');
            break;
        case 3:
            ChangeCharToX(spot3, '3');
            break;
        case 4:
            ChangeCharToX(spot4, '4');
            break;
        case 5:
            ChangeCharToX(spot5, '5');
            break;
        case 6:
            ChangeCharToX(spot6, '6');
            break;
        case 7:
            ChangeCharToX(spot7, '7');
            break;
        case 8:
            ChangeCharToX(spot8, '8');
            break;
        case 9:
            ChangeCharToX(spot9, '9');
            break;



        default:
            std::cout << "Please select a possible place to place your tile \n";
            playerSelection = NULL;
            GiveXInput();
            break;
        }
    }
}
static void GiveOInput()
{
    runInputWhile = true;
    while (runInputWhile)
    {
        botSelection = NULL;
        srand(time(NULL));
        botSelection = rand() % 10;
        switch (botSelection)
        {
        case 1:
            ChangeCharToO(spot1, '1');
            break;
        case 2:
            ChangeCharToO(spot2, '2');
            break;
        case 3:
            ChangeCharToO(spot3, '3');
            break;
        case 4:
            ChangeCharToO(spot4, '4');
            break;
        case 5:
            ChangeCharToO(spot5, '5');
            break;
        case 6:
            ChangeCharToO(spot6, '6');
            break;
        case 7:
            ChangeCharToO(spot7, '7');
            break;
        case 8:
            ChangeCharToO(spot8, '8');
            break;
        case 9:
            ChangeCharToO(spot9, '9');
            break;
        }
    }
}


int main()
{
    while (isRunning) 
    {
        ShowBoard();
        GiveXInput();
        CheckForAvailability();
        CheckForWin();
        if (isRunning == false)
        {
            break;
        }
        //ShowBoard();
        GiveOInput(); 
        CheckForAvailability();
        CheckForWin();
        std::system("cls");
    }
    ShowBoard();
    std::cout << "\n Game Over \n";
}