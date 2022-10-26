#include <iostream>
#include <string>
#include "car.cpp"

using namespace std;

int main()
{
    int i;

    // variables for the room size
    int width=0;
    int height=0;

    monster_truck rc;

    string available_headings = "NESW";
    char heading_char; // Used to fetch user input
    string commands;

    bool success=true; // Set to false if the car runs into a wall

    // Ask the user for the size of the room
    cout << "Please enter the width and heigh of the room separated by a space. No decimals." << endl;
    do
    {
        cin >> width >> height;
        if( cin.fail() )
        {
            cout << "Your input was unacceptable. Try again!" << endl;
        }
        cin.clear();
        cin.ignore(1000, '\n');
    } while(width==0 || height==0);

    cout << "Your room is " << width << "x" << height <<" meters." << endl;

    // Ask about starting position and heading of the car
    cout << "Please enter the starting position and heading of the car \"X Y H\" " << endl
        << "X and Y is whole meters between car edge and west/south wall. " << endl
        << "H is heading N, E, W or S" << endl;
    do
    {
        cin >> rc.x >> rc.y >> heading_char;
        if( cin.fail() )
        {
            cout << "Your input was unacceptable. Try again!" << endl;
        }
        else if(rc.x<0 || rc.x>width-1 || rc.y<0 || rc.y>height-1)
        {
            cout << "Coordinates out of bounds. Try again!" << endl;
        }
        else
        {
            // See if the heading entered is valid and assign it to rc
            rc.current_heading=-1;
            for(i=0; i<available_headings.length(); i++)
            {
                if(available_headings.at(i)==heading_char)
                {
                    rc.current_heading=i;
                }
            }
            if(rc.current_heading==-1)
            {
                cout << "Invalid heading. Try again!" << endl;
            }
        }
        
        cin.clear();
        cin.ignore(1000, '\n');
    } while(rc.x<0 || rc.x>width-1 || rc.y<0 || rc.y>height-1 || rc.current_heading==-1);

    cout << "Current position is (X Y H): " << rc.x << " " << rc.y << " " << available_headings[rc.current_heading] << endl;

    // Ask user for commands to perform
    cout << "Enter commands to simulate. Available commands are F, B, L or R (Forward, Back, rotate Left, rotate Right)." << endl
        << "Other characters will be ignored." << endl;
    do
    {
        commands="";
        getline(cin,commands);
        if( cin.fail() )
        {
            cout << "Is it even possible to fail at entering a string? Seriously, I don't know. Try again!" << endl;
        }
    } while(commands.length()<1);

    // Simulate each command. Fail will print a message what went wrong on the screen
    for(i=0; i<commands.length(); i++)
    {
        if(false==rc.perform_single_command(commands.at(i), width, height, available_headings))
        {
            success=false;
            break;
        }
    }

    // print results
    if(success)
    {
        cout << "Commands simulated successfully.";
    }
    else
    {
        cout << rc.error;
    }
    cout << " End position was (X Y H): " << rc.x << " " << rc.y << " " << available_headings[rc.current_heading] 
        << " after " << rc.steps << " steps " 
        << " and " << rc.turns << " turns " 
        << endl;

    // Wait for key press before exiting
    system("pause");
    return 0;
}