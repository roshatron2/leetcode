class Solution {
public:
    int maxArea(int h, int w, vector<int>& hCs, vector<int>& vCs) {
        int MOD = 1000000007;
        sort(hCs.begin(),hCs.end());
        sort(vCs.begin(),vCs.end());
        int maxHeight = max(hCs[0],h - hCs.back());
        int maxWidth = max(vCs[0],w - vCs.back());
        for(auto i = 1; i < hCs.size(); i++){
           maxHeight = max(maxHeight,hCs[i] - hCs[i - 1]); 
        }
        for(auto i = 1; i < vCs.size(); i++){
            maxWidth = max(maxWidth,vCs[i] - vCs[i - 1]);
        }
        return (long) maxHeight * maxWidth % MOD;
    }
};