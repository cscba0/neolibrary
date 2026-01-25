max_size = 40


def draw_tuple(data):
    flg = False
    size = len(data)

    if max_size < size:
        flg = True
        mid = max_size // 2
        fixed = []
        for i in range(mid):
            fixed.append(str(data[i]))
        for i in range(size - mid, size):
            fixed.append(str(data[i]))
        data = fixed.copy()
        size = len(data)

    max_height = 1
    for i in range(size):
        height = len(str(data[i]).split("\n"))
        max_height = max(max_height, height)
    res = ["║" for _ in range(max_height + 2)]
    res[0] = "╔"
    res[-1] = "╚"
    for i in range(size):
        if 0 < i:
            for j in range(1, max_height + 1):
                res[j] += "│"
            res[0] += "╤"
            res[-1] += "╧"
        if flg and i == (max_size // 2):
            res[0] += "═══╤"
            for j in range(1, max_height + 1):
                if j == (max_height // 2) + 1:
                    res[j] += "...│"
                else:
                    res[j] += "   │"
            res[-1] += "═══╧"

        value = str(data[i]).split("\n")

        max_width = 1
        for j in range(len(value)):
            max_width = max(max_width, len(value[j]))

        for _ in range(max_width + 2):
            res[0] += "═"
            res[-1] += "═"
        pad = (max_height - len(value)) // 2
        for j in range(max_height):
            if 0 <= j - pad and j - pad < len(value):
                res[j + 1] += " "
                res[j + 1] += value[j - pad]
                for _ in range(max_width - len(value[j - pad]) + 1):
                    res[j + 1] += " "
            else:
                res[j + 1] += " " * (max_width + 2)
    res[0] += "╗"
    res[-1] += "╝"
    for j in range(1, max_height + 1):
        res[j] += "║"
    return "\n" + "\n".join(res)
