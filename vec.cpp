#include <iostream>
#include <vector>
#include <ctime>
using namespace std;
int main() {
	int NI = 10, NO = 20, ni, no;
	vector <int> q;
	srand(time(0));
	// enqueue
	ni = rand() % NI;
	for (int i = 0; i < ni; i++) {
		q.push_back(rand() % 20);
		cout << *(q.end() - 1) << " in " << q.size() << endl;
	}
	// dequeue
	if (q.size() == 0) cout << " empty queue\n";
	else {
		no = rand() % NO;
		for (int i = 0; i < no; i++) {
			cout << *q.begin();
			q.erase(q.begin());
			cout << " out " << q.size() << endl;
			if (q.size() == 0) break;
		}
	}
	return 123;
}
