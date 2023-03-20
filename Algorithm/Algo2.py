def binarySearch(arr,key):
    s = 0
    end = len(arr)-1
    # mid = (s+end)//2

    while (s<=end):
        mid = (s+end)//2
        if arr[mid]==key:
            return mid
        elif key>arr[mid]:
            s=mid+1
        else:
            end=mid-1
        
    return -1

arr = [8, 10, 12, 14, 16, 18, 20]
key = 20
ans = binarySearch(arr,key)
if ans == -1:
    print("Element not found ")
else:
    print("Element found in index ",ans)