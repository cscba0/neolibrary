class queue:
    name = "std::queue"
    regex = "^std::queue<.*>$"

    def __init__(self, val):
        self.val = val

    def to_string(self):
        size = (
            self.val["c"]["_M_impl"]["_M_finish"]["_M_cur"]
            - self.val["c"]["_M_impl"]["_M_start"]["_M_cur"]
        )
        res = "["
        for i in range(size):
            if i > 0:
                res += ", "
            res += str(self.val["c"]["_M_impl"]["_M_start"]["_M_cur"][i])
        res += "]"
        return res
