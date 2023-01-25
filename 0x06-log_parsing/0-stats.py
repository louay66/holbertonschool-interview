#!/usr/bin/python3
""" program that read line from stdin"""
import fileinput
from signal import signal, SIGINT
from sys import exit


def print_output(status_code, file_size):
    """ print the status acording"""
    print("File size: {}".format(file_size))
    for a, b in status_code.items():
        if b == 0:
            continue
        print("{}: {}".format(a, b))


def handler(signal_received, frame):
    """ catch ctr + C and print the status acordind"""
    print("File size: {}".format(file_size))
    for a, b in status_code.items():
        if b == 0:
            continue
        print("{}: {}".format(a, b))
    exit()


status_code = {'200': 0, '301': 0, '400': 0,
               '401': 0, '403': 0, '404': 0, '405': 0, '500': 0}
file_size = 0
count = 0

signal(SIGINT, handler)

for i in fileinput.input():
    if count % 10 == 0 and count != 0:
        ''' print("File size: {}".format(file_size))
        for a , b in status_code.items():
            print ("{}: {}".format(a, b)) '''
        print_output(status_code,  file_size)
    data = i.split(" ")
    if data[7] not in status_code.keys():
        continue
    file_size += int(data[8])
    status_code[data[7]] += 1
    count += 1
