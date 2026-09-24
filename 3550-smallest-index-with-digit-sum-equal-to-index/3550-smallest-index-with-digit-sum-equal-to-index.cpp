class Solution {
public:
    int smallestIndex(vector<int>& nums) {
        for(int i=0;i<nums.size();i++){
            string s=to_string(nums[i]);
            int count=0;
            for(int j=0;j<s.size();j++){
                count+=s[j]-'0';
            }
            if(i==count){
                return count;
            }
        }
        return -1;
    }
};