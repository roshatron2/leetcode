class Solution {
public:
    int scheduleCourse(vector<vector<int>>& courses) {
        sort(courses.begin(),courses.end(),[](vector<int> a,vector<int> b){
           return a[1] < b[1]; 
        });
        auto cmp = [](vector<int> a,vector<int> b){
           return a[0] < b[0]; 
        };    
        int time = 0;
        priority_queue<vector<int>,vector<vector<int>>,decltype(cmp)> heap(cmp);
        for(vector<int> course : courses){
            int duration = course[0];
            int lastDay = course[1];
            if(time + duration <= lastDay){
               heap.push(course); 
               time += duration;
            } else if(!heap.empty() and heap.top()[0] > duration){
                time += duration - heap.top()[0];
                heap.pop();
                heap.push(course);
            }
        }
        return heap.size();
    }
};
