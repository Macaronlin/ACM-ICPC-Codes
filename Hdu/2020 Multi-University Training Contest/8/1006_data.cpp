#include <bits/stdc++.h>

using namespace std; 

int main() {
    srand(time(0));
    int n = 5, k = rand() % 5 + 1;
    cout << n << ' ' << k << '\n';
    for (int i = 1; i <= 5; i++) {
        int x = rand() % 10 + 1, y = rand() % 10 + 1;
        if (x > y)  swap(x, y);
        cout << x << ' ' << y << '\n';
    }
#ifndef ONLINE_JUDGE
    system("pause");
#endif
    return 0;
}