/*******************************************************************************
 * Copyright (C) 2022 Intel Corporation
 *
 * SPDX-License-Identifier: MIT
 ******************************************************************************/

#ifndef ANALYTIC_DEFS_HPP
#define ANALYTIC_DEFS_HPP

#include "common/defs.hpp"
#include <cstdint>
#include <climits>

namespace qpl::ml::analytics {

enum class stream_format_t {
    le_format,
    be_format,
    prle_format
};

// Output stream supports the following output bit width formats:
enum class output_bit_width_format_t : uint32_t {
    same_as_input = 0, // Input bit width is same as input stream bit width
    bits_8        = 1, // 8 bits
    bits_16       = 2, // 16 bits
    bits_32       = 3  // 32 bits
};

enum class analytic_pipeline {
    simple,
    prle,
    inflate,
    inflate_prle
};

struct analytic_operation_result_t {
    uint32_t     status_code_     = 0u;
    uint32_t     output_bytes_    = 0u;
    uint8_t      last_bit_offset_ = 0u;
    aggregates_t aggregates_;
    checksums_t  checksums_;
};

#if defined(__linux__)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wunused-parameter"
#endif

void inline aggregates_empty_callback(const uint8_t *src_ptr,
                                      uint32_t length,
                                      uint32_t *min_value_ptr,
                                      uint32_t *max_value_ptr,
                                      uint32_t *sum_ptr,
                                      uint32_t *index_ptr) {
    // Don't do anything, this is just a stub
}

#if defined(__linux__)
#pragma GCC diagnostic pop
#endif

} // namespace qpl::ml::analytics

#endif // ANALYTIC_DEFS_HPP
