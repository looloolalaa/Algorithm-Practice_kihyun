def selection_sort(arr):
    for i in range(len(arr) - 1):
        least = i
        for j in range(i + 1, len(arr)):
            if arr[least] > arr[j]:
                least = j
        arr[i], arr[least] = arr[least], arr[i]


def merge(l, m):
    result = []
    while l and m:
        if l[0] < m[0]:
            result.append(l.pop(0))
        else:
            result.append(m.pop(0))
    if l or m:
        result += l
        result += m
    return result


def merge_sort(arr, start, end):
    if start == end:
        return [arr[start]]
    else:
        mid = int((start + end) / 2)
        return merge(merge_sort(arr, start, mid), merge_sort(arr, mid+1, end))


def mergeSort(arr):
    return merge_sort(arr, 0, len(arr)-1)


def quick_sort(A, left, right):
    if left < right:
        pivot = A[left]
        start = left+1
        end = right

        while True:
            while start <= right and A[start] < pivot:
                start += 1
            while left <= end and A[end] > pivot:
                end -= 1
            if end < start:
                break
            A[start], A[end] = A[end], A[start]
        A[end], A[left] = A[left], A[end]
        pivot_index = end

        # print(left, pivot_index, right)
        quick_sort(A, left, pivot_index-1)
        quick_sort(A, pivot_index+1, right)


if __name__ == '__main__':
    data = [5,3,8,1,2,7,4444,0]
    quick_sort(data, 0, len(data)-1)
    print(data)
