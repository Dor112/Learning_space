#include <iostream>

#include <vector>
#include <string>

#include <iomanip>

using namespace std;
int main()
{

	setlocale(LC_ALL, "RU");


	cout << "Task 8: " << endl;
	cout << "a2 a1 a0 d3 d6 d7 q" << endl;
	for (int a2 = 0; a2 < 2; a2++)
	{
		for (int a1 = 0; a1 < 2; a1++)
		{
			for (int a0 = 0; a0 < 2; a0++)
			{
				for (int d3 = 0; d3 < 2; d3++)
				{
					for (int d6 = 0; d6 < 2; d6++)
					{
						for (int d7 = 0; d7 < 2; d7++)
						{
							if ((!a2 && a1 && a0 && d3) || (a2 && a1 && !a0 && d6) || (a2 && a1 && a0 && d7))
							{
								cout << a2 << "  " << a1 << "  " << a0 << "  " << d3 << "  " << d6 << "  " << d7 << "  1" << endl;
							}
							else
							{
								cout << a2 << "  " << a1 << "  " << a0 << "  " << d3 << "  " << d6 << "  " << d7 << "  0" << endl;
							}
						}
					}
				}
			}
		}
	}

	return 0;

}
//
//int main()
//{
//
//	setlocale(LC_ALL, "RU");
//
//
//	cout << "Task 7" << endl;
//	cout << "a0 a1 d2 d3 q" << endl;
//
//	for (int a0 = 0; a0 < 2; a0++)
//	{
//		for (int a1 = 0; a1 < 2; a1++)
//		{
//			for (int d2 = 0; d2 < 2; d2++)
//			{
//				for (int d3 = 0; d3 < 2; d3++)
//				{
//						if ((a0 && !a1 && d2) || (a0 && a1 && d3))
//						{
//							cout << a0 << "  " << a1 << "  " << d2 << "  " << d3 << "  1" << endl;
//						}
//						else
//						{
//							cout << a0 << "  " << a1 << "  " << d2 << "  " << d3 << "  0" << endl;
//						
//					}
//				}
//			}
//		}
//	}
//
//
//
//
//	return 0;
//
//}
//
