class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        unordered_set<int>s;
        for(int num:nums){
            s.insert(num);
        }
        int temp=1;
        bool check=true;
        while(check){
            if(!s.count(k*temp)){
                check=false;
                
            }else{
                temp++;
            }
        }
        return k*temp;
    }
};