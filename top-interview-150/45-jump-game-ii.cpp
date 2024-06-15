class Solution {
public:
    int jump(vector<int>& nums) {
        if (nums.size() == 1) {
            return 0;
        }

        int last = nums[0];
        int j = nums[0];
        int jump = 1;
        for (int i = 1; i < nums.size() - 1; i++) {
            last = max(last, nums[i] + i);
            
            if (i == j) {
                j = last;
                jump++;    
                
                if (j >= nums.size() - 1) {
                    break;
                }
            }
        }
        return jump;
    }
};
