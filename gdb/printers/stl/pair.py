class pair:
    name = "std::pair"
    regex = "^std::pair<.*>$"

    def __init__(self, val):
        self.val = val

    def to_string(self):
        res = "{" + str(self.val["first"]) + ", " + str(self.val["second"]) + "}"
        return res
