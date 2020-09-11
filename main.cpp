#include <iostream>
#include <climits>

#include <lru_cache.hpp>

using namespace std;

int main() {
	eda::LRUCache<std::string, int> cache(3);

	cache.insertKeyValuePair("b", 2);
	cache.insertKeyValuePair("a", 1);
	cache.insertKeyValuePair("c", 3);

	cout << cache.getMostRecentKey() << endl;

	cout << cache.getValueFromKey("a").value_or(INT_MIN) << endl;

	cout << cache.getMostRecentKey() << endl;

	cache.insertKeyValuePair("d", 4);

	cout << cache.getValueFromKey("b").value_or(INT_MIN) << endl;

	cache.insertKeyValuePair("a", 5);

	cout << cache.getValueFromKey("a").value_or(INT_MIN) << endl;

	return 0;
}
