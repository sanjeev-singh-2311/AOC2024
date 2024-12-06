#include <bits/stdc++.h>
using namespace std;

bool isLooping(vector<string> GRID, int obX, int obY, int currX, int currY) {
    int m = GRID.size(), n = GRID[0].size();
    GRID[obX][obY] = '#';

    vector<pair<int, int>> velo = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
    int dir                     = 0;
    int veloX = velo[dir].first, veloY = velo[dir].second;
    vector<vector<unordered_set<int>>> visited(m,
                                               vector<unordered_set<int>>(n, unordered_set<int>()));

    while (currX >= 0 && currY >= 0 && currX < m && currY < n) {
        auto check = visited[currX][currY];
        if (check.find(dir) != check.end())
            return true;
        visited[currX][currY].insert(dir);
        currX += veloX;
        currY += veloY;
        if (currX >= 0 && currY >= 0 && currX < m && currY < n && GRID[currX][currY] == '#') {
            visited[currX][currY].erase(dir);
            currX -= veloX;
            currY -= veloY;
            dir   = (dir + 1) % 4;
            veloX = velo[dir].first, veloY = velo[dir].second;
        }
    }
    return false;
}

vector<string> makePath(vector<string> GRID, int currX, int currY) {
    int m = GRID.size(), n = GRID[0].size();
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
    return GRID;
}

int main() {
    vector<string> GRID;
    string S;
    while (cin >> S)
        GRID.push_back(S);
    int m = GRID.size(), n = GRID[0].size();
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++)
            cout << GRID[i][j];
        cout << endl;
    }

    int currX = 0, currY = 0;
    while (currX < m) {
        currY = 0;
        while (currY < n) {
            if (GRID[currX][currY] == '^')
                break;
            currY++;
        }
        if (currY < n && GRID[currX][currY] == '^')
            break;
        currX++;
    }
    vector<string> PATH = makePath(GRID, currX, currY);
    long long res       = 0;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (PATH[i][j] != 'X')
                continue;
            cout << i << " " << j << endl;
            if (i == currX && j == currY)
                continue;
            if (isLooping(GRID, i, j, currX, currY)) {
                cout << i << " " << j << endl;
                res++;
            }
        }
    }
    cout << res << endl;
}
