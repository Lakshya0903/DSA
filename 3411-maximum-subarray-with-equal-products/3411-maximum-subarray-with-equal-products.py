class Solution(object):

    def gcd(self, a, b):
        while b:
            a, b = b, a % b
        return a

    def maxLength(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        n = len(nums)
        ans = 0

        for left in range(n):
            product = 1
            gcd_value = 0
            lcm_value = 1

            for right in range(left, n):
                num = nums[right]

                product *= num
                gcd_value = self.gcd(gcd_value, num)

                lcm_value = (lcm_value // self.gcd(lcm_value, num)) * num

                if product == gcd_value * lcm_value:
                    ans = max(ans, right - left + 1)

        return ans