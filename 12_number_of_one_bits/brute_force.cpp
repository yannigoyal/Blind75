#include <iostream>
using namespace std;

// Function to count number of 1 bits (Hamming Weight)
// Brute Force Approach

int hammingWeight(int n) {
    int count = 0;

    // Traverse all bits
    while (n > 0) {
        // Check last bit
        if (n & 1) {
            count++;
        }
        // Right shift to check next bit
        n = n >> 1;
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
1. Check last bit using (n & 1)
2. If it's 1 → increase count
3. Right shift n (n >> 1)
4. Repeat until n becomes 0

Time Complexity: O(32) ≈ O(1)
*/
