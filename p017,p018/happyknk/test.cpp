#include <iostream>
#include <sstream>

using namespace std;

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
		while ( line_stream >> cake[count] )
			count++;

		for ( int i = 0; i < count; i++ )
		{
			for(int j=i+1; j<count; j++){
				if(cake[i]<cake[j]){
					arr[i] = cake[j];
					
				}
			}
			printf("%d ", arr[i]);
		}
	}
}
