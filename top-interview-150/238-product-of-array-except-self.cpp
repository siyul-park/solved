class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> answer(nums.size());
        answer[0] = 1;
        for (int i = 1; i < nums.size(); i++) {
            answer[i] = answer[i - 1] * nums[i - 1];
        }
        int suffix = nums[nums.size() - 1];
        for (int i = nums.size() - 2; i >= 0; i--) {
            answer[i] *= suffix;
            suffix *= nums[i];
        }
        return answer;
    }
};