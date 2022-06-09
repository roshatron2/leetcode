class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        unordered_set<int> set;
        for(int i : arr){
            set.insert(i);
        }
        for(int i = 1; i <= 2001; i++){
           if(set.find(i) == set.end()){
              k--;    
           } 
           if(k == 0){
               return i;
           }
        }    
        return 0;
    }
};
/*
2 3 4 7 11 
k - 0
1 5 6 8 9
*/