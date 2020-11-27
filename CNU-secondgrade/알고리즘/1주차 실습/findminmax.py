def bubble_sort(arr):
    for i in range(len(arr) - 1, 0, -1):
        for j in range(i):
            if arr[j] > arr[j + 1]:
                arr[j], arr[j + 1] = arr[j + 1], arr[j]

a = input()
a = [int(i) for i in a.split()]
b = input()
b = [int(i) for i in b.split()]
bubble_sort(b)
result = b[a[1]-1] - b[a[0] - a[2]]
if result < 0:
    result = result * -1
print(result)