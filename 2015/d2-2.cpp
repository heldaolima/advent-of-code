#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

typedef long long int lli;

int vol(vector<int> vec)
{
    int ans = 1;
    for (auto val : vec)
        ans *= val;
    return ans;
}

lli parse(string dimensions)
{
    string curr_num = "";
    vector<int> dims;
    int j = 0, i = 0;

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
    sort(dims.begin(), dims.end());

    return ((dims[0]*2) + dims[1]*2) + vol(dims);
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