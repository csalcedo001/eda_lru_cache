#ifndef LRU_CACHE_LRU_CACHE_IPP_
#define LRU_CACHE_LRU_CACHE_IPP_

namespace eda {

template <typename K, typename V>
LRUCache<K, V>::LRUCache(int size) : table_() {
	// Initialize empty cache
	this->head_ = this->tail_ = NULL;

	this->size_ = size;
	this->items_ = 0;
}

template <typename K, typename V>
void LRUCache<K, V>::insertKeyValuePair(K key, V value) {
	if (this->size_ == this->items_) {
		Node<K, V> *evicted = this->tail_;

		this->tail_ = evicted->prev_;
		evicted->prev_->next_ = NULL;

		this->table_.erase(evicted->key_);

		delete evicted;
	}

	Node<K, V> *new_node = new Node<K, V>(key, value);

	this->table_[key] = new_node;

	if (this->head_ == NULL) {
		this->head_ = this->tail_ = new_node;
	}
	else {
		// new_node->prev_ initialized as NULL
		new_node->next_ = this->head_;
		this->head_->prev_ = new_node;

		this->head_ = new_node;
	}

	if (this->size_ != this->items_) this->items_++;
}

template <typename K, typename V>
V LRUCache<K, V>::getValueFromKey(K key) {
	Node<K, V> *node = this->table_[key];

	if (node == this->head_) {
		return node->value_;
	}

	if (node == this->tail_) {
		node->prev_->next_ = NULL;
		this->tail_ = node->prev_;
	}
	else {
		node->prev_->next_ = node->next_;
		node->next_->prev_ = node->prev_;
	}

	node->prev_ = NULL;
	node->next_ = this->head_;

	node->next_->prev_ = node;

	this->head_ = node;

	return node->value_;
}

// template <typename K, typename V>
// V LRUCache<K, V>::getMostRecentKey() {
// 	return *this->values_.begin();
// }

template <typename K, typename V>
LRUCache<K, V>::~LRUCache() {
	if (this->head_ == NULL) {
		return;
	}

	Node<K, V> *current = this->head_;

	while (current->next_ != NULL) {
		current = current->next_;

		delete current->prev_;
	}

	delete current;
}

} // namespace eda

#endif // LRU_CACHE_LRU_CACHE_IPP_
