#include <bits/stdc++.h>
#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;

const int maxn = 5000 + 7;
const int maxm = 1e6 + 7;
const long long llINF = 9223372036854775807;
const int INF = 2147483647;
const long long mod = 998244353;
const double pi = acos(-1.0);

int T;
int c[10];

string ans;

bool check(int a, int b) {
    return (((a != b) && c[a] && c[b]) || (a == b && c[a] >= 2));
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("1.in", "r", stdin);
    //freopen("1.out", "w", stdout);
#endif
    scanf("%d", &T);
    while (T--) {
        memset(c, 0, sizeof(c));
        for (int i = 0; i < 10; i++) {
            scanf("%d", &c[i]);
        }

        int sum = 0;
        for (int i = 0; i < 10; i++) {
            sum += c[i];
        }
        ans = "";
        if (c[0]) {
            for (int i = 0; i < sum; i++) {
                ans.push_back('0');
            }
        }
        if (c[4]) {
            ans = "";
            for (int i = 1; i < sum; i++) {
                ans.push_back('0');
            }
            ans.push_back('4');
        }
        if (c[8]) {
            ans = "";
            for (int i = 1; i < sum; i++) {
                ans.push_back('0');
            }
            ans.push_back('8');
        }

        for (int i = 0; i < 25; i++) {
            int res = i * 4;
            int a = res / 10, b = res % 10;
            string tmp = "";
            if (check(a, b)) {
                tmp.push_back(b + '0');
                tmp.push_back(a + '0');
                c[a]--;
                c[b]--;
                for (int k = 0; k < 10; k++) {
                    for (int num = 0; num < c[k]; num++) {
                        tmp.push_back(k + '0');
                    }
                }
                while (tmp.size() < sum) {
                    tmp.push_back('0');
                }
                c[a]++;
                c[b]++;
                reverse(tmp.begin(), tmp.end());
                ans = max(ans, tmp);
            }
        }


        if (ans.empty()) {
            printf("-1\n");
        } else {
            int st = 0;
            while (ans[st] == '0' && st < ans.size()) {
                st++;
            }
            if (st == ans.size()) {
                printf("0\n");
            } else {
                for (int i = st; i < ans.size(); i++) {
                    printf("%c", ans[i]);
                }
                printf("\n");
            }
        }

    }
    return 0;
}