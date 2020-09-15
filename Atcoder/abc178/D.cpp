#include <bits/stdc++.h>
using namespace std;
int WD;
struct Point {
    int x, y;
    bool operator < (const Point &tmp) const { return x == tmp.x ? y < tmp.y : x < tmp.x; }
};

const int maxn = 200000 + 10;

Point p[maxn];

int main() {
    int n;  scanf("%d", &n);
    for (int i = 1; i <= n; i++)    scanf("%d %d", &p[i].x, &p[i].y);
    sort(p + 1, p + 1 + n);
    int y1 = p[1].y, y2 = p[1].y, x = p[1].x, ans = 0;
    for (int i = 2, j; i <= n; i = j) {
        j = i;
        int dx = p[i].x - x, _y1 = y1 - dx, _y2 = y2 + dx;
        int __y1 = p[i].y, __y2 = p[i].y;
        while (j <= n && p[j].x == p[i].x) {
            ans = max(ans, max(abs(p[j].y - y1), abs(p[j].y - y2)) + dx);
            _y1 = min(p[j].y, _y1);
            __y1 = min(p[j].y, __y1);
            _y2 = max(p[j].y, _y2);
            __y2 = max(p[j].y, __y2);
            j++;
        }
        ans = max(ans, __y2 - __y1);
        x += dx;
        y1 = _y1;
        y2 = _y2;
    }
    cout << ans;
#ifndef ONLINE_JUDGE
    system("pause");
#endif
    return 0;
}