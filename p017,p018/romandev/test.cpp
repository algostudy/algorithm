#include <iostream>
#include <sstream>

using namespace std;

int main(void)
{
	string line;
	int    x[50];
	int    count;

	while ( getline(cin, line) != NULL )
	{
		istringstream line_stream(line);

		count = 0;
		while ( line_stream >> x[count] )
			count++;

		for ( int i = 0; i < count; i++ )
		{
			printf("%d ", x[i]);
		}
	}
}
