#include <bits/stdc++.h>
using namespace std;

bool checkDec(vector<int> V) {
    int l = V[0] - 1, r = V[0] - 3;
    for (int i = 1; i < V.size(); i++) {
        if (!(V[i] >= r && V[i] <= l))
            return false;
        l = V[i] - 1, r = V[i] - 3;
    }
    return true;
}
bool checkInc(vector<int> V) {
    int l = V[0] + 1, r = V[0] + 3;
    for (int i = 1; i < V.size(); i++) {
        if (!(V[i] >= l && V[i] <= r))
            return false;
        l = V[i] + 1, r = V[i] + 3;
    }
    return true;
}

bool checkValid(vector<int> V) {
    if (V.size() <= 1)
        return true;

    if (V[0] > V[1])
        return checkDec(V);
    else if (V[0] < V[1])
        return checkInc(V);

    return false;
}

int main() {
    ifstream f("./input2.txt");

    vector<vector<int>> V;
    string S;

    while (getline(f, S)) {
        vector<int> row;
        istringstream s(S);
        int num;
        while (s >> num)
            row.push_back(num);
        V.push_back(row);
    }

    cout << checkInc({1, 3, 6, 7, 9}) << endl;

    int ctr = 0;
    for (vector<int> row : V) {
        if (checkValid(row)) {
            ctr++;
            continue;
        }
        for (int i = 0; i < row.size(); i++) {
            vector<int> temp;
            for (int k = 0; k < row.size(); k++) {
                if (k != i)
                    temp.push_back(row[k]);
            }
            if (checkValid(temp)) {
                ctr++;
                break;
            }
        }
    }

    cout << ctr << endl;
}
