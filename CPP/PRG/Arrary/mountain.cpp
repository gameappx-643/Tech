/* Author: Rajesh Kumar Yadav
    Created At: Tue 28 Oct 2025 01:19:21
*/

/*
Write a function that takes input an array of distinct integers, and returns the length of highest mountain.

• A mountain is defined as adjacent integers that are strictly increasing until they reach a peak, at which the become strictly decreasing.

• At least 3 numbers are required to form a mountain.
Sample Input [ 5, 6, 1, 2, 3, 4, 5, 4, 3, 2, 0, 1, 2, 3, 2, 4]
Sample Output 9

*/
#include <iostream>
#include <vector>
using namespace std;
int highest_mountain(vector<int> a)
{
    int n = a.size();
    int largest = 0;
    // first and last element can not be the peak
    for (int i = 1; i <= n - 2;)
    {

        // check a[il is peak or not
        if (a[i] > a[i - 1] and a[i] > a[i + 1])
        {
            // do some work
            int cnt = 1;
            int j = i;
            // cnt backwards (left)
            while (j >= 1 and a[j] > a[j - 1])
            {
                j--;
                cnt++;
            }
            // cnt forwards (right)
            while (i <= n - 2 and a[i] > a[i + 1])
            {
                i++;
                cnt++;
            }
            largest = max(largest, cnt);
        }
        else
        {
            i++;
        }
    }
    return largest;
}

void solve()
{
    vector<int> arr{5, 6, 1, 2, 3, 4, 5, 4, 3, 2, 0, 1, 2, 3, -2, 4};
    int count = highest_mountain(arr);
    cout << "highest_mountain : " << count << endl;
}

signed main()
{

    solve();

    return 0;
}
