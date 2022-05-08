class Solution {
public:
    vector<int> fairCandySwap(vector<int>& aliceSizes, vector<int>& bobSizes) {
    
        int aliceCount = 0,bobCount = 0; 
        vector<int> ans = {-1,-1};
        unordered_set<int> set;
        
        for(int i : aliceSizes){
            aliceCount += i;
        }
        for(int i : bobSizes){
            bobCount += i;
            set.insert(i);
        }
        for(int i : aliceSizes){
            int requiredBox = (bobCount - aliceCount) / 2 + i;
            if(set.find(requiredBox) != set.end()){
                ans[0] = i;
                ans[1] = requiredBox;
                return ans;
            }
        }
        return ans;        
    }
};
/*
a - 2
b - 4
a - a[i] + b[j] = b - b[j] + a[i]
b[j] = (b - a) / 2 +  a[i]

a - 3
b - 5
[1 2] or [2,3]

[1,3] [2]
a - 4
b - 2
 = -1 + 3

        
*/