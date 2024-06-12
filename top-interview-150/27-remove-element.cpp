class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int i = 0;
        int j = nums.size() - 1;
        while(j >= i) {
            if(nums[i] != val) {
                i++;
            } else if(nums[j] != val) {
                nums[i++] = nums[j--];
            } else {
                j--;
            }
        }
        return i;
    }
};
