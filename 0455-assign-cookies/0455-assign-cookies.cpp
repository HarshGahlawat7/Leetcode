class Solution {
public:
    void insertionSort(vector<int>& arr) {
    for (int i = 1; i < arr.size(); i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}
    int findContentChildren(vector<int>& g, vector<int>& s) {
        insertionSort(g) , insertionSort(s);

        int m = g.size() ; int n = s.size();
        // l is the pointer for the greed array and r is the pointer for the size array
        int l = 0 ; int r = 0 ; 

        while(l < m && r < n){
            if (g[l] <= s[r]){
                l +=1;
                r +=1;
            } 
            else{
                r += 1;
            }
        }
        return l ;
    }
};