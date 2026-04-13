/*
DSA Intuition (Jump Game - Greedy)

1. Represent:
   - maxReach = farthest index we can reach so far

2. Choices:
   - At each index i, check if i <= maxReach
   - Update maxReach = max(maxReach, i + nums[i])

3. Combine:
   - If we ever reach i > maxReach → return false
   - If we finish loop → return true

TC: O(n)  
SC: O(1)
*/

bool canJump(vector<int>& nums) {
    int maxReach = 0;

    for(int i = 0; i < nums.size(); i++) {
        if(i > maxReach) return false;
        maxReach = max(maxReach, i + nums[i]);
    }
    return true;
}
