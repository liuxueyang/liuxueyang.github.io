import sys
import re

for arg in sys.argv[1:]:
    lines = []

    with open(arg, 'r') as f:
        lines = f.readlines()
        for i, line in enumerate(lines[:5]):
            if re.match('tags:.*', line):
                if not re.match(r'.*\[.*\].*', line[5:]):
                    if line[5:].strip():
                        new_line = line[:6] + '[' + line[6:-1] + ']\n'
                        lines[i] = new_line

    with open(arg, 'w') as f:
        f.writelines(lines)
