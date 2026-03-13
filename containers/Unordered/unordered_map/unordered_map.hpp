#pragma once

#include <cstddef>
#include <functional>
#include <initializer_list>
#include <list>
#include <stdexcept>
#include <utility>
#include <vector>

namespace My {

template <typename Key, typename T, typename Hash = std::hash<Key>,
			typename KeyEqual = std::equal_to<Key>>
class unordered_map {
public:
	using key_type = Key;
	using mapped_type = T;
	using value_type = std::pair<const Key, T>;
	using size_type = std::size_t;

	unordered_map()
		: buckets_(kDefaultBucketCount), size_(0), max_load_factor_(1.0f), 
			hasher_(Hash()), key_equal_(KeyEqual()) {}

	explicit unordered_map(size_type bucket_count)
		: buckets_(bucket_count == 0 ? kDefaultBucketCount : bucket_count),
		  size_(0),
		  max_load_factor_(1.0f),
		  hasher_(Hash()),
		  key_equal_(KeyEqual()) {}

	unordered_map(std::initializer_list<value_type> init)
		: unordered_map() {
		for (const auto& item : init) {
			insert(item);
		}
	}

	bool empty() const {
		return size_ == 0;
	}

	size_type size() const {
		return size_;
	}

	size_type bucket_count() const {
		return buckets_.size();
	}

	float load_factor() const {
		if (buckets_.empty()) {
			return 0.0f;
		}
		return static_cast<float>(size_) / static_cast<float>(buckets_.size());
	}

	float max_load_factor() const {
		return max_load_factor_;
	}

	void max_load_factor(float value) {
		if (value <= 0.0f) {
			return;
		}
		max_load_factor_ = value;
		maybe_rehash();
	}

	bool insert(const value_type& value) {
		maybe_rehash();
		auto idx = bucket_index(value.first);
		auto it = find_in_bucket(idx, value.first);
		if (it != buckets_[idx].end()) {
			return false;
		}

		buckets_[idx].push_back(value);
		++size_;
		return true;
	}

	bool insert(value_type&& value) {
		maybe_rehash();
		auto idx = bucket_index(value.first);
		auto it = find_in_bucket(idx, value.first);
		if (it != buckets_[idx].end()) {
			return false;
		}

		buckets_[idx].push_back(std::move(value));
		++size_;
		return true;
	}

	template <typename... Args>
	bool emplace(Args&&... args) {
		value_type value(std::forward<Args>(args)...);
		return insert(std::move(value));
	}

	bool erase(const Key& key) {
		auto idx = bucket_index(key);
		auto it = find_in_bucket(idx, key);
		if (it == buckets_[idx].end()) {
			return false;
		}

		buckets_[idx].erase(it);
		--size_;
		return true;
	}

	bool contains(const Key& key) const {
		auto idx = bucket_index(key);
		return find_in_bucket(idx, key) != buckets_[idx].end();
	}

	mapped_type* find(const Key& key) {
		auto idx = bucket_index(key);
		auto it = find_in_bucket(idx, key);
		if (it == buckets_[idx].end()) {
			return nullptr;
		}
		return &it->second;
	}

	const mapped_type* find(const Key& key) const {
		auto idx = bucket_index(key);
		auto it = find_in_bucket(idx, key);
		if (it == buckets_[idx].end()) {
			return nullptr;
		}
		return &it->second;
	}

	mapped_type& at(const Key& key) {
		auto ptr = find(key);
		if (ptr == nullptr) {
			throw std::out_of_range("unordered_map::at: key not found");
		}
		return *ptr;
	}

	const mapped_type& at(const Key& key) const {
		auto ptr = find(key);
		if (ptr == nullptr) {
			throw std::out_of_range("unordered_map::at: key not found");
		}
		return *ptr;
	}

	mapped_type& operator[](const Key& key) {
		maybe_rehash();
		auto idx = bucket_index(key);
		auto it = find_in_bucket(idx, key);
		if (it == buckets_[idx].end()) {
			buckets_[idx].push_back(value_type(key, mapped_type()));
			++size_;
			it = find_in_bucket(idx, key);
		}
		return it->second;
	}

	void clear() {
		for (auto& bucket : buckets_) {
			bucket.clear();
		}
		size_ = 0;
	}

	void rehash(size_type new_bucket_count) {
		if (new_bucket_count == 0) {
			new_bucket_count = 1;
		}

		std::vector<std::list<value_type>> new_buckets(new_bucket_count);

		for (auto& bucket : buckets_) {
			for (auto& entry : bucket) {
				auto idx = hasher_(entry.first) % new_bucket_count;
				new_buckets[idx].push_back(std::move(entry));
			}
		}

		buckets_.swap(new_buckets);
	}

private:
	static constexpr size_type kDefaultBucketCount = 8;

	using bucket_type = std::list<value_type>;
	using bucket_iterator = typename bucket_type::iterator;
	using const_bucket_iterator = typename bucket_type::const_iterator;

	size_type bucket_index(const Key& key) const {
		return hasher_(key) % buckets_.size();
	}

	bucket_iterator find_in_bucket(size_type idx, const Key& key) {
		auto& bucket = buckets_[idx];
		for (auto it = bucket.begin(); it != bucket.end(); ++it) {
			if (key_equal_(it->first, key)) {
				return it;
			}
		}
		return bucket.end();
	}

	const_bucket_iterator find_in_bucket(size_type idx, const Key& key) const {
		const auto& bucket = buckets_[idx];
		for (auto it = bucket.begin(); it != bucket.end(); ++it) {
			if (key_equal_(it->first, key)) {
				return it;
			}
		}
		return bucket.end();
	}

	void maybe_rehash() {
		if (load_factor() > max_load_factor_) {
			rehash(buckets_.size() * 2);
		}
	}

	std::vector<bucket_type> buckets_;
	size_type size_;
	float max_load_factor_;
	Hash hasher_;
	KeyEqual key_equal_;
};

}