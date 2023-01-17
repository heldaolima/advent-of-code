#include <iostream>
#include <vector>
#include <string>

using namespace std;

typedef long long int lli;

enum {
    l, w, h
};

int size(int s1, int s2, int* min)
{
    int ans = s1 * s2;
    
    if (ans < (*min)) {
        *min = ans;
    }

    return ans * 2;
}

lli parse(string dimensions)
{
    string curr_num = "";
    vector<int> dims;
    int j = 0, i = 0;
    int min = 0, tot = 0;

    for (j = 0; j < dimensions.size(); j++) {
        if (i <= 1) {
            if (dimensions[j] != 'x') {
                curr_num += dimensions[j];
            }
            else {
                dims.push_back(stoi(curr_num));
                i++;
                curr_num = "";
            }
        }
        else {
            curr_num += dimensions[j];
        }
    }
    dims.push_back(stoi(curr_num));

    tot += dims[l] * dims[w];
    min = tot;
    tot *= 2;

    tot += size(dims[w], dims[h], &min);
    tot += size(dims[h], dims[l], &min);
    return tot + min;
}

int main()
{
    string current;
    lli result = 0;

    while (getline(cin, current)) {
        result += parse(current);
    }

    cout << result << "\n";

    return 0;
}