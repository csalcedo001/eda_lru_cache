#ifndef LRU_CACHE_NODE_HPP_
#define LRU_CACHE_NODE_HPP_

namespace eda {

template <typename K, typename V>
class Node : public std::pair<K, V> {
	Node *prev;
	Node *next;
public:
	Node() : std::pair<K, V>() {
		this->prev_ = NULL;
		this->next_ = NULL;
	}
};

} // namespace eda

#endif // LRU_CACHE_NODE_HPP_
