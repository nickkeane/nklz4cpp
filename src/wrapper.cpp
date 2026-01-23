// Name  : wrapper.cpp
// Author: Nicholas Keane
// Desc  : C++ wrapper for LZ4 compression library
//
// Copyright 2026 Nicholas Keane. All rights reserved.
#ifndef NKLZ4CPP_WRAPPER_CPP
#define NKLZ4CPP_WRAPPER_CPP

// TODO: Include lz4 header and implement compression/decompression methods
#include <lz4.h>

#include <vector>
#include <string>
#include <stdexcept>

#include "nklz4cpp/wrapper.hpp"

namespace NKLZ4 {
    Wrapper::Wrapper() {
    }

    Wrapper::~Wrapper() {
    }

    template <typename DecompT, typename CompT>
    Wrapper::compress(std::string const& in) {
        // Implement compression logic using LZ4 library
        return std::vector<char>();
    }

    template <typename DecompT, typename CompT>
    Wrapper<DecompT, CompT>::compress(std::unique_ptr<CompT> const& in) {

    }

    template <typename DecompT, typename CompT>
    Wrapper::decompress(const std::vector<char>& in) {
        // Implement decompression logic using LZ4 library
        return std::string();
    }

    template <typename DecompT, typename CompT>
    Wrapper::decompress(const std::vector<char> const& in, std::string& out) {
        // Implement decompression logic using LZ4 library
    }
}

#endif // NKLZ4CPP_CPP