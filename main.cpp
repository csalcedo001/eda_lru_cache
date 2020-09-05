#include <iostream>
#include <unordered_map>
#include <deque>
#include <utility>

using namespace std;

template <typename K, typename V>
class LRUCache {
	unordered_map <K, typename deque<pair<K, V> >::iterator> table;
	deque< pair<K, V> > values;

	int capacity;
	int size;

public:
	LRUCache(int capacity) : table(), values() {
		this->size = 0;
		this->capacity = capacity;
	}

	void insertKeyValuePair(K key, V value) {
		if (this->capacity == this->size) {
			auto evicted = this->values.back();

			this->values.pop_back();
			this->table.erase(evicted.first);
		}
		else {
			this->size++;
		}

		pair<K, V> p (key, value);
		this->values.push_front(p);
		this->table[key] = this->values.begin();
		//this->table.insert(make_pair<K, V>(key, this->values.end()));
	}
	V getValueFromKey(K key) {
		auto value = this->table.find(key);

		V v = value.second;

		return *(value->second)->second;
	}
	V getMostRecentKey() {
		return *this->values.begin();
	}
};

int main() {
	// Hash table
	LRUCache<string, int> cache(3);

	cache.insertKeyValuePair("b", 2);
	cache.insertKeyValuePair("a", 1);

	return 0;
}
