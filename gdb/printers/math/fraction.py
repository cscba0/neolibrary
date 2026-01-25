class Modint:
    name = "cscba::math::Fraction"
    regex = "cscba::math::Fraction"
    priority = 1

    def __init__(self, val):
        self.val = val

    def to_string(self):
        return str(self.val["x"]) + "/" + str(self.val["y"])
