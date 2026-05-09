/* Author: Rajesh Kumar Yadav
    Created At: Mon 27 Oct 2025 23:58:20
*/

/**
Given an array containing N integers, and an number S denoting a target sum.

Find all distinct integers that can add up to form target sum.
The numbers in each triplet should be ordered in ascending order, and triplets should be ordered too.
Return empty array if no such triplet exists.

Input
array = [1, 2, 3, 4, 5, 6, 7, 8, 9, 15]
target = 18

Output [
    [ 1, 2, 15],
    [3, 7, 8],
    [4, 6, 8],
    [15, 6, 71] ]
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<vector<int>> triplets(vector<int> arr, int targetSum)
{
    vector<vector<int>> result;
    int n = arr.size();
    sort(arr.begin(), arr.end());
    // Pick every a[i] and solve pair sum problem for remaining part
    // to solve pair we need at leat two element
    for (int i = 0; i <= n - 3; i++)
    {

        int j = i + 1;
        int k = n - 1;
        // two pointer approach
        while (j < k)
        {
            int current_sum = arr[i];
            current_sum += arr[j];
            current_sum += arr[k];

            if (current_sum == targetSum)
            {
                // Found one sume
                result.push_back({arr[i], arr[j], arr[k]});
                j++;
                k--;
            }
            else if (current_sum > targetSum)
            {
                k--;
            }
            else
            {
                j++;
            }
        }
    }
    return result;
}

void solve()
{
    vector<int> arr{1, 2, 3, 4, 5, 6, 7, 8, 9, 15};
    int S = 18;

    auto result = triplets(arr, S);
    for (auto v : result)
    {
        for (auto no : v)
        {
            cout << no << " ";
        }
        cout <<endl;
    }
}

signed main()
{

    solve();

    return 0;
}
