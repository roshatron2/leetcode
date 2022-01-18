class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int size = flowerbed.size();
        if(size == 1 and flowerbed[0] == 0 and n == 1){
            return true;
        }
        for(int i = 0; i < size and n > 0; i++){
            if(i == 0 and flowerbed[i] == 0 and flowerbed[i+1] == 0){
                flowerbed[i] = 1;
                n--;
            } else if(i - 1 >= 0 and i + 1 < size and flowerbed[i] == 0 
                      and flowerbed[i-1] == 0 and flowerbed[i+1] == 0){
                flowerbed[i] = 1;
                n--;
            } else if(i == size - 1 and flowerbed[i] == 0 and flowerbed[i-1] == 0){
                flowerbed[i] = 1;
                n--;
            }
            
        }       
        return n == 0;
    }
};