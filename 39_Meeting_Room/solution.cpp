/*
Approach:
Sort the intervals based on start time. Then check adjacent intervals.
If the end time of current interval is greater than the start time of next,
it means there is an overlap → cannot attend all meetings.

TC: O(n log n)
SC: O(1)
*/
bool canAttend(vector<vector<int>> &arr) {
    sort(arr.begin(),arr.end());
    
    for(int i = 0 ; i < arr.size()-1 ;i++) {
        if(arr[i][1] > arr[i+1][0])
            return false;
    }
    return true;
}
