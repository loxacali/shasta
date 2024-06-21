// +-------------------------------------------------------------------------------------------------------------------+
// | File          : kernel/src/arch/inst.c                                                                            |
// | Name          : x86 Instruction Intrinsics & Macros (Source)                                                      |
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

#include "arch/inst.h"

/// @fn      inline void _cpuid(uint32_t *eax, uint32_t *ebx, uint32_t *ecx, uint32_t *edx)
/// @brief   C function exposing the x86 CPUID (CPU identification) instruction.
///
/// @details This function exposes the x86/x86-64 CPUID instruction used to identify late-80486 and post-80486 x86
/// processors. Depending on the arguments passed via the register references, CPUID will return information regarding
/// the CPU family, model, stepping, feature set, and hardware capabilities. For a comprehensive discussion of CPUID 
/// features and semantics, it is recommended to consult the Intel SDM as well as the Intel AN-485 application note.
/// 
/// @param   eax a pointer to the value provided in the EAX register
/// @param   ebx a pointer to the value provided in the EBX register
/// @param   ecx a pointer to the value provided in the ECX register
/// @param   edx a pointer to the value provided in the EDX register
/// @returns None (void) - the four-GPR state post-CPUID is returned in the input argument references
void _cpuid(uint32_t *eax, uint32_t *ebx, uint32_t *ecx, uint32_t *edx)
{
    uint32_t a = *eax, b = *ebx, c = *ecx, d = *edx;
    asm volatile (
        "cpuid"
        : "+a" (a), "+b" (b), "+c" (c), "+d" (d)
    );
    *eax = a; *ebx = b; *ecx = c; *edx = d;
}

uint8_t _inb(uint16_t port)
{

}

uint16_t _inw(uint16_t port)
{

}

uint32_t _inl(uint16_t port)
{

}

