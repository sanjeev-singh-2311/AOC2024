#include <bits/stdc++.h>
using namespace std;

int checkRight(vector<string>& GRID, int i, int j) {
    string temp = "XMAS";
    for (int r = j; r < j + 4; r++) {
        if (r >= GRID[i].size())
            return 0;
        if (GRID[i][r] != temp[r - j])
            return 0;
    }
    return 1;
}
int checkLeft(vector<string>& GRID, int i, int j) {
    string temp = "XMAS";
    for (int r = j; r > j - 4; r--) {
        if (r < 0)
            return 0;
        if (GRID[i][r] != temp[j - r])
            return 0;
    }
    return 1;
}
int checkUp(vector<string>& GRID, int i, int j) {
    string temp = "XMAS";
    for (int r = i; r > i - 4; r--) {
        if (r < 0)
            return 0;
        if (GRID[r][j] != temp[i - r])
            return 0;
    }
    return 1;
}
int checkDown(vector<string>& GRID, int i, int j) {
    string temp = "XMAS";
    for (int r = i; r < i + 4; r++) {
        if (r >= GRID.size())
            return 0;
        if (GRID[r][j] != temp[r - i])
            return 0;
    }
    return 1;
}
int checkDiagonals(vector<string>& GRID, int i, int j) {
    string temp = "XMAS";
    int d1 = 1, d2 = 1, d3 = 1, d4 = 1;
    for (int r = 0; r < 4; r++) {
        if (i + r >= GRID.size() || j + r >= GRID[0].size() || GRID[i + r][j + r] != temp[r]) {
            d1 = 0;
            break;
        }
    }
    for (int r = 0; r < 4; r++) {
        if (i - r < 0 || j - r < 0 || GRID[i - r][j - r] != temp[r]) {
            d2 = 0;
            break;
        }
    }
    for (int r = 0; r < 4; r++) {
        if (i - r < 0 || j + r >= GRID[0].size() || GRID[i - r][j + r] != temp[r]) {
            d3 = 0;
            break;
        }
    }
    for (int r = 0; r < 4; r++) {
        if (i + r >= GRID.size() || j - r < 0 || GRID[i + r][j - r] != temp[r]) {
            d4 = 0;
            break;
        }
    }
    return d1 + d2 + d3 + d4;
}

int checkXMAS(vector<string>& GRID, int i, int j) {
    int a = checkRight(GRID, i, j);
    int b = checkLeft(GRID, i, j);
    int c = checkUp(GRID, i, j);
    int d = checkDown(GRID, i, j);
    int e = checkDiagonals(GRID, i, j);
    // int e = 0;

    return a + b + c + d + e;
}

int main() {
    vector<string> GRID;
    string S;
    while (cin >> S) {
        GRID.push_back(S);
    }
    int m = GRID.size(), n = GRID[0].size();

    long long res = 0;

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (GRID[i][j] == 'X')
                res += checkXMAS(GRID, i, j);
        }
    }

    cout << res << endl;
}
