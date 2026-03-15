#include <string>
using namespace std;

class Robot {
private:
    int x, y;
    string direction;

public:
    Robot(int x, int y, string direction) {
        this->x = x;
        this->y = y;
        this->direction = direction;
    }

    void turnRight() {
        if (direction == "north") direction = "east";
        else if (direction == "east") direction = "south";
        else if (direction == "south") direction = "west";
        else if (direction == "west") direction = "north";
    }

    void turnLeft() {
        if (direction == "north") direction = "west";
        else if (direction == "west") direction = "south";
        else if (direction == "south") direction = "east";
        else if (direction == "east") direction = "north";
    }

    void advance() {
        if (direction == "north") y++;
        else if (direction == "south") y--;
        else if (direction == "east") x++;
        else if (direction == "west") x--;
    }

    void execute(string instructions) {
        for (char c : instructions) {
            if (c == 'R') turnRight();
            else if (c == 'L') turnLeft();
            else if (c == 'A') advance();
        }
    }

    int getX() { return x; }
    int getY() { return y; }
    string getDirection() { return direction; }
};