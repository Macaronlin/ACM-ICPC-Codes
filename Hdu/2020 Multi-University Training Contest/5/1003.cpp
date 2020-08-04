#include <bits/stdc++.h>

using namespace std; 

const int N = 2000 + 10;
int a[N][N], dx[N], id;
void dfs(int L, int R, int len) {
    if (L >= R) {
        if (L == R) {
            dx[L] = len;
        }
        return;
    }
    int M = L + (R - L) / 2;
    dx[M] = len;
    dfs(L, M - 1, len + 1);
    dfs(M + 1, R, len + 1);
}
void up(int col, int n) {
    for (int i = n; i >= 1; i--) {
        a[i][col] = ++id;
    }
}
void down(int col, int n) {
    for (int i = 1; i <= n; i++) {
        a[i][col] = ++id;
    }
}
int calc(int pos, int len) {
    int _pos = (pos - 1) % len + 1;
    _pos = len - _pos + 1;
    return (pos - 1) / len * len + _pos;
}
int p[N * N], p1[N * N], p2[N * N];
int main() {
    int T;  scanf("%d", &T);
    while (T--) {
        int n, k;   scanf("%d  %d", &n, &k);
        dfs(1, (1 << k) - 1, 1);
        id = 0;
        int pos = (1 << k) - 1;
        for (int i = 1, j = 1; i <= (1 << k); i++, j ^= 1) {
            if (j)  up(pos, 2 * n);
            else    down(pos, 2 * n);
            pos = calc(pos, 1 << dx[i]);
        }
        // for (int i = 1; i <= 2 * n; i++) {
        //     for (int j = 1; j <= (1 << k); j++) {
        //         cout << a[i][j] << ' ';
        //     } cout << "\n";
        // } cout << "\n";
        id = 0;
        for (int i = 1; i <= 2 * n; i++) {
            for (int j = 1; j <= (1 << k); j++) {
                p[++id] = a[i][j];
                scanf("%d", &p1[id]);
            }
        }
        id = 0;
        vector <int> ans;
        for (int i = 1; i <= 2 * n; i++) {
            for (int j = 1; j <= (1 << k); j++) {
                ++id;
                p2[id] = p1[p[id]];
                ans.push_back(p2[id]);
            }
        }
        for (int i = 0; i < (int)ans.size(); i++) {
            printf("%d%c", ans[i], "\n "[i < (int)ans.size() - 1]);
        }
    }
#ifndef ONLINE_JUDGE
    system("pause");
#endif
    return 0;
}