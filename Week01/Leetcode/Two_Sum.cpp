class Solution {
public:
    vector<int> twoSum(vector<int> &nums, int target) {

        // Vector to store the indices of the original array.
        vector<int> indices(nums.size());
        iota(indices.begin(), indices.end(), 0);

        // Sort the indices based on the corresponding element values in nums.
        sort(indices.begin(), indices.end(),
             [&nums](int a, int b) { return nums[a] < nums[b]; });

        // Initialize two pointers.
        int left = 0;
        int right = nums.size() - 1;
        int currentSum = 0;

        while (left < right) {
            currentSum = nums[indices[left]] + nums[indices[right]];

            if (currentSum == target) {
                return {indices[left], indices[right]};
            } else if (currentSum < target) {
                left++;
            } else {
                right--;
            }
        }
        return {};
    }
};