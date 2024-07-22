class Solution:
    def sortPeople(self, names: List[str], heights: List[int]) -> List[str]:
        n = len(names)
        helper = list(range(n))
        for i in range(n):
            helper[i] = (heights[i], names[i])
        helper = sorted(helper, reverse=True)
        answer = list()
        for height, name in helper:
            answer.append(name)
        return answer
        