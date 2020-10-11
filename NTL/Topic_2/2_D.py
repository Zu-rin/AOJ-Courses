a, b = map(int, input().split())
m = False
if(a < 0):
    a = -a
    m ^= True
if(b < 0):
    b = -b
    m ^= True
ans = a // b
if(m and ans > 0):
    print("-", end = "")
print(ans)
