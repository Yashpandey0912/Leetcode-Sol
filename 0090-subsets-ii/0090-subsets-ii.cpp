class Solution {
public:
void backtrack(int start ,vector<int>&nums,vector<int>&current,vector<vector<int>>&result){
    result.push_back(current);
    for(int i=start;i<nums.size();i++){
        if(i>start && nums[i]==nums[i-1])continue;
         // Include nums[i] in current subset
            current.push_back(nums[i]);

            // Recurse for next index
            backtrack(i + 1, nums, current, result);

            // Backtrack: remove last added element
            current.pop_back();
    }


}
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
         sort(nums.begin(), nums.end());

        vector<vector<int>> result;
        vector<int> current;

        // Start backtracking from index 0
        backtrack(0, nums, current, result);

        return result;
        
    }
};