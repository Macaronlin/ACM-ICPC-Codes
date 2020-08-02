#include <bits/stdc++.h>

using namespace std;

set <int> ans[26], loc[26][26];

int main() {
    int T;  cin >> T;
    vector <pair<string, string>> vec;
    while (T--) {
        string s, t, _; cin >> s >> _ >> t;
        if ((int)s.size() == 1 && (int)t.size() == 1 && t[0] >= 'a' && t[0] <= 'z') ans[s[0] - 'A'].insert(t[0] - 'a');
        else {
            if ((int)s.size() == 1) {
                if ((int)t.size() == 1) {
                    for (auto c : ans[t[0] - 'A']) {
                        ans[s[0] - 'A'].insert(c);
                    }
                }
                else {
                    for (auto c : ans[t[0] - 'A']) {
                        for (auto _c : loc[c][t[2] - 'a']) {
                            ans[s[0] - 'A'].insert(_c);
                        }
                    }
                }
            }
            else {
                for (auto c : ans[s[0] - 'A']) {
                    for (auto _c : ans[t[0] - 'a']) {
                        loc[c][s[2] - 'A'].insert(_c);
                    }
                }
            }
            vec.push_back({s, t});
        }
    }
    reverse(vec.begin(), vec.end());
    for (auto opt : vec) {
        string s = opt.first, t = opt.second;
        if ((int)s.size() == 1) {
            if ((int)t.size() == 1) {
                for (auto c : ans[t[0] - 'A']) {
                    ans[s[0] - 'A'].insert(c);
                }
            }
            else {
                for (auto c : ans[t[0] - 'A']) {
                    for (auto _c : loc[c][t[2] - 'a']) {
                        ans[s[0] - 'A'].insert(_c);
                    }
                }
            }
        }
        else {
            for (auto c : ans[s[0] - 'A']) {
                for (auto _c : ans[t[0] - 'a']) {
                    loc[c][s[2] - 'A'].insert(_c);
                }
            }
        }
    }
    for (int i = 0; i < 26; i++) {
        cout << (char)(i + 'A') << ": ";
        for (auto c : ans[i]) {
            cout << (char)(c + 'a');
        } cout << '\n';
    }
#ifndef ONLINE_JUDGE
    system("pause");
#endif
    return 0;
    
}