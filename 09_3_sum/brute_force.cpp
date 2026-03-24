// 3 Sum
// TC: O(n^3) SC: O(k), where k = no of duplicate sets

// Store the size of the array in n and declare a set<vector<int>> to automatically handle duplicate triplets.
/*
1. Run 3 nested loops where i starts from 0, j starts from i+1, and k starts from j+1 to generate all unique index combinations, we are incremententing the j and k as the statement says that i!=j!=k.
2. For each combination check if nums[i] + nums[j] + nums[k] == 0.
3. If the sum is 0, store the triplet in a temporary vector and sort it so that triplets like [-1, 2, -1] and [2, -1, -1] become [-1, -1, 2] and are treated as the same.
4. Insert the sorted triplet into the set — duplicates are automatically ignored by the set.
5. Finally convert the set to vector<vector<int>> using iterator constructor and return it.
*/

vector<vector<int>> threeSum(vector<int>& nums) {
    int n = nums.size();
    set<vector<int>> st;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            for(int k=j+1;k<n;k++) {
                if (nums[i] + nums[j] + nums[k] == 0){
                    vector<int> temp = {nums[i],nums[j],nums[k]};
                    sort(temp.begin(),temp.end());
                    st.insert(temp); 
                } 
            }
        }
    }
    vector<vector<int>> res(st.begin(), st.end());
    return res;
}
