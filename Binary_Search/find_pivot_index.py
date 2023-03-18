def pivotIndex(nums):
        S = sum(nums)
        leftsum = 0
        for i, x in enumerate(nums):
            right=(S - leftsum - x)
            if leftsum == right:
                return i
            leftsum += x
        return -1
nums=[1,7,3,6,5,6]
print(pivotIndex(nums))