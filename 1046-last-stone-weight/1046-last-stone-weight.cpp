class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> pq;
        for(int stone : stones){
            pq.push(stone);
        }
        while(pq.size() > 1){
            int bigest = pq.top();
            pq.pop();
            int second_bigest = pq.top();
            pq.pop();
            if(bigest != second_bigest){
                pq.push(bigest - second_bigest);
            }
        }
        return pq.size() ? pq.top() : 0;
    }
};

      