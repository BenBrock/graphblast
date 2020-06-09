#pragma once

namespace graphblas {

namespace backend {

template <typename T>
class cuda_allocator {
public:
  using value_type = T;
  using size_type = std::size_t;
  using pointer = T*;
  using const_pointer = const T*;
  using reference = T&;
  using const_reference = const T&;
  using is_always_equal = std::true_type;

  template <class U> struct rebind {
    typedef cuda_allocator<U> other;
  };

  cuda_allocator() = default;
  cuda_allocator(const cuda_allocator&) = default;

  pointer allocate(size_type n) {
    T* ptr;
    cudaMalloc(&ptr, n*sizeof(value_type));
    return ptr;
  }

  void deallocate(pointer ptr, size_type n = 0) {
    cudaFree(ptr);
  }

  template<typename... Args>
  void construct(pointer ptr, Args&&... args) {
    new(ptr) T(std::forward<Args>(args)...);
  }

  void destroy(pointer ptr) {
    ptr->~T();
  }

  bool operator==(const cuda_allocator&) const {
    return true;
  }

  bool operator!=(const cuda_allocator& other) const {
    return !operator==(other);
  }
};

template <typename T>
using allocator = cuda_allocator<T>;

} // end backend

} // end graphblas
