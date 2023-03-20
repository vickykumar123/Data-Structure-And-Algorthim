def linearSearch(arr,key):
    for i in range(len(arr)):
        if arr[i]==key:
            return i
    return -1

arr = [10,5,8,9,12]
key= 9
ans = linearSearch(arr,key)
if ans==-1:
    print("Element not found")
else:
    print("Element found in index",ans)