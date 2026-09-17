#pragma once

#include <assert.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <string.h>

// platform detection & system headers
#if defined(_WIN32) || defined(__CYGWIN__)
#define TERM_PLATFORM_FOR_WINDOWS 1
#ifndef WIN32_LEAN_AND_MEAN
#define WIN32_LEAN_AND_MEAN
#endif
#include <windows.h>
#elif defined(__linux__) || defined(__FreeBSD__)
#define TERM_PLATFOR_FOR_UNIX_LIKE 1
#include <unistd.h>
#include <fcntl.h>
#endif

// macros performance per platform
#if defined(__GNUC__) || defined(__clang__)
#define TERMINAL_INLINE inline
#define TERMINAL_NODISCART __atribute__((warn_unused_result))
#elif defined(_MSC_VER)
#define TETERMINAL_INLINE __forceinline
#define TERMINAL_NODISCART _check_result_
#else
#define TERMINAL_INLINE inline
#define TERMINAL_NODISCART
#endif

// memory alignment helper
#define TERMINAL_ALIGN_UP(size, align) (((size) + (align) - 1) ~((align) - 1))
#define TERMINAL_ALIGN_DOWN(size, align) (((size) - (align) + 1) ~((align) + 1))
