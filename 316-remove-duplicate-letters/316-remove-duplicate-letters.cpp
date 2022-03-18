class Solution {
public:
    string removeDuplicateLetters(string s) {
        unordered_map<char,bool> visited;
        unordered_map<char,int> counter;
        for(char i : s){
            counter[i]++;
        }
        string result;
        for(char i : s){
            counter[i]--;
            if(visited[i])
                continue;
            while(!result.empty() and result.back() > i and counter[result.back()] > 0){
                visited[result.back()] = false;
                result.pop_back();
            }
            visited[i] = true;
            result += i;
        }
        return result;
    }
};