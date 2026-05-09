/* Author: Rajesh Kumar Yadav
    Created At: Tue 21 Oct 2025 14:45:59
*/
#include <iostream>
// #include <bits/stdc++.h>
using namespace std;

#define int long long int
#define double long double
#define endl '\n'

bool canPlaced(int board[][20], int n, int x, int y)
{
    // coulmn check , go upword for current position
    // row x varies , column y fixed
    for (int k = 0; k < x; k++)
    {
        if (board[k][y])
        {
            return false;
        }
    }
    // left Diagonal go back till 0 0
    int i = x;
    int j = y;
    while (i >= 0 and j >= 0)
    {
        if (board[i][j] == 1)
        {
            return false;
        }
        // one less row and column
        i--;
        j--;
    }
    // right Diagonal start current till righy corner ie n
    i = x;
    j = y;
    while (i >= 0 and j < n)
    {
        if (board[i][j] == 1)
        {
            return false;
        }
        // one less row , and inc column
        i--;
        j++;
    }
    // now its safe
    return true;
}
// print the board
void printBoard(int n, int board[][20])
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}
// print the board
void printDBoard(int n, int board[][20])
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cerr << board[i][j] << " ";
        }
        cerr << endl;
    }
    cerr << endl;
}

// Take No of Queen N
// Max board lenght
// Current Row i
bool solveNQueen(int n, int board[][20], int i)
{
    // base case
    // if we reach a row at the end then its done
    cerr << "solveNQueen I = " << i << " N=" << n << endl;
    printDBoard(n, board);
    if (i == n)
    {
        // print the board
        printBoard(n, board);
        return true;
    }

    // rec case
    // try to place a queen in each row in remaning borad
    for (int j = 0; j < n; j++)
    {
        // whether current i , and j are safe or not
        bool isSafe = canPlaced(board, n, i, j);
        cerr << "I= " << i << " J=" << j << " Is Safe=" << isSafe << endl;
        if (isSafe)
        {
            // place the queen at i,j position
            board[i][j] = 1;
            // call the req for the next row and wait for the result
            bool success = solveNQueen(n, board, i + 1);
            // if you get the succuess from the remaing group then return success
            if (success)
            {
                return true;
                // Note No else false here as still all postition in row(j) is not checked
            }
            // remove the queen from current position and place in next coulmn and check
            board[i][j] = 0;
        }
    }
    return false;
}
// Read the test case input and solve the problem.
void solve(int t)
{
    // max board length , fillied with 0
    int board[20][20] = {0};
    int n;
    cin >> n;
    solveNQueen(n, board, 0);
    // cin >> n >> m;
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
