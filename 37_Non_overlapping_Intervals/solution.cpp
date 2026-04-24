/*
Greedy approach:
- Sort intervals by start time
- Track end of last non-overlapping interval (temp)
- If current interval overlaps (temp > start):
    -> Remove one interval (count++)
    -> Keep interval with smaller end (min) to reduce future overlap
- Else:
    -> No overlap, update temp to current end

TC: O(n log n)
SC: O(1)
*/
int eraseOverlapIntervals(vector<vector<int>>& intervals) {
    int temp, count = 0;
    int n = intervals.size();
    sort(intervals.begin(), intervals.end());
    temp = intervals[0][1];
    for (int i = 1; i < n; i++) {
        if (temp > intervals[i][0]) {
            temp = min(temp, intervals[i][1]);
            count++;
        } else {
            temp = intervals[i][1];
        }
    }
    return count;
}
