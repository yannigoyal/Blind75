// ============================================
// BEST TIME TO BUY AND SELL STOCK - OPTIMAL
// TC: O(n)  SC: O(1)
// ============================================

// Why NOT two pointer?
// - Two pointer would need sorting
// - Order of days matters, can't sort

// Why NOT HashMap?
// - No pair/complement relationship here

// Key Insight:
// Track minimum price seen so far
// At each day calculate profit if sold today
// Update min as we go

int maxProfit(vector<int>& prices) {
    int n = prices.size();
    int maxProfit = 0;
    int mini = prices[0];

    for (int i = 1; i < n; i++) {
        int cost = prices[i] - mini;
        maxProfit = max(maxProfit, cost);
        mini = min(mini, prices[i]);
    }

    return maxProfit;
}
