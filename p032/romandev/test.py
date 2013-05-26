#!/usr/bin/pypy

import random
import sys

test_case_count = 1000

random.seed()

cards = [c for c in range(1, 53)]

print test_case_count
print

for ti in range(0, test_case_count):
	n = random.randrange(1, 101)
	print n
	for ni in range(0, n):
		random.shuffle(cards)
		for ci in range(0, 52):
			sys.stdout.write(str(cards[ci]) + " ")
		print
	methods = [m for m in range(1, n + 1)]
	random.shuffle(methods)
	for ni in range(0, n):
		print methods[ni]
	print
