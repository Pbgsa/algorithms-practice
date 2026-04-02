"""
Heap / Priority Queue Snippets (Python)
Min-heap by default using heapq
"""

import heapq
from collections import Counter


# =========================
# MIN HEAP (default)
# =========================

heap = []

# Push
heapq.heappush(heap, 5)
heapq.heappush(heap, 2)
heapq.heappush(heap, 8)

# Peek (smallest)
smallest = heap[0]

# Pop (remove smallest)
val = heapq.heappop(heap)


# =========================
# BUILD HEAP FROM LIST
# =========================

nums = [5, 3, 8, 1]
heapq.heapify(nums)   # O(n)

# nums is now a heap
# nums[0] is the smallest


# =========================
# MAX HEAP (simulate)
# =========================

# Use negative values
max_heap = []

heapq.heappush(max_heap, -5)
heapq.heappush(max_heap, -2)
heapq.heappush(max_heap, -8)

# Get max
max_val = -heapq.heappop(max_heap)


# =========================
# TOP K ELEMENTS (classic)
# =========================

def top_k_largest(nums, k):
    heap = []

    for num in nums:
        heapq.heappush(heap, num)
        if len(heap) > k:
            heapq.heappop(heap)

    return heap   # k largest elements


# =========================
# TOP K FREQUENT
# =========================

def top_k_frequent(nums, k):
    count = Counter(nums)
    heap = []

    for num, freq in count.items():
        heapq.heappush(heap, (freq, num))
        if len(heap) > k:
            heapq.heappop(heap)

    return [num for freq, num in heap]


# =========================
# MERGE K SORTED LISTS
# =========================

def merge_k_lists(lists):
    heap = []
    result = []

    # initialize heap
    for i, lst in enumerate(lists):
        if lst:
            heapq.heappush(heap, (lst[0], i, 0))

    while heap:
        val, list_idx, elem_idx = heapq.heappop(heap)
        result.append(val)

        if elem_idx + 1 < len(lists[list_idx]):
            next_val = lists[list_idx][elem_idx + 1]
            heapq.heappush(heap, (next_val, list_idx, elem_idx + 1))

    return result


# =========================
# KTH LARGEST ELEMENT
# =========================

def kth_largest(nums, k):
    return heapq.nlargest(k, nums)[-1]


# =========================
# PRIORITY QUEUE WITH OBJECTS
# =========================

# (priority, value)

heap = []
heapq.heappush(heap, (2, "task2"))
heapq.heappush(heap, (1, "task1"))

priority, task = heapq.heappop(heap)


# =========================
# Dijkstra (GRAPH + HEAP)
# =========================

def dijkstra(graph, start):
    heap = [(0, start)]
    distances = {node: float('inf') for node in graph}
    distances[start] = 0

    while heap:
        curr_dist, node = heapq.heappop(heap)

        if curr_dist > distances[node]:
            continue

        for neighbor, weight in graph[node]:
            new_dist = curr_dist + weight

            if new_dist < distances[neighbor]:
                distances[neighbor] = new_dist
                heapq.heappush(heap, (new_dist, neighbor))

    return distances