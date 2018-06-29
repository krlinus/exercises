import sys

def shift_left(arr, nplaces):
    arr=arr[nplaces:]+arr[:nplaces]
    return arr

if __name__=='__main__':
    if len(sys.argv) != 3:
        print 'Usage: %s <number-of-places-to-shift-left> <comma-separated-list-of-numbers>' % sys.argv[0]
        exit(1)
    nplaces = int(sys.argv[1])
    arr = map(int, sys.argv[2].split(','))
    arr = shift_left(arr, nplaces)
    for i in arr[:-1]:
        print '%d, ' % i,
    print arr[-1]
