#include <bits/stdc++.h>

using namespace std;

int main() {
    freopen("I.in", "w", stdout);
    srand(time(0));
    int T = 2; cout << T << '\n';
    while (T--) {
        int n = 100000; cout << n << '\n';
        while (n--) {
            cout << (rand() * rand() % 100000 + 100000) % 100000 + 1 << ' ';
            cout << (rand() * rand() % 100000 + 100000) % 100000 + 1 << '\n';
        }
    }
    return 0;
}