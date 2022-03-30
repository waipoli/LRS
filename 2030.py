def main():
    x = int(input())
    l = 1
    r = x
    while(r -l > 1):
        m = (r+l) // 2
        if x - l*l >= r*r -x:
            l = m
        else:
            r = m
#        print(l,r)
#    print(l,r)
    count = 100
    while(l*l != x):
        if count == 0 or l == 0:
            break
        l-=1
        count-=1

    if l*l == x:
        print(l)
        exit(0)
    count = 100
    while(r*r != x):
        if count == 0:
            break
        r+=1
        count-=1
    if r*r == x:
        print(r)
    else:
        print(-1)
main()
