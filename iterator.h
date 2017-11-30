#ifndef ITERATOR_H
#define ITERATOR_H

class Iterator {
public:
  virtual void first() = 0;
  virtual void next() = 0;
  virtual Term* currentItem() const = 0;
  virtual bool isDone() const = 0;
};

  
/**
 * Implement the interface through your design, 
 * and do not modify the function signature of each.
*/

class DFSIterator :public Iterator {

}

class BFSIterator :public Iterator {

}