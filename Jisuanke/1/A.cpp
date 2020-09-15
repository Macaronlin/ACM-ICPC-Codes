#include <bits/stdc++.h>

using namespace std;

const int N = 30;

char s[N];
int a[N][N];
vector <pair<int, int>> ans;

int dx[] = {1, 0, -1, 0, 1, -1, 1, -1};
int dy[] = {0, 1, 0, -1, 1, 1, -1, -1};

void Add(int x, int y) {
    if (x >= 0 && y >= 0 && x < 25 && y < 25 && !a[x][y]) {
        ans.push_back({x, y});
    }
}



bool work(int i, int j, int now) {
    if (a[i][j] == now) {
        for (int t = 0; t < 8; t++) {
            bool flag = true;
            for (int k = 1; k <= 4; k++) {
                int x = i + k * dx[t], y = j + k * dy[t];
                if (x < 0 || x >= 25 || y < 0 || y >= 25 || a[x][y] != now) {
                    flag = false;
                    break;
                }
            }
            if (flag)   return true;
        }
    }
    return false;
}

int cnt[3];

bool check() {
    for (int i = 0; i < 25; i++) {
        for (int j = 0; j < 25; j++) {
            if (work(i, j, cnt[1] == cnt[2] ? 1 : 2)) {
                return true;
            }
        }
    }
    return false;
}



int main() {
    for (int i = 0; i < 25; i++) {
        scanf("%s", s);
        for (int j = 0; j < 25; j++) {
            if (s[j] == 'x')    a[i][j] = 1;
            else if (s[j] == 'o')   a[i][j] = 2;
            cnt[a[i][j]]++;
        }
    }
    int nxt = cnt[1] == cnt[2] ? 1 : 2;
    for (int i = 0; i < 25; i++) {
        for (int j = 0; j < 25; j++) {
            if (!a[i][j]) {
                a[i][j] = nxt;
                if (check()) {
                    ans.push_back({i, j});
                }
                a[i][j] = 0;
            }
        }
    }
    if (!ans.empty()) {
        sort(ans.begin(), ans.end());
        ans.erase(unique(ans.begin(), ans.end()), ans.end());
        for (auto a : ans) {
            printf("%d %d\n", a.first, a.second);
        }
    }
    else {
        puts("tie");
    }
    
#ifndef ONLINE_JUDGE
    system("pause");
#endif
    return 0;
}