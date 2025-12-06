def get_value_from_vector(raw, size):
    flg = True
    data = []
    count = 1
    for c in raw:
        if c == ",":
            count += 1
    if size == -1:
        size = count
    sep = count // size
    count = 0
    current = ""
    for c in raw:
        if flg:
            flg = False
            continue
        if c == ",":
            count += 1
            if count % sep == 0:
                data.append(current.strip())
                current = ""
        else:
            current += c
    data.append(current.strip()[:-1])
    return data
