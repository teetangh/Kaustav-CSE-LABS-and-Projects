#!/usr/bin/env python3
import numpy as np


def main():
    input_array1 = np.random.randint(100, size=(3, 4))
    print("input_array1  \n", input_array1)

    input_array2 = np.random.randint(100, size=(3, 4))
    print("input_array2  \n", input_array2)

    print("sum \n", input_array1 + input_array2)


if __name__ == "__main__":
    main()
