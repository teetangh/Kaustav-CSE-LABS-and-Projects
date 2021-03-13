#!/usr/bin/env python3
import numpy as np


class Q3():
    def a(self):
        my_list = [float(x) for x in input("Enter the list elements").split()]
        my_array = np.array(my_list)
        print(my_array)

    def b(self):
        my_tuple = tuple([float(x)
                          for x in input("Enter the list elements").split()])
        my_array2 = np.array(my_tuple)
        print(my_array2)

    def c(self):
        zero_matrix = np.zeros((3, 4))
        print(zero_matrix)

    def d(self):
        my_sequence = [int(x) for x in range(0, 21, 5)]
        print(my_sequence)

    def e(self):
        input_array = np.random.randn(3, 4)
        print("input_array", input_array)
        output_array = np.reshape(input_array, (2, 2, 3))
        print("output_array", output_array)

    def f(self):
        input_array = np.random.randn(3, 4)
        print("input_array", input_array)

        print("column sum is: ", input_array.sum(axis=0))
        print("row sum is: ", input_array.sum(axis=1))
        print("column max is: ", input_array.max(axis=0))
        print("row max is: ", input_array.max(axis=1))
        print("column min is: ", input_array.min(axis=0))
        print("row min is: ", input_array.min(axis=1))


if __name__ == "__main__":
    q3 = Q3()

    q3.a()
    q3.b()
    q3.c()
    q3.d()
    q3.e()
    q3.f()
