class Solution {
public:

    int mysearch(vector<int> nums, int lb, int ub, int target){
        if(lb == ub) return target>nums[lb] ? lb+1:lb;
        if(target > nums[ub]) return ub + 1;
        if(target < nums[lb]) return lb;
        if(target > nums[(ub-lb)/2 + lb]) return mysearch(nums,(ub-lb)/2 + 1 + lb, ub, target);
        else if(target < nums[(ub-lb)/2 + lb]) return mysearch(nums,lb,(ub-lb)/2 - 1 + lb, target);
        if(target == nums[(ub-lb)/2 + lb]) return (ub-lb)/2 + lb;
        if(target == nums[ub]) return ub;
        if(target == nums[lb]) return lb;
    }
    
    int searchInsert(vector<int>& nums, int target) {
        if(nums.size() == 0) return 0;
        return mysearch(nums, 0, nums.size() - 1, target);
    }
};
