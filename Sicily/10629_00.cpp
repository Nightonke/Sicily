// Problem#: 10629
// Submission#: 2808569
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <stdio.h>
struct Position {
         int x;
         int y;
};

class Robot {
public:
         Robot();                           /* default constructor, initialize at (0,0) */
         Robot(Position pos);     /* initialize at pos */
         void Move(char Dir);     /* Dir could be 'N', 'E', 'S', 'W', for other characters, the robot don’t move */
         Position GetPosition();        /* return current position */
private:
         Position currentPos;
};

Robot::Robot(Position pos) {
    currentPos.x = pos.x;
    currentPos.y = pos.y;
}

void Robot::Move(char Dir) {
    if (Dir == 'N') {
        currentPos.y++;
    } else if (Dir == 'E') {
        currentPos.x++;
    } else if (Dir == 'S') {
        currentPos.y--;
    } else if (Dir == 'W') {
        currentPos.x--;
    } else {
        return;
    }
}

Position Robot::GetPosition() {
    return currentPos;
}

int main() {
}                                 