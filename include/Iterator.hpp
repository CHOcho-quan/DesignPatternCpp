#pragma once

#include <vector>
#include <iostream>

template <typename T>
class Iterator {
 public:
    virtual void Begin() = 0;
    virtual void Next() = 0;
    virtual bool End() = 0;
    virtual T* Current() = 0;
};

template <typename T>
class Aggregator {
 public:
    virtual Iterator<T>* GetIterator() = 0;
    virtual void Push(const T& data) = 0;
    virtual void Pop() = 0;
    virtual T* Top() = 0;
    virtual T* Get(size_t i) = 0;
    virtual int Size() = 0;
};

template <typename T>
class ConcreteIterator : public Iterator<T> {
 public:
   explicit ConcreteIterator(Aggregator<T>* agg) : vector_(agg), count_(0) {}

   void Begin() {
      count_ = 0;
   }

   void Next() {
      count_++;
   }

   bool End() {
      return (count_ == vector_->Size());
   }

   T* Current() {
      return vector_->Get(count_);
   }

//  private:
   int count_;
   Aggregator<T>* vector_;
};

template <typename T>
class ConcreteAggregator : public Aggregator<T> {
 public:
   ConcreteIterator<T>* GetIterator() {
      return new ConcreteIterator<T>(this);
   }

   void Push(const T& data) {
      vec_.push_back(data);
   }

   void Pop() {
      vec_.pop_back();
   }

   T* Top() {
      if (vec_.size() != 0) {
         return &vec_[0];
      } else {
         return nullptr;
      }
   }

   T* Get(size_t i) {
      if (vec_.size() > i) {
         return &vec_[i];
      } else {
         return nullptr;
      }
   }

   int Size() {
      return static_cast<int>(vec_.size());
   }

 private:
   std::vector<T> vec_;
};
