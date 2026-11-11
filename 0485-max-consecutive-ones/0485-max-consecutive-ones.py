class Solution(object):
    def findMaxConsecutiveOnes(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        one,maxone=0,0
        for num in nums:
            if(num==1):
                one+=1
            else:
                maxone=max(one,maxone)
                one=0
        
        return max(one,maxone)
        