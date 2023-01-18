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
    char ch = '\0';
    
    coord current = { 0, 0 };
    
    vector<coord> visited = {current};

    while (scanf("%c", &ch) != EOF) {
        // printf("%c\t", ch);
        switch (ch)
        {
        case north:
            current.x++;
            break;
        case south:
            current.x--;
            break;
        case east:
            current.y++;
            break;
        case west:
            current.y--;
            break;
        default:
            break;
        }

        if (!already_there(visited, current)) {
            visited.push_back(current);
        }
    }

    cout << visited.size() << "\n";

    return 0;
}