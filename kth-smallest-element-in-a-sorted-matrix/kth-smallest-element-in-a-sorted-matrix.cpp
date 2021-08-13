class Solution {
   public:
    struct greater {
        bool operator()(const pair<int, pair<int, int>> a, const pair<int, pair<int, int>> b) {
            return a.first > b.first;
        }
    };
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n = matrix.size();
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater> pq;
        for (int i = 0; i < n; i++) {
            pq.push(make_pair(matrix[i][0], make_pair(i, 0)));
        }
        while (!pq.empty()) {
            if (--k == 0) {
                break;
            }
            auto top = pq.top();
            pq.pop();
            top.second.second++;
            if (n > top.second.second) {
                int heaptop = matrix[top.second.first][top.second.second];
                pq.push(make_pair(heaptop,make_pair(top.second.first,top.second.second)));
            }
        }
        return pq.top().first;
    }
};