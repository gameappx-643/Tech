/* Author: Rajesh Kumar Yadav
    Created At: Sat 25 Oct 2025 17:07:55
*/
#include <iostream>
using namespace std;

bool isSafe(int mat[][9], int i, int j, int no)
{
    // Check for row and col
    for (int k = 0; k < 9; k++)
    {
        if (mat[k][j] == no || mat[i][k] == no)
        {
            return false;
        }
    }
    // check for subgrid
    int sx = (i / 3) * 3;
    int sy = (j / 3) * 3;

    for (int x = sx; x < sx + 3; x++)
    {
        for (int y = sy; y < sy + 3; y++)
        {
            if (mat[x][y] == no)
            {
                return false;
            }
        }
    }

    return true;
}

bool solveSudoku(int mat[][9], int i, int j, int n)
{
    // base case
    if (i == n)
    {
        // print the solution matrix
        for (size_t i = 0; i < 9; i++)
        {
            for (size_t j = 0; j < 9; j++)
            {
                cout << mat[i][j] << " ";
            }
            cout << endl;
        }

        return true;
    }

    // rec case , row end  try next row from 0th column
    if (j == n)
    {
        return solveSudoku(mat, i + 1, 0, n);
    }

    // skip the prefilled cell
    if (mat[i][j] != 0)
    {
        return solveSudoku(mat, i, j + 1, n);
    }

    // cell to be filled try out all possibilites
    for (int no = 1; no <= n; no++)
    {
        // whether it is safe to place the number or not
        if (isSafe(mat, i, j, no))
        {
            mat[i][j] = no;
            bool solveSubproblem = solveSudoku(mat, i, j + 1, n);
            if (solveSubproblem == true)
            {
                return true;
            }
        }
    }

    // if no option works , remove it and returent false to parent
    mat[i][j] = 0;
    return false;
}

void solve()
{
    int n = 9;
    int mat[9][9] = {
        {5, 3, 0, 0, 7, 0, 0, 0, 0},
        {6, 0, 0, 1, 9, 5, 0, 0, 0},
        {0, 9, 8, 0, 0, 0, 0, 6, 0},
        {8, 0, 0, 0, 6, 0, 0, 0, 3},
        {4, 0, 0, 8, 0, 3, 0, 0, 1},
        {7, 0, 0, 0, 2, 0, 0, 0, 6},
        {0, 6, 0, 0, 0, 0, 2, 8, 0},
        {0, 0, 0, 4, 1, 9, 0, 0, 5},
        {0, 0, 0, 0, 8, 0, 0, 7, 9}};

    if (!solveSudoku(mat, 0, 0, n))
    {
        cout << "No solution exists!" << endl;
    }
}
signed main()
{
    solve();
    return 0;
}
