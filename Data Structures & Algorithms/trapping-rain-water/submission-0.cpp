class Solution {
public:
    int trap(vector<int>& height) {
        int n=height.size(), ans=0;
        vector<int> preMax(n, height[0]), postMax(n, height[n-1]);
        for(int i=1;i<n;i++){
            preMax[i]=max(preMax[i-1], height[i]);
            postMax[n-i-1]=max(postMax[n-i], height[n-i-1]);
        }
        for(int i=0;i<n;i++){
            ans+=min(preMax[i], postMax[i])-height[i];
        }
        return ans;
    }
};
