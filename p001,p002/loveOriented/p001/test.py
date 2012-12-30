import sys
import random

def make_input():
	i = 0
	output_file = open("case.txt", 'w')
	while( i < 1000):
		a = random.randrange(1, 1000000, 1)
		b = random.randrange(1, 1000000, 1)
		if( a > b ) :
			continue
		i = i + 1		
		newLine = str(a) + ' ' + str(b) + '\n'
		output_file.write(newLine)
	output_file.close()


if __name__ == "__main__":
	make_input()
