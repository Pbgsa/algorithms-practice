from collections import defaultdict

class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        mp = defaultdict(list)

        for word in strs:
            sorted_s = ''.join(sorted(word))
            mp[sorted_s].append(word)
        
        return list(mp.values())