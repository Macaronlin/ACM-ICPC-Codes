#include <bits/stdc++.h>

using namespace std; 

const int N = 200000 + 10;
int head[N], to[N << 1], nxt[N << 1], tot, weight[N << 1];
void AddEdge(int u, int v, int w) {
    to[++tot] = v;
    nxt[tot] = head[u];
    head[u] = tot;
    weight[tot] = w;
}

int n, m, rt, a[N];

long long dis[N], minv[N << 2];
bool flag[N << 2];
int fa[N];
void dfs(int u, int fath) {
    fa[u] = fath;
    for (int i = head[u]; i; i = nxt[i]) {
        int v = to[i];
        if (v != fath) {
            dis[v] = dis[u] + weight[i];
            dfs(v, u);
            
        }
    }
}
void Build(int o, int L, int R) {
    if (L == R) {
        minv[o] = dis[a[L]];
        flag[o] = 0;
    }
    else {
        int M = (L + R) >> 1;
        Build(o << 1, L, M);
        Build(o << 1 | 1, M + 1, R);
        flag[o] = 0;
        minv[o] = min(minv[o << 1], minv[o << 1 | 1]);
    }
}

void Update(int o, int L, int R, int l, int r) {
    if (flag[o])    return;
    if (l <= L && R <= r) {
        flag[o] = 1;
        if (L == R) {
            a[L] = fa[a[L]];
            minv[o] = dis[a[L]];
        }
        else {
            int M = (L + R) >> 1;
            Update(o << 1, L, M, l, r);
            Update(o << 1 | 1, M + 1, R, l, r);
            minv[o] = min(minv[o << 1], minv[o << 1 | 1]);
        }
    }
    else {
        int M = (L + R) >> 1;
        if (l <= M) Update(o << 1, L, M, l, r);
        if (r >= M + 1) Update(o << 1 | 1, M + 1, R, l, r);
        minv[o] = min(minv[o << 1], minv[o << 1 | 1]);
    }
}
long long Query(int o, int L, int R, int l, int r) {
    if (l <= L && R <= r) {
        return minv[o];
    }
    else {
        int M = (L + R) >> 1;
        long long res = LONG_LONG_MAX;
        if (l <= M) res = min(res, Query(o << 1, L, M, l, r));
        if (r >= M + 1) res = min(res, Query(o << 1 | 1, M + 1, R, l, r));
        return res;
    }
}

int main() {
    int T;  scanf("%d", &T);
    while (T--) {
        int n, m, rt;   scanf("%d %d %d", &n, &m, &rt);
        tot = 0;
        memset(dis, 0, sizeof(long long) * (n + 5));
        memset(head, 0, sizeof(int) * (n + 5));
        for (int i = 1; i < n; i++) {
            int u, v, w;    scanf("%d %d %d", &u, &v, &w);
            AddEdge(u, v, w);
            AddEdge(v, u, w);
        }
        for (int i = 1; i <= n; i++)    scanf("%d", &a[i]);
        dfs(rt, rt);
        Build(1, 1, n);
        for (int i = 1; i <= n; i++) {
            cout << Query(1, 1, n, i, i) << ' ';
        } cout << '\n';
        for (int i = 1; i <= m; i++) {
            int opt, l, r;  scanf("%d %d %d", &opt, &l, &r);
            if (opt == 2)   printf("%lld\n", Query(1, 1, n, l, r));
            else    Update(1, 1, n, l, r);
        }
    }
#ifndef ONLINE_JUDGE
    system("pause");
#endif
    return 0;
}