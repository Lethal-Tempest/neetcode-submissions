class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> freq;
        for(int& i: nums) freq[i]++;
        int n=nums.size();
        vector<vector<int>> buckets(n+1, vector<int>());
        auto it=freq.begin();
        while(it!=freq.end()){
            buckets[it->second].push_back(it->first);
            it++;
        }
        int cnt=0, curr=n;
        vector<int> ans;
        while(cnt<k && curr>=0){
            for(int i=0;i<buckets[curr].size() && cnt<k;i++){
                ans.push_back(buckets[curr][i]);
                cnt++;
            }
            curr--;
        }
        return ans;
    }
};
