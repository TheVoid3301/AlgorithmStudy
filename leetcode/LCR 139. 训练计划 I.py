class Solution:
    def trainingPlan(self, actions: List[int]) -> List[int]:
        res = []
        for i in actions:
            if i % 2 == 1:
                res.insert(0, i)
            else:
                res.append(i)
        return res
        