#include <bits/stdc++.h>

using namespace std;

int n, m;

int ans[9][9] = {
    {0},
    {0, 2, 6, 20, 70, 252, 924, 3432, 12870},
    {0, 6, 90, 1860, 44730, 1172556, 32496156, 936369720, 817760799},
    {0, 20, 1860, 297200, 60871300, 392323778, 932185828, 944343811, 180846167},
    {0, 70, 44730, 60871300, 169206949, 660469253, 209560164, 202780073, 710851014},
    {0, 252, 1172556, 392323778, 660469253, 395384428, 821780699, 605240292, 714213243},
    {0, 924, 32496156, 932185828, 209560164, 821780699, 584498879, 268950048, 673945339},
    {0, 3432, 936369720, 944343811, 202780073, 605240292, 268950048, 55183176, 563571987},
    {0, 12870, 817760799, 180846167, 710851014, 714213243, 673945339, 563571987, 844138055}
};

int main() {
    freopen("enigmatic.in", "r", stdin);
    freopen("enigmatic.out", "w", stdout);
    while (~scanf("%d %d", &n, &m) && n && m) {
        printf("%d\n", ans[n / 2][m / 2]);
    }
    return 0;
}