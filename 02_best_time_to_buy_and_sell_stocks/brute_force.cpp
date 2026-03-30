// ============================================
// BEST TIME TO BUY AND SELL STOCK - BRUTE FORCE
// TC: O(n²)  SC: O(1)
// ============================================
/*
We use two loops to check all possible pairs of buy and sell days. For each day i, we assume we buy the stock on that day.
Then, using the inner loop, we try selling on every future day j > i. We calculate the profit as prices[j] - prices[i] and keep track of the maximum profit.
*/

int maxProfit(vector<int>& prices) {
    int n = prices.size();
    int maxProfit = 0;

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            int profit = prices[j] - prices[i];
            maxProfit = max(maxProfit, profit);
        }
    }

    return maxProfit;
}
