#include <bits/stdc++.h>
#define lld long long

using namespace std;

inline lld poww(lld n, lld k) {
    lld res = 1;
    while(k > 0) {
        if(k&1) // checks if k is odd number
            res *= n;
        k >>= 1;
        n *= n;
    }
    return res;
}

int main()
{
    lld a = 2, b = 12;
    printf("%lld ^ %lld = %lld\n", a, b, poww(a, b));
    return 0;
}

