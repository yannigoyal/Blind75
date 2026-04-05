/*
Problem: Longest Increasing Subsequence (LIS)
Approach: Recursion (Take / Not Take)

TC:
- O(2^n) → Exponential
- At every index we have 2 choices (take / not take)

SC:
- O(n) → Recursion stack (max depth n)

Logic:
- f(i, prev) → LIS starting from index i with previous index = prev
- Take:
    if prev == -1 OR nums[i] > nums[prev]
    → include current element → 1 + f(i+1, i)
- Not Take:
    → skip current element → f(i+1, prev)
- Return max(take, notTake)

Base Case:
- If i == n → return 0

Key Idea:
- Try all subsequences and pick the longest increasing one

Problem with Recursion:
- Same states (i, prev) are recomputed many times
- Leads to exponential time → TLE

Example:
- f(3,1) can be called multiple times from different paths
Conclusion:
- Overlapping subproblems → need DP (memoization)
*/
int f(int i, int prev, vector<int> & nums) {
    if(i ==nums.size())
    return 0;

    int take=0;
    if(prev==-1 ||nums[i]>nums[prev]){
        take = 1+f(i+1,i,nums);

    }
    int nonTake=f(i+1,prev,nums);
    return max(take, nonTake);
}
int lengthOfLIS(vector<int>& nums) {
    return f(0,-1,nums);
}
