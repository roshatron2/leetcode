class Solution {
public:
    vector<int> intersection(vector<int> &arr1,vector<int> &arr2){
       int i = 0,j = 0,n1 = arr1.size(),n2 = arr2.size();
       vector<int> res;
       while(i < n1 and j < n2){
            if(arr1[i] < arr2[j]){
                i++;
            } else if(arr1[i] > arr2[j]){
                j++;
            } else {
                res.push_back(arr1[i]);
                i++;
                j++;
                while(i < n1 and arr1[i] == arr1[i - 1]){
                    i++;
                }
                while(j < n2 and arr2[j] == arr2[j - 1]){
                    j++;
                }
            }
        }
        return res;
    }
    vector<int> arraysIntersection(vector<int>& arr1, vector<int>& arr2, vector<int>& arr3) {
        vector<int> temp = intersection(arr1,arr2);
        return intersection(temp,arr3);    
    }
};