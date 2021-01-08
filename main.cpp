#include "complex.h"
using namespace std;

int main()
{
	string stopper;
	bool stop = true;
	do {
		complex a;
		cout << "enter two double numbers separated by space: " << endl;
		cin >> a;
		cout << a << endl;
		cout << "test again? ";
		cin >> stopper;
		if (stopper == "n") {
			stop = false;
		}
	} while (stop);
}
