// Watched.h
#ifndef WATCHED_H
#define WATCHED_H 

#include <string>

class Watched {
	std::string _name;
public:
	Watched(const std::string& name);
	const std::string& name();
};

#endif //WATCHED_H
