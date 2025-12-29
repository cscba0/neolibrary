class string:
    name = "^std::string$"
    regex = "string"
    priority = 9

    def __init__(self, val):
        self.val = val

    def to_string(self):
        max_len = 200
        # libstdc++ (newer): _M_impl.{_M_start,_M_finish}
        try:
            start = self.val["_M_impl"]["_M_start"]
            finish = self.val["_M_impl"]["_M_finish"]
            length = int(finish - start)
            if length < 0:
                length = 0
            if length > max_len:
                s = start.string(length=max_len)
                return '"' + s + '" ...'
            return '"' + start.string(length=length) + '"'
        except Exception:
            pass

        # libstdc++ (older): _M_dataplus._M_p
        try:
            p = self.val["_M_dataplus"]["_M_p"]
            s = p.string()
            if len(s) > max_len:
                return '"' + s[:max_len] + '" ...'
            return '"' + s + '"'
        except Exception:
            pass

        # 最終フォールバック：gdb の文字列表現を使う
        try:
            s = str(self.val)
            # 文字列リテラル風に整形（長ければ切る）
            if len(s) > max_len:
                return '"' + s[:max_len] + '" ...'
            return '"' + s + '"'
        except Exception:
            return "<std::string?>"
