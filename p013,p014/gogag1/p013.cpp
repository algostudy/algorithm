#include <iostream>

using namespace std;

int main()
{
	int n;
	double x1, y1, x2, y2, a, b;
	bool isEnd = false;

	while(1)
	{
		cin >> n;
		cin >> x1 >> y1 >> x2 >> y2;
		
		if(n==EOF)
			break;
		double x3 = 2*x1 - x2;
		double x4 = 2*x1 + x2;
		double y3 = 2*y1 - y2;
		double y4 = 2*y1 + y2;

		while(n--)
		{
			cin >> a >> b;

			if( (3*a+x4)*(a-x3) + (3*b-y4)*(b-y3)<0)
			{
				cout << "The gopher can escape through the hole at (" <<a <<"," << b << ")." << endl;
				isEnd = true;
				break;
			}
		}
		if(!isEnd)
			cout << "The gopher cannot escape." << endl;
	}
}
