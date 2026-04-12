/*
TC: O(nlogn), SC: O(1)

We run a loop from 0 to n. For each number, we check its last bit (whether it is 1 or 0) using num % 2 
and increment the count accordingly.
Then we remove the last bit by dividing the number by 2. 
This continues until the number becomes 0. Finally, we store the count of set bits in the array.
*/



vector<int> countBits(int n) {
    vector<int> ans(n+1,0);
    for(int i= 0;i<=n;i++) {
        int num = i;
        int count =0;
        while(num) {
            count += num%2;
            num/=2;
        }
        ans[i] = count;
    }
    return ans;
}
