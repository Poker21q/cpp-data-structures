#ifndef CPP_DATA_STRUCTURES_RB_TREE_H_
#define CPP_DATA_STRUCTURES_RB_TREE_H_

#include <cstddef>

template <typename K, typename V>
class RBTree {
 public:
  enum class Color {
    kRed = 0,
    kBlack,
  };

  struct Node {
    Node* left;
    Node* right;
    Node* parent;
    Color color;
    K key;
    V value;
  };

  class Iterator {
   public:
    Iterator(const Node& node);
    ~Iterator() = default;

    Node& operator*();
    Iterator operator++();
    Iterator operator++(int);
    Iterator operator--();
    Iterator operator--(int);

   private:
    Node* node_;
  };

  RBTree();

  // **** Rule of Five ****

  RBTree(const RBTree&);
  RBTree(RBTree&&);
  RBTree& operator=(const RBTree&);
  RBTree& operator=(RBTree&&);
  ~RBTree();

  // **** Methods ****

  Iterator Insert(const K& key, const V& value);
  Iterator Insert(const K& key, V&& value);
  Iterator Find(const K& key);
  void Delete(const K& key);

 private:
  Node* root_{nullptr};
  size_t len_{0UL};
};

template <typename K, typename V>
RBTree<K, V>::RBTree() : root_(nullptr), len_(0UL) {}

template <typename K, typename V>
RBTree<K, V>::Iterator RBTree<K, V>::Insert(const K& key, const V& value) {}

template <typename K, typename V>
RBTree<K, V>::~RBTree() {}

#endif