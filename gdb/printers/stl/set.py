class set:
    name = "std::set"
    regex = "^std(::__debug)?::set<.*>$"

    def __init__(self, val):
        self.val = val

    def to_string(self):
        return "Not yet"
