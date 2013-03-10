#!/usr/bin/pypy

import random
import sys

random.seed()

alphabet = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ"
length = len(alphabet)
direction = [ [-1, -1], [0, -1], [1, -1],
			  [-1, 0],           [1, 0],
			  [-1, 1],  [0, 1],  [1, 1] ]

def make_table(m, n):
	return [ [alphabet[random.randrange(0, length)] for j in range(n)] for i in range(m) ]

def print_table(t):
	m = len(t)
	n = len(t[0])

	print str(m) + " " + str(n)
	for i in range(0, m):
		for j in range(0, n):
			sys.stdout.write(t[i][j])
		sys.stdout.write("\n")

def get_start_points(t):
	m = len(t)
	n = len(t[0])

	max_range = m * n
	if max_range > 20: max_range = 20
	k = random.randrange(1, max_range + 1)

	points = [ [i, j] for i in range(0, m) for j in range(0, n) ]
	random.shuffle(points)

	return points[:k]

def make_word(t):
	m = len(t)
	n = len(t[0])

	p = get_start_points(t)
	p_count = len(p)

	word_max_length = 0
	if m < n: word_max_length = m
	elif m >= n: word_max_length = n

	word_list = {}

	for i in range(0, p_count):

		d = direction[random.randrange(0, 8)]

		word = ""
		word_length = random.randrange(1, word_max_length + 1)

		y = p[i][0]
		x = p[i][1]

		while 0 <= x and x < n and 0 <= y and y < m and word_length > 0:
			word = word + t[y][x]
			y = y + d[1]
			x = x + d[0]

			word_length = word_length - 1

		if word_list.get(word) == None:
			word_list[word] = word

	print len(word_list)
	for word in word_list:
		print word

		#print str(p[i][0]) + " " + str(p[i][1])

print 10000
print
for i in range(0, 10000):
	table = make_table(random.randrange(1, 51), random.randrange(1, 51))
	print_table(table)
	make_word(table)
	print


'''
def make_table(m, n):
	return [ [alphabet[random.randrange(0, length)] for j in range(n)] for i in range(m) ]


def get_start_points(m, n, x):
	points = [ [i, j] for i in range(0, m) for j in range(0, n) ]
	random.shuffle(points);
	return points[0:x]

def make_string(t, p):

	m = len(t)
	n = len(t[0])

	count = len(p)

	word_list = {}

	for i in range(0, count):

		d = direction[random.randrange(0, 8)]
		x = p[i][0]
		y = p[i][1]
		word = ""
		word_length = 0
		if ( m > n ):
			word_length = random.randrange(1, n)
		else:
			word_length = random.randrange(1, m)

		if word_length <= 0:
			word_length = 1

		while 0 <= x and x < n and 0 <= y and y < m and word_length > 0:
			word = word + t[y][x]
			x = x + d[0]
			y = y + d[1]
			word_length = word_length - 1

		if word == "":
			count = count - 1
		elif word_list.get(word) == None:
			word_list[word] = word
		else:
			count = count - 1

	if count != 0:
		print str(m) + " " + str(n)
		for i in range(0, m):
			for j in range(0, n):
				sys.stdout.write(t[i][j])
			print
		print count
		for w in word_list:
			print w
		print

for i in range(0, 1000):
	m = random.randrange(2, 51)
	n = random.randrange(2, 51)
	k = random.randrange(1, m * n)
	if k > 20: k = 20
	elif k <= 0: k = 1
	table = make_table(m, n)
	points = get_start_points(m, n, k)
	make_string(table, points)

#get_start_points(3, 3, 2)

'''


'''
alphabet = [ 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z',
			'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 
'''




'''
import random
import sys

alphabet = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ"
length = len(alphabet);

m = 5
n = 5

table = [ [alphabet[random.randrange(0, length)] for j in range(n)] for i in range(m) ]

direction = [ [-1, -1], [0, -1], [1, -1],
			  [-1, 0],           [1, 0],
			  [-1, 1],  [0, 1],  [1, 1] ]




print table
print table[0][0]
'''
'''
for i in range(5):
	for j in range(5):
		alphabet[random.randrange(0, length)]
'''


'''
length = len(alphabet)

m = random.randrange(1, 51)
n = random.randrange(1, 51)

print str(m) + " " + str(n)

for i in range(m):
	for j in range(n):
		sys.stdout.write(alphabet[random.randrange(0, length)]);
	print

print len(alphabet)
'''
