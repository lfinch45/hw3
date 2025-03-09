#ifndef HEAP_H
#define HEAP_H
#include <functional>
#include <stdexcept>
#include <vector>

template <typename T, typename PComparator = std::less<T> >
class Heap
{
public:
  /**
   * @brief Construct a new Heap object
   * 
   * @param m ary-ness of heap tree (default to 2)
   * @param c binary predicate function/functor that takes two items
   *          as an argument and returns a bool if the first argument has
   *          priority over the second.
   */
  Heap(int m=2, PComparator c = PComparator());

  /**
  * @brief Destroy the Heap object
  * 
  */
  ~Heap();

  /**
   * @brief Push an item to the heap
   * 
   * @param item item to heap
   */
  void push(const T& item);

  /**
   * @brief Returns the top (priority) item
   * 
   * @return T const& top priority item
   * @throw std::underflow_error if the heap is empty
   */
  T const & top() const;

  /**
   * @brief Remove the top priority item
   * 
   * @throw std::underflow_error if the heap is empty
   */
  void pop();

  /// returns true if the heap is empty

  /**
   * @brief Returns true if the heap is empty
   * 
   */
  bool empty() const;

    /**
   * @brief Returns size of the heap
   * 
   */
  size_t size() const;

private:
  // Lets add helper functions for trickling up and down
  void trickleUp(size_t indx);
  void trickleDown(size_t indx);

  // And the necessary data members
  std::vector<T> data;
  PComparator comp;
  int m;

};

// Constructor
template <typename T, typename PComparator>
Heap<T,PComparator>::Heap(int m, PComparator c)
: comp(c), m(m) {

}

// Destructor
template <typename T, typename PComparator>
Heap<T,PComparator>::~Heap(){
  
  
}


template <typename T, typename PComparator>
void Heap<T,PComparator>::push(const T& item){
  data.push_back(item);
  trickleUp(data.size() - 1);

}

// We will start top() for you to handle the case of 
// calling top on an empty heap
template <typename T, typename PComparator>
T const & Heap<T,PComparator>::top() const{
  if(empty()){
    throw std::underflow_error("Empty heap");
  }
  return data.front(); 
}


// We will start pop() for you to handle the case of 
// calling top on an empty heap
template <typename T, typename PComparator>
void Heap<T,PComparator>::pop()
{
  if(empty()){
    throw std::underflow_error("Empty heap");
  }
  std::swap(data.front(), data.back());
  data.pop_back();

  // Handle the case where heap is not empty
  if(!empty()){
    trickleDown(0);
  }
}

template <typename T, typename PComparator>
bool Heap<T,PComparator>::empty() const{
  return data.empty();

}

template <typename T, typename PComparator>
size_t Heap<T,PComparator>::size() const{
  return data.size();

}

template <typename T, typename PComparator>
void Heap<T,PComparator>::trickleUp(size_t indx){
  if(indx == 0){
    return;
  }
  size_t parentNode = (indx - 1)/m;
  // Use recursion to trickle up into the heap is in the right order
  if(comp(data[indx], data[parentNode])){
    std::swap(data[indx], data[parentNode]);
    trickleUp(parentNode);
  }
}

template <typename T, typename PComparator>
void Heap<T,PComparator>::trickleDown(size_t indx){
  size_t highest = indx;
  for(int i = 1; i<=m; i++){
    size_t childNode = m * indx + i;
    if(childNode < data.size() && comp(data[childNode], data[highest])){
      highest = childNode;
    }
  }
  if(highest != indx){
    std::swap(data[indx], data[highest]);
    trickleDown(highest);
  }
}

#endif