/// @fn      inline void _int(uint8_t vec)
/// @brief   C function exposing the x86 INT (assert interrupt) instruction.
///
/// @details This function exposes the x86/x86-64 INT function used for assertion of interrupts. Because INT only 
/// possesses an imm8 form and there are no encodings which support a register or memory operand, all possible vector
/// paths must be manually encoded via a jump table.
///
/// @param   vec: the interrupt vector (number) to assert
/// @returns None (void)
void _int(uint8_t vec)
{
    switch (vec) {
        case 0x00: asm volatile ("int $0x00"); break;
        case 0x01: asm volatile ("int $0x01"); break;
        case 0x02: asm volatile ("int $0x02"); break;
        case 0x03: asm volatile ("int $0x03"); break;
        case 0x04: asm volatile ("int $0x04"); break;
        case 0x05: asm volatile ("int $0x05"); break;
        case 0x06: asm volatile ("int $0x06"); break;
        case 0x07: asm volatile ("int $0x07"); break;
        case 0x08: asm volatile ("int $0x08"); break;
        case 0x09: asm volatile ("int $0x09"); break;
        case 0x0A: asm volatile ("int $0x0A"); break;
        case 0x0B: asm volatile ("int $0x0B"); break;
        case 0x0C: asm volatile ("int $0x0C"); break;
        case 0x0D: asm volatile ("int $0x0D"); break;
        case 0x0E: asm volatile ("int $0x0E"); break;
        case 0x0F: asm volatile ("int $0x0F"); break;
        case 0x10: asm volatile ("int $0x10"); break;
        case 0x11: asm volatile ("int $0x11"); break;
        case 0x12: asm volatile ("int $0x12"); break;
        case 0x13: asm volatile ("int $0x13"); break;
        case 0x14: asm volatile ("int $0x14"); break;
        case 0x15: asm volatile ("int $0x15"); break;
        case 0x16: asm volatile ("int $0x16"); break;
        case 0x17: asm volatile ("int $0x17"); break;
        case 0x18: asm volatile ("int $0x18"); break;
        case 0x19: asm volatile ("int $0x19"); break;
        case 0x1A: asm volatile ("int $0x1A"); break;
        case 0x1B: asm volatile ("int $0x1B"); break;
        case 0x1C: asm volatile ("int $0x1C"); break;
        case 0x1D: asm volatile ("int $0x1D"); break;
        case 0x1E: asm volatile ("int $0x1E"); break;
        case 0x1F: asm volatile ("int $0x1F"); break;
        case 0x20: asm volatile ("int $0x20"); break;
        case 0x21: asm volatile ("int $0x21"); break;
        case 0x22: asm volatile ("int $0x22"); break;
        case 0x23: asm volatile ("int $0x23"); break;
        case 0x24: asm volatile ("int $0x24"); break;
        case 0x25: asm volatile ("int $0x25"); break;
        case 0x26: asm volatile ("int $0x26"); break;
        case 0x27: asm volatile ("int $0x27"); break;
        case 0x28: asm volatile ("int $0x28"); break;
        case 0x29: asm volatile ("int $0x29"); break;
        case 0x2A: asm volatile ("int $0x2A"); break;
        case 0x2B: asm volatile ("int $0x2B"); break;
        case 0x2C: asm volatile ("int $0x2C"); break;
        case 0x2D: asm volatile ("int $0x2D"); break;
        case 0x2E: asm volatile ("int $0x2E"); break;
        case 0x2F: asm volatile ("int $0x2F"); break;
        case 0x30: asm volatile ("int $0x30"); break;
        case 0x31: asm volatile ("int $0x31"); break;
        case 0x32: asm volatile ("int $0x32"); break;
        case 0x33: asm volatile ("int $0x33"); break;
        case 0x34: asm volatile ("int $0x34"); break;
        case 0x35: asm volatile ("int $0x35"); break;
        case 0x36: asm volatile ("int $0x36"); break;
        case 0x37: asm volatile ("int $0x37"); break;
        case 0x38: asm volatile ("int $0x38"); break;
        case 0x39: asm volatile ("int $0x39"); break;
        case 0x3A: asm volatile ("int $0x3A"); break;
        case 0x3B: asm volatile ("int $0x3B"); break;
        case 0x3C: asm volatile ("int $0x3C"); break;
        case 0x3D: asm volatile ("int $0x3D"); break;
        case 0x3E: asm volatile ("int $0x3E"); break;
        case 0x3F: asm volatile ("int $0x3F"); break;
        case 0x40: asm volatile ("int $0x40"); break;
        case 0x41: asm volatile ("int $0x41"); break;
        case 0x42: asm volatile ("int $0x42"); break;
        case 0x43: asm volatile ("int $0x43"); break;
        case 0x44: asm volatile ("int $0x44"); break;
        case 0x45: asm volatile ("int $0x45"); break;
        case 0x46: asm volatile ("int $0x46"); break;
        case 0x47: asm volatile ("int $0x47"); break;
        case 0x48: asm volatile ("int $0x48"); break;
        case 0x49: asm volatile ("int $0x49"); break;
        case 0x4A: asm volatile ("int $0x4A"); break;
        case 0x4B: asm volatile ("int $0x4B"); break;
        case 0x4C: asm volatile ("int $0x4C"); break;
        case 0x4D: asm volatile ("int $0x4D"); break;
        case 0x4E: asm volatile ("int $0x4E"); break;
        case 0x4F: asm volatile ("int $0x4F"); break;
        case 0x50: asm volatile ("int $0x50"); break;
        case 0x51: asm volatile ("int $0x51"); break;
        case 0x52: asm volatile ("int $0x52"); break;
        case 0x53: asm volatile ("int $0x53"); break;
        case 0x54: asm volatile ("int $0x54"); break;
        case 0x55: asm volatile ("int $0x55"); break;
        case 0x56: asm volatile ("int $0x56"); break;
        case 0x57: asm volatile ("int $0x57"); break;
        case 0x58: asm volatile ("int $0x58"); break;
        case 0x59: asm volatile ("int $0x59"); break;
        case 0x5A: asm volatile ("int $0x5A"); break;
        case 0x5B: asm volatile ("int $0x5B"); break;
        case 0x5C: asm volatile ("int $0x5C"); break;
        case 0x5D: asm volatile ("int $0x5D"); break;
        case 0x5E: asm volatile ("int $0x5E"); break;
        case 0x5F: asm volatile ("int $0x5F"); break;
        case 0x60: asm volatile ("int $0x60"); break;
        case 0x61: asm volatile ("int $0x61"); break;
        case 0x62: asm volatile ("int $0x62"); break;
        case 0x63: asm volatile ("int $0x63"); break;
        case 0x64: asm volatile ("int $0x64"); break;
        case 0x65: asm volatile ("int $0x65"); break;
        case 0x66: asm volatile ("int $0x66"); break;
        case 0x67: asm volatile ("int $0x67"); break;
        case 0x68: asm volatile ("int $0x68"); break;
        case 0x69: asm volatile ("int $0x69"); break;
        case 0x6A: asm volatile ("int $0x6A"); break;
        case 0x6B: asm volatile ("int $0x6B"); break;
        case 0x6C: asm volatile ("int $0x6C"); break;
        case 0x6D: asm volatile ("int $0x6D"); break;
        case 0x6E: asm volatile ("int $0x6E"); break;
        case 0x6F: asm volatile ("int $0x6F"); break;
        case 0x70: asm volatile ("int $0x70"); break;
        case 0x71: asm volatile ("int $0x71"); break;
        case 0x72: asm volatile ("int $0x72"); break;
        case 0x73: asm volatile ("int $0x73"); break;
        case 0x74: asm volatile ("int $0x74"); break;
        case 0x75: asm volatile ("int $0x75"); break;
        case 0x76: asm volatile ("int $0x76"); break;
        case 0x77: asm volatile ("int $0x77"); break;
        case 0x78: asm volatile ("int $0x78"); break;
        case 0x79: asm volatile ("int $0x79"); break;
        case 0x7A: asm volatile ("int $0x7A"); break;
        case 0x7B: asm volatile ("int $0x7B"); break;
        case 0x7C: asm volatile ("int $0x7C"); break;
        case 0x7D: asm volatile ("int $0x7D"); break;
        case 0x7E: asm volatile ("int $0x7E"); break;
        case 0x7F: asm volatile ("int $0x7F"); break;
        case 0x80: asm volatile ("int $0x80"); break;
        case 0x81: asm volatile ("int $0x81"); break;
        case 0x82: asm volatile ("int $0x82"); break;
        case 0x83: asm volatile ("int $0x83"); break;
        case 0x84: asm volatile ("int $0x84"); break;
        case 0x85: asm volatile ("int $0x85"); break;
        case 0x86: asm volatile ("int $0x86"); break;
        case 0x87: asm volatile ("int $0x87"); break;
        case 0x88: asm volatile ("int $0x88"); break;
        case 0x89: asm volatile ("int $0x89"); break;
        case 0x8A: asm volatile ("int $0x8A"); break;
        case 0x8B: asm volatile ("int $0x8B"); break;
        case 0x8C: asm volatile ("int $0x8C"); break;
        case 0x8D: asm volatile ("int $0x8D"); break;
        case 0x8E: asm volatile ("int $0x8E"); break;
        case 0x8F: asm volatile ("int $0x8F"); break;
        case 0x90: asm volatile ("int $0x90"); break;
        case 0x91: asm volatile ("int $0x91"); break;
        case 0x92: asm volatile ("int $0x92"); break;
        case 0x93: asm volatile ("int $0x93"); break;
        case 0x94: asm volatile ("int $0x94"); break;
        case 0x95: asm volatile ("int $0x95"); break;
        case 0x96: asm volatile ("int $0x96"); break;
        case 0x97: asm volatile ("int $0x97"); break;
        case 0x98: asm volatile ("int $0x98"); break;
        case 0x99: asm volatile ("int $0x99"); break;
        case 0x9A: asm volatile ("int $0x9A"); break;
        case 0x9B: asm volatile ("int $0x9B"); break;
        case 0x9C: asm volatile ("int $0x9C"); break;
        case 0x9D: asm volatile ("int $0x9D"); break;
        case 0x9E: asm volatile ("int $0x9E"); break;
        case 0x9F: asm volatile ("int $0x9F"); break;
        case 0xA0: asm volatile ("int $0xA0"); break;
        case 0xA1: asm volatile ("int $0xA1"); break;
        case 0xA2: asm volatile ("int $0xA2"); break;
        case 0xA3: asm volatile ("int $0xA3"); break;
        case 0xA4: asm volatile ("int $0xA4"); break;
        case 0xA5: asm volatile ("int $0xA5"); break;
        case 0xA6: asm volatile ("int $0xA6"); break;
        case 0xA7: asm volatile ("int $0xA7"); break;
        case 0xA8: asm volatile ("int $0xA8"); break;
        case 0xA9: asm volatile ("int $0xA9"); break;
        case 0xAA: asm volatile ("int $0xAA"); break;
        case 0xAB: asm volatile ("int $0xAB"); break;
        case 0xAC: asm volatile ("int $0xAC"); break;
        case 0xAD: asm volatile ("int $0xAD"); break;
        case 0xAE: asm volatile ("int $0xAE"); break;
        case 0xAF: asm volatile ("int $0xAF"); break;
        case 0xB0: asm volatile ("int $0xB0"); break;
        case 0xB1: asm volatile ("int $0xB1"); break;
        case 0xB2: asm volatile ("int $0xB2"); break;
        case 0xB3: asm volatile ("int $0xB3"); break;
        case 0xB4: asm volatile ("int $0xB4"); break;
        case 0xB5: asm volatile ("int $0xB5"); break;
        case 0xB6: asm volatile ("int $0xB6"); break;
        case 0xB7: asm volatile ("int $0xB7"); break;
        case 0xB8: asm volatile ("int $0xB8"); break;
        case 0xB9: asm volatile ("int $0xB9"); break;
        case 0xBA: asm volatile ("int $0xBA"); break;
        case 0xBB: asm volatile ("int $0xBB"); break;
        case 0xBC: asm volatile ("int $0xBC"); break;
        case 0xBD: asm volatile ("int $0xBD"); break;
        case 0xBE: asm volatile ("int $0xBE"); break;
        case 0xBF: asm volatile ("int $0xBF"); break;
        case 0xC0: asm volatile ("int $0xC0"); break;
        case 0xC1: asm volatile ("int $0xC1"); break;
        case 0xC2: asm volatile ("int $0xC2"); break;
        case 0xC3: asm volatile ("int $0xC3"); break;
        case 0xC4: asm volatile ("int $0xC4"); break;
        case 0xC5: asm volatile ("int $0xC5"); break;
        case 0xC6: asm volatile ("int $0xC6"); break;
        case 0xC7: asm volatile ("int $0xC7"); break;
        case 0xC8: asm volatile ("int $0xC8"); break;
        case 0xC9: asm volatile ("int $0xC9"); break;
        case 0xCA: asm volatile ("int $0xCA"); break;
        case 0xCB: asm volatile ("int $0xCB"); break;
        case 0xCC: asm volatile ("int $0xCC"); break;
        case 0xCD: asm volatile ("int $0xCD"); break;
        case 0xCE: asm volatile ("int $0xCE"); break;
        case 0xCF: asm volatile ("int $0xCF"); break;
        case 0xD0: asm volatile ("int $0xD0"); break;
        case 0xD1: asm volatile ("int $0xD1"); break;
        case 0xD2: asm volatile ("int $0xD2"); break;
        case 0xD3: asm volatile ("int $0xD3"); break;
        case 0xD4: asm volatile ("int $0xD4"); break;
        case 0xD5: asm volatile ("int $0xD5"); break;
        case 0xD6: asm volatile ("int $0xD6"); break;
        case 0xD7: asm volatile ("int $0xD7"); break;
        case 0xD8: asm volatile ("int $0xD8"); break;
        case 0xD9: asm volatile ("int $0xD9"); break;
        case 0xDA: asm volatile ("int $0xDA"); break;
        case 0xDB: asm volatile ("int $0xDB"); break;
        case 0xDC: asm volatile ("int $0xDC"); break;
        case 0xDD: asm volatile ("int $0xDD"); break;
        case 0xDE: asm volatile ("int $0xDE"); break;
        case 0xDF: asm volatile ("int $0xDF"); break;
        case 0xE0: asm volatile ("int $0xE0"); break;
        case 0xE1: asm volatile ("int $0xE1"); break;
        case 0xE2: asm volatile ("int $0xE2"); break;
        case 0xE3: asm volatile ("int $0xE3"); break;
        case 0xE4: asm volatile ("int $0xE4"); break;
        case 0xE5: asm volatile ("int $0xE5"); break;
        case 0xE6: asm volatile ("int $0xE6"); break;
        case 0xE7: asm volatile ("int $0xE7"); break;
        case 0xE8: asm volatile ("int $0xE8"); break;
        case 0xE9: asm volatile ("int $0xE9"); break;
        case 0xEA: asm volatile ("int $0xEA"); break;
        case 0xEB: asm volatile ("int $0xEB"); break;
        case 0xEC: asm volatile ("int $0xEC"); break;
        case 0xED: asm volatile ("int $0xED"); break;
        case 0xEE: asm volatile ("int $0xEE"); break;
        case 0xEF: asm volatile ("int $0xEF"); break;
        case 0xF0: asm volatile ("int $0xF0"); break;
        case 0xF1: asm volatile ("int $0xF1"); break;
        case 0xF2: asm volatile ("int $0xF2"); break;
        case 0xF3: asm volatile ("int $0xF3"); break;
        case 0xF4: asm volatile ("int $0xF4"); break;
        case 0xF5: asm volatile ("int $0xF5"); break;
        case 0xF6: asm volatile ("int $0xF6"); break;
        case 0xF7: asm volatile ("int $0xF7"); break;
        case 0xF8: asm volatile ("int $0xF8"); break;
        case 0xF9: asm volatile ("int $0xF9"); break;
        case 0xFA: asm volatile ("int $0xFA"); break;
        case 0xFB: asm volatile ("int $0xFB"); break;
        case 0xFC: asm volatile ("int $0xFC"); break;
        case 0xFD: asm volatile ("int $0xFD"); break;
        case 0xFE: asm volatile ("int $0xFE"); break;
        case 0xFF: asm volatile ("int $0xFF"); break;
        default: break;
    }
}

inline void _lgdt(void *loc)
{

}

inline void _lidt(void *loc)
{

}

inline void _outb(uint16_t port, uint8_t  value)
{

}

inline void _outw(uint16_t port, uint16_t value)
{

}

inline void _outl(uint16_t port, uint32_t value)
{

}

inline uint64_t _rdmsr(uint32_t msr)
{

}

inline uint64_t _rdtsc(void)
{

}

inline void _sgdt(void *tab)
{

}

inline void _sidt(void *tab)
{

}

inline void _wrmsr(uint32_t msr, uint64_t value)
{

}