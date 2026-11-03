class Solution {
public:
    int minMoves(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        int lar=nums[n-1],moves=0;
        for(int i=0;i<n;i++){
            moves+=abs(nums[i]-lar);
        }
        return moves;
    }
};