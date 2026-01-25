import os, sys

base_dir = os.path.dirname(os.path.abspath(__file__))
root = os.path.abspath(os.path.join(base_dir, "..", ".."))

sys.path.insert(0, os.path.join(root, "lib"))


from tupl import draw_tuple  # pyright: ignore[reportMissingImports]


class pair:
    name = "std::pair"
    regex = "^std::pair<.*>$"

    def __init__(self, val):
        self.val = val

    def to_string(self):
        data = [self.val["first"], self.val["second"]]
        return draw_tuple(data)  # pyright: ignore[reportCallIssue]
