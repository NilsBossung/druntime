/**
 * This module is used to detect copy relocated ModuleInfos (located in .bss section).
 *
 * Copyright: Copyright Martin Nowak 2014-.
 * License:   <a href="http://www.boost.org/LICENSE_1_0.txt">Boost License 1.0</a>.
 * Authors:   Martin Nowak
 * Source: $(DRUNTIMESRC src/rt/_sections_linux.d)
 */

/* These symbols are defined in the linker script and bracket the
 * .bss, .lbss, .lrodata and .ldata sections.
 */
#if __linux__
// Need to use weak linkage to workaround a bug in ld.bfd (Bugzilla 13025).
extern int __attribute__((weak)) __bss_start, _end;

void* rt_get_bss_start() { return (void*)&__bss_start; }
void* rt_get_end() { return (void*)&_end; }
#endif
