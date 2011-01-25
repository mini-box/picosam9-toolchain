/* CS3 header file.
 *
 * Copyright 2007 CodeSourcery
 * Version:CodeSourcery Sourcery G++ Lite 2007q3-53
 * BugURL:https://support.codesourcery.com/GNUToolchain/
 */

#ifndef CSL_CS3_H
#define CSL_CS3_H

#include <stddef.h>

#if __cplusplus
extern "C" {
#endif

typedef unsigned char __cs3_byte_align8 __attribute ((aligned (8)));

struct __cs3_region
{
  unsigned flags;       /* Flags for this region.  None defined yet.  */
  __cs3_byte_align8 *init;  /* Initial contents of this region.  */
  __cs3_byte_align8 *data;  /* Start address of region.  */
  size_t init_size;     /* Size of initial data.  */
  size_t zero_size;     /* Additional size to be zeroed.  */
};

/* number of elements in __cs3_regions */
extern const char __cs3_region_num __attribute__((weak));
#define __cs3_region_num ((size_t)&__cs3_region_num)

extern const struct __cs3_region __cs3_regions[];

extern void __cs3_start_c (void) __attribute ((noreturn));

/* regions, some may not be present on particular boards or profiles */

/* We use weak on objects that might be at address zero.
   The compiler is at liberty to presume that no non-weak
   object resides at address zero (because that's
   indistinguishable from the NULL pointer on the systems
   we care about).  */

#if __cplusplus
}
#endif
#endif /* CSL_CS3_H */
