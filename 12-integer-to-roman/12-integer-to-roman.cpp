class Solution {
public:
    string intToRoman(int num) {
        map<int,string,greater<int>> map;
        map[1] = "I";
        map[4] = "IV";
        map[5] = "V";
        map[9] = "IX";
        map[10] = "X";
        map[40] = "XL";
        map[50] = "L";
        map[90] = "XC";
        map[100] = "C";
        map[400] = "CD";
        map[500] = "D";
        map[900] =  "CM";
        map[1000] = "M";
        string res;
        while(num){
            for(auto [k,v] : map){
                if(k <= num){
                    int count = num / k;
                    string cur;
                    for(int i = 0; i < count; i++){
                       cur += map[k]; 
                    }
                    res += cur;
                    num = num - count * k;
                }
            }
        }
        return res; 
    }
};