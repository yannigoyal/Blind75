/*
We reverse bits using bitwise operations.

In each step:
- Extract last bit using (n & 1)
- Left shift result to make space
- Add extracted bit to result
- Right shift n to process next bit

Repeat this process 32 times (for 32 bits)

Result: bits are reversed
TC: O(1)  (constant 32 iterations)
*/

int reverseBits(int n) {
    int result = 0;

    for(int i = 0 ;i <32;i++ ) {
        int bit = n&1;
        result = result<<1;
        result = result | bit;
        n = n>>1;
    }
    return result;
}
