#include <iostream>
using namespace std;

// Function to count number of 1 bits
// Optimal Approach

int hammingWeight(int n) {
    int count = 0;

    while (n != 0) {
        // Remove the last set bit
        n = n & (n - 1);
        count++;
    }

    return count;
}

int main() {
    int n = 11; // Binary: 1011
    cout << "Number of 1 bits: " << hammingWeight(n) << endl;
    return 0;
}

/*
Explanation:
n & (n - 1) removes the last set bit (1)

Example:
n = 1011
n-1 = 1010
n&(n-1) = 1010

Each iteration removes one '1'

Time Complexity: O(number of set bits)
→ Faster than brute force
*/
