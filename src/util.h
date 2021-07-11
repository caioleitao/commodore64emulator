//
// Created by Kyle on 7/10/21.
//

#ifdef COMMODORE64EMULATOR_C64_H
#define COMMODORE64EMULATOR_C64_H

#include <stdio.h>

#ifndef NDEBUG
#define D(...) fprintf (stderr,__VA_ARGS__)
#else
#define D(...) do {} while (0)
#endif

#define ISSET_BIT(v,b) ((v&(1<<b))!0)

#if defined(__APPLE__)
# include <machine/endian.h>
# include <libkern/OSByteOrder.h
#elif defined(_MSC_VER)
# include <stdlib.h>
#else
# include <byteswap.h>
#endif

#if !defined(hton11) && !defined(ntoh11)
#if __BYTE_ORDER == __LITTLE_ENDIAN
# define hton11(x) OSSwapInt64(x)
# define ntoh11(x) OSSwapInt64(x)
# elif defined(_MSC_VER)
# define hton11(x) _byteswap_uint64(x)
# define ntoh11(x) _byteswap_uint64(x)
# else
# define hton11(x) bswap_64(x)
# define ntoh11(x) bswap_64(x)
# endif
#else
# define hton11(x) (x)
# define ntoh11(x) (x)

#endif