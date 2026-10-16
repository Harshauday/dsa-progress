class Solution {
    int n;
    vector<long long> sumOfX;
    vector<long long> sumOfX2;
    vector<long long> lazy;
    const int MOD = 1e9 + 7;

    void apply(int node, int start, int end, long long val) {
        long long range_len = end - start + 1;
        // Formula: (x + val)^2 = x^2 + 2*val*x + val^2 * len
        sumOfX2[node] = (sumOfX2[node] + 2 * val * sumOfX[node] % MOD + val * val % MOD * range_len % MOD) % MOD;
        sumOfX[node] = (sumOfX[node] + val * range_len) % MOD;
        lazy[node] = (lazy[node] + val) % MOD;
    }

    void push(int node, int start, int end) {
        if (lazy[node] == 0) return;
        int mid = (start + end) / 2;
        apply(2 * node, start, mid, lazy[node]);
        apply(2 * node + 1, mid + 1, end, lazy[node]);
        lazy[node] = 0;
    }

    void updateRange(int node, int start, int end, int l, int r, int val) {
        if (r < start || end < l) return;
        if (l <= start && end <= r) {
            apply(node, start, end, val);
            return;
        }
        push(node, start, end);
        int mid = (start + end) / 2;
        updateRange(2 * node, start, mid, l, r, val);
        updateRange(2 * node + 1, mid + 1, end, l, r, val);
        sumOfX[node] = (sumOfX[2 * node] + sumOfX[2 * node + 1]) % MOD;
        sumOfX2[node] = (sumOfX2[2 * node] + sumOfX2[2 * node + 1]) % MOD;
    }

public:
    int sumCounts(vector<int>& nums) {
        n = nums.size();
        sumOfX.assign(4 * n, 0);
        sumOfX2.assign(4 * n, 0);
        lazy.assign(4 * n, 0);
        
        long long totalAns = 0;
        unordered_map<int, int> lastSeen; 

        for (int i = 0; i < n; i++) {
            int prevIdx = lastSeen.count(nums[i]) ? lastSeen[nums[i]] : 0;
            
            // Range update for subarrays gaining a brand new distinct item
            updateRange(1, 1, n, prevIdx + 1, i + 1, 1);
            
            totalAns = (totalAns + sumOfX2[1]) % MOD;
            lastSeen[nums[i]] = i + 1;
        }
        return totalAns;
    }
};
