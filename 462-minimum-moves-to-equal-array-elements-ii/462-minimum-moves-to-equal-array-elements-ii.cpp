class Solution {
public:
    int calcMoves(vector<int> &nums,int median){
        int moves = 0;
        for(int num : nums){
            moves += abs(num - median);
        }
        return moves;
    }
    int minMoves2(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        if(n % 2 == 1){
            int median = nums[(n + 1)/ 2 - 1];
            return calcMoves(nums,median); 
        } 
        
        double median = (nums[(n + 1) / 2 - 1] + nums[(n + 1) / 2]) / 2.0;
        return min(calcMoves(nums,floor(median)),calcMoves(nums,ceil(median)));
    }
};
/*
[1,10,2,9]
0 1 2 3
1 2 9 10
median = 6
5 4 3 4
*/