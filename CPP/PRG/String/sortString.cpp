/* Author: Rajesh Kumar Yadav
    Created At: Thu 30 Oct 2025 13:03:12
*/
/*

Given a list of 'n' strings SO,S1,S2,......Sn-1, each consisting of digits and spaces, the number of spaces is the same for each entry, the goal is to implement a variation of a sort command. None of the strings contains consecutive spaces. Also, no string starts with a space nor ends with it. Spaces are used to divide string into columns, which can be used as keys in comparisons.
The program has to support the required parameters: key: integer denoting the column used as a key in comparisons. The left-most column is denoted by 1. reversed: boolean variable indicating whether to reverse the result of comparisons.

comparison-type: either lexicographic or numeric. Lexicographic means that we use Lexicographical order where for example (122 < 13).

Numeric means that we compare the strings by their numerical values, so (13 < 122). If the comparison type is 'numeric' and numeric values of keys of Si and Sj are equal for i < j, then Si is considered strictly smaller than Sj because it comes first.

*/
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cstring>
using namespace std;

string extractStringAtKey(string str, int key)
{

    // string tokeniser
    // hello how are you

    char *s = strtok((char *)str.c_str(), " ");
    while (key > 1)
    {
        s = strtok(NULL, " ");
        key--;
    }
    return (string)s;
}

int convertToInt(string s)
{

    int ans = 0;
    int p = 1;

    for (int i = s.length() - 1; i >= 0; i--)
    {
        // Equivalent integer digit
        ans += ((s[i] - '0') * p);
        p = p * 10;
    }
    return ans;
}

bool lexicoCompare(pair<string, string> s1, pair<string, string> s2)
{
    string key1, key2;
    key1 = s1.second;
    key2 = s2.second;
    return key1 < key2;
}

bool numericCompare(pair<string, string> s1, pair<string, string> s2)
{
    string key1, key2;
    key1 = s1.second;
    key2 = s2.second;

    return convertToInt(key1) < convertToInt(key2);
}

void solve()
{
    int n;
    cin >> n;
    // consume the extra \n
    cin.get();
    string temp;
    vector<string> v;
    for (int i = 0; i < n; i++)
    {
        getline(cin, temp); // includes white spaces
        v.push_back(temp);
    }
    int key;
    string reversal, ordering;
    cin >> key >> reversal >> ordering;
    // 1. TO extract keys for comparison & store them
    vector<pair<string, string>> vp;
    for (int i = 0; i < n; i++)
    {
        vp.push_back({v[i], extractStringAtKey(v[i], key)});
    }
    // 2. Sorting
    if (ordering == "numeric")
    {
        sort(vp.begin(), vp.end(), numericCompare);
    }
    else
    {
        sort(vp.begin(), vp.end(), lexicoCompare);
    }

    // 3 Reversal
    if (reversal == "true")
    {
        reverse(vp.begin(), vp.end());
    }

    // 4. output
    for (int i = 0; i < n; i++)
    {
        cout << vp[i].first << endl;
    }
}

signed main()
{

    solve();

    return 0;
}
