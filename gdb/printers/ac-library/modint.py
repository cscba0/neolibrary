class AtCoderModint:
    name = "atcoder::modint"
    regex = "atcoder::static_modint<(.*)>"
    priority = 1

    def __init__(self, val):
        self.val = val

    def to_string(self):
        return str(self.val["_v"])
