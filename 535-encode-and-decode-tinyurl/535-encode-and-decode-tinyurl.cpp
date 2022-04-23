class Solution {
public:
    string prefix = "http://tinyurl.com/";
    int count = 0;
    unordered_map<string,string> map;
    // Encodes a URL to a shortened URL.
    string encode(string longUrl) {
        string shortUrl = prefix + to_string(count);
        map[shortUrl] = longUrl;
        return shortUrl;
    }

    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl) {
        return map[shortUrl];    
    }
};

// Your Solution object will be instantiated and called as such:
// Solution solution;
// solution.decode(solution.encode(url));