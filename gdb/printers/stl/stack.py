import os, sys

base_dir = os.path.dirname(os.path.abspath(__file__))
root = os.path.abspath(os.path.join(base_dir, "..", ".."))

sys.path.insert(0, os.path.join(root, "lib"))


from vector import draw_vector


class stack:
    name = "std::stack"
    regex = "^std::stack<.*>$"

    def __init__(self, val):
        self.val = val

    def to_string(self):
        size = (
            self.val["c"]["_M_impl"]["_M_finish"]["_M_cur"]
            - self.val["c"]["_M_impl"]["_M_start"]["_M_cur"]
        )
        data = []
        for i in range(size):
            data.append(str(self.val["c"]["_M_impl"]["_M_start"]["_M_cur"][i]))
        return draw_vector(data)  # pyright: ignore[reportCallIssue]
