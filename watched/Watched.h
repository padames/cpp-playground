// Watched.h
#ifndef WATCHED_H
#define WATCHED_H 

#include <string>

using namespace std;

class Watched {
	string _name;
public:
	Watched(const string& name);
	const string& name();
};

#endif //WATCHED_H
