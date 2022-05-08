/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */

class NestedIterator {
public:
    vector<NestedInteger> list;
    vector<int> nums;
    int pos = 0;
    NestedIterator(vector<NestedInteger> &nestedList) {
       list = nestedList; 
       flatten(list); 
    }
    void flatten(vector<NestedInteger> item){
       for(NestedInteger nestedInteger : item){
           if(nestedInteger.isInteger()){
               nums.push_back(nestedInteger.getInteger());
           } else {
               flatten(nestedInteger.getList());
           }
       } 
    } 
    int next() {
       if(hasNext())
           return nums[pos++];
        return -1;
    }
    
    bool hasNext() {
       return pos < nums.size(); 
    }
};

/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nestedList);
 * while (i.hasNext()) cout << i.next();
 */