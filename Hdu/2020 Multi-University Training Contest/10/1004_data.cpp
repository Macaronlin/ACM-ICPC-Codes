#include <bits/stdc++.h>

using namespace std; 

int main() {
    freopen("1004.in", "w", stdout);
    cout << 1 << '\n';
    cout << 500 << '\n';
    for (int i = 1; i < 500; i++) {
        cout << (i & 1) << ' ';
    }
    return 0;
}