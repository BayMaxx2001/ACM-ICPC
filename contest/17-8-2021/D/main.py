


if __name__ == '__main__':
    list_input = lambda: list(map(int, input().split()))
    d = dict()
    n, k = list_input()
    for i in range(3*n):
        s = input()
        tmp = d.get(s, [0, i])
        d[s] = [tmp[0]+1, i]
    result = sorted(d, key = lambda x: d[x])

    if len(result) > k:
        for i in range(len(result)-1, len(result)-1-k, -1):
            print(result[i])
    else:
        print(*result[::-1], sep = '\n')