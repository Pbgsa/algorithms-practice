from collections import deque

class RecentCounter:

    def __init__(self):
        self.q = deque()
        self.count = 0

    def ping(self, t: int) -> int:
        self.q.append(t)
        self.count += 1

        while (self.q[0] < (t - 3000)):
            self.q.popleft()
            self.count -=1
        
        return self.count
    
# The time complexity of the ping method is O(n) in the worst case since we may need to remove all elements from the queue, and the space complexity is O(n) in the worst case if all pings are within the last 3000 milliseconds and added to the queue.