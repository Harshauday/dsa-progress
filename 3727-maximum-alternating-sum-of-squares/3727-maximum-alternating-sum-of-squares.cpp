class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        int n = nums.size();
        vector<long long> squares(n);
        
        // Convert all elements to their squares
        for (int i = 0; i < n; i++) {
            squares[i] = (long long)nums[i] * nums[i];
        }
        
        // Sort squares in ascending order
        sort(squares.begin(), squares.end());
        
        long long ans = 0;
        // There are exactly (n / 2) negative positions
        int negative_count = n / 2; 
        
        // The smallest elements go to the negative positions
        for (int i = 0; i < negative_count; i++) {
            ans -= squares[i];
        }
        
        // The remaining largest elements go to the positive positions
        for (int i = negative_count; i < n; i++) {
            ans += squares[i];
        }
        
        return ans;
    }
};
