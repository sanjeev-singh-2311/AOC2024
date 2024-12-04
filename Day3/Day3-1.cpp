#include <bits/stdc++.h>
#include <regex>
using namespace std;

int calculate(string s) {
    int d1 = 0, d2 = 0;
    int l = 0;
    while (!isdigit(s[l]))
        l++;
    while (isdigit(s[l])) {
        d1 = d1 * 10 + (s[l] - '0');
        l++;
    }
    while (!isdigit(s[l]))
        l++;
    while (isdigit(s[l])) {
        d2 = d2 * 10 + (s[l] - '0');
        l++;
    }
    return d1 * d2;
}

int main() {
    string S;

    long long res = 0;
    while (getline(cin, S)) {

        regex pat("mul\\(\\d{1,3}\\,\\d{1,3}\\)");

        for (int i = 0; i < S.size(); i++) {
            if (S[i] != 'm')
                continue;
            int j = i + 1;
            while (j < S.size() && S[j] != ')')
                j++;

            string sub = S.substr(i, j - i + 1);
            if (!regex_match(sub, pat)) {
                continue;
            }

            int dl = 0;
            while (!(sub[dl] != '('))
                dl++;
            res += calculate(sub);
        }
    }

    cout << res << endl;
}
