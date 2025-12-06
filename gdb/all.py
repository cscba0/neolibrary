import os
import sys
import importlib.util
import inspect
import gdb
import gdb.printing

directory = os.path.join(os.environ["HOME"], "neolibrary/gdb/printers")
sys.path.insert(0, directory)

pp = gdb.printing.RegexpCollectionPrettyPrinter("neolibrary")

normal = []
prioritized = []

for root, dirs, files in os.walk(directory):
    for filename in files:
        if not filename.endswith(".py"):
            continue

        path = os.path.join(root, filename)
        module_name = os.path.splitext(os.path.relpath(path, directory))[0].replace(
            os.sep, "_"
        )

        spec = importlib.util.spec_from_file_location(module_name, path)
        module = importlib.util.module_from_spec(spec)
        spec.loader.exec_module(module)

        for _, obj in inspect.getmembers(module, inspect.isclass):
            if hasattr(obj, "name") and hasattr(obj, "regex"):
                if hasattr(obj, "priority"):
                    prioritized.append(obj)
                else:
                    normal.append(obj)

for cls in normal:
    pp.add_printer(cls.name, cls.regex, cls)

prioritized.sort(key=lambda c: c.priority, reverse=True)
for cls in prioritized:
    pp.add_printer(cls.name, cls.regex, cls)

gdb.printing.register_pretty_printer(gdb.current_objfile(), pp)
