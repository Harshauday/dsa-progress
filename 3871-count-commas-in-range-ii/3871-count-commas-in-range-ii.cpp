
class Solution {
public:
    long long countCommas(long long n) {
        long long total_commas = 0;
        long long threshold = 1000;

        // Loop through comma thresholds: 1,000, then 1,000,000, up to 10^15
        while (n >= threshold) {
            // Count how many numbers are greater than or equal to this threshold
            total_commas += (n - threshold + 1);
            
            // Move to the next comma placement tier (multiply by 1000)
            // Using a safety check to prevent long long overflow beyond 10^15
            if (threshold > 1000000000000LL) { 
                break; 
            }
            threshold *= 1000;
        }

        return total_commas;
    }
};
