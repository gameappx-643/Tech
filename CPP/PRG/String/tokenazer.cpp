/* Author: Rajesh Kumar Yadav
    Created At: Thu 30 Oct 2025 12:53:05
*/
#include <iostream>
#include <cstring>
using namespace std;
char *mystrtok(char *str, char delim)
{
    static char *input = NULL;
    if (str != NULL)
    {
        input = str;
    }
    char *token = new char[strlen(input) + 1];
    int i = 0;
    for (; input[i] != '\0'; i++)
    {
        if (input[i] != delim)
        {
            token[i] = input[i];
        }
        else
        {
            token[i] = '\0';
            input = input + i + 1;
            return token;
        }
    }
    // out of the loop
    token[i] = '\0';
    // reset the input as NULL
    input = NULL;
    return token;
}

void solve()
{
    char s[1000];
    cout << "Enter The String : ";
    cin.getline(s, 1000);
    // strtok()
    char *token = mystrtok(s, ' ');
    while (token != NULL)
    {
        cout << token << endl;
        token = mystrtok(NULL, ' ');
    }
}

signed main()
{

    solve();

    return 0;
}
