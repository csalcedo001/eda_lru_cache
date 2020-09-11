#ifndef LRU_CACHE_NODE_HPP_
#define LRU_CACHE_NODE_HPP_

namespace eda {

template <typename K, typename V>
class Node {
public:
	K key_;
	V value_;

	Node *prev_;
	Node *next_;

	Node();
	Node(K, V);
};

} // namespace eda

#include "impl/node.ipp"

#endif // LRU_CACHE_NODE_HPP_
