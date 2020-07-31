#include <bits/stdc++.h>

using namespace std; 

const double G = 6.67430e-11;

int main() {
    int T;  scanf("%d", &T);
    while (T--) {
        int a, b, c, t; scanf("%d %d %d %d", &a, &b, &c, &t);
        double F = a * b * G / (c * c) / 1000 / 1000;
        double x = 0.5 * t * t * (F / a + F / b);
        printf("%.20lf\n", c - x);
    }
#ifndef ONLINE_JUDGE
    system("pause");
#endif
    return 0;
}