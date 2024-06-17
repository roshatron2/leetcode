class Solution {
public:
    bool mergeTriplets(vector<vector<int>>& triplets, vector<int>& target) {
        bool one = false, two = false, three = false;
        for(auto &v : triplets){
            if(v[0] > target[0] or v[1] > target[1] or v[2] > target[2])
                continue;
            if(v[0] == target[0])
                one = true;
            if(v[1] == target[1])
                two = true;
            if(v[2] == target[2])
                three = true;
            if(one and two and three)
                return true;
        }    
        return false;
    }
};