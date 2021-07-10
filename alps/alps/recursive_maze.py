def find_start():
    for y, row in enumerate(map):
        for x, val in enumerate(row):
            if val == 'e':
                return y, x


def is_valid(y, x):
    return 0 <= y <= height-1 and 0 <= x <= width-1


def go(i, j):
    global done
    if not done:
        if is_valid(i, j):
            now = map[i][j]
            if now == 'x':
                print(i, j, "<-exit found")
                done = True
            elif now == '0' or now == 'e':
                print(i, j)
                map[i][j] = '1'
                go(i+1, j)
                go(i, j+1)
                go(i-1, j)
                go(i, j-1)


if __name__=='__main__':
    map = [['1', '1', '1', '1', '1', '1'],
           ['e', '0', '1', '0', '0', '1'],
           ['1', '0', '0', '0', '1', '1'],
           ['1', '0', '1', '0', '1', '1'],
           ['1', '0', '1', '0', '0', 'x'],
           ['1', '1', '1', '1', '1', '1']]
    height = len(map)
    width = len(map[0])
    done = False

    start = find_start()
    go(start[0], start[1])

