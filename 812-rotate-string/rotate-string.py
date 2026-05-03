class Solution(object):
    def rotateString(self, s, goal):
        """
        :type s: str
        :type goal: str
        :rtype: bool
        """
        k = len(s)
        l = k
        while(l):
            s = s[-1] + s
            s = s[:k]
            if s == goal:
                return True
            l -= 1
        return False
        