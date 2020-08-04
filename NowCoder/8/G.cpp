#include <bits/stdc++.h>

using namespace std;

const int N = 2506;
const int P = 1000000000 + 7;
const int bas = 2333;

int mul(int a, int b) { return 1LL * a * b % P; }
int add(int a, int b) { return a + b >= P ? a + b - P : a + b; }

int n;
char s[N];
// 42
struct Node {
    int a[4];
}node[N];

bool Check(int a, int b, int c) {
    for (int i = 0; i < 4; i++) {
        if (node[a].a[i] == '*' || node[b].a[i] == '*' || node[c].a[i] == '*');
        else if (node[a].a[i] == node[b].a[i] && node[b].a[i] == node[c].a[i]);
        else if (node[a].a[i] != node[b].a[i] && node[b].a[i] != node[c].a[i] && node[a].a[i] != node[c].a[i]);
        else return false;
    }
    return true;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("G.in", "r", stdin);
    freopen("G.out", "w", stdout);
    clock_t _s = clock();
#endif
    int _, __;  scanf("%d", &__);
    for (_ = 1; _ <= __; _++) {
        scanf("%d", &n);
        for (int i = 0; i < n; i++) {
            scanf("%s", s);
            int len = strlen(s), hs = 0, id = 0;
            for (int j = 0; j < len; j++) {
                if (s[j] == '[')    hs = 0;
                else if (s[j] == ']')   node[i].a[id++] = hs;
                else    hs = add(mul(hs, bas), s[j]);
            }
        }
        bool flag = false;
        int ans1, ans2, ans3;
        for (int i = 0; i < n && !flag; i++) {
            for (int j = i + 1; j < n && !flag; j++) {
                for (int k = j + 1; k < n && !flag; k++) {
                    flag = Check(i, j, k);
                    ans1 = i + 1, ans2 = j + 1, ans3 = k + 1;
                }
            }
        }
        printf("Case #%d: ", _);
        if (flag) {
            printf("%d %d %d\n", ans1, ans2, ans3);
        }
        else {
            puts("-1");
        }
    }
#ifndef ONLINE_JUDGE
    clock_t _t = clock();
    printf("%ldms\n", _t - _s);
    system("pause");
#endif
    return 0;
}