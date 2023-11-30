class Solution {
public:
    static double distance(int x1, int y1, int x2, int y2){
        int x_diff = x1 - x2; 
        int y_diff = y1 - y2;
        return sqrt(pow(x_diff, 2) + pow(y_diff, 2));
    }
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        vector<vector<int>> res;
        auto cmp = [](vector<int> &p1, vector<int> &p2){
            return distance(0, 0, p1[0], p1[1]) < distance(0, 0, p2[0], p2[1]);
        };
        priority_queue<vector<int>, vector<vector<int>>, decltype(cmp)> heap(cmp);    
        for(vector<int> point : points){
            heap.push(point);
            if(heap.size() > k){
                heap.pop();
            }
        }
        while(!heap.empty()){
            res.push_back(heap.top());
            heap.pop();
        }
        return res;
    }
};
