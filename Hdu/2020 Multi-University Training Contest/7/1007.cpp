#include <bits/stdc++.h>

using namespace std; 

const int N = 2000 + 10;

struct Point { 
    long long x, y;
    bool operator < (const Point &p) const { return x == p.x ? y < p.y : x < p.x; }
};

struct Node {
    int u, v;
    long long w;
    bool operator < (const Node &tmp) const { return w > tmp.w; }
};

long long sqr(long long x) { return x * x; }
long long dis(Point a, Point b) { return sqr(a.x - b.x) + sqr(a.y - b.y); }

int vis[N];
bool Solve() {
    int n;  scanf("%d", &n);
    memset(vis, 0, sizeof(int) * (n + 5));
    vector <Point> ps;
    for (int i = 1; i <= n; i++) {
        int x, y;   scanf("%d %d", &x, &y);
        ps.push_back((Point){x, y});
    }
    vector <Node> vec;
    for (int i = 0; i < (int)ps.size(); i++) {
        for (int j = i + 1; j < (int)ps.size(); j++) {
            vec.push_back((Node){i, j, dis(ps[i], ps[j])});
        }
    }
    sort(vec.begin(), vec.end());
    for (int i = 0, j; i < (int)vec.size(); i = j) {
        j = i;
        while (j < (int)vec.size() && vec[i].w == vec[j].w) {
            if (!vis[vec[j].u] && !vis[vec[j].v]) {
                vis[vec[j].u] = vis[vec[j].v] = 1;
                if (!vec[j].u)  return true;
                if (!vec[j].v)  return true;
            }
            j++;
        }
    }
    return false;
}

int main() {
    int T;  scanf("%d", &T);
    while (T--) {
        puts(Solve() ? "Yes" : "No");
    }
#ifndef ONLINE_JUDGE
    system("pause");
#endif
    return 0;
}