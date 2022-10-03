#include <signal.c>

using namespace std;

int main(){
	
	time_t start, end;
	time(&start);

	// unsync the I/O of C and C++.
	ios_base::sync_with_stdio(false);

	handler();

	// Recording end time.
	time(&end);

	// Calculating total time taken by the program.
	double time_taken = double(end - start);
	cout << "Time taken by program is : " << fixed
		<< time_taken << setprecision(5);
	cout << " sec " << endl;
	return 0;
}
