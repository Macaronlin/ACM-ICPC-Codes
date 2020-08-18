#include <bits/stdc++.h>

using namespace std; 

const int N = 100000 + 10;
int dp1[N], dp2[N];
int a[N];

int calc1(int *a, int n) {
    int res = 0;
    for (int i = 1; i <= n; i++) {
        dp1[i] = 1;
        for (int j = 1; j < i; j++) {
            if (a[i] > a[j]) {
                dp1[i] = max(dp1[i], dp1[j] + 1);
            }
        }
        res = max(res, dp1[i]);
    }
    return res;
}

int calc2(int *a, int n) {
    int res = 0;
    for (int i = 1; i <= n; i++) {
        dp2[i] = 1;
        for (int j = 1; j < i; j++) {
            if (a[i] < a[j]) {
                dp2[i] = max(dp2[i], dp2[j] + 1);
            }
        }
        res = max(res, dp2[i]);
    }
    return res;
}

// void Solve(int n, int)

int main() {
    int T;  scanf("%d", &T);
    while (T--) {
        int n, x, y;    scanf("%d %d %d", &n, &x, &y);
        // if (Solve(n, x, y, 1)) {
        //     puts("YES");
        //     for (int i = 1; i <= n; i++) {
        //         printf("%d%c", a[i], " \n"[i == n]);
        //     }
        // }
        // else {
        //     puts("NO");
        // }
    }
    set <pair<int, int>> st;
    int n = 4;
    for (int i = 1; i <= n; i++)    a[i] = i;
    for (int i = 1; i <= 120; i++) {
        int x = calc1(a, n), y = calc2(a, n);
        pair <int, int> pi = {x, y};
        if (st.lower_bound(pi) == st.end() || *st.lower_bound(pi) != pi) {
            printf("(");
            for (int j = 1; j <= n; j++) {
                printf("%d, ", a[j]);
            }
            printf(") : x = %d, y = %d\n", x, y);
        }
        st.insert(pi);
        next_permutation(a + 1, a + 1 + n);
    }
    for (auto x : st) {
        printf("(%d, %d) : %d, %d\n", x.first, x.second, x.first - x.second, x.first + x.second);
    }
#ifndef ONLINE_JUDGE
    system("pause");
#endif
    return 0;
}

// n = 6
// (1, 2, 3, 4, 5, 6, ) : x = 6, y = 1
// (1, 2, 3, 4, 6, 5, ) : x = 5, y = 2
// (1, 2, 3, 6, 5, 4, ) : x = 4, y = 3
// (1, 2, 4, 3, 6, 5, ) : x = 4, y = 2
// (1, 2, 6, 5, 4, 3, ) : x = 3, y = 4
// (1, 3, 2, 6, 5, 4, ) : x = 3, y = 3
// (1, 6, 5, 4, 3, 2, ) : x = 2, y = 5
// (2, 1, 4, 3, 6, 5, ) : x = 3, y = 2
// (2, 1, 6, 5, 4, 3, ) : x = 2, y = 4
// (3, 2, 1, 6, 5, 4, ) : x = 2, y = 3
// (6, 5, 4, 3, 2, 1, ) : x = 1, y = 6

// n = 8
// (1, 2, 3, 4, 5, 6, 7, 8, ) : x = 8, y = 1
// (1, 2, 3, 4, 5, 6, 8, 7, ) : x = 7, y = 2
// (1, 2, 3, 4, 5, 8, 7, 6, ) : x = 6, y = 3
// (1, 2, 3, 4, 6, 5, 8, 7, ) : x = 6, y = 2
// (1, 2, 3, 4, 8, 7, 6, 5, ) : x = 5, y = 4
// (1, 2, 3, 5, 4, 8, 7, 6, ) : x = 5, y = 3
// (1, 2, 3, 8, 7, 6, 5, 4, ) : x = 4, y = 5
// (1, 2, 4, 3, 6, 5, 8, 7, ) : x = 5, y = 2
// (1, 2, 4, 3, 8, 7, 6, 5, ) : x = 4, y = 4
// (1, 2, 5, 4, 3, 8, 7, 6, ) : x = 4, y = 3
// (1, 2, 8, 7, 6, 5, 4, 3, ) : x = 3, y = 6
// (1, 3, 2, 8, 7, 6, 5, 4, ) : x = 3, y = 5
// (1, 4, 3, 2, 8, 7, 6, 5, ) : x = 3, y = 4
// (1, 8, 7, 6, 5, 4, 3, 2, ) : x = 2, y = 7
// (2, 1, 4, 3, 6, 5, 8, 7, ) : x = 4, y = 2
// (2, 1, 5, 4, 3, 8, 7, 6, ) : x = 3, y = 3
// (2, 1, 8, 7, 6, 5, 4, 3, ) : x = 2, y = 6
// (3, 2, 1, 8, 7, 6, 5, 4, ) : x = 2, y = 5
// (4, 3, 2, 1, 8, 7, 6, 5, ) : x = 2, y = 4
// (8, 7, 6, 5, 4, 3, 2, 1, ) : x = 1, y = 8