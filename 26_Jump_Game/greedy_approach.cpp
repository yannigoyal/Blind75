/*
DSA Intuition (Jump Game - Greedy)

1. Represent:
   - maxReach = farthest index we can reach till now

2. Choices:
   - At each index i, check if we can reach i (i <= maxReach)
   - Update maxReach = max(maxReach, i + nums[i])

3. Combine:
   - If any i > maxReach → cannot proceed → return false
   - If loop completes → we can reach end → return true

TC: O(n)  
SC: O(1)
*/
bool canJump(vector<int>& nums) {
    int n = nums.size();
    int maxReach = 0;

    for(int i = 0 ; i < n ;i++) {
        if(i > maxReach) return false;

        maxReach = max(maxReach, i +nums[i]);
    }
    return true;
}
