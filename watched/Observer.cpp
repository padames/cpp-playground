//Observer.cpp
#include <iostream>
#include <string>
#include <memory>

#include "Observer.h"
#include "Watched.h"


using namespace std;

Observer::Observer(const string& name){
	_name = name;
}

const string& Observer::name() {
	return _name;
}

void Observer::watch(shared_ptr<Watched> const w) {
	_watched_list.push_back(w);
	cout << _name << " is now watching " << w->name() << endl;
}

bool Observer::isWatching(shared_ptr<Watched> w) {
	bool result = false;	
	for(_iter = _watched_list.begin(); _iter != _watched_list.end(); _iter++) {
		if ((*_iter).get() == w.get()) {
			result = true;
			break;
		}
	}
	return result;
}

void Observer::unwatch(shared_ptr<Watched> w) {
	_watched_list.remove_if([&w](shared_ptr<Watched> i){ return w.get() == i.get(); });
	return;
}

void Observer::printWatched() {
	for (shared_ptr<Watched> i: _watched_list) {
		cout << i->name() << endl;
	}
}
