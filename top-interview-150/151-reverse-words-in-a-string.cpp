class Solution {
public:
    string reverseWords(string s) {
        reverse(s.begin(), s.end());
        int n = s.size();
        int left = 0;
        int right = 0;
        for (int i = 0; i < n; i++) {
            if (s[i] != ' ') {
                s[right++] = s[i];
            }
            if ((i == n - 1 || s[i] == ' ') && right > 0 && s[right - 1] != ' ') {
                reverse(s.begin() + left, s.begin() + right);
                s[right++] = ' ';
                left = right;
            }
        }
        s.resize(right - 1);
        return s;
    }
};
