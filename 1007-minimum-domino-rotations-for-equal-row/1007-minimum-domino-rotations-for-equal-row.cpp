class Solution {
public:
    int check(int x,vector<int> &A,vector<int> &B){
        int rotA = 0,rotB = 0;
        for(int i = 0; i < A.size(); i++){
            if(A[i] != x and B[i] != x)
                return -1;
            else if(A[i] != x){
                rotA++;
            } else if(B[i] != x){
                rotB++;
            }
        }
        return min(rotA,rotB);
    }
    int minDominoRotations(vector<int>& tops, vector<int>& bottoms) {
        int rotA = check(tops[0],tops,bottoms);
        if(rotA != -1 or tops[0] == bottoms[0])
            return rotA;
        return check(bottoms[0],tops,bottoms);
    }
};