class Solution {
public:
    struct node {
        int val,x,y;
        node(int _val,int _x,int _y){
            val = _val;
            x = _x;
            y = _y;
        }
    };
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        auto cmp = [](node a, node b){
            return a.val > b.val;
        };
        priority_queue<node,vector<node>,decltype(cmp)> pq(cmp);
        for(int i = 0; i < matrix.size(); i++){
            pq.push(node(matrix[i][0],i,0));
        }
        vector<int> nums;
        while(!pq.empty()){
            node cur = pq.top();
            nums.push_back(cur.val);
            pq.pop();
            if(cur.y + 1 < matrix[0].size()){
                pq.push(node(matrix[cur.x][cur.y + 1],cur.x,cur.y + 1));
            }
        }
        return nums[k-1];
    }
};

/*
1

10

12


*/