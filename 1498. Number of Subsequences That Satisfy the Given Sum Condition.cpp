// Time Complexity: O(2^n)
// Space Complexity: O(n)
//using recusrsion
//not optimised
class Solution {
public:
    int mod=1000000007; 
    int solve(vector<int>&nums,int target,int i,int maxi,int mini,bool taken){
        if(i>=nums.size()){
            if(taken && mini+maxi<=target)  return 1;
            return 0;
        }
        int skip=solve(nums,target,i+1,maxi,mini,taken);
        maxi=max(maxi,nums[i]);
        mini=min(mini,nums[i]);
        int take=solve(nums,target,i+1,maxi,mini,true);
        
        return (take+skip)%mod;
    }
    int numSubseq(vector<int>& nums, int target) {
        return solve(nums,target,0,0,INT_MAX,false);
    }
};
