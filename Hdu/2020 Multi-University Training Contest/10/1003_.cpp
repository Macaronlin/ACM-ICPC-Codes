#include <bits/stdc++.h>

using namespace std;

int n, m;
int dx[] = {0, 0, 1, -1, 1, 1, -1, -1};
int dy[] = {1, -1, 0, 0, 1, -1, 1, -1};
char a[123][123];

int calc() {
    int res = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (a[i][j] == '.') {
                for (int k = 0; k < 8; k++) {
                    int x = i + dx[k], y = j + dy[k];
                    if (x >= 1 && x <= n && y >= 1 && y <= m) {
                        if (a[x][y] == 'X') {
                            res++;
                        }
                    }
                }
            }
        }
    }
    return res;
}

int main() {
    freopen("1003.out", "r", stdin);
    freopen("100.out", "w", stdout);
    for (int t = 0; t <= 1000; t++) {
        memset(a, 0, sizeof(a));
        cin >> n >> m;
        for (int i = 1; i <= n; i++) {
            cin >> (a[i] + 1);
        }
        if (t != calc()) {
            cout << t << '\n';
        }
    }
#ifndef ONLINE_JUDGE
    system("pause");
#endif
    return 0;
}