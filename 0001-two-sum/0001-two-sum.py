class Solution(object):
    def twoSum(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: List[int]
        """


        map = {}

        for i , num in enumerate(nums):
            c = target - num
            if c in map:
                return [map[c] , i]

            map[num] = i
        