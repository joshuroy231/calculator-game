#pragma once

#include <utility>

template<typename T>
class UniquePtr {
    private:
        T* ptr;
    public:
        explicit UniquePtr(T* ptr)
        : ptr(ptr) {}
        UniquePtr(const UniquePtr&) = delete;
        UniquePtr& operator=(const UniquePtr&) = delete;
        ~UniquePtr() {
            delete ptr;
        }
        T& operator*() {
            return *ptr;
        }
        T* operator->() {
            return ptr;
        }
};

template<typename T, typename ...Args>
UniquePtr<T> makeUnique(Args&& ...args) {
    return UniquePtr(new T(std::forward<Args>(args)...));
}