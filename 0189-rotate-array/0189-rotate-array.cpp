class Solution {
public:
    void reverseArray(vector<int>&nums,int start,int end){
        while(start<end){
            swap(nums[start],nums[end]);
            start++;
            end--;        }
    }
    void rotate(vector<int>& nums, int k) {
        int n=nums.size();
        //check edge case
        if(n==0||k==0)return ;
        k=k%n;
         reverseArray(nums,0,n-1);
        reverseArray(nums,0,k-1);
        reverseArray(nums,k,n-1);
       

        return ;
    }
    
};