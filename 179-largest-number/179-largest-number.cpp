class Solution {
public:
    string largestNumber(vector<int>& nums) {
        vector<string> arr;
        for(int i : nums){
            arr.push_back(to_string(i));
        }
        sort(arr.begin(),arr.end(),[](string a,string b){
            return (a + b) > (b + a);
        });
        string res;
        for(string i : arr){
            res += i;
        }
        return res[0] == '0' ? "0" : res;
    }
};

    
