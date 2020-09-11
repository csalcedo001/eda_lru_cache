#include <iostream>

#include <lru_cache.hpp>

using namespace std;

int main() {
	eda::LRUCache<std::string, int> cache(3);

	cout << "Keys 'b', 'a' and 'c' inserted in that order" << endl;

	// Insert multiple elements to the cache
	cache.insertKeyValuePair("b", 2);
	cache.insertKeyValuePair("a", 1);
	cache.insertKeyValuePair("c", 3);

	// Print the most recently accessed key
	cout << "Most recently accessed key: " << cache.getMostRecentKey() << endl;

	// Get a value of a key
	cout << "Get value from 'a': " << cache.getValueFromKey("a").value_or(NULL) << endl;

	// Accessing a value updates the most recently accessed key
	cout << "New most recently accessed key: " << cache.getMostRecentKey() << endl;

	// When cache is full, one key is evicted
	cache.insertKeyValuePair("d", 4);

	// Since 'b' was the least recently used key, it is no longer in the cache
	cout << "Trying to access evicted key 'b': " << cache.getValueFromKey("b").value_or(NULL) << endl;

	cout << "Update value of 'a' to 5" << endl;

	// Modify value of an existing key
	cache.insertKeyValuePair("a", 5);
	cout << "Get value from 'a': " << cache.getValueFromKey("a").value_or(NULL) << endl;

	return 0;
}
