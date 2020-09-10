#ifndef LRU_CACHE_NODE_IPP_
#define LRU_CACHE_NODE_IPP_

namespace eda {

template <typename K, typename V>
Node<K, V>::Node() : std::pair<K, V>() {
	this->prev_ = NULL;
	this->next_ = NULL;
}

} // namespace eda

#endif // LRU_CACHE_NODE_IPP_
