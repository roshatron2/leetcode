class Solution {
public:
    static const int N = 100001;
    vector<int> adj[N];
    bool visited[N];
    
    void DFS(string &s,int vertex,vector<char> &characters,vector<int> &indices){
        characters.push_back(s[vertex]);
        indices.push_back(vertex);
        
        visited[vertex] = true;
        
        for(int adjacent : adj[vertex]){
            if(!visited[adjacent]){
                DFS(s,adjacent,characters,indices);
            }
        }
    }
    string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) {
        for(auto pair : pairs){
           adj[pair[0]].push_back(pair[1]);
           adj[pair[1]].push_back(pair[0]);
        }
        
        for(int i = 0; i < s.size(); i++){
            if(!visited[i]){
                vector<char> characters;
                vector<int> indices;
                
                DFS(s,i,characters,indices);
                
                sort(characters.begin(),characters.end());
                sort(indices.begin(),indices.end());
                
                for(int i = 0; i < indices.size(); i++){
                    s[indices[i]] = characters[i];
                }
            }
        }
        return s;
    }
};