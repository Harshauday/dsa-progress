class Solution {
public:
    bool checkDivisibility(int n) {
        int sum=0,pro=1;
        string s=to_string(n);
        for(auto ch:s){
            int num=ch-'0';
            sum+=num;
            pro*=num;
        }
        return n%(sum+pro)==0;
    }
};