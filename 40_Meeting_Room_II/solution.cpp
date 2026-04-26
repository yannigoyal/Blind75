/*
 * Minimum Meeting Rooms
 *
 * Pair start & end times → sort by start time.
 * Use a min-heap to track earliest ending meeting.
 *
 * For each meeting:
 *   - top of heap = earliest free room
 *   - start >= top → reuse that room (pop + push)
 *   - start <  top → need new room (just push)
 *
 * heap size at end = rooms needed.
 *
 * TC: O(n log n)  SC: O(n)
 */
int minMeetingRooms(vector<int> &start, vector<int> &end) {
    vector<vector<int>> arr;
    priority_queue<int, vector<int>, greater<int>> minHeap;
    
    for(int i = 0;i<start.size();i++) {
        arr.push_back({start[i], end[i]});
    }
    
    sort(arr.begin(), arr.end());
    
    minHeap.push(arr[0][1]);
    
    
    for(int i = 1 ;i < arr.size();i++) {
        if(arr[i][0] >= minHeap.top()) {
            minHeap.pop();
        }
        minHeap.push(arr[i][1]);
    }
    return minHeap.size();
}
