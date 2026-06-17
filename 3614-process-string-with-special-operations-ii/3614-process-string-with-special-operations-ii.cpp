class Solution {
public:
    char processStr(string s, long long k) {
        int n = s.size();

        vector<long long> len(n + 1, 0);

        for (int i = 0; i < n; i++) {
            char c = s[i];

            if ('a' <= c && c <= 'z') {
                len[i + 1] = len[i] + 1;
            }
            else if (c == '*') {
                len[i + 1] = max(0LL, len[i] - 1);
            }
            else if (c == '#') {
                len[i + 1] = len[i] * 2;
            }
            else {
                len[i + 1] = len[i];
            }
        }

        if (k >= len[n]) return '.';

        for (int i = n - 1; i >= 0; i--) {
            char c = s[i];

            if ('a' <= c && c <= 'z') {
                if (k == len[i + 1] - 1) return c;
            }
            else if (c == '#') {
                if (k >= len[i]) k -= len[i];
            }
            else if (c == '%') {
                k = len[i] - 1 - k;
            }
        }

        return '.';
    }
};