class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n = cardPoints.size();
        cardPoints.push_back(0);
        k = n - k;
        int sum = 0;
        int minWin = INT_MAX;
        vector<int> prefix(n + 1,0);
        for(int i = 0; i <= n; i++){
            prefix[i] = sum;
            sum += cardPoints[i]; 
        }
        for(int i = k; i <= n; i++){
           minWin = min(minWin,prefix[i] - prefix[i - k]); 
        }
        return sum - minWin;
    }
};
/*
0 1 2  3  4  5  6 7
1 2 3  4  5  6  1
0 1 3  6 10 15 21 22

1 2 3 4 - 10
2 3 4 5 - 14
3 4 5 6 - 18
4 5 6 1 - 16
*/