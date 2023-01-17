#include <iostream>

using namespace std;

int main()
{
    char ch = '\0';
    int floor = 0, i = 1;

    while (scanf("%c", &ch) != EOF) {
        if (ch == '(') 
            floor++;

        else if (ch == ')') 
            floor--;
        
        if (floor == -1)
            break;

        i++;
    }   

    cout << i << "\n";

    return 0;
}