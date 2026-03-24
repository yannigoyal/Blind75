/*
  Container With Most Water

  TC: O(n)
  SC: O(1)

  Key Idea:
  2 pointers work when:
  - You can eliminate possibilities logically
  - Not necessarily when the array is sorted

  We are solving:
  Area = min(height[l], height[r]) * (r - l)

  Observations:
  - Width -> decreasing every step
  - Height -> we try to improve

  Core Logic:
  If height[left] < height[right]:
  - Area depends on height[left]
  - Because it is the minimum

  Rule:
  Always move the smaller pointer

  Important Insight:
  This is not a sorting problem, it is a decision problem.
  At each step we eliminate one pointer based on which side limits the area.
*/

int maxArea(vector<int>& height) {
    int n = height.size();
    int left=0,right=n-1;
    int maxi = INT_MIN;

    while(left<right) {
        int area = min(height[left], height[right]) * (right-left);
        maxi = max(maxi, area);
        if(height[left] < height[right]) {
            left++;
        } else {
            right--;
        }
    }
    return maxi;
}
