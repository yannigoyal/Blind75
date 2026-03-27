// We use the Arithmetic Sum Formula.
//
// Sum of numbers from 0 to n = n * (n + 1) / 2
//
// Calculate expected sum using formula,
// then subtract the actual sum of array elements.
//
// The difference gives the missing number.

int missingNumber(vector<int>& nums) {
    int n = nums.size();
    
    return n*(n+1)*0.5 - accumulate(nums.begin(), nums.end(),0);
}
