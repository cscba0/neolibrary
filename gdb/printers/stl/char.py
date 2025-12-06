class char:
    name = "char"
    regex = "^char$"

    def __init__(self, val):
        self.val = val

    def to_string(self):
        return f"'{str(chr(self.val))}'"
