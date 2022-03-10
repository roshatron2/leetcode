/* The knows API is defined for you.
      bool knows(int a, int b); */

class Solution {
public:
    int findCelebrity(int n) {
        int candidate = 0;
        for(int i = 0; i < n; i++){
            if(i == candidate)
                continue;
            if(knows(candidate,i) or !knows(i,candidate)){
                candidate = i;
            }
        }
        for(int i = 0; i < n; i++){
            if(i == candidate)
                continue;
            if(!knows(i,candidate) or knows(candidate,i))
                return -1;
        }
        return candidate;
    }
};