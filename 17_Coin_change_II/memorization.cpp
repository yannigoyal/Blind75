/*
TC:
- O(n × amount)
- Each state (index, remaining) computed once

SC:
- O(n × amount) → DP array + O(amount) recursion stack

Logic:
- Store result of each state in dp[index][remaining]
- If already computed → return directly

Benefit:
- Removes overlapping subproblems
- Converts exponential → polynomial
*/

int dp[300][5001];
int f(int index, int remaining, vector<int>& coins) {
    if (remaining == 0)
        return 1;
    if (index == coins.size())
        return 0;
    if(dp[index][remaining] != -1) {
        return dp[index][remaining];
    }
    int take = 0;

    if (coins[index] <= remaining) {
        take = f(index, remaining - coins[index], coins);
    }
    int notTake = f(index + 1, remaining, coins);
    return dp[index][remaining] = take + notTake;
}
int change(int amount, vector<int>& coins) { 
    memset(dp,-1,sizeof(dp));
    return f(0, amount, coins); 
}
