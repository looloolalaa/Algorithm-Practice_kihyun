def draw_tree(row, length):
    # print(row, length)
    if length < 0:
        print("length error")
        return
    elif length == 0:
        return
    elif length == 1:
        return print("X", end='')
    else:
        if row == 0:
            s = ""
            for i in range(length):
                s += '-'
            half_len = int(length/2)
            s = s[:half_len]+'X'+s[half_len+1:]
            print(s, end='')
        else:
            half_len = int(length / 2)
            if length % 2:
                draw_tree(row - 1, half_len)
                draw_tree(row - 1, half_len+1)
            else:
                draw_tree(row - 1, half_len)
                draw_tree(row - 1, half_len)


if __name__ == '__main__':
    draw_tree(3, 40)
