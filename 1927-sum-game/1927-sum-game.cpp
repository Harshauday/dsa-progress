class Solution {
public:
    bool sumGame(string num) {
        int n = num.length();
        int sumL = 0, sumR = 0;
        int qL = 0, qR = 0;
        
        // Step 1: Calculate sums and question mark counts for both halves
        for (int i = 0; i < n / 2; ++i) {
            if (num[i] == '?') {
                qL++;
            } else {
                sumL += num[i] - '0';
            }
        }
        
        for (int i = n / 2; i < n; ++i) {
            if (num[i] == '?') {
                qR++;
            } else {
                sumR += num[i] - '0';
            }
        }
        
        // Step 2: If the total number of turns is odd, Alice always wins
        if ((qL + qR) % 2 != 0) {
            return true;
        }
        
        // Step 3: Check if Bob can perfectly balance the sums using his pairs
        // Alice wins if the balance cannot be perfectly achieved
        return (sumL - sumR) != (qR - qL) / 2 * 9;
    }
};
