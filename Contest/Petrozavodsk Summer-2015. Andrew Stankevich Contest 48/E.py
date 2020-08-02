p = 998244353
for i in range(0, 8):
    ans = ['0']
    for j in range(0, 8):
        s = input()
        s = s.split(' ')
        a = int(s[0])
        b = int(s[1])
        ans.append(str(b % p))
    print('{', end = '')
    print(', '.join(ans), end = '},\n')
