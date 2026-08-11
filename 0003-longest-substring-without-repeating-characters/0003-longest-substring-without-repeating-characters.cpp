class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> ind(256, -1);
        int left=0, right=0;
        int len=0;
        while (right<s.size()) {
            if (ind[s[right]]!=-1 && ind[s[right]]>=left) {
                left = ind[s[right]]+1; 
            }
            ind[s[right]] = right;
            len = max (len, right-left+1);
            right++;
        }
        return len;
    }
};