def mergeSort(arr1,n,arr2,m,arr3):
    i=0
    j=0
    # k=0
    while(i<=n and j<=m):
        if(arr1[i]<arr2[j]):
            arr3.append(arr1[i])
            # k+=1
            i+=1
        else:
            arr3.append(arr2[j])
            # k+=1
            j+=1
    while(i<n):
        arr3.append(arr1[i])
        # k+=1
        i+=1
    while(j<m):
        arr3.append(arr2[j])
        # k+=1
        j+=1
arr1=[1,3,5,7,9,10,11]
arr2=[2,6,10]
arr3=[]
mergeSort(arr1,len(arr1),arr2,len(arr2)-1,arr3)
print(arr3)