class Solution {
public:
    string frequencySort(string s) {
        map<char, int> map;
        for (char i : s) {
            map[i]++;
        }
        auto cmp = [&map](char a, char b) {
            if (map[a] == map[b]) {
                return a < b;
            }
            return map[a] < map[b];
        };
        priority_queue<char, vector<char>, decltype(cmp)> pq(cmp);
        for (auto i : map) {
            for (int j = 0; j < i.second; j++)
                pq.push(i.first);
        }
        string res;
        while (!pq.empty()) {
            res += pq.top();
            pq.pop();
        }
        return res;
    }
};