class Solution {
public:
    bool canReach(vector<int>& start, vector<int>& target) {
        int r1 = start[0], c1 = start[1];
        int r2 = target[0], c2 = target[1];

        return ((r1+c1)%2) == ((r2+c2)%2);
    }
};