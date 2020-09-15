#include <bits/stdc++.h>

using namespace std;

const int N = 100000 + 10;

int head[N], to[N << 1], nxt[N << 1], tot;
void AddEdge(int u, int v) {
    to[++tot] = v;
    nxt[tot] = head[u];
    head[u] = tot;
}

int n, siz[N], maxp[N], fa[N], rt;
void dfs(int u, int fath) {
    siz[u] = 1;
    maxp[u] = 0;
    for (int i = head[u]; i; i = nxt[i]) {
        int v = to[i];
        if (v != fath) {
            dfs(v, u);
            siz[u] += siz[v];
            maxp[u] = max(maxp[u], siz[v]);
        }
    }
    maxp[u] = max(maxp[u], n - siz[u]);
    if (!rt || maxp[u] < maxp[rt]) {
        rt = u;
    }
}
vector <int> leaf, r;
void dfs2(int u, int fath, bool ok) {
    fa[u] = fath;
    bool flag = true;
    for (int i = head[u]; i; i = nxt[i]) {
        int v = to[i];
        if (v != fath) {
            flag = false;
            dfs2(v, u, ok || (u == r[0]));
        }
    }
    if (flag && ok)   leaf.push_back(u);
}

int main() {
    int T;  scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        memset(head, 0, sizeof(int) * (n + 5));
        tot = rt = 0;
        r.clear();
        leaf.clear();
        for (int i = 1; i < n; i++) {
            int u, v;   scanf("%d %d", &u, &v);
            AddEdge(u, v);
            AddEdge(v, u);
        }
        dfs(1, 0);
        for (int i = 1; i <= n; i++) {
            if (maxp[i] == maxp[rt]) {
                r.push_back(i);
            }
        }
        // printf("rt : ");
        // for (auto u : r) {
        //     cout << u << ' ';
        // }
        // cout << '\n';
        if (r.size() == 1) {
            dfs2(1, 1, 0);
            printf("%d %d\n", n, fa[n]);
            printf("%d %d\n", n, fa[n]);
        }
        else {
            dfs2(r[1], r[1], 0);
            printf("%d %d\n", leaf[0], fa[leaf[0]]);
            printf("%d %d\n", r[1], leaf[0]);
        }
    }
#ifndef ONLINE_JUDGE
    system("pause");
#endif
    return 0;
}