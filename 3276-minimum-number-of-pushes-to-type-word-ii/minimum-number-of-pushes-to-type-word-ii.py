class Solution:
    def minimumPushes(self, word: str) -> int:
        mp = [0 for i in range(ord('z') - ord('a') + 1)]
        for letter in word:
            index = ord(letter) - ord('a')
            mp[index] += 1
        mp.sort(reverse=True)

        answer = 0
        occuried = 0
        for frequince in mp:
            answer += (occuried // 8 + 1) * frequince
            occuried += 1

        return answer 
        