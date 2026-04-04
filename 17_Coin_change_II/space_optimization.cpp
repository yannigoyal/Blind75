/*
Why unsigned long long?
- Number of combinations can become large
- Prevents overflow during calculation
- Final answer fits in int, but intermediate values may not

Time Complexity:
- O(n × amount)
- Outer loop runs for all coins
- Inner loop runs for all amounts

Space Complexity:
- O(amount) - Using 1D DP array

Logic:
- dp[i] → number of ways to make amount i
- dp[0] = 1 → one way to make 0 (choose nothing)

Transition:
- dp[i] += dp[i - coin]
- Add ways of forming remaining amount using current coin

Important:
- Coins loop is outer → ensures combinations (not permutations)

Summary:
- Bottom-up DP
- Efficient solution without recursion
*/

int change(int amount, vector<int>& coins) { 

    vector<unsigned long long>dp(amount+1,0);
    dp[0] = 1;

    for(int coin:coins) {
        for(int i = coin; i<=amount;i++) {
            dp[i] += dp[i-coin];
        }
    } 

    return dp[amount]; 
}
