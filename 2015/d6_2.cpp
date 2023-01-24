#include <iostream>
#include <string>
#include <vector>

#define lines 1000
#define cols lines

using namespace std;

enum instruct {
    toggle,
    turn_off,
    turn_on
};

enum indexes {
    from_i,
    from_j,
    to_i,
    to_j
};


bool is_eq(string s1, string s2);
#define is_eq(s1, s2) ((s1).compare(s2) == 0)

void get_nums(string instruction, int *i, vector<int> *vec, int from) {
    string command = "";
    while (!isspace(instruction[*i])) {
        //split on ','
        if (instruction[*i] == ',') {
            vec->at(from) = stoi(command);
            command = "";
        } else {
            command += instruction[*i];
        }
        (*i)++;

        // will happen in with the second pair of numbers
        if (*i == instruction.length()) {
            break;
        }
    }
    vec->at(from+1) = stoi(command);
}

vector<int> parse(string instruction, int *i)
{
    // get range
    vector<int> numbers(4);

    // get from_i and from_j
    get_nums(instruction, i, &numbers, 0);
    
    // ignore word 'through' and spaces
    do {
        (*i)++;
    } while (!isdigit(instruction[*i]));
    
    // get to_i and to_j
    get_nums(instruction, i, &numbers, 2);

    return numbers;
}

void lights(int grid[][cols], string instruction) 
{
    enum instruct inst;
    string command = "";
    int i = 0, j = 0;
    // get instruction
    for (i = 0; !isdigit(instruction[i]); i++) {
        command += instruction[i];
    }

    if (is_eq(command, "toggle "))
        inst = toggle;
    else if (is_eq(command, "turn off "))
        inst = turn_off;
    else if (is_eq(command, "turn on "))
        inst = turn_on;
    else {
        cout << "did not recognize instruction\n";
        exit(1);
    }

    vector<int> nums = parse(instruction, &i);

    for (i = nums[from_i]; i <= nums[to_i]; i++) {
        for (j = nums[from_j]; j <= nums[to_j]; j++) {
            switch(inst) {
                case turn_on:
                    grid[i][j]++;
                    break;
                case turn_off:
                    if (grid[i][j] > 0) grid[i][j]--;
                    break;
                case toggle:
                    grid[i][j] += 2;
                    break;
                default: break;
            }
        }
    }

}

int main()
{
    unsigned int count = 0, i = 0, j = 0;
    string instruction;
    int grid[lines][cols];

    // initialize
    for (i = 0; i < lines; i++) {
        for (j = 0; j < cols; j++) {
            grid[i][j] = 0;
        }
    }

    while (getline(cin, instruction)) {
        lights(grid, instruction);
    }

    for (i = 0; i < lines; i++) {
        for (j = 0; j < cols; j++) {
            count += grid[i][j];
        }
    }

    cout << count << "\n";

    return 0;
}