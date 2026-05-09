/* Author: Rajesh Kumar Yadav
    Created At: Tue 28 Oct 2025 19:28:14
*/
/*
Implement a function that takes in a vector of integers, and returns a vector of the same length, where each element in the output array is equal to the product of every other number in the input array. Solve this problem without using division.

In other words, the value at output[i] is equal to the product of every number in the input array other than input[i]. You can assume that answer can be stored inside int datatype and no- overflow will occur due to products.

Sample Input
Both inputs and outputs are vectors.  { 1, 2, 3, 4, 5}

Sample Output
 {120, 60, 40, 30, 24}

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
