/*
 * Approach: Sort + Greedy Merge
 * 
 * 1. Sort intervals by start time → guarantees that overlapping
 *    intervals will be adjacent in the array.
 * 
 * 2. Push the first interval into the result list as our starting point.
 * 
 * 3. For each next interval:
 *    - If it overlaps with the last interval in result 
 *      (i.e., result.back().end >= current.start), 
 *      extend the end to max(result.back().end, current.end).
 *    - Otherwise, push it as a new interval.
 * 
 * Note: We compare against result.back() (the merged interval), 
 *       not the original previous one, since merging may have 
 *       extended the end further.
 * 
 * TC: O(n log n)  — sorting dominates, loop is O(n)
 * SC: O(n)        — for the result array (O(log n) aux for sort)
*/
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> result;
        int n = intervals.size();

        // Step 1: Sort by start time
        sort(intervals.begin(), intervals.end());

        // Step 2: Seed result with the first interval
        result.push_back(intervals[0]);

        // Step 3: Iterate and either merge or append
        for (int i = 1; i < n; i++) {
            if (result.back()[1] >= intervals[i][0]) {
                // Overlap → extend the end of the last merged interval
                result.back()[1] = max(result.back()[1], intervals[i][1]);
            } else {
                // No overlap → add as a new interval
                result.push_back(intervals[i]);
            }
        }

        return result;
    }
};

