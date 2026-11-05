class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int pro=1, num=0;
        for(int& i: nums){
            if(i==0) num++;
            else pro*=i;
        }
        if(num>1){
            vector<int> ans(nums.size(), 0);
            return ans;
        }
        else if(num==1){
            vector<int> ans(nums.size());
            for(int i=0;i<nums.size();i++){
                if(nums[i]==0){
                    ans[i]=pro;
                }
                else ans[i]=0;
            }
            return ans;
        }
        vector<int> ans(nums.size());
        for(int i=0;i<nums.size();i++){
            ans[i]=pro/nums[i];
        }
        return ans;
    }
};
