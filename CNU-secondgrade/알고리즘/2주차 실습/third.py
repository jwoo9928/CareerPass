import heapq

def max(nums, k):
  heap = []
  for num in nums:
    heapq.heappush(heap, (-num,num))

  kth_max = None
  for _ in range(k):
    kth_max = heapq.heappop(heap)[1]
  return kth_max


nm = input()
nm = [int(i) for i in nm.split()]
b = input()
b = [int(i) for i in b.split()]
print(max(b, nm[1]+1))