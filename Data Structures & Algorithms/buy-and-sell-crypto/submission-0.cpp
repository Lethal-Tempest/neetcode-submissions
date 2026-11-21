class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size(), ans=0;
        vector<int> preMin(n, prices[0]), postMax(n, prices[n-1]);
        for(int i=1;i<n;i++){
            preMin[i]=min(preMin[i-1], prices[i]);
            postMax[n-1-i]=max(postMax[n-i], prices[n-1-i]);
        }
        for(int i=0;i<n;i++) ans=max(ans, postMax[i]-preMin[i]);
        return ans;
    }
};
