
'''
1. declare local variables using the allowed syntaxes

2. find of behaviour of static variables in a function, in a file, etc. 

3. declaration together with initialization for native and user-defined

4. pass vars to a function. Pass address of variable (try swap program)

5. exercise every type of variable declaration

6. make is_palindrome in different possible ways
'''

# Ordinary variables
i = 10
l = 51924361L

#static variables (function static). Note: there are no static variables per se in python

def foo():
  if not hasattr(foo, "counter"):
     foo.counter = 0  # it doesn't exist yet, so initialize it
  foo.counter += 1
  print 'counter is', foo.counter

if __name__ == '__main__':
  foo()
  foo()
  foo()


#declaring and instantiating class objects
class myUdt:
  a=10

udt = myUdt()

def swap_fn(a,b):
  a,b = b,a

swap_fn(i,l)

print 'i=%d, l=%d\n' % (i, l)
# Conclusion -- it is not possible to pass by reference (address - you know what I mean)

def is_palindrome(s):
  i=0
  l=len(s)
  if l == 0: return False 
  while i < l/2:
    if s[i] != s[l - i - 1]:
      return False
    i += 1
  return True

for s in ('aba','abba','ab','abb',''):
  print '%s, %d' %(s,is_palindrome(s))




