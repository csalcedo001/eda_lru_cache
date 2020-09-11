#include <iostream>

#include <lru_cache.hpp>

using namespace std;

int main() {
	eda::LRUCache<std::string, int> cache(3);

	cache.insertKeyValuePair("b", 2);
	cache.insertKeyValuePair("a", 1);

	cout << cache.getValueFromKey("b").value_or(-1) << endl;
	cout << cache.getValueFromKey("b").value_or(-1) << endl;
	cout << cache.getValueFromKey("b").value_or(-1) << endl;
	cout << cache.getValueFromKey("b").value_or(-1) << endl;
	cout << cache.getValueFromKey("a").value_or(-1) << endl;
	cout << cache.getValueFromKey("a").value_or(-1) << endl;
	cout << cache.getValueFromKey("b").value_or(-1) << endl;
	cout << cache.getValueFromKey("a").value_or(-1) << endl;
	cout << cache.getValueFromKey("b").value_or(-1) << endl;
	cout << cache.getValueFromKey("a").value_or(-1) << endl;

	cout << cache.getValueFromKey("c").value_or(-1) << endl;

	return 0;
}
