/*
Approach: Binary Search (Patience Sorting)

TC: O(n log n)

SC: O(n)

Logic:
- Maintain a temporary array (lis)

- For each element:
    → find position using lower_bound
    → replace element OR append

Important:
- lis does NOT store actual subsequence
- It stores best possible tail values
*/

int lengthOfLIS(vector<int>& nums) {
    vector<int> lis;

    for (int num : nums) {
        auto it = lower_bound(lis.begin(), lis.end(), num);

        if (it == lis.end()) {
            lis.push_back(num);
        } else {
            *it = num;
        }
    }

    return lis.size();
}
