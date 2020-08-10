#include <bits/stdc++.h>

using namespace std;

long long fac(int x) {
    long long res = 1;
    for (int i = 1; i <= x; i++)    res = res * i;
    return res;
}

int calc(vector <pair<int, int>> a, int n) {
    int res = 0;
    for (int i = 1; i <= n; i++) {
        int l = -1, r = -1
        for (int j = 0; j < (int)a.size(); j++) {
            if (a[j].first == i || a[j].second == i) {
                if (l == -1)    l = j;
                r = j;
            }
        }
        res += r - l + 1;
    }
    return res;
}

int main() {
    srand(time(0));
    for (int n = 3; n <= 10; n++) {
        vector <pair<int, int>> a;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j < i; j++) {
                a.push_back({j, i});
            }
        }
        printf("n = %d, guess = %d, ", n, calc(a, n));
        for (auto x : a) {
            printf("(%d %d), ", x.first, x.second);
        } puts("");
        long long tot = 100000;
        vector <pair<int, int>> _ans;
        int ans = INT_MAX;
        for (int i = 1; i <= tot; i++) {
            int sum = 0;
            for (int j = 1; j <= n; j++) {
                int right = -1, left = -1;
                for (int k = 0; k < (int)a.size(); k++) {
                    if (a[k].first == j || a[k].second == j) {
                        right = k;
                        if (left == -1) left = k;
                    }
                }
                sum += right - left + 1;
            }
            if (sum < ans) {
                _ans = a;
                ans = sum;
            }
            random_shuffle(a.begin(), a.end());
        }
        printf("n = %d, ans = %d, ", n, ans);
        for (auto x : _ans) {
            printf("(%d %d), ", x.first, x.second);
        } puts("");
    }
#ifndef ONLINE_JUDGE
    system("pause");
#endif
    return 0;
}