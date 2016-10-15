
#Note: I tried set-comprehension, and it worked!
orig_set= {x for x in range(100,300)}
set3={x for x in orig_set if x % 3 ==0}
set5={x for x in orig_set if x % 5 ==0}

print '3 only', set3
print '5 only', set5

print '3 & 5', set3 & set5
print '3 or 5', set3 | set5

print 'neither of 3 and 5', orig_set - (set3 | set5) #BTW, Python rocks!

