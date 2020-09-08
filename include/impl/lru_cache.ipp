#ifndef LRU_CACHE_IPP_
#define LRU_CACHE_IPP_

namespace eda {

template <typename K, typename V>
LRUCache<K, V>::LRUCache(int size) : table(), values() {
	this->items_ = 0;
	this->size_ = size;
}

template <typename K, typename V>
void LRUCache<K, V>::insertKeyValuePair(K key, V value) {
	if (this->size_ == this->items_) {
		auto evicted = this->values.back();

		this->values.pop_back();
		this->table.erase(evicted.first);
	}
	else {
		this->items_++;
	}

	std::pair<K, V> p (key, value);
	this->values.push_front(p);
	this->table[key] = this->values.begin();
	//this->table.insert(make_pair<K, V>(key, this->values.end()));
}

template <typename K, typename V>
V LRUCache<K, V>::getValueFromKey(K key) {
	auto value = this->table.find(key);

	return value->second->second;
}

template <typename K, typename V>
V LRUCache<K, V>::getMostRecentKey() {
	return *this->values.begin();
}

} // namespace eda

#endif // LRU_CACHE_IPP_
