#include <bits/stdc++.h>

using namespace std; 

int main() {
    srand(time(0));
    freopen("C.in", "w", stdout);
    int T = 5;  cout << T << '\n';
    while (T--) {
        int n = 50000, m = 50000;   cout << n << ' ' << m << '\n';
        int id = 0;
        for (int i = 2; i <= n; i++) {
            int fa = rand() % (i - 1) + 1;
            cout << i << ' ' << fa << '\n';
        }
        for (int i = 1; i <= m; i++) {
            // int opt = i % 3 + 1;
            // int opt = rand() % 2;
            int opt = i % 2;
            opt = opt * 2 + 1;
            cout << opt << ' ';
            if (opt == 1) {
                // cout << rand() % n + 1 << ' ' << rand() % 1000000 + 1 << '\n';
                id = id % n + 1;
                cout << id << ' ' << rand() % 1000000 + 1 << '\n';
            }
            else    cout << rand() % n + 1 << '\n';
        }
    }
    return 0;
}