def sq(num):
  return num*num

print list(map(sq,[1,2,3,]))

print 2

print [sq(x) for x in [1,2,3]]

print 3
print list(map(pow,[2,3,4],[7,8,9]))
# map() can be used instead of a for loop
print 4
print list(map(sq,[0,1,2,3,0])) #prints false instead of 0 in py 3.5
print 5
print [sq(x) for x in [0,1,2,3,0] if x]
print 6
print all([True,True]) #AND condition
print 7
print any([True,True]) #OR condition

#Qs: How to combine the all/any with the map() ?

class Foo:
  val=10

class Bar(Foo):
  bval=20
print 8
print issubclass(Bar,Foo)

print '9. closure'
def gen_adder(n):
  def adder(x):
    return n+x
  print("id(adder): %x" % id(adder))
  return adder

add_2_5 = gen_adder(5)
print add_2_5
print 10
del gen_adder
print add_2_5(10)
print 11
print add_2_5

print '12. decorator'

def wrapped():
  print 'Hello'

def wrapper(wrapped):
  print 'calling world'
  return wrapped


def memoize(f):
  memo = {}
  def helper(x):
    if x not in memo:
      memo[x]=f(x)
    return memo[x]
  return helper

#5383zy
@memoize
def factorial(n):
  if n == 1:
    return 1
  else:
    return n * factorial(n-1)

print '13. memoization of recursive factorial'

print factorial(5)
print factorial(50)
print factorial(100)
print factorial(500)

print 'you can use same wrapper for fibonacci'

class Base(object):
  def __init__(self):
    print 'Base'
  def m(self):
    print 'Base m'

class Der1(Base):
  def __init__(self):
    print 'Der1'
  def m(self):
    print 'Der1 m'

class Der2(Base):
  def __init__(self):
    print 'Der2'
  def m(self):
    print 'Der2 m'

class Gc(Der1,Der2):
  def __init__(self):
    print 'Gc'
  def m(self):
    print 'Gc m'

print '14 diamond inh - 1'
gc = Gc()
gc.m()

print '15'
print type(type)

print 16
# a,b,*c=range(5) #only valid in py3
print a, b
