#include <bits/stdc++.h>

using namespace std;

int main() {
    long long a, b, c, d;   cin >> a >> b >> c >> d;
    long long ans = b * d;
    ans = max(ans, a * c);
    ans = max(ans, a * d);
    ans = max(ans, b * c);
    if (a <= 0 && b >= 0)   ans = max(ans, 0LL);
    if (c <= 0 && d >= 0)   ans = max(ans, 0LL);
    cout << ans;
    system("pause");
    return 0;
}