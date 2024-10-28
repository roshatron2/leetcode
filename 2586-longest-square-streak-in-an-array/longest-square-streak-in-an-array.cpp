class Solution {
public:
    int longestSquareStreak(vector<int>& nums) {
        unordered_set<int> unique_nums(nums.begin(), nums.end());
        int max_streak = 1;
        for(int i : nums){
            long long num = i;
            int streak = 0;

            while(unique_nums.find(num) != unique_nums.end()){
                streak++;
                if(num * num > 1e5){
                    break;
                }

                num *= num;
            }
            max_streak = max(max_streak, streak);
        }

        return max_streak >= 2 ? max_streak : -1;
    }
};