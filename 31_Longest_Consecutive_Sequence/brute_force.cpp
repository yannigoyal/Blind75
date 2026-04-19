/*
    Approach: Sorting + Linear Scan
    --------------------------------
    - Sort the array so consecutive numbers come next to each other.
    - Traverse the sorted array and count consecutive sequences:
        * If current == previous  -> duplicate, skip (continue).
        * If current == previous+1 -> part of the sequence, count++.
        * Else -> sequence broken, reset count to 1.
    - Track the maximum sequence length seen so far.

    Key Idea:
    - After sorting, consecutive elements are adjacent,
      so we just need one pass to find the longest run.
    - Duplicates are skipped so they don't break the sequence.

    TC: O(n log n)   // due to sorting
    SC: O(1)         // in-place sort, no extra space
*/
int longestConsecutive(vector<int>& nums) {
    if(nums.empty()) return 0;   
    
    sort(nums.begin(), nums.end());
    
    int count = 1;       // current sequence length (start from 1)
    int maxLen = 1;     
    
    for(int i = 1; i < nums.size(); i++) {
        if(nums[i] == nums[i-1]) {
            continue;    // duplicate skip
        }
        
        if(nums[i] == nums[i-1] + 1) {
            count++;     // consecutive
        } else {
            count = 1;   // sequence broken, reset
        }
        
        maxLen = max(maxLen, count);   // update every iteration
    }
    
    return maxLen;
}

