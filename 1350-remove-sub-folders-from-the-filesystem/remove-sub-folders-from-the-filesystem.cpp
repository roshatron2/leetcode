class Solution {
public:
    vector<string> removeSubfolders(vector<string>& folder) {
        sort(folder.begin(), folder.end());
        vector<string> res = {folder[0]};
         
        for(int i = 1; i < folder.size(); i++){
            string lastFolder = res.back();
            lastFolder += '/';
            string prefix = folder[i].substr(0, lastFolder.size());

            if(prefix != lastFolder){
                res.push_back(folder[i]);
            }
        }
        return res;
    }
};