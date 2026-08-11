class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int r = cardPoints.size()-1, rsum = 0, lsum = 0;
        for(int i = 0; i <k; i++ ){
            lsum += cardPoints[i];
        }
        int maxSum = lsum;
        for(int i = k-1; i >= 0 ; i--){
            rsum += cardPoints[r--];
            lsum -= cardPoints[i];
            maxSum = max(maxSum, (lsum+rsum));
        }
        return maxSum;
    }
};