#!/usr/bin/pypy
'''
alphabet = [ 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z',
			'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 
'''

import random
import sys

alphabet = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ"
length = len(alphabet)

m = random.randrange(1, 51)
n = random.randrange(1, 51)

print str(m) + " " + str(n)

for i in range(m):
	for j in range(n):
		sys.stdout.write(alphabet[random.randrange(0, length)]);
	print

print len(alphabet)
