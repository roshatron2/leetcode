class Codec {
public:

    // Encodes a list of strings to a single string.
    string encode(vector<string>& strs) {
        string encoded;
        for(string word : strs){
           encoded += to_string(word.size()) +  "." + word;
        }
        return encoded;
    }

    // Decodes a single string to a list of strings.
    vector<string> decode(string s) {
        vector<string> decoded;
        for(int i = 0; i < s.size(); i++){
            int len = 0;
            string word;
            while(isdigit(s[i]))
                len = len * 10 + s[i++] - '0';
            word = s.substr(i + 1,len);
            i += len;
            decoded.push_back(word);
        }
        return decoded;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.decode(codec.encode(strs));