// We use XOR to find the missing number.
//
// Key properties:
// - a ^ a = 0  (same numbers cancel out)
// - a ^ 0 = a
//
// We XOR all indices (0 to n) and all elements of the array.
// All matching numbers cancel each other,
// and only the missing number remains.
//
// Steps:
// 1. Initialize res = 0
// 2. For each index i:
//      res = res ^ i ^ nums[i]
// 3. Finally, XOR with n (last index)
//
// Result: res contains the missing number
int missingNumber(vector<int>& nums) {
    int res = 0;
    int n = nums.size();
    for(int i = 0 ;i<n;i++) {
        res = res ^ i^nums[i];
    }
    return res ^ n;
}
