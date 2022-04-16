class Solution {
public:
    vector<int> unique;
    map<int,int> count;
    int partition(int left,int right,int pivot_index){
        int pivot_frequency = count[unique[pivot_index]];
        swap(unique[pivot_index],unique[right]);
        
        int store_index = left;
        for(int i = left; i <= right; i++){
            if(count[unique[i]] < pivot_frequency){
                swap(unique[store_index],unique[i]);
                store_index++;
            }
        }
        swap(unique[right],unique[store_index]);
        return store_index;
    }
    void quickSelect(int left,int right,int k_smallest){
       if(left == right)
           return;
        int pivot_index = left + rand() % (right - left + 1);
        pivot_index = partition(left,right,pivot_index);
        
        if(k_smallest == pivot_index){
            return;
        } else if(k_smallest < pivot_index){
            quickSelect(left,pivot_index - 1,k_smallest);
        } else{
            quickSelect(pivot_index + 1,right,k_smallest);
        }
    }
    vector<int> topKFrequent(vector<int>& nums, int k) {
        for(int n : nums){
            count[n]++;
        }
        int n = count.size();
        for(pair<int,int> p : count){
            unique.push_back(p.first);
        }
        quickSelect(0,n - 1,n - k);
        vector<int> res(k);
        copy(unique.begin() + n - k,unique.end(),res.begin());
        return res;
    }
};