#!/usr/bin/pypy

import sys

direction = [ [-1, -1], [0, -1], [1, -1],
			  [-1, 0],           [1, 0],
			  [-1, 1],  [0, 1],  [1, 1] ]

test_case_count = int(sys.stdin.readline())
sys.stdin.readline()	# read blank line

def check(g, w):

	m = len(g)
	n = len(g[0])

	for i in range(0, m):
		for j in range(0, n):
			y = i
			x = j
			l = 0
			word_length = len(w)
			success = True

			for d in range(0, 8):
				while 0 <= x and x < n and 0 <= y and y < m and word_length > l:
					if g[y][x] != w[l]:
						success = False
						break

					y = y + direction[d][0]
					x = x + direction[d][1]
					l = l + 1

				if success and word_length - l == 1:
					print str(i) + " " + str(j)
					return


# get m, n
grid_size = sys.stdin.readline().split()
m = int(grid_size[0])
n = int(grid_size[1])


# get grid data
grid = [ sys.stdin.readline() for i in range(0, m) ]


# get k
k = int(sys.stdin.readline())


# get words
words = [ sys.stdin.readline() for i in range(0, k) ]

check(grid, "bk")






