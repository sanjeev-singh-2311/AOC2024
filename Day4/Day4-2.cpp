#include <bits/stdc++.h>
using namespace std;

int checkCross(vector<string>& GRID, int i, int j) {

    if (i == 0 || i == GRID.size() - 1 || j == 0 || j == GRID[0].size() - 1)
        return 0;
    int d1 = 1, d2 = 1, d3 = 1, d4 = 1;
    string temp = "MAS";
    for (int r = 0; r < 3; r++) {
        if ((i - 1 + r) >= GRID.size() || (j - 1 + r) >= GRID[0].size() ||
            GRID[i - 1 + r][j - 1 + r] != temp[r]) {
            d1 = 0;
            break;
        }
    }
    for (int r = 0; r < 3; r++) {
        if ((i + 1 - r) < 0 || (j + 1 - r) < 0 || GRID[i + 1 - r][j + 1 - r] != temp[r]) {
            d2 = 0;
            break;
        }
    }
    for (int r = 0; r < 3; r++) {
        if ((i - 1 + r) >= GRID.size() || (j + 1 - r) < 0 ||
            GRID[i - 1 + r][j + 1 - r] != temp[r]) {
            d3 = 0;
            break;
        }
    }
    for (int r = 0; r < 3; r++) {
        if ((i + 1 - r) < 0 || (j - 1 + r) >= GRID[0].size() ||
            GRID[i + 1 - r][j - 1 + r] != temp[r]) {
            d4 = 0;
            break;
        }
    }
    int cross1 = (d1 | d2) ? 1 : 0;
    int cross2 = (d3 | d4) ? 1 : 0;
    return cross1 & cross2;
}

int main() {
    vector<string> GRID;
    string S;
    while (cin >> S)
        GRID.push_back(S);

    int m = GRID.size(), n = GRID[0].size();

    long long res = 0;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (GRID[i][j] == 'A')
                res += checkCross(GRID, i, j);
        }
    }

    cout << res << endl;
}
