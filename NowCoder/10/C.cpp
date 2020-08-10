#include <bits/stdc++.h>

using namespace std;

struct Edge { int u, v, w; };
vector <Edge> edges;
const int N = 100 + 10;
multiset <int> st[N];
long long sum[N];
int calc(int u) {
    if ((int)st[u].size() == 1)  return 0;
    long long maxv = *st[u].rbegin();
    return maxv > sum[u] - maxv ? sum[u] - maxv : sum[u] >> 1;
}
int main() {
    int n, q;   scanf("%d %d", &n, &q);
    long long ans = 0;
    for (int i = 1; i < n; i++) {
        int u, v, w;   scanf("%d %d %d", &u, &v, &w);
        edges.push_back((Edge){u, v, w});
        st[u].insert(w);
        st[v].insert(w);
        sum[u] += w;
        sum[v] += w;
        ans += w;
    }
    for (int i = 1; i <= n; i++) {
        long long maxv = *st[i].rbegin();
        if (maxv > sum[i] - maxv)   ans -= sum[i] - maxv;
        else    ans -= sum[i] / 2;
    }
    printf("%lld\n", ans);
    for (int i = 1; i <= q; i++) {
        int id, w;  scanf("%d %d", &id, &w);
        id--;
        int u = edges[id].u, v = edges[id].v;
        ans += calc(u);
        ans += calc(v);

        sum[u] += w - edges[id].w;
        sum[v] += w - edges[id].w;
        st[u].erase(st[u].lower_bound(edges[id].w));
        st[v].erase(st[v].lower_bound(edges[id].w));
        st[u].insert(w);
        st[v].insert(w);
        

        ans -= calc(u);
        ans -= calc(v);
        
        ans += w - edges[id].w;
        edges[id].w = w;
        // for (int j = 1; j <= n; j++) {
        //     printf("%d: ", j);
        //     for (auto x : st[j]) {
        //         cout << x << ' ';
        //     } cout << '\n';
        // }
        printf("%lld\n", ans);
    }
#ifndef ONLINE_JUDGE
    system("pause");
#endif
    return 0;
}