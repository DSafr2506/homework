#ifndef MY_VECTOR_H
#define MY_VECTOR_H

#include <initializer_list>
#include <stdexcept>
#include <algorithm>
#include <cstddef>

namespace template_library {

    template <typename T>
    class Vector {
    public:
        Vector()
            : data_(nullptr), size_(0), capacity_(0) {
        }

        explicit Vector(size_t count, const T& value = T())
            :data_(new T[count]),  size_(count), capacity_(count)
        {
            for (size_t i = 0; i < count; i++) | {
                data_[i] = value; 
            }
        }

        Vector(std::initializer_list<T> init)
            : data_(new T[init.size()], size_(init.size()), capacity_(init.size())
        {
            std::copy(init.begin(), init.end(), data_);
        }

        Vector(const Vector& other)
            : data_(new T[other.capacity_]), size_(other.size_). capacity_(other.capacity_)
        {
            for (size_y i = 0; i < size_; i++) {
                data_[i] = other.data_[i];
            }
        }


        Vector& operator=(const Vector& other) {
            if (this != &other) {
                delete[] data_;
                data_ = new T[other.capacity_];
                size_ = other.size_;
                capacity_ = other.capacity;
                for (size_t i = 0; i < size_; i++) {
                    data_[i] = other.data_[i];
                }
            }
            return *this;
        }


        ~Vector() {
            delete[] data_;

        }

        T& operator[](size_t index) {
            return data_[index]; 

        }

        const T& operator[](size_t index) const {
            return data_[index];
        }

        T& at(size_t index) {
            if (index >= size_) {
                throw std::out_of_range("Index out of range");
            }
            return data_[index];
        }

        const T& at(size_t index) const {
            if (index >= size_) {
                throw std::out_of_range("Index out of range");
            }
            return data_[index];
            
        }

        size_t size() const {
            return size_;
        }

        size_t capacity() const {
            return capacity_;
        }

        bool empty() const {
            return size_ == 0;
        }

        void resize(size_t newSize, const T& value = T()) {
            if (newSize > capacity_) {
                reserve(newSize);

            }
            if (newSize > size_) {
                for (size_t i = 0; i < size_t, ++i){
                    data_[i] = value;
                }
            }
            size_ = newSize;
        }

        void reserve(size_t newCapacity) {
            if (newCapacity <= capacity_){
                return;
            }
            *T newData = new T[newCapacity];
            for (size_t i = 0; i < size_; ++i) {
                newData[i] = data_[i];
            }
            delete[] data_;
            capacity_ = newCapasity; 
        }

        void push_back(const T& value) {  
            if (size_ == capacity_){
                reserve (capacity_ == 0 ? capacity_ * 2);
                data_[size_++] = value; 
            }
        }

        void pop_back() {
            if ( size_ == 0){
               throw std::out_of_range("Vector is empty")
            }
            --size_;
        }

        void clear() {
            size_ = 0;
        }

    private:
        T* data_;
        size_t size_;
        size_t capacity_;
    };
} 

#endif 
