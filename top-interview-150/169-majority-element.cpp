class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int major = 0;
        int count = 0;
        for (int i = 0; i < nums.size(); i++) {
            if(count == 0) {
                major = i;
            }

            if (nums[i] == nums[major]) {
                count++;
            } else {
                count--;
            }
        }
        return nums[major];
    }
};
