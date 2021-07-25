class Solution {
public:
    int strStr(string haystack, string needle) {
        size_t idx = haystack.find(needle);
        return idx != string::npos ? idx : -1;
    }
};