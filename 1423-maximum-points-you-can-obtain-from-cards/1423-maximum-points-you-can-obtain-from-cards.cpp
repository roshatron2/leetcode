class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n = cardPoints.size();
        k = n - k;
        int window = accumulate(cardPoints.begin(),cardPoints.begin() + k,0);
        int total = accumulate(cardPoints.begin(),cardPoints.end(),0);
        int minWin = window;
        
        for(int i = k; i < n; i++){
            window += cardPoints[i] - cardPoints[i - k];
            minWin = min(window,minWin);
        }
        return total - minWin; 
    }
};
/*
0 1 2 3 4 5 6
1 2 3 4 5 6 1
i = 5
k = 4
sum = 10 + 5 - 1 = 14
sum = 14 + 6 - 2 = 18
sum = 18 + 1 - 3 = 16
*/