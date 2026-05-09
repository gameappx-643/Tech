/* Author: Rajesh Kumar Yadav
    Created At: Sat 25 Oct 2025 16:33:57
*/
#include <iostream>
using namespace std;

void generateBrackets(string output, int n, int open, int close, int i)
{
    // base case
    if (i == 2 * n)
    {
        cout << output << endl;
        return;
    }
    // open bracket
    // plac open bracket only if its less than total number
    if (open < n)
    {
        generateBrackets(output + '(', n, open + 1, close, i + 1);
    }

    // closing bracket
    // close bracket should be less then no of open bracket
    if (close < open)
    {
        generateBrackets(output + ')', n, open, close + 1, i + 1);
    }
}

void solve()
{
    int n;
    string output;
    cout << "Enter length : ";
    cin >> n;
    generateBrackets(output, n, 0, 0, 0);
}

signed main()
{

    solve();

    return 0;
}
