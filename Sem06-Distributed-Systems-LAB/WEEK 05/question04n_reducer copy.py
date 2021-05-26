#!/usr/bin/env python
import sys
from operator import itemgetter
from itertools import groupby
"""A more advanced Reducer, using Python iterators and generators."""


def read_mapper_output(file, separator="\t"):
    # print(separator)
    for line in file:
        # print("DEBUG\t", line.rstrip().split(separator, 100))
        yield (line.rstrip().split(separator, 1))


def main(separator='\t'):

    # input comes from STDIN (standard input)
    data = read_mapper_output(sys.stdin, separator=separator)
    # groupby groups multiple word-count pairs by word,
    # and creates an iterator that returns consecutive keys and their group:
    # current_word - string containing a word (the key)
    # group - iterator yielding all ["&lt;current_word&gt;", "&lt;count&gt;"] items

    for current_word, group in groupby(data, itemgetter(0)):
        # print(current_word, " $ ", [k for k, g in group])
        try:
            total_count = sum(int(count) for current_word, count in group)
            print("%s%s%d" % (current_word, separator, total_count))
        except ValueError:
            # count was not a number, so silently discard this item
            pass


if __name__ == "__main__":
    main()
