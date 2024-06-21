// +-------------------------------------------------------------------------------------------------------------------+
// | File          : kernel/src/arch/struct.h                                                                          |
// | Name          : x86 Descriptor Table Structure Declarations                                                       |
// | Project       : Shasta Microkernel                                                                                |
// | Author        : Elijah Creed Fedele                                                                               |
// | Contributors  : see CONTRIBUTORS.md                                                                               |
// | Version       : 0.0.0                                                                                             |
// | License       : GNU General Public License (GPL), version 3.0                                                     |
// | Date Created  : June 21, 2024                                                                                     |
// | Date Modified : June 21, 2024                                                                                     |
// | Description   : Provides C structure definitions of integral x86 and x86-64 descriptor table structures.          |
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

#ifndef _ARCH_STRUCT_H
#define _ARCH_STRUCT_H

#include "sys/freestd.h"

struct gdt_gate {
    uint16_t limit_low;
    uint16_t base_low;
    uint8_t  base_mid_low;
    uint8_t  access;
    uint8_t  flags;
    uint8_t  base_mid_high;
    uint32_t base_high;
    uint32_t padding;
} __attribute__((packed));

struct idt_gate {
    uint16_t offset_low;
    uint16_t segment;
    uint16_t attributes;
    uint16_t offset_mid;
    uint32_t offset_high;
    uint32_t padding;
} __attribute__((packed));

struct tss_entry {
    uint32_t reserved_0;
    uint64_t stack_ptr_0;
    uint64_t stack_ptr_1;
    uint64_t stack_ptr_2;
    uint64_t reserved_1;
    uint64_t interrupt_stack_1;
    uint64_t interrupt_stack_2;
    uint64_t interrupt_stack_3;
    uint64_t interrupt_stack_4;
    uint64_t interrupt_stack_5;
    uint64_t interrupt_stack_6;
    uint64_t interrupt_stack_7;
    uint64_t reserved_2;
    uint16_t reserved_3;
    uint16_t iopb_tss_offset;
} __attribute__((packed));

#endif /* _ARCH_STRUCT_H */