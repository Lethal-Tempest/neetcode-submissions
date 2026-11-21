class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());
        int n=nums.size();
        for(int& i: nums) cout<<i<<" ";
        cout<<endl;
        for(int i=0;i<n-2;i++){
            if(i>0 && nums[i]==nums[i-1]) continue;
            int target=-nums[i], l=i+1, r=n-1;
            while(l<r){
                int sum=nums[l]+nums[r];
                // cout<<i<<" "<<l<<" "<<r<<"  "<<nums[i]<<" "<<nums[l]<<" "<<nums[r]<<"  "<<target<<" "<<sum<<endl;
                if(sum<target){
                    l++;
                }
                else if(sum>target){
                    r--;
                }
                else {
                    ans.push_back({nums[i], nums[l], nums[r]});
                    l++; r--;
                    while(l>0 && l<r && nums[l-1]==nums[l]) l++;
                    while(r<n-1 && l<r && nums[r+1]==nums[r]) r--;
                }
                
            }
            // cout<<endl;
        }
        return ans;
    }
};
