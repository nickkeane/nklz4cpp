// Name  : wrapper.hpp
// Author: Nicholas Keane
// Desc  : C++ wrapper for LZ4 compression library
//
// Copyright 2026 Nicholas Keane. All rights reserved.
#ifndef NKLZ4CPP_WRAPPER_HPP
#define NKLZ4CPP_WRAPPER_HPP

class std::string;
class std::vector<T>;

namespace NKLZ4 {

    /**
     * @brief Singleton Wrapper for LZ4 C++. Use NKLZ4::Wrapper<>::get() to access byte-processor instance.
     * @tparam DecompT Type for decompressed data (default: unsigned char)
     * @tparam CompT Type for compressed data (default: unsigned char)
     */
    template <typename DecompT = unsigned char, typename CompT = unsigned char>
    class Wrapper {
        public:
            Wrapper();
            ~Wrapper();
        public:
            std::vector<CompT> compress(const std::vector<DecompT>& in);
            std::vector<DecompT> decompress(const std::vector<CompT>& in);
            bool decompress(const std::vector<CompT> const& in, std::vector<DecompT>& out);

        public:
            using value_type_decompressed = DecompT;
            using value_type_compressed = CompT;

            static Wrapper<DecompT, CompT>& get() {
                static Wrapper<DecompT, CompT> instance;
                return instance;
            }
        };

        class ICompressor {

        };

        class IDecompressor {

        };

        class StreamCompressor : ICompressor {

        };

        class StreamDecompressor : IDecompressor {

        };

        class FileCompressor : ICompressor {

        };

        class FileDecompressor : IDecompressor {

        };

        class ObjectCompressor : ICompressor {

        };

        class ObjectDecompressor : IDecompressor {

        };
}

#endif