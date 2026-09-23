class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int total = 0;
        for (int num : nums) total += num;
        int target = total - x;
        if (target < 0) return -1;  // Not possible if x > total sum
        if (target == 0) return nums.size();  // Remove all elements

        int left = 0, current_sum = 0, max_len = -1;
        for (int right = 0; right < nums.size(); right++) {
            current_sum += nums[right];
            while (current_sum > target) {
                current_sum -= nums[left];
                left++;
            }
            if (current_sum == target) {
                max_len = max(max_len, right - left + 1);
            }
        }
        return max_len == -1 ? -1 : (int)nums.size() - max_len;
    }
};
