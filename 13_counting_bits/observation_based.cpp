/*
TC: O(n) SC: O(1), since we are using vector to return the answer array we can neglect that array in space Complexity

For this approach, we use a pattern based on even and odd numbers:

For even numbers:
The number of set bits in i is the same as in i / 2
(because dividing by 2 is equivalent to a right shift)

Example:
2 → 10, 4 → 100
Both have the same number of set bits

For odd numbers:
The number of set bits in i is ans[i / 2] + 1
(because the last bit is always 1)

Example:
3 → 11, 7 → 111
Both have one extra set bit compared to their half

*/

vector<int> countBits(int n) {
    vector<int> ans(n+1,0);
    for(int i= 0;i<=n;i++) {
        
        //for even numbers
        if(i%2 == 0) {
            ans[i] =ans[i/2];
        
        } else {
            ans[i] = ans[i/2]+1;
        }
    }
    return ans;
}
