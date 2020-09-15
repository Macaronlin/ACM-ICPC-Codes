#include <bits/stdc++.h>

using namespace std;

const int N = 2000000 + 10;

// struct Node {
//     int pos, v;
//     bool operator < (const Node &tmp) const { return v < tmp.v; }
// }a[N], b[N];

int a[N], b[N], c[N], n;

int check() {
    unordered_map <int, int> ump1, ump2;
    for (int i = 1; i <= n; i++)    ump1[a[i]]++;
    for (int i = 1; i <= n; i++)    ump2[b[i]]++;
    int res = 0;
    for (auto x : ump1) {
        if (ump2.count(x.first)) {
            if (min(x.second, ump2[x.first]) > n / 2) {
                return -1;
            }
            res = max(res, max(x.second, ump2[x.first]));
        }
    }
    return res;
}

int main() {
    cin >> n;    
    for (int i = 1; i <= n; i++)    scanf("%d", a + i);
    for (int i = 1; i <= n; i++)    scanf("%d", b + i);
    unordered_map <int, pair<int,int>> ump1, ump2;
    for (int i = 1; i <= n; i++) {
        if (ump1.count(a[i]))   ump1[a[i]].second = i;
        else    ump1[a[i]] = {i, i};
    }
    for (int i = 1; i <= n; i++) {
        if (ump2.count(b[i]))   ump2[b[i]].second = i;
        else    ump2[b[i]] = {i, i};
    }
    int L = 0, R = 2 * n;
    for (auto x : ump1) {
        int val = x.first;
        if (ump2.count(val)) {
            int l1 = ump1[val].first, r1 = ump1[val].second;
            int l2 = ump2[val].first, r2 = ump2[val].second;
            L = max(L, r1 - l2 + 1);
            R = min(R, l1 + n - r2 - 1);
        }
    }
    if (L <= R) {
        cout << "Yes\n";
        int dx = L;
        for (int i = 1; i <= n; i++)    c[(i + dx - 1) % n + 1] = b[i];
        for (int i = 1; i <= n; i++)    cout << c[i] << ' ';
    }
    else {
        cout << "No\n";
    }
#ifndef ONLINE_JUDGE
    system("pause");
#endif
    return 0;
}
