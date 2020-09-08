#ifndef LRU_CACHE_HPP_
#define LRU_CACHE_HPP_

#include <unordered_map>
#include <deque>
#include <utility>

namespace eda {

template <typename K, typename V>
class LRUCache {
private:
	std::unordered_map <K, typename std::deque<
		std::pair<K, V>
	>::iterator> table;
	std::deque< std::pair<K, V> > values;

	int size_;
	int items_;

public:
	LRUCache(int);

	void insertKeyValuePair(K, V);
	V getValueFromKey(K);
	V getMostRecentKey();
};

} // namespace eda

#include <impl/lru_cache.ipp>

#endif // LRU_CACHE_H_
