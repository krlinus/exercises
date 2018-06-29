s = raw_input()

hist_dict=dict()
for c in s:
    if c in hist_dict:
        hist_dict[c] += '#'
    else:
        hist_dict[c] = '#'

for k in hist_dict.keys():
    print '%s: %s' % (k,hist_dict[k])
