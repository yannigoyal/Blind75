/*
DSA Intuition (Jump Game - Recursion)

1. Represent:
   - f(i) = can we reach last index starting from index i

2. Choices:
   - From index i, try all jumps from 1 → nums[i]
   - Move to (i + step) recursively

3. Combine:
   - If any path returns true → return true
   - Else → return false

TC: O(2^n) (worst case)  
SC: O(n) recursion stack
*/
bool f(int i, vector<int> &nums) {
    int n = nums.size();

    if(i >=n-1) return true; 
    if(nums[i] == 0) return false;
    for(int step = 1; step<=nums[i]; i++) {
        if(f(i+step, nums)) return true;
    }
    return false;
}
bool canJump(vector<int>& nums) {
    return f(0, nums); 
}
