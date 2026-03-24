/*
  Brute Force Approach

  TC: O(n^2)
  SC: O(1)

  We check all possible pairs of lines:

  1. Use two loops
  2. Pick two indices i and j where i < j
  3. Calculate area using:
     Area = min(height[i], height[j]) * (j - i)

     Width = (j - i) -> distance between lines
     Height = min(height[i], height[j])

  Important Points:
  - We treat water like a rectangle
  - Height = shorter bar
  - Width = distance between bars

  Note:
  Water level is bounded by the shorter line because any excess water would overflow
*/

int maxArea(vector<int>& height) {
    int n = height.size();
    int maxi = 0;
    for(int i = 0 ; i < n ;i++) {
        for(int j = i+1 ; j<n;j++) {
            int area = min(height[i], height[j]) * (j-i);
            maxi = max(maxi, area);
        }
    }
    return maxi;
}
