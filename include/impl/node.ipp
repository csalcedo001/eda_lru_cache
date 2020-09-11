#ifndef LRU_CACHE_NODE_IPP_
#define LRU_CACHE_NODE_IPP_

namespace eda {

template <typename K, typename V>
Node<K, V>::Node() {
	this->prev_ = NULL;
	this->next_ = NULL;
}

template <typename K, typename V>
Node<K, V>::Node(K key, V value) : Node() {
	this->key_ = key;
	this->value_ = value;
}

} // namespace eda

#endif // LRU_CACHE_NODE_IPP_
