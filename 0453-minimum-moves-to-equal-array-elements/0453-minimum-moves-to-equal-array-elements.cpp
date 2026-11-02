class Solution {
public:
    int minMoves(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        int moves=0,lar=nums[0];
        for(int i=0;i<n;i++){
            moves+=abs(nums[i]-lar);
        }
        return moves;
    }
};