#!/usr/bin/env python3
import numpy as np


def main():
    elements = list([float(x) for x in input().split()])
    print(elements)

    nrows, ncols = [int(x) for x in input("Enter nrows and ncols: ").split()]
    elements_np = np.array(elements)
    elements_matrix = np.reshape(elements, [nrows, ncols])
    print(elements_matrix, "Before transposing")

    elements_matrix = np.transpose(elements_matrix)
    print(elements_matrix, "After transposing")


if __name__ == "__main__":
    main()
