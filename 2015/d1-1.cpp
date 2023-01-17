#include <iostream>

using namespace std;

int main()
{
    char ch = '\0';
    int floor = 0;

    while (scanf("%c", &ch) != EOF) {
        if (ch == '(') 
            floor++;

        else if (ch == ')') 
            floor--;
    }   

    cout << floor << "\n";

    return 0;
}