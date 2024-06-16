class Solution {
public:
    int strStr(string haystack, string needle) {
        int m = needle.length();
        int n = haystack.length();
        
        vector<int> pi(m, 0);
        int j = 0; 
        for (int i = 1; i < m; i++) {
            while (j > 0 && needle[i] != needle[j]) {
                j = pi[j - 1];
            }
            if (needle[i] == needle[j]) {
                pi[i] = ++j;
            }
        }
        
        j = 0; 
        for (int i = 0; i < n; i++) {
            while (j > 0 && haystack[i] != needle[j]) {
                j = pi[j - 1];
            }
            if (haystack[i] == needle[j]) {
                j++;
            }
            if (j == m) {
                return i - m + 1; 
            }
        }
        
        return -1; 
    }
};
