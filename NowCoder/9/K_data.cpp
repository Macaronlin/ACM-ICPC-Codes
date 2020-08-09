#include <bits/stdc++.h>

using namespace std;

int main() {
    srand(time(0));
    freopen("K.in", "w", stdout);
    int n = 100000;
    cout << n << ' ' << 0 << '\n';
    for (int i = 1; i < n; i++) {
        cout << 2 << ' ' << (i + 1 == 2 ? 1 : i + 1) << '\n';
    }
    return 0;
}