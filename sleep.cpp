#include <iostream>
#include <Windows.h> // Sleep( )
using namespace std;
int main() {
	int elapsedSeconds = 0, x, T = 3;
	cout << " RANDMAX  " << RAND_MAX << endl;
	while (elapsedSeconds < 18) {
		Sleep(T * 1000);  // milliseconds
		x = rand() % 100;  // 0~99 random  
		elapsedSeconds += T;
		cout << "  Elapsed time[sec] = "
			<< elapsedSeconds << "   " << x << endl;
	}
	return 123;
}
