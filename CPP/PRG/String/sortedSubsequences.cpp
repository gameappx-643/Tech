/* Author: Rajesh Kumar Yadav
    Created At: Thu 30 Oct 2025 18:21:20
*/

/*
You are given a string, you need to print all subsequences of the string sorted by length and lexicographic sorted order if length is same.

Sample Input
abcd
Sample Output
,a, b,c, d, ab, ac, ad, bc, bd, cd, abc, abd, acd, bed, abcd,
*/
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

// sorted subsequences
void subsequence(string s, string o, vector<string> &v)
{
    // base case
    if (s.size() == 0)
    {
        v.push_back(o);
        return;
    }
    // rec case
    char ch = s[0];
    string reduced_input = s.substr(1);
    // includes
    subsequence(reduced_input, o + ch, v);
    // excludes
    subsequence(reduced_input, o, v);
}

bool compare(string s1, string s2)
{
    if (s1.length() == s2.length())
    {
        return s1 < s2;
    }
    return s1.length() < s2.length();
}

void solve()
{
    string s = "abcd";
    vector<string> v;
    string output = "";
    subsequence(s, output, v);
    sort(v.begin(), v.end(), compare);
    for (auto s : v)
    {
        cout << s << ", ";
    }
}

signed main()
{

    solve();

    return 0;
}
