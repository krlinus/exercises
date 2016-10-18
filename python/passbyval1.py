
#Qs. Can I change my function parameter by using += operator?
#    .. since += on a list does change the parameter, can it work 
#    with other types?
#Ans. No.


def spoilval(v):
  o=v
  v += 10
  v -= o

a=30
spoilval(a)
print a #prints 30
