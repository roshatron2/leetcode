class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<int,int>> cars;
        for(int i = 0; i < speed.size(); i++){
            cars.push_back({position[i],speed[i]});
        }
        sort(cars.begin(),cars.end(),[](pair<int,int> &a,pair<int,int> &b){
            return a.first < b.first;
        });
        stack<float> stack;
        for(int i = 0; i < cars.size(); i++){
            float time = (target - cars[i].first) / (float)cars[i].second;
            while(!stack.empty() and time >= stack.top()){
                stack.pop();
            }
            stack.push(time);
        }
        return stack.size();
    }
};