class Solution:
    def maximumHappinessSum(self, happiness: List[int], k: int) -> int:

        happiness.sort(reverse=True)
        counter=0
        ret=0
        for i in range(k):
            ret+=max(happiness[i]-i,0)
            counter+=1

        return ret
        