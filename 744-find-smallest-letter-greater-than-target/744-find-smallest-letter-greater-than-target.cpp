class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        int l = 0,r = letters.size() - 1;
        
        while(l <= r){
            int mid = (l + r) >> 1;
            if(letters[mid] <= target and mid == letters.size() - 1)
                return letters[0];
            if(letters[mid] > target){
                if(mid == 0 or letters[mid-1] <= target)
                    return letters[mid];
                else
                    r = mid - 1;
            } else if(letters[mid] <= target){
                l = mid + 1;
            }
        }
        return '-';
    }
};