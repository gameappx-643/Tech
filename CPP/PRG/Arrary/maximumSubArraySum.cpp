/* Author: Rajesh Kumar Yadav
    Created At: Tue 28 Oct 2025 19:22:20
*/
/*
Implement a function that takes an input a vector of integers, and prints the maximum subarray sum that can be formed. A subarray is defined as consecutive segment of the array. If all numbers are negative, then return O.

Input
 { -1, 2, 3, 4, -2, 6, -8, 3}
Output :
13

Hint
Expected Time Complexity O(N)
Space Complexity 0(1)
*/
#include <iostream>
using namespace std;

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
