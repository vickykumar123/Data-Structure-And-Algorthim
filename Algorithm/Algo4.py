def ceilFloor(arr,x):
    arr = sorted(arr)
    s= 0
    end =len(arr)-1
    floor = -1
    ceil= -1
    while(s<=end):
        mid = (s+end)//2
        if (arr[mid]<x):
            while(s<=end):
                if arr[mid]<=x and floor != arr[mid]:
                    floor=arr[mid]
                    s=mid+1
                elif (arr[mid] >= x):
                    ceil= arr[mid]
                    s=mid+1
                    break
                # s=mid+1
                mid=(s+end)//2
            
        else:
            ceil = arr[mid]
            end = mid-1
            
    return floor, ceil
arr=[85,24,40,10,66,16,6,54,93,42,6,98,49,100,98,23,59,48,17,56,64,94,77]
x= 42
print(ceilFloor(arr,x))

    
# print(sorted([5, 6, 8, 9, 6, 5, 5, 6]))