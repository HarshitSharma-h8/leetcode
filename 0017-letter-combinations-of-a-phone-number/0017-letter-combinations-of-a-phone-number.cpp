class Solution {
public:
    vector<string> letterCombinations(string digits) {
        string combos[] = {"",    "",    "abc",  "def", "ghi",
                           "jkl", "mno", "pqrs", "tuv", "wxyz"};
        vector<string> res;
        string str = "";
        gc(res, str, 0, digits, combos);
        return res;
    }

    void gc(vector<string>& res, string& str, int i, string& digits,
            string (&combos)[10]) {
        // base condition
        if (i == digits.size()) {
            res.push_back(str);
            return;
        }

        // // include first character
        // str += combos[digits[i] - '0'][0];
        // gc(res, str, i + 1, digits, combos);
        // str.pop_back();

        // // include 2nd character
        // str += combos[digits[i] - '0'][1];
        // gc(res, str, i + 1, digits, combos);
        // str.pop_back();

        // // include thirtd character
        // str += combos[digits[i] - '0'][2];
        // gc(res, str, i + 1, digits, combos);
        // str.pop_back();

        string letters = combos[digits[i] - '0'];

        for ( char ch : letters) {
            str += ch;
            gc(res, str, i + 1, digits, combos);
            str.pop_back();
        }
    }
};