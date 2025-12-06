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
        res = "["
        for i in range(size):
            if i > 0:
                res += ", "
            res += str(start["_M_cur"][i])
        res += "]"
        return res
