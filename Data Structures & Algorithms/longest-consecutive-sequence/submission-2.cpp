class Solution {
public:
    int fill(unordered_map<int, int>& mp, int key){
        if(!mp.count(key)) return 0;
        if(mp[key]!=0) return mp[key];
        mp[key]=1+fill(mp, key+1);
        // cout<<mp[key]<<endl;
        return mp[key];
    }
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int, int> mp;
        int ans=0;
        for(int& i: nums) mp[i]=0;
        for(auto [key, val]:mp){
            mp[key]=fill(mp, key);
            ans=max(ans, mp[key]);
        }
        return ans;
    }
};
