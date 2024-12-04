#include <bits/stdc++.h>
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

long long makeCalc(string S) {

    long long res = 0;

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

    return res;
}

int main() {
    string S = "";

    string temp;
    long long res = 0;

    while (getline(cin, temp))
        S += "M" + temp;

    cout << S << endl;

    int enables = true;
    string sta  = "";
    for (int i = 0; i < S.size(); i++) {
        if (S[i] == 'd') {
            string poss1 = S.substr(i, 4);
            string poss2 = S.substr(i, 7);
            if (enables && poss2 == "don't()") {
                enables = false;
                res += makeCalc(sta);
                sta = "";
            } else if (!enables && poss1 == "do()") {
                enables = true;
            }
        }
        if (enables)
            sta += S[i];
    }

    cout << res << endl;
}
