#ifndef LRU_CACHE_LRU_CACHE_HPP_
#define LRU_CACHE_LRU_CACHE_HPP_

#include <unordered_map>
#include <deque>
#include <utility>

#include <node.hpp>

namespace eda {

template <typename K, typename V>
class LRUCache {
private:
	std::unordered_map <K, Node<K, V> *> table_;

	Node<K, V> *head_;
	Node<K, V> *tail_;

	int size_;
	int items_;

public:
	LRUCache(int);

	void insertKeyValuePair(K, V);
	V getValueFromKey(K);
	V getMostRecentKey();

	~LRUCache();
};

} // namespace eda

#include "impl/lru_cache.ipp"

#endif // LRU_CACHE_LRU_CACHE_HPP_
