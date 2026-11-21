class Solution {
public:
    int maxArea(vector<int>& heights) {
        int n=heights.size();
        int l=0, r=n-1, ans=0;
        while(l<r){
            int len=heights[l]<heights[r]?l:r;
            ans=max(ans, heights[len]*(r-l));
            if(l==len) l++;
            else r--;
        }
        return ans;
    }
};
