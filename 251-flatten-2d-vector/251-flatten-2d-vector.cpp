class Vector2D {
public:
    vector<vector<int>> matrix;
    int i = 0, j = 0;
    Vector2D(vector<vector<int>>& vec) {
        matrix = vec;
    }
    
    int next() {
        if(hasNext()){
            return matrix[i][j++];
        }
        return -1;
    }
    
    bool hasNext() {
        while(i < matrix.size() and j == matrix[i].size()){
            j = 0;
            i++;
        }
        return i < matrix.size();
    }
};

/**
 * Your Vector2D object will be instantiated and called as such:
 * Vector2D* obj = new Vector2D(vec);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */