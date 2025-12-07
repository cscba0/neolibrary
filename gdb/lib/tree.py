def get_str_with_padding(target, padding):
    result = ""
    vec = target.split("\n")
    pad = " " * padding
    width = 0
    for el in vec:
        width = max(width, len(el))
    result += f"{pad}┌{'─' * width}┐\n"
    for el in vec:
        result += f"{pad}│{el}{' ' * (width - len(el))}│\n"
    result += f"{pad}└{'─' * width}┘\n"
    return result


def draw_binary_tree(data, padding, ind, size):
    result = ""
    if ind * 2 < size:
        result += draw_binary_tree(data, padding, ind * 2, size)
    result += get_str_with_padding(data[ind], padding[get_height(ind) - 1])
    if ind * 2 + 1 < size:
        result += draw_binary_tree(data, padding, ind * 2 + 1, size)
    return result


def get_height(ind):
    height = 0
    while ind > 0:
        ind = ind // 2
        height += 1
    return height
