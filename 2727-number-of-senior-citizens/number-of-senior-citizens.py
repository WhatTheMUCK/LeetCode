class Solution(object):
    def countSeniors(self, details):
        """
        :type details: List[str]
        :rtype: int
        """
        return sum(int(info[11:13]) > 60 for info in details)
        