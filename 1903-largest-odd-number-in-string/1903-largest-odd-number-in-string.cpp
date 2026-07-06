class Solution {
public:
    string largestOddNumber(string num) {
        // We have to scan the number from the end in this particlar question because we have 
        // to get the biggest odd number and then will happen only if start from the end.
        int n = num.length();
        int last_odd = -1;

        for(int i = n - 1 ; i >= 0 ;i--){
            if(num[i] % 2 != 0){
                num.resize(i+1);
                return num;
            }
        }
        return "";
            
    }
};
