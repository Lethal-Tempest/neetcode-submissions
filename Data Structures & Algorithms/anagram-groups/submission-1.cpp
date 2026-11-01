class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        int n=strs.size();
        unordered_map<string, vector<string>> mp;
        for(int i=0;i<n;i++){
            string key="";
            vector<int> freq(26, 0);
            for(char& c: strs[i]){
                freq[c-'a']++;
            }
            for(int i=0;i<26;i++){
                key=key+to_string(freq[i])+" ";
            }
            mp[key].push_back(strs[i]);
            // cout<<key<<endl;
        }
        auto it=mp.begin();
        vector<vector<string>> ans;
        while(it!=mp.end()){
            ans.push_back(it->second);
            it++;
        }
        return ans;
    }
};
