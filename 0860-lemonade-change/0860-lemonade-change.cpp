class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        // No. of denominations
        int five=0 ; int ten = 0;
        
        for(int i = 0 ; i < bills.size(); i ++){
            
            if (bills[i] == 5){
                five +=1;
            }
            else if(bills[i] == 10){
                if(five){
                ten+=1;
                five-=1;
                }
                else 
                return false;
            }
            else{
                if(ten >=1 && five>=1 ){
                    ten -= 1;
                    five -= 1;
                }
                else if (five >=3){
                    five -= 3;
                }
                else{
                    return false;
                }
            }
        }
        return true;
    }
};