class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int last[256];
        fill(last, last + 256, -1);

        int l = 0;
        int maxLen = 0;

        for (int r = 0; r < s.length(); r++) {

            if (last[s[r]] >= l) {
                l = last[s[r]] + 1;
            }

            last[s[r]] = r;

            maxLen = max(maxLen, r - l + 1);
        }

        return maxLen;
    }
};