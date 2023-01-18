#include <iostream>
#include <vector>

#define north '^'
#define south 'v'
#define east '>'
#define west '<'

using namespace std;

typedef struct coord {
    int x;
    int y;
} coord;

bool already_there(vector<coord> coords, coord curr)
{
    for (auto coord: coords) {
        if (coord.x == curr.x && coord.y == curr.y) {
            return true;
        }
    }
    return false;
}

int main()
{
    char ch_noel = '\0', ch_robot = '\0';
    
    coord current_noel = { 0, 0 }, current_robot = { 0, 0 };
    
    vector<coord> visited = {current_noel};

    while (scanf("%c%c", &ch_noel, &ch_robot) != EOF) {
        switch (ch_noel)
        {
        case north:
            current_noel.x++;
            break;
        case south:
            current_noel.x--;
            break;
        case east:
            current_noel.y++;
            break;
        case west:
            current_noel.y--;
            break;
        default:
            break;
        }

        switch (ch_robot)
        {
        case north:
            current_robot.x++;
            break;
        case south:
            current_robot.x--;
            break;
        case east:
            current_robot.y++;
            break;
        case west:
            current_robot.y--;
            break;
        default:
            break;
        }

        if (!already_there(visited, current_noel)) {
            visited.push_back(current_noel);
        }

        if (!already_there(visited, current_robot)) {
            visited.push_back(current_robot);
        }
    }

    cout << visited.size() << "\n";

    return 0;
}