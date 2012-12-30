import sys
import random

def seq(num, isJolly, file)
	if(isJolly == 0 ):
		a = random.randrange(1, 3000, 1)
		while(i < num):
			:wq
		
			
			
		
	else :


def make_input():
	i = 0
	output_file = open("case.txt", 'w')
	while( i < 100):
		a = random.randrange(2, 3000, 1)
		b = random.randrange(1, 100, 1)
		if ( b > 50 ):
			seq(a, 0, output_file)
		else:
			seq(a, 1, output_file)

			
				
			
				



		if( a > b ) :
			continue
		i = i + 1		
		newLine = str(a) + ' ' + str(b) + '\n'
		output_file.write(newLine)
	output_file.close()


if __name__ == "__main__":
	make_input()
