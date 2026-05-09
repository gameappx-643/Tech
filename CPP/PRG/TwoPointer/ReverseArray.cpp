/* Author: Rajesh Kumar Yadav
    Created At: Wed 19 Nov 2025 18:53:59
*/
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

void reverseArrary(int arr[], int len)
{
    int *start = arr;

    int *end = arr + len - 1;
    for (; start < end;)
    {
        int temp = *start;
        *start = *end;
        *end = temp;
        start++;
        end--;
    }
}

void printArray(int arr[], int len)
{

    // int len = sizeof(arr) / sizeof(arr[0]); // This will not work as expected because arr decays to pointer and lenth was 2
    for (int i = 0; i < len; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void solve()
{
    int arr[] = {
        1,
        2,
        3,
        4,
        5,
        6,
    };
    /*
    Short answer:

    sizeof(arr) / sizeof(arr[0]) gives the correct element count only when arr is an actual array object in that scope.
    In a function parameter declared as int arr[] (or int *arr) the array decays to a pointer, so sizeof(arr) is size of a pointer (e.g. 8) not total bytes of elements (e.g. 24). 8/4 == 2, hence your len == 2.
    Fixes (pick one):

    Compute length where the array is declared and pass it to the function (simple).
    Use std::vector or std::array (they know their size).
    Use a template that takes the array by reference to preserve size: template<size_t N> void f(int (&arr)[N]) { /* N is length */

    int len = sizeof(arr) / sizeof(arr[0]);
    reverseArrary(arr, len);
    printArray(arr, len);
}

signed main()
{
    solve();
    return 0;
}
