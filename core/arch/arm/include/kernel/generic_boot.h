/*
 * Copyright (c) 2015, Linaro Limited
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 * 1. Redistributions of source code must retain the above copyright notice,
 * this list of conditions and the following disclaimer.
 *
 * 2. Redistributions in binary form must reproduce the above copyright notice,
 * this list of conditions and the following disclaimer in the documentation
 * and/or other materials provided with the distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE
 * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 */
#ifndef KERNEL_GENERIC_BOOT_H
#define KERNEL_GENERIC_BOOT_H

#include <stdint.h>

#if defined(CFG_WITH_ARM_TRUSTED_FW)
uint32_t cpu_on_handler(uint32_t a0, uint32_t a1);
uint32_t *generic_boot_init_primary(uint32_t pageable_part);
uint32_t generic_boot_cpu_on_handler(uint32_t a0, uint32_t a1);
#else
void generic_boot_init_primary(uint32_t pageable_part, uint32_t nsec_entry);
void generic_boot_init_secondary(uint32_t nsec_entry);
#endif

void main_init_gic(void);

const struct thread_handlers *generic_boot_get_handlers(void);

extern uint8_t __text_init_start[];
extern uint8_t __data_start[];
extern uint8_t __data_end[];
extern uint8_t __bss_start[];
extern uint8_t __bss_end[];
extern uint8_t __init_start[];
extern uint8_t __init_size[];
extern uint8_t __heap1_start[];
extern uint8_t __heap1_end[];
extern uint8_t __heap2_start[];
extern uint8_t __heap2_end[];
extern uint8_t __pageable_part_start[];
extern uint8_t __pageable_part_end[];
extern uint8_t __pageable_start[];
extern uint8_t __pageable_end[];

#endif /* KERNEL_GENERIC_BOOT_H */
