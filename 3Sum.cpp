/*
15. 3Sum

Given an integer array nums, return all the triplets [nums[i], nums[j], nums[k]] such that i != j, i != k, and j != k, and nums[i] + nums[j] + nums[k] == 0.

Notice that the solution set must not contain duplicate triplets.

 

Example 1:

Input: nums = [-1,0,1,2,-1,-4]
Output: [[-1,-1,2],[-1,0,1]]
Example 2:

Input: nums = []
Output: []
Example 3:

Input: nums = [0]
Output: []
 

Constraints:

0 <= nums.length <= 3000
-105 <= nums[i] <= 105
*/


class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        
        for(unsigned int i=0; i<nums.size(); i++){
            if ((i>0) && (nums[i]==nums[i-1]))
                continue;
            
            int l=i+1;
            int r=nums.size()-1;
            while(l<r){
                int sum=nums[r]+nums[l]+nums[i];
                if(sum>0){
                    r--;
                }else if(sum<0){
                    l++;
                }else{
                    res.push_back(vector<int> {nums[i], nums[l], nums[r]});
                    while (l + 1 < r && nums[l]==nums[l+1]) l++;
                    while (r - 1 > l && nums[r]==nums[r-1]) r--;
                    l++; r--;
                }
            }
        }
        return res;
    }
};

