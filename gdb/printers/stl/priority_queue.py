class priority_queue:
    name = "std::priority_queue"
    regex = "^std::priority_queue<.*>$"

    def __init__(self, val):
        self.val = val

    def to_string(self):
        return self.val["c"]
