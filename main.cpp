#include <iostream>

#include <lru_cache.hpp>

using namespace std;

int main() {
	eda::LRUCache<std::string, int> cache(3);

	cache.insertKeyValuePair("b", 2);
	cache.insertKeyValuePair("a", 1);

	cout << cache.getValueFromKey("b") << endl;
	cout << cache.getValueFromKey("b") << endl;
	cout << cache.getValueFromKey("b") << endl;
	cout << cache.getValueFromKey("b") << endl;
	cout << cache.getValueFromKey("a") << endl;
	cout << cache.getValueFromKey("a") << endl;
	cout << cache.getValueFromKey("b") << endl;
	cout << cache.getValueFromKey("a") << endl;
	cout << cache.getValueFromKey("b") << endl;
	cout << cache.getValueFromKey("a") << endl;

	return 0;
}
