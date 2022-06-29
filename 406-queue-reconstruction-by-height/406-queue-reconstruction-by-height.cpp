class Solution {
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        sort(people.begin(),people.end(),[](vector<int> &a,vector<int> &b){
           if(a[0] == b[0]){
               return a[1] < b[1];
           } 
           return a[0] > b[0];
        });       
        vector<vector<int>> res;
        for(auto person : people){
            if(res.size() > person[1]){
               res.insert(res.begin() + person[1],person); 
            } else {
                res.push_back(person);
            }
        }
        return res;
    }
};
