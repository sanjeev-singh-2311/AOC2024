#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<string> GRID;
    string S;
    while (cin >> S)
        GRID.push_back(S);
    int m = GRID.size(), n = GRID[0].size();

    int currX = 0, currY = 0;
    while (currX < m) {
        currY = 0;
        while (currY < n) {
            if (GRID[currX][currY] == '^')
                break;
            currY++;
        }
        if (GRID[currX][currY] == '^')
            break;
        currX++;
    }
    vector<pair<int, int>> velo = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
    int dir                     = 0;
    int veloX = velo[dir].first, veloY = velo[dir].second;
    while (currX < m && currY < n) {
        GRID[currX][currY] = 'X';
        currX += veloX;
        currY += veloY;
        if (currX < m && currY < n && GRID[currX][currY] == '#') {
            currX -= veloX;
            currY -= veloY;
            dir   = (dir + 1) % 4;
            veloX = velo[dir].first, veloY = velo[dir].second;
        }
    }
    long long res = 0;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cout << GRID[i][j];
            if (GRID[i][j] == 'X')
                res++;
        }
        cout << endl;
    }
    cout << res << endl;
}
