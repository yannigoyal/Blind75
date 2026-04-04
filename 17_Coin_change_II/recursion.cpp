/*
TC:
- Exponential (≈ 2^n)
- At each index → take / not take → branching

SC:
- O(amount)
- Recursion stack (depth depends on amount)

Logic:
- Try all combinations using take / not take
- Take → stay at same index (infinite supply)
- Not take → move to next index

Problem:
- Same states (index, remaining) recomputed multiple times
- Leads to TLE
*/

int f(int index, int remaining, vector<int>& coins) {
    if (remaining == 0)
        return 1;
    if (index == coins.size())
        return 0;
    int take = 0;
    if (coins[index] <= remaining) {
        take = f(index, remaining - coins[index], coins);
    }
    int notTake = f(index + 1, remaining, coins);
    return take + notTake;
}

int change(int amount, vector<int>& coins) { 
  return f(0, amount, coins);
}
