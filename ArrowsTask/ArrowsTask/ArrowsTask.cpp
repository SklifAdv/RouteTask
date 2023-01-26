#include <iostream>
#include <conio.h>
#include <vector>
#include "Arrow.h"

#define KEY_UP 72
#define KEY_DOWN 80
#define KEY_LEFT 75
#define KEY_RIGHT 77
#define ESCAPE 27
#define SMALL_Q 113
#define BIG_Q 81

void mainMenu();
void firstCommandMenu();
void secondCommandMenu();
bool isValidMovement(const Arrow movement, const std::vector<Arrow>& routeVector);
bool isVictory(const Coordinate& currentDestination, const Coordinate& finalDestination);
void firstCommand();
void secondCommand(const std::vector<Arrow>& routeVector);
std::string arrowToSymbol(const Arrow::Direction dir);

int main()
{
    while (true)
    {
        mainMenu();

        char option = '0';
        std::cin >> option;

        switch (option)
        {
        case '1':
        {
            firstCommand();
            break;
        }
        case '2':
        {
            return 0;
        }
        }
    }
}

void mainMenu()
{
    system("cls");

    std::cout << "Good day! Please, choose option:\n"
        << "* 1. Start a game\n"
        << "* 2. Quit\n\n"
        << "Option: ";
}

void firstCommandMenu()
{
    system("cls");

    std::cout << "* Please, insert data via arrow keys to define route.\n"
        << "* Your movements will shown at screen as text.\n"
        << "* To end route, press ESC key.\n\n"
        << "Your route: ";
}

void secondCommandMenu() 
{
    system("cls");

    std::cout << "* Now you should enter the arrow keys to find final destination.\n"
        << "* But no worries, we won't let you to deviate from the original route more, than 1 step.\n"
        << "* If you lost and want to quit, enter 'q'.\n\n";
}

bool isValidMovement(const Arrow movement, const std::vector<Arrow>& routeVector)
{
    const Coordinate startCoord(0, 0);
    const Coordinate dest = movement.getDestination();

    short curDistance = dest.distanceTo(startCoord);

    if (curDistance > 1)
    {
        for (unsigned int i = 0; i < routeVector.size(); ++i)
        {
            const Coordinate curRoutePoint = routeVector.at(i).getDestination();
            curDistance = dest.distanceTo(curRoutePoint);

            if (curDistance < 2)
                return true;
        }
        return false;
    }
    return true;
}

void firstCommand() 
{
    firstCommandMenu();

    bool exitFlag = false;
    Coordinate currentCoord(0, 0);
    std::vector<Arrow> arrowsVector;

    do {
        int asciiCode = 0;
        asciiCode = _getch();

        if (asciiCode == 0 || asciiCode == 224)
        {
            asciiCode = _getch();
            switch (asciiCode)
            {
            case KEY_UP:
            case KEY_DOWN:
            case KEY_LEFT:
            case KEY_RIGHT:
            {
                Arrow::Direction dir = (Arrow::Direction)asciiCode;
                std::string str = arrowToSymbol(dir);

                Arrow curArrow(currentCoord, dir);
                arrowsVector.push_back(curArrow);
                currentCoord = curArrow.getDestination();

                std::cout << str << " ";
                break;
            }
            }
        }
        else if (asciiCode == ESCAPE)
        {
            if (arrowsVector.size() == 0)
            {
                std::cout << "\nWarning! Enter at least 1 arrow to continue!\n";
                continue;
            }
            exitFlag = true;
        }
    } while (!exitFlag);

    std::cout << std::endl;
    system("pause");

    secondCommand(arrowsVector);
}

void secondCommand(const std::vector<Arrow>& routeVector)
{
    secondCommandMenu();

    Coordinate currentCoord(0, 0);
    Coordinate finalDest = routeVector.back().getDestination();
    bool exitFlag = false;

    do {
        int asciiCode = 0;
        asciiCode = _getch();

        if (asciiCode == 0 || asciiCode == 224)
        {
            asciiCode = _getch();
            switch (asciiCode)
            {
            case KEY_UP:
            case KEY_DOWN:
            case KEY_LEFT:
            case KEY_RIGHT:
            {
                Arrow::Direction dir = (Arrow::Direction)asciiCode;
                std::string str = arrowToSymbol(dir);

                Arrow curArrow(currentCoord, dir);

                std::cout << "Movement " << str << " is ";
                if (isValidMovement(curArrow, routeVector))
                {
                    std::cout << "valid!\n";
                    currentCoord = curArrow.getDestination();
                    if (isVictory(currentCoord, finalDest))
                    {
                        exitFlag = true;
                        std::cout << "\n\t*****Congratulations! You won!*****\n";
                    }
                }
                else
                {
                    std::cout << "not valid! Try again!\n";
                }

                break;
            }
            }
        }
        else if (asciiCode == SMALL_Q || asciiCode == BIG_Q)
        {
            std::cout << "\nYou decided to quit. Goodbye!\n";
            exitFlag = true;
        }
    } while (!exitFlag);
    
    std::cout << std::endl;
    system("pause");
}

std::string arrowToSymbol(const Arrow::Direction dir)
{
    std::string symbArrow = "";

    switch (dir)
    {
    case Arrow::kUp:
    {
        symbArrow = "\x18";
        break;
    }
    case Arrow::kDown:
    {
        symbArrow = "\x19";
        break;
    }
    case Arrow::kLeft:
    {
        symbArrow = "<-";
        break;
    }
    case Arrow::kRight:
    {
        symbArrow = "\x1a";
        break;
    }
    }

    return symbArrow;
}

bool isVictory(const Coordinate& currentDestination, const Coordinate& finalDestination)
{
    return (currentDestination.x() == finalDestination.x() && currentDestination.y() == finalDestination.y());
}