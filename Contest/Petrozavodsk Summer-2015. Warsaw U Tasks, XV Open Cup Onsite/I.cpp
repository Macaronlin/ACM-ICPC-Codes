#include <bits/stdc++.h>

using namespace std; 

const int N = 1000 + 10;
int pic[N][N], pic2[N][N];
char s[N];

int main() {
    int T;  scanf("%d", &T);
    while (T--) {
        int n, m, a, b; scanf("%d %d %d %d", &n, &m, &a, &b);
        vector <pair<int, int>> pos;
        for (int i = 1; i <= n; i++) {
            scanf("%s", s + 1);
            for (int j = 1; j <= m; j++) {
                pic[i][j] = (s[j] == 'x');
                if (s[j] == 'x') {
                    pos.push_back({i, j});
                }
            }
        }
        vector <pair<int, int>> dpos;
        for (int i = 1; i <= a; i++) {
            scanf("%s", s + 1);
            for (int j = 1; j <= b; j++) {
                pic2[i][j] = (s[j] == 'x');
            }
        }
        int X = 0, Y = 0;
        for (int i = 1; i <= a; i++) {
            for (int j = 1; j <= b; j++) {
                if (pic2[i][j]) {
                    if (!X && !Y) {
                        X = i, Y = j;
                    }
                    dpos.push_back({i - X, j - Y});
                }
            }
        }
        bool flag = true;
        for (auto point : pos) {
            int x = point.first, y = point.second;
            if (pic[x][y]) {
                for (auto dpoint : dpos) {
                    int tx = x + dpoint.first, ty = y + dpoint.second;
                    if (tx < 1 || tx > n || ty < 1 || ty > m || !pic[tx][ty]) {
                        flag = false;
                        break;
                    }
                    pic[tx][ty] = 0;
                }
                if (!flag)  break;
            }
        }
        if (flag) {
            for (int i = 1; i <= n; i++) {
                for (int j = 1; j <= m; j++) {
                    if (pic[i][j]) {
                        flag = false;
                        break;
                    }
                }
            }
        }
        puts(flag ? "TAK" : "NIE");
    }
#ifndef ONLINE_JUDGE
    system("pause");
#endif
    return 0;
}