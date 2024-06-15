class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        vector<int> water(n, 0);

        int left = 0;
        for (int i = 0; i < n; i++) {
            left = max(left, height[i]);
            water[i] = left;
        }
        
        int right = 0;
        for (int i = n - 1; i >= 0; i--) {
            right = max(right, height[i]);
            water[i] = min(water[i], right);
        }
        
        for (int i = 0; i < n; i++) {
            water[i] -= height[i];
        }
        
        return accumulate(water.begin(), water.end(), 0);
    }
};
