#!/usr/bin/env python3
import numpy as np


def find_factors(num):

    for i in range(1, num + 1):
        if num % i == 0:
            print(i, end=" , ")


def main():
    num = int(input("Enter the number to find the factors of: "))
    find_factors(num)


if __name__ == "__main__":
    main()
