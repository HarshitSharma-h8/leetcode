class Solution {
public:
    int countPrimes(int n) {
        if (n <= 2) return 0;

        // index i represents number (2*i + 1)
        int size = n / 2;
        vector<bool> isComposite(size, false);

        for (int i = 3; i * i < n; i += 2) {
            if (!isComposite[i / 2]) {

                // Start from i*i
                // Only mark odd multiples
                for (int j = i * i; j < n; j += 2 * i) {
                    isComposite[j / 2] = true;
                }
            }
        }

        int count = 1; // 2 is prime

        for (int i = 1; i < size; i++) {
            if (!isComposite[i]) {
                count++;
            }
        }

        return count;
    }
};