/*
560. Subarray Sum Equals K

Given an array of integers nums and an integer k, return the total number of continuous subarrays whose sum equals to k.

 

Example 1:

Input: nums = [1,1,1], k = 2
Output: 2
Example 2:

Input: nums = [1,2,3], k = 3
Output: 2
 

Constraints:

1 <= nums.length <= 2 * 104
-1000 <= nums[i] <= 1000
-107 <= k <= 107
*/

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        if(n==0)
            return 0;
        
        unordered_map<int,int> m;   
        int currSUM = 0;
        int i = 0;
        int count = 0;
        
        while(i<n){
            currSUM += nums[i];
            
            if(currSUM == k)   
                count += 1;
            
            if(m.find(currSUM-k)!=m.end())
                count += m[currSUM-k];
            
            m[currSUM]++;
            i++;
        }
        return count;
    }
};
