/*
  Step 1: Represent problem in terms of index
  → index tells which candidate we are currently exploring
  → target tells how much sum is still needed

  Step 2: Try all possibilities (choices)
  → At each step we have 2 choices:
     1. Pick the current element → reduce target, stay at same index (reuse allowed)
     2. Skip the current element → move to next index

  Step 3: Combine results
  → If target == 0 → valid combination found → add to result
  → If index reaches end or target < 0 → stop (invalid path)

  TC: ~O(2^n * k)
  SC: ~O(k) (recursion stack + current list)
*/
void f(int index, int target, vector<int>& current,
    vector<vector<int>>& result, vector<int>& candidates) {

    if (target == 0) {
        result.push_back(current);
        return;
    }

    if (index == candidates.size())
        return;

    if (candidates[index] <= target) {
        current.push_back(candidates[index]);
        f(index, target - candidates[index], current, result, candidates);
        current.pop_back();
    }

    f(index + 1, target, current, result, candidates);
}
vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
    vector<vector<int>> result;
    vector<int> current;
    f(0, target, current, result, candidates);
    return result;
}
