/*
TC:
- O(n * n)
- Total states = n (i) × n (prev)
- Each state computed once

SC:
- O(n * n) → DP table
- + O(n) recursion stack

DP State:
- dp[i][prev+1]
- i → current index
- prev → index of previous element (-1 handled using prev+1)

Logic:
- f(i, prev) → LIS starting from index i with previous index = prev

Choices:
1. Take:
   - if prev == -1 OR nums[i] > nums[prev]
   - include element → 1 + f(i+1, i)
2. Not Take:
   - skip element → f(i+1, prev)
- Store result in dp[i][prev+1]

Base Case:
- if i == n → return 0

// prev = -1 → we shift index by +1
dp[i][prev + 1]

Key Idea:
- Avoid recomputation of same states (i, prev)
- Convert exponential recursion → polynomial DP
*/
int f(int i, int prev, vector<int> & nums,vector<vector<int>> &dp) {
    if(i ==nums.size())
    return 0;

    if(dp[i][prev+1] !=-1){
        return dp[i][prev+1];
    }
    int take=0;
    if(prev==-1 ||nums[i]>nums[prev]){
        take = 1+f(i+1,i,nums,dp);

    }
    int nonTake=f(i+1,prev,nums,dp);
    return dp[i][prev+1]=max(take, nonTake);
}
int lengthOfLIS(vector<int>& nums) {
    int n=nums.size();
    vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
    return f(0,-1,nums,dp);
}
