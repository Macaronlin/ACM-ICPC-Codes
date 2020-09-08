#include <bits/stdc++.h>

using namespace std;

int a[4][4];

int calc(int x1, int y1, int x2, int y2) {
    int res = 0;
    for (int i = 1; i <= 3; i++) {
        for (int j = 1; j <= 3; j++) {
            if (i == x1 && j == y1) continue;
            if (i == x2 && j == y2) continue;
            if (i != x1 && i != x2 && j != y1 && j != y2)   res ^= a[i][j];
            else    res ^= (a[i][j] - 1);
        }
    }
    return res;
}

int main() {
    int T;  scanf("%d", &T);
    while (T--) {
        for (int i = 1; i <= 3; i++) {
            for (int j = 1; j <= 3; j++) {
                scanf("%d", &a[i][j]);
            }
        }
        int ans = 0;
        for (int i = 1; i <= 3; i++) {
            for (int j = 1; j <= 3; j++) {
                set <int> st;
                for (int ii = 1; ii <= 3; ii++) {
                    if (i == ii)    continue;
                    for (int jj = 1; jj <= 3; jj++) {
                        if (j == jj)    continue;
                        st.insert(calc(i, j, ii, jj));
                    }
                }
                if (*st.begin() != 0)   ans++;
            }
        }
        printf("%d\n", ans);
    }
#ifndef ONLINE_JUDGE
    system("pause");
#endif
    return 0;
}