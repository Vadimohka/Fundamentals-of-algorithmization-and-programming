#include "String.hpp"
#include <algorithm>

#include <iostream>


void CharDeleter::operator()(char* p){
    delete[] p;
}

String::String(const char* src){
  const char* c = src;
  data_.reset(new char[size_update]);
  size_ = 0;
  reserved_ = size_update;
  while(*c != '\0'){
    append(*c);
    ++c;
  }
  data_.get()[size_] = 0;

}

    String::String(const String & v) : size_(v.size_)
    {
      data_.reset(new char[v.size_+1]);
      if(v.data_ != this->data_){
        char* src = data_.get();
        char* dst = v.data_.get();
        char* end = src + size_ + 1;
        while(src != end){
          *src = *end;
          ++src; ++end;
        }
      }

        reserved_ = size_ + 1;
    }


    String::String(size_t reserve) {
        this->data_.reset(new char[reserve+1]);
        this->reserved_ = reserve+1;
        this->size_ = 0;
    }

    String::String() {
        this->data_.reset(new char[size_update]);
        this->reserved_ = size_update;
        this->size_ = 0;
    }

    String::~String() {
        data_.release();
        size_ = 0;
        reserved_ = 0;
    }

    String::iterator String::begin(){
        iterator iter (data_.get());
        return iter;
    }

     String::iterator String::end(){
        iterator iter (data_.get() + size_);
        return iter;
    }



    int String::size() const {
        return size_;
    }

    int String::capacity() const {
        return reserved_;
    }


    char String::front() const {
        if(size_ == 0){
            throw std::runtime_error("The String is empty. There is no front element");
        } 
        return data_.get()[0];
    }

    char String::back() const {
        if(size_ == 0){
            throw std::runtime_error("The String is empty. There is no back element");
        } 
        return data_.get()[size_-1];
    }

    const char* String::c_str() const {
        return data_.get();

    }

    bool String::empty() const {
        return size_ == 0;
    }


    size_t String::max_size() const
    {
        return std::numeric_limits<uintptr_t>::max() / sizeof(char);
    }

 
    char& String::operator[](size_t x){
        return data_.get()[x];
    }

    char String::operator[](size_t x) const{
        return data_.get()[x];
    }


    char String::at(size_t x) const{
        if(x >= size_){
            throw std::invalid_argument("Index out of range");
        } 
        return data_.get()[x];
    }

    char& String::at(size_t x){
       if(x >= size_){
            throw std::invalid_argument("Index out of range");
        } 
        return data_.get()[x];
    }

    void String::reserve(size_t new_res)
    {
        if(reserved_ >= new_res){
            return;
        } else {
            char *new_data = new char[new_res+1];
            for(int i = 0; i <= size_; ++i){
                new_data[i] = data_.get()[i];
            }

            data_.reset(new_data);
            reserved_ = new_res+1;
        }
    }


    void String::resize(size_t sz, char def)
    {
        size_t oldSize = this->size_;
        if(sz >= size_){

            reserve(sz);
            char* ptr = data_.get();
            for(int i = oldSize; i < sz; ++i){
                ptr[i] = def;
            }
            ptr[sz] = '\0';

        } else {

            char* n_data = new char[sz+1];
            char* data = data_.get();
            for(int i = 0; i <= sz; ++i){
                n_data[i] = data[i];
            }
            data_.reset(n_data);

            reserved_ = sz;
            size_ = sz;
        }
    }

    
void String::append(const String& other) {
        int old_sz = size_;
        int new_sz = size_ + other.size_ + 1;

        char* data = data_.get();
        char* other_data = other.data_.get();
        reserve(new_sz+1);

        int other_i = 0;
        for(int i = old_sz; i < new_sz; ++i, ++other_i){
            data[i] = other_data[ other_i ];
        }

        
    }


    void String::append(char c){
        int old_size = size_;
        size_++;
        if(size_-1 >= reserved_){
            char* new_data = new char[reserved_*2];
            char* old_data = data_.get();
            for(int i = 0; i <= old_size; ++i){
                new_data[i] = old_data[i];
            }
            data_.reset(new_data);
        }
        data_.get()[size_-1] = c;


    }


    void String::pop_back(){
        if(size_ == 0){
            return;
        }
        size_ -= 1;
        if(size_ && reserved_ / size_ > 2.){
            reserve(size_);
        }
    }


    void String::erase(int x){
        char* c = data_.get();
        for(int i = x; i < size_-1; i++){
            c[i] = c[i+1];
        }
        size_--;
    }

    void String::clear() {
        data_.reset();
        this->size_ = 0;
        this->reserved_ = 0;
    }
