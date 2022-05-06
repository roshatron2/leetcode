class Solution {
public:
    set<int> findPrimes(int n){
         set<int> primes;
         while(n % 2 == 0){
                primes.insert(2);
                n /= 2;
         }
         for(int i = 3; i <= sqrt(n); i += 2){
             while(n % i == 0){
                primes.insert(i);
                n /= i;
             }
         }
         if(n > 2){
            primes.insert(n);
         }   
         return primes;
    }
    bool isUgly(int n) {
        if(n <= 0){
            return false;
        }
        set<int> primes = findPrimes(n);
        set<int> set = {2,3,5};
        for(int i : primes){
            if(set.find(i) == set.end()){
                return false;
            }
        }
        return true; 
    }
};
/*
find all prime factors
go through the factors and see if there any factors
*/
