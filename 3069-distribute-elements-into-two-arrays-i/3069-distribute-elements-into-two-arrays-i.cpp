class Solution {
public:
    vector<int> resultArray(vector<int>& nums) {
        vector<int>arr1,arr2;
        arr1.push_back(nums[0]);
        arr2.push_back(nums[1]);
        int m=0,n=0;
        for(int i=2;i<nums.size();i++){
            if(arr1[m]>arr2[n]){
                arr1.push_back(nums[i]);
                m++;
            }else{
                arr2.push_back(nums[i]);
                n++;
            }
        }
        for(int i=0;i<=n;i++){
            arr1.push_back(arr2[i]);
        }
        
        return arr1;
    }
};