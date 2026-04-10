/*
DSA Intuition (House Robber - Recursion)

1. Represent:
   - f(i) = maximum money we can rob starting from index i

2. Choices:
   - Rob current house → nums[i] + f(i+2)
   - Skip current house → f(i+1)

3. Combine:
   - Take max of both → max(rob, skip)

TC: O(2^n) Exponential
SC: O(n)
*/
int f(int i, vector<int>& nums) {
    if (i >= nums.size()) return 0;

    int rob = nums[i] + f(i + 2, nums);
    int skip = f(i + 1, nums);

    return max(rob, skip);
}

int rob(vector<int>& nums) {
    return f(0, nums);
}
