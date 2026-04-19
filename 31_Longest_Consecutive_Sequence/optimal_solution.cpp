/*
    Approach: HashSet + Starting Point Trick
    -----------------------------------------
    - Put all numbers into an unordered_set (duplicates auto-removed).
    - For each unique number, check if it's the START of a sequence:
        * A number 'num' is a starter only if 'num-1' is NOT in the set.
        * If num-1 exists, some other number will start that chain.
    - From a starter, keep extending (num+1, num+2, ...) while found in set.
    - Track the maximum chain length.

    Key Idea:
    - Iterating over the SET (not nums) avoids duplicate work on repeated values.
    - Only starting from "chain starters" ensures each element is visited
      at most once in the while loop, giving O(n) overall.

    TC: O(n)   // each number touched at most twice (insert + chain walk)
    SC: O(n)   // hash set stores all unique numbers
*/
int longestConsecutive(vector<int>& nums) {
    if (nums.empty())
        return 0;
    unordered_set<int> s(nums.begin(), nums.end());

    int maxLen = 0;

    for (int num : s) {
        if (!s.count(num - 1)) {
            int currNum = num;
            int currLen = 1;

            while (s.count(currNum + 1)) {
                currNum++;
                currLen++;
            }
            maxLen = max(maxLen, currLen);
        }
    }
    return maxLen;
}
