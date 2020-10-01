class Solution:
    def isPowerOfFour(self, n: int) -> bool:
        if n!=0 and (n&(n-1))==0:
            if (not(n & 0xAAAAAAAA)):
                return True
        return False
        
		
#Why 0xAAAAAAAA?
# Think for even number of zeros and 10101010101010 concept.