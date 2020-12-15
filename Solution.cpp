#include <iostream>
#include <ctime>
#include <cmath>
using namespace std;


static int syc = 10;
const double pi = 3.1415; // Constant Pi Number.
const int iteration = 60000; //Being repeated.
static double arr[6]; //Variable Stored In The Results.

double eval(double x1, double x2)
{
	double y = 50+pow(x1,2)+pow(x2,2)-(20*(cos(2*pi*x1)+cos(2*pi*x2))); //Mathematical Function To Be Calculated.
	return y;
}
double perturb() //The Function That Determines The Amount Of Our Movement In The + And - Direction.
{	
	srand((unsigned)time(NULL)); //Function Generating Different Number In Each Study.As The Search Gets Deeper,It Searches More Precisely.
	double rnd;
	return rnd = (double)1 / (rand() % syc + 1);
	syc+=1000;
}
double *hill_climb(int max_iteration) //Function To Find The Best Solution.
{
	srand((unsigned)time(NULL));
	double x1 = (double)(rand() % 10) - 5; //Initial x1.
	double x2 = (double)(rand() % 10) - 5; //Initial x2.
	double lowest = eval(x1, x2);  //With Initial Values We Find The Current Value Of The Function.
	arr[0] = {x1}; //We Assign The Initial x1 Value To The Array.
	arr[1] = {x2}; //We Assign The Initial x1 Value To The Array.
	arr[2] = {lowest}; //We Assign The Initial Lowest Value To The Array.
	int t = 1;
	while (t < max_iteration) //Function To Repeat.
	{
		
		if (((x1<=5 && x1>=-5) && (x2<=5&&x2>=-5)) && ((eval(x1 + perturb(), x2) < lowest)))
		{
			x1 = x1 + perturb();
		}
		else
		{
			x1 = x1 - perturb();
		}
		if (((x1<=5 && x1>=-5) && (x2<=5 && x2>=-5)) && ((eval(x1, x2 + perturb()) < lowest)))
		{
			x2 = x2 + perturb();
		}
		else
		{
			x2 = x2 - perturb();
		}
		lowest = eval(x1, x2);
		t += 1;
	}
	arr[3] = {x1}; //We Assign The Initial x1 Value To The Array.
	arr[4] = {x2}; //We Assign The Initial x2 Value To The Array.
	arr[5] = {eval(x1,x2)}; //We Assign The Initial Lowest Value To The Array.
	return arr;
}

void main()
{
	double *p;

	p = hill_climb(iteration);
	cout << "Hill Climbing Search : " << endl;
	cout << "Initial X1 Value : "  << *(p + 0) << endl;
	cout << "Initial X2 Value : "  << *(p + 1) << endl;
	cout << "Initial (y) Value : " << *(p + 2) << endl;
	cout << "Found X1 : " << *(p + 3) << endl;	
	cout << "Found X2 : " << *(p + 4) << endl;
	cout << "Found Result (y) : " << *(p + 5) << endl;
	
	system("Pause");
}