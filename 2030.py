def main():
    n = int(input())
    l = 0
    r = n
    while r - l > 1:
        m = (r + l) // 2
        if m * m > n:
            r = m
        else:
            l = m

    if r*r == n:
        print(r)
        exit(0)
    if l*l == n:
        print(l)
        exit(0)
    print(-1)

if __name__ == '__main__':
    main()