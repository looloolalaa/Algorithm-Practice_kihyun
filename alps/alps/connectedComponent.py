def show_image(img):
    for row in img:
        for pixel in row:
            if pixel == 0:
                print(".", end='')
            else:
                print(pixel, end='')
        print()
    print()


def is_valid(y, x, img):
    return y in height and x in width


def paint(y, x, color, img):
    if not is_valid(y, x, img):
        return
    else:
        if img[y][x] == 9:
            img[y][x] = color
            paint(y-1, x, color, img)
            paint(y, x-1, color, img)
            paint(y, x+1, color, img)
            paint(y+1, x, color, img)


def blob_coloring(img):
    new_img = img
    count = 1
    for y, row in enumerate(img):
        for x, pixel in enumerate(row):
            if pixel == 9:
                paint(y, x, count, new_img)
                count += 1

    return new_img


if __name__ == '__main__':
    original_image = [[0,0,0,0,0,0,9,0,0,0,0,9,9,9,9,9,0,0,9,9],
                      [9,9,9,9,9,0,9,0,0,0,0,0,0,0,0,9,0,0,9,9],
                      [0,0,9,0,0,0,9,0,0,0,0,9,9,9,9,9,0,0,9,9],
                      [0,9,9,9,0,0,9,9,9,0,0,9,0,0,0,0,0,0,9,9],
                      [0,9,0,9,0,0,9,0,0,0,0,9,9,9,9,9,0,0,9,9],
                      [9,9,0,9,9,0,9,0,0,0,0,0,0,0,0,0,0,0,9,9],
                      [9,0,0,0,9,0,9,0,0,0,0,0,9,0,9,0,0,0,0,0],
                      [9,0,0,0,9,0,9,0,0,0,0,0,9,0,9,0,0,0,9,9],
                      [0,0,0,0,0,0,9,0,0,0,0,9,9,9,9,9,0,0,9,9]]
    height = range(len(original_image))
    width = range(len(original_image[0]))

    show_image(original_image)
    new_img = blob_coloring(original_image)
    show_image(new_img)

