// +-------------------------------------------------------------------------------------------------------------------+
// | File          : kernel/include/arch/inst.h                                                                        |
// | Name          : x86 Instruction Intrinsics & Macros (Header)                                                      |
// | Project       : Shasta Microkernel                                                                                |
// | Author        : Elijah Creed Fedele                                                                               |
// | Contributors  : see CONTRIBUTORS.md                                                                               |
// | Version       : 0.0.0                                                                                             |
// | License       : GNU General Public License (GPL), version 3.0                                                     |
// | Date Created  : June 20, 2024                                                                                     |
// | Date Modified : June 20, 2024                                                                                     |
// | Description   : Provides inline C functions which expose specialized x86 and x86-64 instructions.                 |
// +-------------------------------------------------------------------------------------------------------------------+
// | Copyright (C) 2024 Elijah Creed Fedele                                                                            |
// |                                                                                                                   |
// | This program is free software: you can redistribute it and/or modify it under the terms of the GNU General Public | 
// | License as published by the Free Software Foundation, either version 3 of the License, or (at your option) any    |
// | later version.                                                                                                    |
// |                                                                                                                   |
// | This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the        | 
// | implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for   | 
// | more details.                                                                                                     |
// |                                                                                                                   |
// | You should have received a copy of the GNU General Public License along with this program.  If not, see           |
// |     <http://www.gnu.org/licenses/>.                                                                               |
// +-------------------------------------------------------------------------------------------------------------------+

#ifndef INST_H
#define INST_H

#include "freestd.h"

inline void     _cpuid(uint32_t *eax, uint32_t *ebx, uint32_t *ecx, uint32_t *edx);
inline uint8_t  _inb  (uint16_t port);
inline uint16_t _inw  (uint16_t port);
inline uint32_t _inl  (uint16_t port);
inline void     _int  (uint8_t  vec);
inline void     _lgdt (void *loc);
inline void     _lidt (void *loc);
inline void     _outb (uint16_t port, uint8_t  value);
inline void     _outw (uint16_t port, uint16_t value);
inline void     _outl (uint16_t port, uint32_t value);
inline uint64_t _rdmsr(uint32_t msr);
inline uint64_t _rdtsc(void);
inline void     _sgdt (void *tab);
inline void     _sidt (void *tab);
inline void     _wrmsr(uint32_t msr, uint64_t value);

#endif /* INST_H */