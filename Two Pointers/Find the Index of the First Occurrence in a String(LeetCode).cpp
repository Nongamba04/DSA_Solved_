//LINK : https://leetcode.com/problems/find-the-index-of-the-first-occurrence-in-a-string/

class Solution {
public:
    int strStr(string haystack, string needle) {
        int m = haystack.length();
        int n = needle.length();

        if (n == 0) {
            return 0; // If needle is empty, return 0 (as per the problem's definition)
        }

        for (int j = 0; j <= m - n; j++) {
            int i = 0;
            while (i < n && haystack[j + i] == needle[i]) {
                i++;
            }
            if (i == n) {
                return j; // Found the needle in haystack
            }
        }
        
        return -1; // Needle not found
    }
};
