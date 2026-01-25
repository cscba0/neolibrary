import os
import sys

base_dir = os.path.dirname(os.path.abspath(__file__))
root = os.path.abspath(os.path.join(base_dir, "..", ".."))

sys.path.insert(0, os.path.join(root, "lib"))


from vector import get_value_from_vector, draw_vector

max_size = 40


class vector:
    name = "std::vector"
    regex = "^std(::__debug)?::vector<.*>$"
    priority = 10

    def __init__(self, val):
        self.val = val

    def to_string(self):
        size = self.val["_M_impl"]["_M_finish"] - self.val["_M_impl"]["_M_start"]
        data = []
        for i in range(size):
            data.append(str(self.val["_M_impl"]["_M_start"][i]).strip())

        return draw_vector(data)  # pyright: ignore[reportCallIssue]


class vector2D:
    name = "std::vector2D"
    regex = r"^std(::__debug)?::vector<std(::__debug)?::vector<.*>.*>$"
    priority = 20

    def __init__(self, val):
        self.val = val

    def to_string(self):
        outer_size = self.val["_M_impl"]["_M_finish"] - self.val["_M_impl"]["_M_start"]
        data = []
        max_height = [1 for _ in range(outer_size)]
        max_width = []
        for i in range(outer_size):
            data.append(
                get_value_from_vector(
                    str(self.val["_M_impl"]["_M_start"][i])
                )  # pyright: ignore[reportCallIssue]
            )
        flg = False
        if max_size < outer_size:
            flg = True
            mid = max_size // 2
            fixed = []
            for i in range(mid):
                fixed.append(data[i])
            for i in range(outer_size - mid, outer_size):
                fixed.append(data[i])
            data = fixed.copy()
            outer_size = len(data)
        for i in range(outer_size):
            while len(max_width) < len(data[i]):
                max_width.append(1)
            for j in range(len(data[i])):
                max_height[i] = max(max_height[i], len(data[i][j].split("\n")))
                width = 0
                for line in data[i][j].split("\n"):
                    width = max(width, len(line))
                max_width[j] = max(max_width[j], width)

        if True:
            for i in range(outer_size):
                while len(data[i]) < len(max_width):
                    data[i].append(
                        "\n".join([" " * max_width[j] for j in range(max_height[i])])
                    )

        res = ["" for _ in range(sum(max_height) + outer_size + 1)]

        res[0] = "┌"
        if True:
            nex = max_width[0]
            ind = 1
            for i in range(sum(max_width) + len(max_width) - 1):
                if i == nex:
                    res[0] += "┬"
                    nex += max_width[ind] + 1
                    ind += 1
                else:
                    res[0] += "─"
        res[0] += "┐"

        pos = 1
        for i in range(outer_size):
            for j in range(max_height[i]):
                res[pos + j] = "│"
            for j in range(len(data[i])):
                spl = data[i][j].split("\n")
                for k in range(len(spl)):
                    res[pos + k] += spl[k]
                    for _ in range(max_width[j] - len(spl[k])):
                        res[pos + k] += " "
                    res[pos + k] += "│"
            pos += max_height[i] + 1
            if i == outer_size - 1:
                res[pos - 1] += "└"
            else:
                res[pos - 1] += "├"
            nex = max_width[0]
            ind = 1
            for j in range(sum(max_width) + len(max_width) - 1):
                if j == nex:
                    if i == outer_size - 1:
                        res[pos - 1] += "┴"
                    else:
                        res[pos - 1] += "┼"
                    nex += max_width[ind] + 1
                    ind += 1
                else:
                    res[pos - 1] += "─"
            if i == outer_size - 1:
                res[pos - 1] += "┘"
            else:
                res[pos - 1] += "┤"
        if flg:
            pos = 1
            for i in range(max_size // 2):
                pos += max_height[i] + 1
            res.insert(pos, res[pos - 1])
            x_pos = (sum(max_width) + len(max_width) - 1) // 2
            res.insert(pos, " " * x_pos + "...")
        return "\n".join(res)


class vector3D:
    name = "std::vector3D"
    regex = "^std(::__debug)?::vector<std(::__debug)?::vector<std(::__debug)?::vector<.*>.*>$"
    priority = 30

    def __init__(self, val):
        self.val = val

    def to_string(self):
        outer_size = self.val["_M_impl"]["_M_finish"] - self.val["_M_impl"]["_M_start"]
        if max_size < outer_size:
            mid = max_size // 2
            res = ""
            for i in range(mid):
                if i > 0:
                    res += "\n\n"
                res += str(self.val["_M_impl"]["_M_start"][i])
            res += "\n.\n.\n."
            for i in range(mid):
                res += "\n\n"
                res += str(self.val["_M_impl"]["_M_start"][outer_size - mid + i])
            return res
        res = ""
        for i in range(outer_size):
            if i > 0:
                res += "\n\n"
            res += str(self.val["_M_impl"]["_M_start"][i])
        return res
