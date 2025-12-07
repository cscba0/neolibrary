class Tuple:
    name = "std::tuple"
    regex = "^std::tuple<.*>$"

    def __init__(self, val):
        self.val = val

    def to_string(self):
        size = len(self.get_template_arg_list(self.val.type))
        node = self.val.cast(self.val.type.fields()[0].type)
        res = "("
        for i in range(size):
            if i > 0:
                res += ", "
            res += str(self._tuple_impl_get(node))
            node = node.cast(node.type.fields()[0].type)
        res += ")"
        return res

    def get_template_arg_list(self, type_obj):
        n = 0
        template_args = []
        while True:
            try:
                template_args.append(type_obj.template_argument(n))
            except:
                return template_args
            n += 1

    def _tuple_impl_get(self, val):
        """Return the tuple element stored in a _Tuple_impl<N, T> base class."""
        bases = val.type.fields()
        if not bases[-1].is_base_class:
            raise ValueError(
                "Unsupported implementation for std::tuple: %s" % str(val.type)
            )
        # Get the _Head_base<N, T> base class:
        head_base = val.cast(bases[-1].type)
        fields = head_base.type.fields()
        if len(fields) == 0:
            raise ValueError(
                "Unsupported implementation for std::tuple: %s" % str(val.type)
            )
        if fields[0].name == "_M_head_impl":
            # The tuple element is the _Head_base::_M_head_impl data member.
            return head_base["_M_head_impl"]
        elif fields[0].is_base_class:
            # The tuple element is an empty base class of _Head_base.
            # Cast to that empty base class.
            return head_base.cast(fields[0].type)
        else:
            raise ValueError(
                "Unsupported implementation for std::tuple: %s" % str(val.type)
            )
