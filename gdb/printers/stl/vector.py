import os
import sys

base_dir = os.path.dirname(os.path.abspath(__file__))
root = os.path.abspath(os.path.join(base_dir, "..", ".."))

sys.path.insert(0, os.path.join(root, "lib"))


from vector import get_value_from_vector

max_size = 30


class vector:
    name = "std::vector"
    regex = "^std(::__debug)?::vector<.*>$"
    priority = 10

    def __init__(self, val):
        self.val = val

    def to_string(self):
        size = self.val["_M_impl"]["_M_finish"] - self.val["_M_impl"]["_M_start"]
        if max_size < size:
            mid = max_size // 2
            res = "["
            for i in range(mid):
                if 0 < i:
                    res += ", "
                res += str(self.val["_M_impl"]["_M_start"][i])

            res += ", ... "
            for i in range(mid):
                if 0 < i:
                    res += ", "
                res += str(self.val["_M_impl"]["_M_start"][size - mid + i])
            res += "]"
            return res

        res = "["
        for i in range(size):
            if i > 0:
                res += ", "
            res += str(self.val["_M_impl"]["_M_start"][i])
        res += "]"
        return res


class vector2D:
    name = "std::vector2D"
    regex = r"^std(::__debug)?::vector<std(::__debug)?::vector<.*>.*>$"
    priority = 20

    def __init__(self, val):
        self.val = val

    def to_string(self):
        outer_size = self.val["_M_impl"]["_M_finish"] - self.val["_M_impl"]["_M_start"]
        if max_size < outer_size:
            mid = max_size // 2
            data = []
            max_width = []
            for i in range(mid):
                data.append(
                    get_value_from_vector(
                        str(self.val["_M_impl"]["_M_start"][i]), -1
                    )  # pyright: ignore[reportCallIssue]
                )
                for j in range(len(data[-1])):
                    if len(max_width) <= j:
                        max_width.append(0)
                    max_width[j] = max(max_width[j], len(data[-1][j]))
            for i in range(mid):
                data.append(
                    get_value_from_vector(
                        str(self.val["_M_impl"]["_M_start"][outer_size - mid + i]), -1
                    )  # pyright: ignore[reportCallIssue]
                )
                for j in range(len(data[-1])):
                    if len(max_width) <= j:
                        max_width.append(0)
                    max_width[j] = max(max_width[j], len(data[-1][j]))
            res = ""
            for i in range(mid):
                if i > 0:
                    res += "\n"
                res += "["
                for j in range(len(data[i])):
                    if j > 0:
                        res += ", "
                    for _ in range(max_width[j] - len(data[i][j])):
                        res += " "
                    res += data[i][j]
                res += "]"
            res += "\n.\n.\n."
            for i in range(mid, mid * 2):
                res += "\n["
                for j in range(len(data[i])):
                    if j > 0:
                        res += ", "
                    for _ in range(max_width[j] - len(data[i][j])):
                        res += " "
                    res += data[i][j]
                res += "]"
            return res
        data = []
        max_width = []
        for i in range(outer_size):
            data.append(
                get_value_from_vector(
                    str(self.val["_M_impl"]["_M_start"][i]), -1
                )  # pyright: ignore[reportCallIssue]
            )
            for j in range(len(data[-1])):
                if len(max_width) <= j:
                    max_width.append(0)
                max_width[j] = max(max_width[j], len(data[-1][j]))
        res = ""
        for i in range(outer_size):
            if i > 0:
                res += "\n"
            res += "["
            for j in range(len(data[i])):
                if j > 0:
                    res += ", "
                for _ in range(max_width[j] - len(data[i][j])):
                    res += " "
                res += data[i][j]
            res += "]"
        return res


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
