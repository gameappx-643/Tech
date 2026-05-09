/* Author: Rajesh Kumar Yadav
    Created At: Thu 30 Oct 2025 19:07:39
*/
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int getIthBit(int n, int i)
{
    int mask = (1 << i);
    return (n & mask) > 0 ? 1 : 0;
}

void setIthBit(int &n, int i)
{
    int mask = (1 << i);
    n = (n | mask);
}

void clearIthBit(int &n, int i)
{
    int mask = ~(1 << i);
    n = n & mask;
}

void updateIthBit(int &n, int i, int v)
{
    clearIthBit(n, i);
    int mask = (v << i);
    n = n | mask; // sets the right value
}

void clearLastIBits(int &n, int i)
{
    int mask = (-1 << i);
    n = n & mask;
}

void solve()
{
    int n, m;
    cout << "Enter Two no ( N M ) : ";
    cin >> n >> m;
    cout << " Sum = " << n + m << endl;
    cerr << n << " And " << m << endl;
}

signed main()
{

    solve();

    return 0;
}
