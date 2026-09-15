class Solution {
public:
    vector<vector<int>> generate(int numRows) {

        vector<vector<int>> vec;
        vec.push_back({1});
        if(numRows==1){
            return vec;
        }
        vec.push_back({1, 1});
        for (int i = 2; i < numRows; i++) {
            vector<int> temp;
            for (int j = 0; j <= i ; j++) {

                if (j == 0 || j == i ) {
                    temp.push_back(1);
                } else {
                    temp.push_back(vec[i-1][j] + vec[i-1][j - 1]);
                }
            }
            vec.push_back(temp);
        }
        return vec;
    }
};