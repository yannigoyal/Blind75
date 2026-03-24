// 3 Sum
// TC: O(n^2) SC: O(k), where k = no of duplicate sets

/*
    1. Sort the array.
    2. Iterate through the array and for each element, use two pointers to find 2 more value that will sum to the arr[i].
    3. If the sum is equal to zero, add the triplet to the result.
    4. If the sum is less than zero, move the left pointer to the right to increase the sum.
    5. If the sum is greater than zero, move the right pointer to the left to decrease the sum.
    6. Skip duplicate elements to avoid repeating the same triplets.
*/
vector<vector<int>> threeSum(vector<int>& arr) {
    int n = arr.size();
    sort(arr.begin(), arr.end());
    vector<vector<int>> ans;
    for(int i =0;i<n;i++) {
        if(i>0 && arr[i] == arr[i-1]) continue;
        int left = i+1,right=n-1;

        while(left<right) {
            int sum = arr[i]+arr[left] +arr[right];

            if(sum == 0) {
                ans.push_back({arr[i],arr[left],arr[right]});
                left++;
                right--;

                while(left<right && arr[left] == arr[left-1] ) left++;
                while(left<right && arr[right] == arr[right+1]) right--;
            } else if(sum<0) left++;
            else{
                right--;
            }
        }
    }
    return ans;

}