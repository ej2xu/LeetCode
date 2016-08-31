class Solution(object):
    def getSum(self, a, b):
        while b:
            t = a
            a ^= b
            b = (b&t) << 1
        return a
