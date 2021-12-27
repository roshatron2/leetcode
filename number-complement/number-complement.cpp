class Solution {
public:
    int findComplement(int num) {
        string complement;
        while(num){
            int digit = num % 2;
            digit == 1 ? complement += "0" : complement += "1";
            num /= 2;
        }
        int ans = 0;
        for(int i = complement.size() - 1; i >= 0; i--){
            ans = ans * 2 + complement[i] - '0';
        }
        return ans;
    }
};