#include <iostream>
#include <functional>
using namespace std;
int main()
{
    int n;
    std::cout << "Enter the number of disks: ";
    std::cin >> n;

    // Function to print the steps to solve Tower of Hanoi
    std::function<void(int, char, char, char)> towerOfHanoi = [&](int disks, char source, char target, char auxiliary)
    {
        if (disks == 1)
        {
            std::cout << "Move disk 1 from rod " << source << " to rod " << target << std::endl;
            return;
        }
        towerOfHanoi(disks - 1, source, auxiliary, target);
        std::cout << "Move disk " << disks << " from rod " << source << " to rod " << target << std::endl;
        towerOfHanoi(disks - 1, auxiliary, target, source);
    };

    towerOfHanoi(n, 'A', 'C', 'B'); // A, B and C are names of rods
    return 0;
}
