#include <string>
#include <iostream>

using namespace std;

class car {
    public:
        // variables for the car position and heading
        int x;
        int y;
        int steps=0;
        int turns=0;
        
        /*  We use integer for easier rotation. 
            0 represents N
            1 represents E
            2 represents S
            3 represents W
        */
        int current_heading; 
        string error;
};

class monster_truck : public car
{
    public:
        bool perform_single_command(char command, int room_width, int room_height, string available_headings)
        {
            int new_x=this->x;
            int new_y=this->y;

            switch(command)
            {
                case 'R': // Rotate right
                    this->current_heading=(this->current_heading+1)%4;
                    turns++;
                    break;
                case 'L': // Rotate left
                    this->current_heading=(this->current_heading+3)%4;
                    turns++;
                    break;
                case 'F': // Forward
                case 'B': // Back
                    if((command=='F' && this->current_heading==0) || (command=='B' && this->current_heading==2))
                        new_y++;
                    else if((command=='F' && this->current_heading==2) || (command=='B' && this->current_heading==0))
                        new_y--;
                    else if((command=='F' && this->current_heading==1) || (command=='B' && this->current_heading==3))
                        new_x++;
                    else if((command=='F' && this->current_heading==3) || (command=='B' && this->current_heading==1))
                        new_x--;
                    steps++;
                    break;
                default:
                    break;
            }

            if(new_x<0)
            {
                this->error = "Ran into the west wall.";
                return false;
            }
            if(new_x>=room_width)
            {
                this->error = "Ran into the east wall.";
                return false;
            }
            if(new_y<0)
            {
                this->error = "Ran into the south wall.";
                return false;
            }
            if(new_y>=room_height)
            {
                this->error = "Ran into the north wall.";
                return false;
            }

            this->x=new_x;
            this->y=new_y;
            return true;
        }
};
