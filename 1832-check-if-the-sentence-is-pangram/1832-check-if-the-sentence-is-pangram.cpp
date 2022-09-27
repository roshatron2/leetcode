class Solution {
public:
    bool checkIfPangram(string sentence) {
        vector<int> map(26,0);
        for(char i : sentence){
            map[i - 'a']++;
        }
        for(int i = 0; i < map.size(); i++){
            if(map[i] == 0){
               return false; 
            }
        }
        return true;
    }
};