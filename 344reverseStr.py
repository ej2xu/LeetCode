class Solution(object):
    def reverseString(self, s):
        """
        :type s: str
        :rtype: str
        """
        s = list(s)
        for i in xrange(len(s)/2):
            s[i], s[-i-1] = s[-i-1], s[i]
        return "".join(s)
