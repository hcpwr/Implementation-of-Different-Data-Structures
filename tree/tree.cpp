#include <iostream>

template <typename T> class tree_node {
	T data;
	tree_node<T> *left, *right;

public:
	tree_node(
		T data,
		tree_node<T> *left = nullptr,
		tree_node<T> *right = nullptr)
		: data(data), left(left), right(right) {
	}

	tree_node(tree_node<T> const &o)
		: data(o.data),
		  left(o.left ? new tree_node<T>(*o.left) : nullptr),
		  right(o.right ? new tree_node<T>(*o.right) : nullptr) {
	}

	~tree_node() {
		if (left)
			delete left;
		if (right)
			delete right;
	}

	tree_node<T> &operator=(tree_node<T> const &o) {
		if (left)
			delete left;
		if (right)
			delete right;
		data = o.data;
		left = o.left ? new tree_node<T>(*o.left) : nullptr;
		right = o.right ? new tree_node<T>(*o.right) : nullptr;
		return *this;
	}

	void insert(T new_data) {
		if (new_data == data)
			return;
		else if (new_data < data) {
			if (left)
				left->insert(new_data);
			else
				left = new tree_node<T>(new_data);
		} else {
			if (right)
				right->insert(new_data);
			else
				right = new tree_node<T>(new_data);
		}
	}

	size_t num_nodes() const {
		return 1 + (left ? left->num_nodes() : 0) +
			(right ? right->num_nodes() : 0);
	}

	T nth_smallest(size_t &n) const {
		size_t left_nodes = left ? left->num_nodes() : 0;
		if (n == left_nodes + 1) {
			return data;
		} else if (n <= left_nodes) {
			return left->nth_smallest(n);
		} else {
			n -= left_nodes + 1;
			return right->nth_smallest(n);
		}
	}
};

template <typename T> class tree {
	tree_node<T> *root;

public:
	tree() : root(nullptr) {
	}

	tree(tree<T> const &o)
		: root(o.root ? new tree_node<T>(*o.root) : nullptr) {
	}

	~tree() {
		if (root)
			delete root;
	}

	tree<T> operator=(tree<T> const &o) {
		if (root && o.root)
			*root = *o.root;
		else if (root)
			delete root;
		else if (o.root)
			root = new tree_node<T>(*o.root);
		return *this;
	}

	void insert(T data) {
		if (root)
			root->insert(data);
		else
			root = new tree_node<T>(data);
	}

	T nth_smallest(size_t n) const {
		if (!root || n < 1 || n > root->num_nodes()) {
			throw std::out_of_range("Invalid value of n");
		}
		return root->nth_smallest(n);
	}
};