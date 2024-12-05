#include <bits/stdc++.h>
using namespace std;

int main() {
    unordered_map<int, pair<unordered_set<int>, unordered_set<int>>> M;
    string S;
    while (cin >> S) {
        if (S[2] != '|')
            break;
        string a = "", b = "";
        int i = 0;
        while (isdigit(S[i]))
            a.push_back(S[i++]);
        i++;
        while (isdigit(S[i]))
            b.push_back(S[i++]);

        M[stoi(b)].first.insert(stoi(a));
        M[stoi(a)].second.insert(stoi(b));
    }

    long long res = 0;
    do {
        vector<int> V;
        string a = "";
        for (int i = 0; i < S.size(); i++) {
            if (S[i] == ',') {
                V.push_back(stoi(a));
                a = "";
                continue;
            }
            a.push_back(S[i]);
        }
        V.push_back(stoi(a));

        bool isValid = true;
        for (int i = 0; i < V.size(); i++) {
            auto entry = M[V[i]];
            for (int j = i - 1; j >= 0; j--) {
                if (entry.second.find(V[j]) != entry.second.end()) {
                    isValid = false;
                    break;
                }
            }
            if (!isValid)
                break;
            for (int j = i + 1; j < V.size(); j++) {
                if (entry.first.find(V[j]) != entry.first.end()) {
                    isValid = false;
                    break;
                }
            }
            if (!isValid)
                break;
        }
        if (isValid)
            res += V[V.size() / 2];
    } while (cin >> S);
    cout << res << endl;
}
