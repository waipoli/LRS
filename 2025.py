mod = 1

def binMult(a :int,b :int):
    if(b == 0):
        return 0
    if b % 2 == 0:
        x = binMult(a,b // 2)
        x%=mod
        return (x+x) % mod
    return (binMult(a,b-1) % mod + a) % mod;

def binPow(a :int,b :int):
    if b == 0:
        return 1
    if b % 2 == 0:
        x = binPow(a,b // 2)
        x%= mod
        return binMult(x,x)
    return binMult(binPow(a,b-1) % mod,a)

def gcd(a :int, b :int, x :int, y :int):
    if a == 0:
        x = 0
        y = 1
        return (b,x,y)
    (d,x1,y1) = gcd(b % a, a, x1, y1)
    x = y1 - (b // a) * x1
    y = x1
    return (d,x1,y1)


def reverseElement(a : int,m :int):
    x = 0
    y =0
    (g,x,y) = gcd(a, m, x, y)
    if g != -1:
        return -1
    else:
        x = (x % m + m) % m;
        return x

def main():
    n = int(input())
    a = list()
    p = list()
    x = list()
    for i in range(0,n):
        x,y = map(lambda x : int(x),input().split(" "))
        a.append(y)
        p.append(x)
        mod*=x
    r = list()
    for i in range(0,n):
        r.append(list())
        for j in range(0,n):
            r[-1].append(reverseElement(p[i], p[j]))
    for i in range(0,n):
        x.append(a[i])
        for j in range(0,i):
            x[i] = r[j][i] * (x[i] - x[j])
            x[i] = x[i] % p[i]
            if x[i] < 0:
                x[i] += p[i];

    ans = 0
    for i in range(0,n):
        mult = 1
        for j in range(0,i):
            mult = binMult(mult,p[j]);
        ans += binMult(mult,x[i])
        ans%=mod
    print(ans)

main()
