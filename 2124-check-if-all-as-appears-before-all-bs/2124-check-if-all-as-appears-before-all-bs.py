class Solution(object):
    def checkString(self, s):
        b = False

        for i in s:
            if i == 'b':
                b = True
            elif i == 'a' and b:
                return False

        return True