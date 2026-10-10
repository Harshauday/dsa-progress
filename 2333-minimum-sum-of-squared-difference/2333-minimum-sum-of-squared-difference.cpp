class Solution {
public:
    long long minSumSquareDiff(vector<int>& nums1, vector<int>& nums2, int k1, int k2) {
        int n = nums1.size();
        long long k = k1 + k2;
        
        // Find the maximum possible difference to size our bucket array
        int max_diff = 0;
        for (int i = 0; i < n; i++) {
            max_diff = max(max_diff, abs(nums1[i] - nums2[i]));
        }
        
        if (max_diff == 0) return 0;
        
        // Count frequencies of each difference
        vector<long long> bucket(max_diff + 1, 0);
        for (int i = 0; i < n; i++) {
            bucket[abs(nums1[i] - nums2[i])]++;
        }
        
        // Process differences from largest down to smallest in batches
        for (int diff = max_diff; diff > 0; diff--) {
            if (bucket[diff] == 0) continue;
            
            // If we have enough k to reduce all elements at this difference level
            if (k >= bucket[diff]) {
                k -= bucket[diff];
                bucket[diff - 1] += bucket[diff];
                bucket[diff] = 0;
            } else {
                // If k is exhausted before reducing all elements at this level
                bucket[diff - 1] += k;
                bucket[diff] -= k;
                k = 0;
                break;
            }
        }
        
        // Calculate the final sum of square differences safely using long long
        long long ans = 0;
        for (long long diff = 1; diff <= max_diff; diff++) {
            if (bucket[diff] > 0) {
                ans += bucket[diff] * (diff * diff);
            }
        }
        
        return ans;
    }
};
