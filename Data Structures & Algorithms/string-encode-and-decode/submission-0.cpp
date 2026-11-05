class Solution {
public:

    string encode(vector<string>& strs) {
        string ans="";
        for(string& s: strs){
            ans+=to_string(s.size())+"#"+s;
        }
        return ans;
    }

    vector<string> decode(string s) {
        int i=0, n=s.size();
        vector<string> ans;
        while(i<n){
            int j=i;
            while(s[j]!='#'){
                j++;
            }
            int size=stoi(s.substr(i, j-i));
            ans.push_back(s.substr(j+1, size));
            i=j+1+size;
        }
        return ans;
    }
};
