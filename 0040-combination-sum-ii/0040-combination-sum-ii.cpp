class Solution {
public:
void findCombinations(int ind,int target,vector<int>&arr,vector<int>&ds,vector<vector<int>>&ans){
    if(target==0){
        ans.push_back(ds);

    }
    for(int i=ind;i<arr.size();i++){
    if(i>ind && arr[i]==arr[i-1])continue;
    if(arr[i]>target)break;
    ds.push_back(arr[i]);
    

    findCombinations(i+1,target-arr[i],arr,ds,ans);
    ds.pop_back();
    }
}

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
         sort(candidates.begin(),candidates.end());
     vector<vector<int>> ans;  // To store the final answer
    vector<int> ds;  // To store the current combination
    findCombinations(0, target, candidates, ds, ans);  // Call the helper function
    return ans;
        
    }
};