class vector:
    name = "std::vector"
    regex = "^std(::__debug)?::vector<.*>$"
    priority = 10

    def __init__(self, val):
        self.val = val

    def to_string(self):
        size = self.val["_M_impl"]["_M_finish"] - self.val["_M_impl"]["_M_start"]
        if size > 60:
            return "[]"
        res = "["
        for i in range(size):
            if i > 0:
                res += ", "
            res += str(self.val["_M_impl"]["_M_start"][i])
        res += "]"
        return res


class vector2:
    name = "std::vector2D"
    regex = r"^std(::__debug)?::vector<std(::__debug)?::vector<.*>.*>$"
    priority = 20

    def __init__(self, val):
        self.val = val

    def to_string(self):
        outer_size = self.val["_M_impl"]["_M_finish"] - self.val["_M_impl"]["_M_start"]

        if outer_size > 60:
            return "[ ... ]"

        rows = []
        for i in range(outer_size):
            inner = self.val["_M_impl"]["_M_start"][i]
            inner_size = inner["_M_impl"]["_M_finish"] - inner["_M_impl"]["_M_start"]

            elems = []
            for j in range(inner_size):
                elems.append(str(inner["_M_impl"]["_M_start"][j]))

            rows.append("[ " + ", ".join(elems) + " ]")

        return "  " + "\n  ".join(rows) + "\n"
