#! /usr/bin/env python
from random import random, randint, randrange
import sys

def jacobi(a,n):  
         j = 1                                
         while (a != 0):  

             while (a%2==0):                   
                 j = j * pow(-1,(n*n-1)/8)    
                 a = a/2  
                   
             if not ( (a-3)%4 or (n-3)%4 ):   
                 j = -j  
                   
             a,n = n,a                         
             a = a % n                                  
         return j  
   
def isPrime_solovay(n, k=10):  
     if n == 2 or n == 3:  
         return True  
     if not n & 1:  
         return False  
           
     for i in xrange(k):  
         a = randrange(2, n - 1)        
         x = jacobi(a, n)                      
           
         y = pow(a, (n - 1) / 2, n)             
         if y != 1 and y != 0:                          
             y = -1  
         
         if (x == 0) or (y != x):            
             return False         
     return True  

def main():
	if(len(sys.argv) == 2):
            val = int(sys.argv[1])
            if (val < 1):
					exit("Must be greater than 1")
            char0 = '0'
            char1 = '1'

            rangeStart = char1 + char0*(val-1)
            rangeEnd = char1*(val)
            a = int(rangeStart,2)
            b = int(rangeEnd,2)

            size = a - b + 1
            zero = 0
            flag = True
            while flag:
                tmp = randint(a,b)
                if tmp%2 == 1 :
                    if isPrime_solovay(tmp,10):
                        print "Generated key: " + "{0:b}".format(tmp)
                        flag = False
                
                zero+=1
                if size == zero and flag is True:
                        flag = False
                        print "There is no prime number with "+ str(val) +" bits"
                
	else:
            print "Usage: python generateRandomKey.py <numberOfBits>"
		


if __name__ == "__main__":
    main()
