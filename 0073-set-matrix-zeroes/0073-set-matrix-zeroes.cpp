class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        vector<int> idx;
        int count = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (matrix[i][j] == 0) {
                    idx.push_back(count);
                    
                }
                count++;
            }
        }
        
        for (int i = 0; i < idx.size(); i++) {
            int val = idx[i];
            int row = val / m;
            int col = val % m;
            
            for (int i = 0; i < m; i++) {
                matrix[row][i]=0;
            }
            for (int i = 0; i < n; i++) {
                matrix[i][col]=0;
            }
        }
    }
};