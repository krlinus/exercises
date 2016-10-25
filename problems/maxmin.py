N = input()
K = input()
lists = [input() for _ in range(0,N)]
lists.sort()
print lists
#min_diff = max(lists) ## Write code here to compute the answer using (n, k, candies)
diffs = [lists[x+K-1]-lists[x] for x in range(0,N-K+1)]
print diffs
min_diff = min(diffs)
print min_diff
