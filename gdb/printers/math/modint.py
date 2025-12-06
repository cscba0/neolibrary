class Modint:
    name = "cscba::math::Modint"
    regex = "cscba::math::Modint"
    priority = 1

    def __init__(self, val):
        self.val = val

    def to_string(self):
        return str(self.val["x"])
