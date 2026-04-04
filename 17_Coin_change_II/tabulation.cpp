/*
TC:
- O(n × amount) - Filling DP table once

SC:
- O(n × amount) - 2D DP table

Logic:
- dp[index][remaining] → ways to form remaining using coins from index

Base Case:
- dp[index][0] = 1 (one way to make 0)

Transition:
- take     = dp[index][remaining - coins[index]]
- notTake  = dp[index + 1][remaining]

Important:
- Fill index from n-1 → 0 (bottom-up)
- Remove recursion completely
*/
int change(int amount, vector<int>& coins) { 
    int n = coins.size();
    vector<vector<long long>> dp(n+1, vector<long long>(amount+1, 0));

    for(int i = 0;i<=n;i++){
        dp[i][0] = 1;
    }
    for(int index = n-1;index>=0;index--) {
        for(int remaining =0;remaining<=amount;remaining++) {
            long long take = 0;
            if(coins[index] <= remaining) {
                take = dp[index][remaining-coins[index]];
            }
            int nonTake = dp[index+1][remaining];
            dp[index][remaining] = take+nonTake;
        }
    }
    return dp[0][amount]; 
}
