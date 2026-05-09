/* Author: Rajesh Kumar Yadav
    Created At: Tue 28 Oct 2025 18:51:56
*/
/*
Given an array of size N, find the minimum number of swaps needed to make the array as sorted.

Sample Input :
a1 = [ 5, 4, 3, 2, 1 ]

Sample Output :  5->1 , 2->4
2

Sample Input :
a1 = [10,11,5,4,3,2,1]

Sample Output :
4
*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int countMinSwaps(vector<int> arr)
{

    int n = arr.size();
    int ans = 0;
    // Know the actual positions of elements (sorting)
    // store the current indices
    pair<int, int> ap[n];
    for (int i = 0; i < n; i++)
    {
        ap[i].first = arr[i];
        ap[i].second = i;
    }
    // sorting
    sort(ap, ap + n);

    // build the main logic
    vector<bool> visited(n, false);

    for (int i = 0; i < n; i++)
    {

        // if element is visited or element is in right postion
        int old_position = ap[i].second;
        if (visited[i] == true or old_position == i)
        {
            continue;
        }

        // visiting the element (index) for first time
        int node = i;
        int cycle = 0;

        while (!visited[node])
        {
            visited[node] = true;
            int next_node = ap[node].second;
            node = next_node;
            cycle += 1;
        }
        // for 3 element cycly two swap needed
        ans += (cycle - 1);
    }

    return ans;
}

void solve()
{
    vector<int> arr{5, 4, 3, 2, 1};
    cout << countMinSwaps(arr) << endl;
}

signed main()
{

    solve();

    return 0;
}
