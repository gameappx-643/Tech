/* Author: Rajesh Kumar Yadav
    Created At: Tue 28 Oct 2025 01:34:40
*/
/*
Given an array containing N integers, find length of longest band.

A band is defined as a subsequence which can be re- ordered in such a manner all elements appear consecutive (ie with absolute difference of 1 between neighbouring elements)

A longest band is the band (subsequence) which contains maximum integers.
Input
Array [1, 9, 3, 0, 18, 5, 2, 4, 10, 7, 12, 6]
Output 8
Explanation Largest subset containing consecutive numbers is {0,1,2,3,4,5,6,7}
*/
#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;
int largestBand(vector<int> arr)
{
    int n = arr.size();
    unordered_set<int> s;

    // Data inside a set
    for (int x : arr)
    {
        s.insert(x);
    }

    // Iterate over the arr
    int largestLen = 1;

    for (auto element : s)
    {
        int parent = element - 1;

        if (s.find(parent) == s.end())
        {
            // find entire band / chain starting from element
            int next_no = element + 1;
            int cnt = 1;

            while (s.find(next_no) != s.end())
            {
                next_no++;
                cnt++;
            }

            if (cnt > largestLen)
            {
                largestLen = cnt;
            }
        }
    }

    return largestLen;
}

void solve()
{
    vector<int> arr{1, 9, 3, 0, 18, 5, 2, 4, 10, 7, 12, 6};
    cout << largestBand(arr) << endl;
}

signed main()
{

    solve();

    return 0;
}
