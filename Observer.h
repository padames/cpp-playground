// observer.h
#include  <list>
#include <string>
#include <memory>

class Watched; // forward declaration

using namespace std;

class Observer {
	string _name;
	list<shared_ptr<Watched>> _watched_list;
	list<shared_ptr<Watched>>::iterator _iter;
public:
	Observer(const string&);
	const string& name();
	void watch(shared_ptr<Watched> w);
	bool isWatching(shared_ptr<Watched> w);
	void unwatch(shared_ptr<Watched> w);
	void printWatched();
};
