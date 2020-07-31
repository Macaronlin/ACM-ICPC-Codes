#include <bits/stdc++.h>

using namespace std; 

int main() {
    freopen("1003.in", "w", stdout);
    int T = 10; cout << T << endl;
    while (T--) {
        int n = 1000, m = 1000; cout << n << ' ' << m << endl;
        for (int i = 1; i <= n; i++)    cout << rand() % 1000 + 1 << ' ' << rand() % 1000 + 1 << endl;
        for (int i = 1; i <= m; i++)    cout << rand() % 1000 + 1 << ' ' << rand() % 1000 + 1 << endl;
    }
    return 0;
}