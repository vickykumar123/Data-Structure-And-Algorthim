# comparing two list and putting into one in sorted manner.
def merge(a,b):
    i=0
    j=0
    c=[]
    while i<=len(a)-1 and j<=len(b)-1: # we can't use for loop don't waste time in thinking..
        if a[i]<b[j]:
            c.append(a[i])
            i+=1
        else:
            c.append(b[j])
            j+=1

    # below code is if there is any remaining element.

    while i<=len(a)-1:                    # we can't use for loop don't waste time in thinking..
        c.append(a[i])
        i+=1
    while j<=len(b)-1:                    # we can't use for loop don't waste time in thinking..
        c.append(b[j])
        j+=1


    return c
 
a=[2, 8, 15, 18,19,20]
b=[5, 9, 12, 17]
# print(merge(a,b))# only two is given follow this
c=[13,14,19,21]
d = [13,15,35]

list1= merge(a,b) # for n-number of list do this.
list2= merge(c,d)
print(merge(list1,list2))