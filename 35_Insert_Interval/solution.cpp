/*
    Approach: 3-Phase Strategy (Before → Merge → After)

    1. Phase 1 (Before): Add all intervals that end BEFORE newInterval starts.
                         Condition: intervals[i][1] < newInterval[0]

    2. Phase 2 (Merge):  Merge all overlapping intervals into newInterval
                         by updating its start to min and end to max.
                         Condition: intervals[i][0] <= newInterval[1]

    3. Push the merged newInterval into result (exactly once).

    4. Phase 3 (After):  Add all remaining intervals that come AFTER newInterval.

    Pointer 'i' moves forward only — each interval is visited once.

    TC: O(n)
    SC: O(n)   // for result array (auxiliary: O(1))
*/
 
vector<vector<int>> insert(vector<vector<int>>& intervals,
                           vector<int>& newInterval) {
    vector<vector<int>> result;
    int n = intervals.size();
    int i = 0;

    // 🟢 Phase 1: Add 'before' interval
    while (i < n && intervals[i][1] < newInterval[0]) {
        result.push_back(intervals[i]);
        i++;
    }

    // 🟡 Phase 2: Merge overlapping interval
    while (i < n && intervals[i][0] <= newInterval[1]) {
        newInterval[0] = min(newInterval[0], intervals[i][0]);
        newInterval[1] = max(newInterval[1], intervals[i][1]);
        i++;
    }

    // Add merged newInterval
    result.push_back(newInterval);

    // 🔵 Phase 3: Add 'after' interval
    while (i < n) {
        result.push_back(intervals[i]);
        i++;
    }

    return result;
}
