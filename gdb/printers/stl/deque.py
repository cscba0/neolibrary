import os, sys

base_dir = os.path.dirname(os.path.abspath(__file__))
root = os.path.abspath(os.path.join(base_dir, "..", ".."))

sys.path.insert(0, os.path.join(root, "lib"))


from vector import draw_vector


class deque:
    name = "std::deque"
    regex = "^std(::__debug)?::deque<.*>$"

    def __init__(self, val):
        self.val = val
        self.elttype = val.type.template_argument(0)
        size = self.elttype.sizeof
        if size < 512:
            self.buffer_size = int(512 / size)
        else:
            self.buffer_size = 1

    def to_string(self):
        start = self.val["_M_impl"]["_M_start"]
        end = self.val["_M_impl"]["_M_finish"]
        delta_n = end["_M_node"] - start["_M_node"] - 1
        delta_s = start["_M_last"] - start["_M_cur"]
        delta_e = end["_M_cur"] - end["_M_first"]
        size = self.buffer_size * delta_n + delta_s + delta_e
        data = []
        for i in range(size):
            data.append(str(start["_M_cur"][i]).strip())
        return draw_vector(data)  # pyright: ignore[reportCallIssue]
