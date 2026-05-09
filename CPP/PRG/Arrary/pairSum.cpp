/* Author: Rajesh Kumar Yadav
    Created At: Mon 27 Oct 2025 15:02:01
*/
#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

vector<int> pairSum(vector<int> arr, int sum)
{
    // Logic
    unordered_set<int> s;
    vector<int> result;
    for (int i = 0; i < arr.size(); i++)
    {
        int x = sum - arr[i];
        if (s.find(x) != s.end())
        {
            result.push_back(x);
            result.push_back(arr[i]);
            return result;
            // insert the current no inside set
        }
        s.insert(arr[i]);
    }
    return result;
}
void solve()
{
    vector<int> arr{10, 5, 2, 3, -6, 9, 11};
    int S = 4;

    auto p = pairSum(arr, S);
    if (p.size() == 0)
    {
        cout << "No such pair";
    }
    else
    {
        cout << p[0] << "," << p[1] << endl;
    }
}

signed main()
{

    solve();

    return 0;
}
