
def next_permu(seq : list) -> list:
    res=seq.copy()
    # find the pivot - seq[i-1] < seq[i]
    p=len(res)
    for i in range(len(res)-1,1,-1):
        if res[i-1] < res[i]:
            p=i-1
            break
    # swap pivot with least significant number 
    # greater than it
    for i in range(len(res)-1,p,-1):
        if res[i] > res[p]:
            res[i],res[p] = res[p],res[i]
            break
    # reverse from p+1 to end
    res[p+1:] = reversed(res[p+1:])
    return res

if __name__=='__main__':
    tests=[([5,1,2,4,3],[5,1,3,2,4])]
    for q, r in tests:
        assert(next_permu(q) == r)
        t=q.copy()
        for i in range(5):
            t=next_permu(t)
            print(t)
