#include <bits/stdc++.h>

using namespace std;

const int N = 1000 + 10;
struct Node {
    int t, id;
    bool operator < (const Node &tmp) const { return t == tmp.t ? id < tmp.id : t > tmp.t; }
}node[N];

int main() {
    int T;  scanf("%d", &T);
    while (T--) {
        int n, m, k;    scanf("%d %d %d", &n, &m, &k);
        for (int i = 1; i <= n; i++) {
            int t;  scanf("%d", &t);
            node[i] = {t, i};
        }
        if (k == 0) {
            for (int i = 1; i <= n; i++) {
                printf("%d%c", i, " \n"[i == n]);
            }
        }
        else {
            sort(node + 1, node + 1 + n);
            for (int i = 1; i <= n; i++) {
                printf("%d%c", node[i].id, " \n"[i == n]);
            }    
        }
    }
#ifndef ONLINE_JUDGE
    system("pause");
#endif
    return 0;
}