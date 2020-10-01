class Solution:
    # @param A : list of integers
    # @return A after the sort
    def sortColors(self, A):
        i=0
        n=len(A)
        if n<=1:
            return A
        j=n-1
        k=0
        while k<=j:
            if A[k]==0:
                A[i],A[k]=A[k],A[i]
                i+=1
                k+=1
            elif A[k]==2:
                A[j],A[k]=A[k],A[j]
                j-=1
            else:
                k+=1
        return A
