//timer.cpp
#include <iostream>
#include <ctime>

using std::cout; using std::endl;

int main() {
  double x, sec;
  clock_t start = clock();
  while(x < 1000)
    x += 0.000001;
  sec = (double)(clock() - start)/(double)CLOCKS_PER_SEC;
  cout << "The while loop took " << sec << " seconds to compute x = "
       << x << endl;
  return 0;
}
