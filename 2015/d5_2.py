import re

def debug(fmt) -> None:
    print(f"[DEBUG]: {fmt}")


def is_nice(string:str) -> bool:
    return re.search(r'(..).*\1', string) and re.search(r'(.).\1', string)


with open('input.in', 'r') as tests:
    count = 0
    for line in tests:
        if is_nice(line):
            count += 1

print(count)