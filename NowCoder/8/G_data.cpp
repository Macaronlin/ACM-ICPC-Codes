#include <bits/stdc++.h>

using namespace std;

string s[4][4] = {
    {"one", "two", "three", "*"},
    {"diamond", "squiggle", "oval", "*"},
    {"solid", "striped", "open", "*"},
    {"red", "green", "purple", "*"}
};

int main() {
    freopen("G.in", "w", stdout);
    srand(time(0));
    int T = 100; cout << T << '\n';
    while (T--) {
        int n = 256; cout << n << '\n';
        while (n--) {
            for (int i = 0; i < 4; i++) {
                cout << "[";
                cout << s[i][rand() % 3] << "]";
            }
            cout << '\n';
        }
    }
    return 0;
}