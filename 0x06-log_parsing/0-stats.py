#!/usr/bin/python3
""" program that read line from stdin"""
from sys import stdin


def print_output():
    """ print the status acording"""
    print("File size: {}".format(file_size))
    for a, b in sorted(status_code.items()):
        if b != 0:
            print("{}: {}".format(a, b))


if __name__ == "__main__":
    status_code = {'200': 0, '301': 0, '400': 0,
                   '401': 0, '403': 0, '404': 0, '405': 0, '500': 0}
    file_size = 0
    count = 0
    try:
        for i in stdin:
            try:
                data = i.split(" ")
                if data[7] in status_code.keys():
                    status_code[data[7]] += 1
                file_size += int(data[8])
                count += 1
            except Exception:
                pass
            if count % 10 == 0:
                print_output()
        print_output()
    except KeyboardInterrupt:
        print_output()
        raise
