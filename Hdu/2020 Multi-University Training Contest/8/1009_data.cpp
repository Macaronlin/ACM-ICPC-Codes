#include <bits/stdc++.h>

using namespace std; 

int main() {
    
    int T = 5;  cout << T << '\n';
    while (T--) {
        int n = 5000000;
        cout << n << '\n';
        for (int i = 1; i <= n; i++) {
            putchar(char(rand() % 26 + 'a'));
        }  putchar('\n');
    }
#ifndef ONLINE_JUDGE
    system("pause");
#endif
    return 0;
}