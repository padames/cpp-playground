// for while example
#include <iostream>
#include <cstdlib>

using namespace std;

int main(int argc, char* argv []) {
	int start = atoi(argv[1]);
	int end = atoi(argv[2]);
	cout << "Read " << start << " for a starting value and " << end << " for the final value" << endl;
	// do the sum with the for loop
	int sum = 0;
	for(int i = start; sum < end; i++) {
		sum += 1;
		cout << "[" << i << "]: " << sum << endl;
	}
	cout << "Sum using a for loop = " << sum << endl;
	//now do the same sum with a while loop
	sum = 0;
	int i = start;
	while ( sum < end ) {
		sum += abs(i++);
	}
	cout << "Sum using while loop = " << sum << endl;
	return 0;
}
