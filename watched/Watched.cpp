#include "Watched.h"
#include <string>

using namespace std;

Watched::Watched(const string& name ) {
	_name = name;
}

const string& Watched::name() {
	return _name;
}
