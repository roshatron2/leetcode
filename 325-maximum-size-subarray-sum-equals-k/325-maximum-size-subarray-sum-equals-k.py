class Solution:
    def maxSubArrayLen(self, nums: List[int], k: int) -> int:
        prefixSum = 0
        res = 0
        indices = {}
        
        for i,value in enumerate(nums):
            prefixSum += value
            
            if prefixSum == k:
                res = i + 1
            if prefixSum - k in indices:
                res = max(res,i - indices[prefixSum - k])
            if prefixSum not in indices:
                indices[prefixSum] = i
        return res
        