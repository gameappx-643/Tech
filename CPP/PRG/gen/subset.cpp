/* Author: Rajesh Kumar Yadav
    Created At: Fri 24 Oct 2025 14:08:00
*/
// #include <iostream>
#include <bits/stdc++.h>
using namespace std;

#define int long long int
#define double long double
#define endl '\n'

void findSubset(char *input, char *output, int i, int j)
{
    // abccout << " Input :" << input << endl;
    //  base case , if input is null the print the string
    if (input[i] == '\0')
    {
        output[j] = '\0';
        if (output[0] == '\0')
        {
            cout << "NULL" << endl;
        }
        cout << output << endl;
        return;
    }
    // rec case
    // include the ith letter and call the subset in remaing string
    output[j] = input[i];
    findSubset(input, output, i + 1, j + 1);

    // Exclude the ith element;
    findSubset(input, output, i + 1, j);
}

// Read the test case input and solve the problem.
void solve(int t)
{
    int n, m;
    char input[100], output[100];
    cin >> input;
    findSubset(input, output, 0, 0);
    // cout << n + m << endl;
    // cerr << n << " And " << m << endl;
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

#ifdef RKY_LOCAL_RUN
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    freopen("debug.txt", "w", stderr);
#endif

    clock_t start = clock();
    // read number of test cases
    int t = 1;
    cin >> t;
    while (t--)
        solve(t);

    // // Calculating total time taken by the program.
    // #undef double
    // double time_taken = double ( clock() - start ) / double ( CLOCKS_PER_SEC );
    // cerr << "Time taken by program is : " << fixed
    //      << time_taken << setprecision(5) << " sec " << endl;

    // bool check = compareFiles( "output.txt", "expected.txt" );
    // if ( check ) cerr << "OK\n";
    // else cerr << "Failed!\n";

    return 0;
}
