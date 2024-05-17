import string

class Solution:
    def reversePrefix(self, word: str, ch: str) -> str:
        decider = -1
        for i in range(len(word)):
            if (word[i] == ch):
                decider = i
                break

        ans = ""
        if (decider == -1):
            ans = word
        else: 
            ans = word[i::-1] + word[i + 1:]

        return ans