/*
 * Below is the interface for Iterator, which is already defined for you.
 * **DO NOT** modify the interface for Iterator.
 *
 *  class Iterator {
 *		struct Data;
 * 		Data* data;
 *  public:
 *		Iterator(const vector<int>& nums);
 * 		Iterator(const Iterator& iter);
 *
 * 		// Returns the next element in the iteration.
 *		int next();
 *
 *		// Returns true if the iteration has more elements.
 *		bool hasNext() const;
 *	};
 */

class PeekingIterator : public Iterator {
public:
    vector<int> nums;
    int i = 0;
	PeekingIterator(const vector<int>& nums) : Iterator(nums) {
	    // Initialize any member here.
	    // **DO NOT** save a copy of nums and manipulate it directly.
	    // You should only use the Iterator interface methods.
        this->nums = nums;
	}
	
    // Returns the next element in the iteration without advancing the iterator.
	int peek() {
       return nums[i]; 
	}
	
	// hasNext() and next() should behave the same as in the Iterator interface.
	// Override them if needed.
	int next() {
       return  nums[i++];  
	}
	
	bool hasNext() const {
	   return i < nums.size();
	}
};

/*
i - 2
return nums[0] - 1
return nums[i + 1]; - 3
return nums[1] - 2
return nums[2] - 3
return 2 + 1 < 3 - false
1 3 2 3 false
*/