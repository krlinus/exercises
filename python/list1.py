def inc_list(arg, new_item):
  arg += new_item

l = [1,2,3,4]
l += [5]
print l

sl=['abc','def']

sl += ['ghi']
print sl

inc_list(l,[6])
print l

inc_list(sl,['jkl'])
print sl


