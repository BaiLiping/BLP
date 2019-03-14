//Samantha Lee PA 2 

#ifndef WTDGRAPH_H
#define WTDGRAPH_H
#include <cassert>
#include <cstdlib> 
#include <map>
#include "graph.h"

namespace main_savitch_15 {

	template <class Item>
	class wtdgraph : public graph<Item>
	{
	public:
	// define all constructors:
    	wtdgraph();
    	wtdgraph(std::size_t initial_allocation);
    	wtdgraph(const wtdgraph &source);

// make destructor virtual:
    	virtual ~wtdgraph();

// overload add_edge with default weight parameter:
    	void add_edge(std::size_t source, std::size_t target,
                  std::size_t weight=0);

// redefine others as needed to handle weights:
   	 	void remove_edge(std::size_t source, std::size_t target);
    	wtdgraph<Item> &operator=(const wtdgraph &source);

// override resize function to allocate weights:
    	virtual void resize(std::size_t new_allocation);

// add edge_weight function to return a weight:
    	std::size_t edge_weight(std::size_t source, std::size_t target) const;

	private:
		std::size_t sizeWeights;
// need a way to store the weights - for example:
    	std::map<std::size_t, std::size_t> *weights;
    	bool **edges;
	};
    template class wtdgraph<std::string>;
    template class wtdgraph<int>;
    template class wtdgraph<double>;
}


#endif 
