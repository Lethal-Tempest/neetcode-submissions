class Solution {
public:
    int bs(vector<int> nums, int target, int lo, int hi, vector<int> pos){
        // cout<<lo<<" "<<hi<<endl;
        while(lo<=hi){
            int mid=lo+(hi-lo)/2;
            if(target<nums[pos[mid]]) hi=mid-1;
            else if(target>nums[pos[mid]]) lo=mid+1;
            else return pos[mid];
        }
        return -1;
    }
    vector<int> twoSum(vector<int>& nums, int target) {
        int n=nums.size();
        vector<int> pos(n);
        for(int i=0;i<n;i++) pos[i]=i;
        sort(pos.begin(), pos.end(), [&](int a, int b){
            return nums[a]<nums[b];
        });
        for(int i=0;i<n;i++){
            int j=bs(nums, target-nums[pos[i]], i+1, n-1, pos);
            if(j!=-1) return {min(pos[i], j), max(pos[i], j)};
        }
        return {-1, -1};
    }
};
