#include <iostream>
#include <sstream>

using namespace std;

void reverse( int *s, int len ){

	for(int i=0; i<(len/2+len%2); i++){
		char temp = s[i];
		s[i] = s[len-i];
		s[len-i] = temp;
	}
	printf("\n");
	for(int j=0; j<15; j++){
		printf("%d, ", s[j]);
	}
	printf("\n");
}

int main(void)
{
	string line;
	int cake[30];
	int arr[30];
	int count;

	while ( getline(cin, line) != NULL )
	{
		istringstream line_stream(line);

		count = 0;
		while ( line_stream >> cake[count] ){
			arr[count] = cake[count];
			count++;
		}

		for ( int i = 0; i < count; i++ )
		{
			printf("%d ", cake[i]);
			for(int j=i+1; j<count; j++){
				if(arr[i]>arr[j]){
					int temp = arr[i];
					arr[i] = arr[j];
					arr[j] = temp;
				}
			}
		}

		printf("\n");

		printf("\n");
		for ( int i = count-1; i>=0; i-- ){
			if(cake[i]!=arr[i]){
				for ( int j = i-1; j>=0; j-- ){
					if(cake[j]==arr[i]){
						if(j!=0){
							printf("%d ", count - j);
							reverse(cake, j+1);
						}
						printf("%d ", count - i);
						reverse(cake, i);

					}

				}
			}
		}
		printf("0\n");
	}
}
