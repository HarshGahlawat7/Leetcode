class Solution {
public:
    string decodeCiphertext(string encodedText, int rows) {
        if (encodedText.empty()) return "";
        
        int n = encodedText.length();
        int cols = n / rows;
        string res = "";
        
        for (int c = 0; c < cols; ++c) {
            int curr_row = 0;
            int curr_col = c;
            
            while (curr_row < rows && curr_col < cols) {
                int index = curr_row * cols + curr_col;
                res += encodedText[index];
                
                curr_row++;
                curr_col++;
            }
        }
        
        size_t last = res.find_last_not_of(' ');
        if (last == string::npos) return ""; 
        
        return res.substr(0, last + 1);
    }
};