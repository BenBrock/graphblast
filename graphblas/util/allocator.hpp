#pragma once

#define __GRB_BACKEND_ALLOCATION_HEADER <graphblas/backend/__GRB_BACKEND_ROOT/util/allocator.hpp>
#include __GRB_BACKEND_ALLOCATION_HEADER

namespace graphblas {

template <typename T>
using allocator = backend::allocator<T>;

// Rebind Allocator<U> as type T
template <typename Allocator, typename T>
using rebind_allocator_t = typename Allocator::rebind<T>::other;

} // end graphblas
