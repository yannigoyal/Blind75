/*
Approach:
We use math formulas for sum and sum of squares of numbers from 1 to n*n.

- Let a = repeating number, b = missing number.
- Compute:
  D1 = expectedSum - actualSum = (b - a)
  D2 = expectedSq - actualSq = (b^2 - a^2)

- Since (b^2 - a^2) = (b - a)(b + a),
  we get:
    b + a = D2 / D1

- Now solve:
    a = (sumAB - D1) / 2
    b = (sumAB + D1) / 2

Return {a, b}.

TC: O(n^2)
SC: O(1)
*/
vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
    long long n = grid.size();
    long long totalSum = 0;
    long long totalSq = 0;

    for (int i = 0; i < grid.size(); ++i) {
        for (int j = 0; j < grid[i].size(); ++j) {
            totalSum += grid[i][j];
            totalSq += (grid[i][j] * grid[i][j]);
        }
    }

    long long expectedSum = n*n*(n*n+1)/2;
    long long expectedSq = n*n*(n*n+1)*(2*n*n+1)/6;

    long long D1 = expectedSum - totalSum;
    long long D2 = expectedSq - totalSq;
    long long sumAB = D2 / D1;
    long long a = (sumAB - D1) / 2;
    long long b = (sumAB + D1) / 2;

    return {(int)a, (int)b};
}
