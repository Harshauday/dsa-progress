#include <vector>
#include <numeric>
#include <algorithm>

class Solution {
private:
    
    long long countAmounts(long long target, const std::vector<int>& coins) {
        int n = coins.size();
        long long count = 0;
        int totalSubsets = 1 << n; // 2^n combinations

        // Iterate through all possible subsets (excluding empty subset 0)
        for (int mask = 1; mask < totalSubsets; ++mask) {
            long long currentLcm = 1;
            int elementsInSubset = 0;

            for (int i = 0; i < n; ++i) {
                if (mask & (1 << i)) {
                    // C++17 std::lcm calculates Least Common Multiple
                    currentLcm = std::lcm(currentLcm, coins[i]);
                    elementsInSubset++;
                }
            }

            // Inclusion-Exclusion Principle
            if (elementsInSubset % 2 == 1) {
                count += target / currentLcm; // Odd number of elements -> Add
            } else {
                count -= target / currentLcm; // Even number of elements -> Subtract
            }
        }
        return count;
    }

public:
    long long findKthSmallest(std::vector<int>& coins, int k) {
        // Find the minimum coin value to establish search boundaries
        long long minCoin = *std::min_element(coins.begin(), coins.end());
        
        long long low = 1;
        long long high = minCoin * k; // Absolute upper bound
        long long ans = high;

        // Perform Binary Search
        while (low <= high) {
            long long mid = low + (high - low) / 2;

            if (countAmounts(mid, coins) >= k) {
                ans = mid;       // Potential answer found, try to find a smaller one
                high = mid - 1;
            } else {
                low = mid + 1;   // Not enough combinations, push lower bound up
            }
        }
        return ans;
    }
};
