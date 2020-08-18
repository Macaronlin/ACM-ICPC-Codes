#include <bits/stdc++.h>

using namespace std; 

int main() {
    freopen("1007.in", "w", stdout);
    cout << 1 << '\n';
    int n = 2e5, q = 2e5;   cout << n << ' ' << q << '\n';
    for (int i = 1; i <= n; i++)    cout << rand() % 10000 + 1 << ' ';
    cout << '\n';
    for (int i = 1; i <= q; i++) {
        int opt = rand() % 2 + 1;   cout << opt << ' ';
        if (opt == 1)   cout << rand() % n + 1 << ' ' << rand() % 10000 + 1 << '\n';
        else    cout << rand() % n + 1 << '\n';
    }
    return 0;
}