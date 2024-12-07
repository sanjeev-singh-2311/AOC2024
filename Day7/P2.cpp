#include <bits/stdc++.h>
using namespace std;

bool isValid(vector<long long>& nums, long long target, long long curr, int i) {
    if (i == nums.size())
        return target == curr;
    if (target < curr)
        return false;

    return isValid(nums, target, (curr == -1) ? nums[i] : nums[i] + curr, i + 1) ||
           isValid(nums, target, (curr == -1) ? nums[i] : nums[i] * curr, i + 1) ||
           isValid(nums,
                   target,
                   (curr == -1) ? nums[i] : stoll(to_string(curr) + to_string(nums[i])),
                   i + 1);
}

int main() {
    string S;
    long long res = 0;
    while (getline(cin, S)) {
        long long needed = 0;
        vector<long long> V;
        int i = 0;
        while (isdigit(S[i])) {
            needed = needed * 10 + (S[i] - '0');
            i++;
        }
        long long a = 0;
        while (i < S.size()) {
            if (S[i] == ':')
                i += 2;
            if (isdigit(S[i])) {
                a = a * 10 + (S[i] - '0');
            } else {
                V.push_back(a);
                a = 0;
            }
            i++;
        }
        V.push_back(a);
        cout << needed << " -> ";
        for (int i : V)
            cout << i << " ";
        cout << endl;
        if (isValid(V, needed, -1, 0))
            res += needed;
    }
    vector<long long> V = {6, 8, 6, 15};
    cout << isValid(V, 7290, -1, 0) << endl;
    cout << res << endl;
}
