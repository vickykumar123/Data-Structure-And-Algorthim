"""
Example 1:

Input: nums = [0,1,0,3,12]
Output: [1,3,12,0,0]
Example 2:

Input: nums = [0]
Output: [0]
"""
arr=[0,1,0,3,4]
for i in range(len(arr)):
   if(arr[i]==0):
      arr.append(arr[i])
      arr.remove(arr[i])
print(arr)
