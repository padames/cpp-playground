// observer.h
#include  <list>
#include <string>
#include <memory>

class Watched; // forward declaration

class Observer {
	std::string _name;
	std::list< std::shared_ptr< Watched> > _watched_list;
	std::list< std::shared_ptr< Watched> >::iterator _iter;
public:
	Observer(const std::string&);
	const std::string& name();
	void watch(std::shared_ptr<Watched> w);
	bool isWatching(std::shared_ptr<Watched> w);
	void unwatch(std::shared_ptr<Watched> w);
	void printWatched();
};
