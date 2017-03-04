// Euclidean Algorithm for finding the
// greatest common divisor of two numbers
#include <bits/stdc++.h>
#define lld long long

using namespace std;

// Procedural
inline lld gcd(lld a, lld b) {
    if(b > a)
        swap(a, b);

    lld tmp = 1;
    while(b) {
        tmp = a % b;
        a = b;
        b = tmp;
    }
    return a;
}

// Recursive
lld gcdr(lld a, lld b) {
    return (a % b == 0) ? b : gcdr(b, a % b);
}

int main()
{
    lld a = 123129, b = 12312;
    printf("%lld", gcd(a, b));
    return 0;
}
