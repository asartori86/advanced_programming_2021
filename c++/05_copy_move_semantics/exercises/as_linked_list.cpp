#include <memory>

enum class method {push_back, push_front};

template <typename T>
class List{
  struct node{
    T value;
    std::unique_ptr<node> next;
    node(const T& x, T* p):
      value{x}, // copy ctor
      next{p}
    {}
    
    node(T&& x, T* p):
      value{std::move(x)}, // move ctor
      next{p}
    {}

    explicit node(const std::unique_ptr<node>& p):value{p->value}{
      if (p->next)
	next = std::make_unique<node>(p->next);
    }
};
  std::unique_ptr<node> head;
public:
  void insert(const T& x, method m){ _insert(x, m); }
  void insert(T&& x, method m){ _insert(std::move(x), m); }

  List() = default;
  List(List&&) = default;
  List& operator=(List&&) = default;

  List(const List& that){
    if(that.head)
      head = std::make_unique<node>(that.head);
  }

  List& operator=(const List& x){
    head.reset();
    auto tmp = x;
    (*this) = std::move(tmp);
    return *this;
  }

  auto begin() { return iterator{head.get()}; }
  iterator end() {}

  // const_iterator begin() const {}
  // const_iterator end() const {}

  class iterator{
    node* current;
  public:
    explicit iterator(node * x): current{x} {}
    T& operator*() const { return node->value; }
    iterator& operator++() { // pre-increment
      current = current->next.get();
      return *this;
    }
    iterator operator++(int){ // post-increment
      auto tmp = *this;
      ++(*this);
      return tmp;
    }
    friend bool operator==(const iterator& x, const iterator& y){
      return x.current == y.current;
    }

    friend bool operator!=(const iterator& x, const iterator& y){
      return !(x == y);
    }
  };
  
private:

  template <typename X>
  void _insert(X&& x, method m){ // forwarding ref.
    if (!head){ // head == nullptr
      head = std::make_unique<node>(std::forward<X>(x),nullptr);
      return;
    }
    switch (m) {
    case method::push_back:
      push_back(std::forward<X>(x));
      break;
    case method::push_front:
      push_front(std::forward<X>(x));
      break;
    default:
      std::cerr << "unknown insertion method" << std::endl;
      break;
    };
  }
  
  T* last_node(){
    auto tmp = head.get();
    while(tmp->next) // tmp->next != nullptr
      tmp = tmp->next.get();
    return tmp;
  }
  
  void push_back(const T& x){
    auto tmp = last_node();
    tmp->next = std::make_unique<node>(x,nullptr);

  }
  void push_back(T&& x){
    last_node()->next = std::make_unique<node>(std::move(x),nullptr);
  }

  void push_front(const T& x){
    // auto tmp = new node{x,head.release()};
    // head.reset(tmp);

    // head.reset(new node{x,head.release()});

    head = std::make_unique<node>(x,head.release());

    // auto tmp = std::make_unique<node>(x,head.release());
    // head.swap(std::make_unique<node>(x,head.release()));
  }
  void push_front(T&& x){
    // head = std::make_unique<node>(x,head.release()); // l-val
    head = std::make_unique<node>(std::move(x),head.release()); // r-val
  }

  
};


int main(){
  List<int> l;
  
  l.insert(3,method::push_front);

}
