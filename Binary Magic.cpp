#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main()
{
    int N = 2;
    int A = 5, B = 4;

    // return least signicifant bit of A
    cout << (A & -A) << endl;

    // check if N-th bit is set
    cout << (A & (1 << N)) << endl;

    // claer N-th bit
    A &= ~(1 << N);
    cout << A << endl;

    // set N-th bit
    A |= (1 << N);
    cout << A << endl;

    // return 2^N
    cout << "2 ^ " << N << " = " << (1 << N) << endl;

    // swap A and B
    cout << "Before swaping: " << A << " " << B << endl;
    A ^= B;
    B ^= A;
    A ^= B;
    cout << "After swaping: " << A << " " << B << endl;

    string S{"Programming is fun!"};
    for_each(S.begin(), S.end(), [] (auto& c) { c |= ' '; }); // lowercase whole string
    cout << S << endl;
    S[0] = 'P';
    for_each(S.begin(), S.end(), [] (auto& c) { c &= '_'; }); // uppercase whole string, some characters get lost, but letters are still there
    cout << S << endl;
    return 0;
}

