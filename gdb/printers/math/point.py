class Point:
    name = "cscba::math::Point"
    regex = "^cscba::math::Point<.*>$"

    def __init__(self, val):
        self.val = val

    def to_string(self):
        res = "(" + str(self.val["x"]) + ", " + str(self.val["y"]) + ")"
        return res
