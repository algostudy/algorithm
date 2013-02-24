import java.util.Scanner;

class inTest
{
	public static void main(String[] a_args)
	{
		/*
		 *	// C code
		 *
		 *	int num_of_student;
		 *	int x, y;
		 *
		 *	while ( scanf("%d ", &num_of_student) == 1 && num_of_student != 0 )
		 *	{
		 *		for ( int i = 0; i < num_of_student; i++ )
		 *		{
		 *			scanf("%d %d", &x, &y);
		 *
		 *			// process x, y
		 *			printf("process (%d,%d)\n", x, y);
		 *		}
		 *		printf("\n");
		 *	}
		 *
		 */

		Scanner stdin = new Scanner(System.in);

		int num_of_student;
		int x, y;

		while ( stdin.hasNext() && (num_of_student = stdin.nextInt()) != 0 )
		{
			for ( int i = 0; i < num_of_student; i++ )
			{
				x = stdin.nextInt();
				y = stdin.nextInt();

				// process x, y
				System.out.println("process (" + x + "," + y + ")");
			}

			// print blank line
			System.out.println();
		}
	}
}
