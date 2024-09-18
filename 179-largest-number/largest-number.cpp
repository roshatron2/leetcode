class Solution {
public:
    string largestNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end(), [](int a, int b){
            string str_a = to_string(a);
            string str_b = to_string(b);
            return str_a + str_b > str_b + str_a;
        });
        string res;
        for(int i : nums){
            res += to_string(i);
        }
        return res[0] == '0' ? "0" : res;
    }
};