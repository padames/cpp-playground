//watchinDriver.cpp
#include <iostream>
#include <memory>
#include "Watched.h"
#include "Observer.h"

using namespace std;

int main() {
	shared_ptr<Watched> w1(new Watched("The Creole Food Channel"));
	shared_ptr<Watched> w2(new Watched("The Alton Brown Network"));
	unique_ptr<Observer> o1(new Observer("Captain O"));
	o1->watch(w1);
	o1->watch(w2);

	string o1_is_or_not = o1->isWatching(w2)? " is ": " is not ";
	cout << o1->name() << o1_is_or_not << "watching " << w2->name() << endl;

	cout << "Before " << o1->name() << " stops watching " << w2->name() << " he is watching:" << endl;
	
	o1->printWatched();

	o1->unwatch(w2);

	o1_is_or_not = o1->isWatching(w2)? " is ": " is not ";
	cout << o1->name() << o1_is_or_not << "watching " << w2->name() << endl;

	cout << o1->name() << " is watching: " << endl;
	o1->printWatched();

}
