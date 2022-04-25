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
    int nextVal;
    bool hasNextVal;
	PeekingIterator(const vector<int>& nums) : Iterator(nums) {
	    // Initialize any member here.
	    // **DO NOT** save a copy of nums and manipulate it directly.
	    // You should only use the Iterator interface methods.
       hasNextVal = Iterator::hasNext();
	   if(hasNextVal)
           nextVal = Iterator::next();
	}
    	
    // Returns the next element in the iteration without advancing the iterator.
	int peek() {
       return nextVal; 
	}
	
	// hasNext() and next() should behave the same as in the Iterator interface.
	// Override them if needed.
	int next() {
        int cur = nextVal;
        hasNextVal = Iterator::hasNext();
        if(hasNextVal){
            nextVal = Iterator::next();
        }
        return cur;
	}
	
	bool hasNext() const {
        return hasNextVal;
	}
};