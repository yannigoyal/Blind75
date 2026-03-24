// 3 Sum
// TC: O(n^2) SC: O(k), where k = no of duplicate sets

/*
1. We Will use a set to store the unique triplets. 
2. We will iterate through the array and for each element, we will use a hashset to find the third element that can form a triplet with the current element and the next element. 
3. If we find such an element, we will sort the triplet and insert it into the set. 
4. Finally, we will convert the set to a vector and return it.
*/

vector<vector<int>> threeSum(vector<int>& arr) {
    int n = arr.size();
    set<vector<int>> st;
    for (int i = 0; i < n; i++) {
        set<int>hashset;
        for (int j = i + 1; j < n; j++) {
            int third = -(nums[i] + nums[j]);
            if(hashset.find(third) != hashset.end()) {
                vector<int> temp = {nums[i], nums[j], third};
                sort(temp.begin(), temp.end());
                st.insert(temp);
            } 
            hashset.insert(nums[j]);
        }
    }
    vector<vector<int>> res(st.begin(), st.end());
    return res;
}
