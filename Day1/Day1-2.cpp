#include <bits/stdc++.h>
using namespace std;

int main() {
    ifstream f("./Day1-1.txt");

    vector<int> A;
    vector<int> B;
    map<int, int> Bcount;

    string s;

    while (getline(f, s)) {
        int i = 0;
        while (s[i] != ' ')
            i++;
        A.push_back(stoi(s.substr(0, i)));
        while (s[i] == ' ')
            i++;
        B.push_back(stoi(s.substr(i, s.size())));
        Bcount[B[B.size() - 1]]++;
    }

    long long res = 0;
    for (int i = 0; i < A.size(); i++) {
        res += A[i] * Bcount[A[i]];
    }

    cout << res << endl;
}
