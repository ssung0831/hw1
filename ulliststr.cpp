/*
This cpp file contains the functions needed for an unrolled linked list
*/

#include <cstddef>
#include <stdexcept>
#include "ulliststr.h"

ULListStr::ULListStr()
{
  head_ = NULL;
  tail_ = NULL;
  size_ = 0;
}

ULListStr::~ULListStr()
{
  clear();
}

bool ULListStr::empty() const
{
  return size_ == 0;
}

size_t ULListStr::size() const
{
  return size_;
}

// WRITE YOUR CODE HERE

/**
   * Adds a new value to the back of the list
   *   - MUST RUN in O(1)
*/
void ULListStr::push_back(const std::string& val){
		
	//if list is empty, create a new node with one array value
		if(empty()){
			Item* i1 = new Item();
			head_ = i1;
			tail_ = i1;
			i1 -> val[0] = val;
			tail_ -> last = tail_ -> last + 1;
			size_ = 1;
		}
		else if ((tail_ -> last) == ARRSIZE){ //array full, create a new node
			Item* i2 = new Item();
			tail_ -> next = i2;
			i2 -> prev = tail_;
			tail_ = i2;

			i2 -> val[0] = val;
			tail_ -> last = tail_ -> last + 1;
			
			size_++;
		}
		else{ //tail is not full
			tail_ -> val[tail_ -> last] = val;
			tail_ -> last = tail_ -> last + 1;
			size_++;
		}
}

  /**
   * Removes a value from the back of the list
   *   - MUST RUN in O(1)
*/
  void ULListStr::pop_back(){

		//if list is empty, no action
		if(size_ <= 0){
			return;
		}
		else if (size_ == 1){ //remove the only value, so set head and tail to null
			delete tail_;
			head_ = NULL;
			tail_ = head_;
		}
		else if(tail_ -> last == 1){ //if there is a node with one value, take it out
			tail_ = tail_ -> prev;
			delete tail_ -> next;
			tail_ -> next = NULL;
			size_--;
		}
		else{
			tail_ -> last = tail_ -> last -1;
			size_--;
		}
	}
  
  /**
   * Adds a new value to the front of the list.
   * If there is room before the 'first' value in
   * the head node add it there, otherwise, 
   * allocate a new head node.
   *   - MUST RUN in O(1)
   */
  void ULListStr::push_front(const std::string& val){
		
		//if the list is empty, create a new node with one array value
		if(empty()){
			Item* i1 = new Item();
			head_ = i1;
			tail_ = i1;
			i1 -> val[0] = val;
			tail_ -> last = tail_ -> last + 1;
			size_ = 1;
		}
		else if ((head_ -> first) == 0){ //array full, create a new node at the front with value at index 9
			Item* i2 = new Item();
			head_ -> prev = i2;
			i2 -> next = head_;
			head_ = i2;

			i2 -> val[ARRSIZE - 1] = val;
			i2 -> first = ARRSIZE - 1;
			i2 -> last = ARRSIZE;
			
			size_++;
		}
		else{ //head is not full
			head_ -> val[head_ -> first - 1] = val;
			head_ -> first = head_ -> first - 1;
			size_++;
		}
	}

  /**
   * Removes a value from the front of the list
   *   - MUST RUN in O(1)
   */
  void ULListStr::pop_front(){

		//if empty, do nothing
		if(size_ <= 0){
			return;
		}
		else if (size_ == 1){ //remove the only value, so set head and tail to NULL
			Item* temp = head_;
			delete temp;
			head_ = NULL;
			tail_ = head_;
		}
		else if(head_ -> first == ARRSIZE - 1){ //if there is a node with one value, take it out
			head_ = head_ -> next;
			delete head_ -> prev;
			size_--;
		}
		else{
			head_ -> first = head_ -> first + 1;
			size_--;
		}
	}

  /**
   * Returns a const reference to the back element
   *   - MUST RUN in O(1)
   */
  std::string const & ULListStr::back() const{
		return tail_ -> val[tail_ -> last - 1];
	}

  /**
   * Returns a const reference to the front element
   *   - MUST RUN in O(1)
   */
  std::string const & ULListStr::front() const{
		return head_ -> val[head_ -> first];
	}

void ULListStr::set(size_t loc, const std::string& val)
{
  std::string* ptr = getValAtLoc(loc);
  if(ptr == NULL){
    throw std::invalid_argument("Bad location");
  }
  *ptr = val;
}

std::string& ULListStr::get(size_t loc)
{
  std::string* ptr = getValAtLoc(loc);
  if(ptr == NULL){
    throw std::invalid_argument("Bad location");
  }
  return *ptr;
}

std::string const & ULListStr::get(size_t loc) const
{
  std::string* ptr = getValAtLoc(loc);
  if(ptr == NULL){
    throw std::invalid_argument("Bad location");
  }
  return *ptr;
}

void ULListStr::clear()
{
  while(head_ != NULL){
    Item *temp = head_->next;
    delete head_;
    head_ = temp;
  }
  tail_ = NULL;
  size_ = 0;
}

  /** 
   * Returns a pointer to the item at index, loc,
   *  if loc is valid and NULL otherwise
   *   - MUST RUN in O(n) 
   */
  std::string* ULListStr::getValAtLoc(size_t loc) const{
		
		//if loc is invalid/out of bounds, return NULL
		if(loc < 0 || loc >= size_){
			return NULL;
		}
		else{

			//while going through each loc, iterate through each node;
			size_t tracer = head_ -> first; //this tracer determines where we are in the array
			Item* node_counter = head_; //this counter determines what node we are on

			
			for(size_t l = 0; l < loc; l++){
				tracer++;
				if(node_counter -> last == tracer){
					tracer = 0;
					node_counter = node_counter -> next;
				}
			}
			return &node_counter -> val[tracer];
		}
	}
