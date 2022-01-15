class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) {
        int count = 0;
        int mp[61] = {0};
        for(int i = 0; i < time.size(); i++){
            int x = time[i] % 60;
            int y  = (60 - time[i] % 60) % 60;
            count += mp[y];
            mp[x]++;
        }
        return count;
    }
};