import sys, os

base_dir = os.path.dirname(os.path.abspath(__file__))
root = os.path.abspath(os.path.join(base_dir, "../../.."))

sys.path.insert(0, os.path.join(root, "lib"))

from vector import get_value_from_vector  # pyright: ignore[reportMissingImports]
from tree import draw_binary_tree, get_height  # pyright: ignore[reportMissingImports]


class SegmentTree:
    name = "SegmentTree"
    regex = "^cscba::data_structure::segment_tree::SegmentTree<.*>$"

    def __init__(self, val):
        self.val = val

    def to_string(self):
        size = int(self.val["n"])
        height = 1
        while 2 ** (height - 1) < size:
            height += 1
        data = get_value_from_vector(list(str(self.val["v"])), size * 2)
        padding = [0 for _ in range(height + 1)]

        # 幅を計算する
        for i in range(1, size * 2):
            vec = data[i].split("\n")
            h = get_height(i)
            for el in vec:
                padding[h] = max(padding[h], len(el) + 3)

        for i in range(1, height):
            padding[i] += padding[i - 1]

        result = draw_binary_tree(data, padding, 1, size * 2)
        return result
