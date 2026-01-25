def get_value_from_vector(raw):
    size = 0
    slice = raw.strip().split("\n")
    sep = []
    for i in range(len(slice[0])):
        if slice[0][i] == "┬" or slice[0][i] == "┌":
            size += 1
        if slice[0][i] == "┬":
            sep.append(i)
    data = ["" for _ in range(size)]
    for i in range(1, len(slice) - 1):
        spl = [""]
        for j in range(1, len(slice[i]) - 1):
            if j in sep:
                spl.append("")
            else:
                spl[-1] += slice[i][j]
        for j in range(size):
            if i != 1:
                data[j] += "\n"
            data[j] += spl[j]
    return data


max_size = 40


def draw_vector(data):
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
    res = ["│" for _ in range(max_height + 2)]
    res[0] = "┌"
    res[-1] = "└"
    for i in range(size):
        if 0 < i:
            for j in range(1, max_height + 1):
                res[j] += "│"
            res[0] += "┬"
            res[-1] += "┴"
        if flg and i == (max_size // 2):
            res[0] += "───┬"
            for j in range(1, max_height + 1):
                if j == (max_height // 2) + 1:
                    res[j] += "...│"
                else:
                    res[j] += "   │"
            res[-1] += "───┴"

        value = str(data[i]).split("\n")

        max_width = 1
        for j in range(len(value)):
            max_width = max(max_width, len(value[j]))

        for _ in range(max_width + 2):
            res[0] += "─"
            res[-1] += "─"
        for j in range(len(value)):
            res[j + 1] += " "
            res[j + 1] += value[j]
            for _ in range(max_width - len(value[j]) + 1):
                res[j + 1] += " "
    res[0] += "┐"
    res[-1] += "┘"
    for j in range(1, max_height + 1):
        res[j] += "│"
    return "\n" + "\n".join(res)
