/*
 * Copyright (c) 2019-2021, ARM Limited. All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef CORTEX_A78_H
#define CORTEX_A78_H

#include <lib/utils_def.h>

#define CORTEX_A78_MIDR					U(0x410FD410)

/*******************************************************************************
 * CPU Extended Control register specific definitions.
 ******************************************************************************/
#define CORTEX_A78_CPUECTLR_EL1				S3_0_C15_C1_4
#define CORTEX_A78_CPUECTLR_EL1_BIT_8			(ULL(1) << 8)

/*******************************************************************************
 * CPU Power Control register specific definitions
 ******************************************************************************/
#define CORTEX_A78_CPUPWRCTLR_EL1			S3_0_C15_C2_7
#define CORTEX_A78_CPUPWRCTLR_EL1_CORE_PWRDN_EN_BIT	U(1)

/*******************************************************************************
 * CPU Auxiliary Control register specific definitions.
 ******************************************************************************/
#define CORTEX_A78_ACTLR_TAM_BIT			(ULL(1) << 30)

#define CORTEX_A78_ACTLR2_EL1				S3_0_C15_C1_1
#define CORTEX_A78_ACTLR2_EL1_BIT_1			(ULL(1) << 1)

/*******************************************************************************
 * CPU Activity Monitor Unit register specific definitions.
 ******************************************************************************/
#define CPUAMCNTENCLR0_EL0				S3_3_C15_C2_4
#define CPUAMCNTENSET0_EL0				S3_3_C15_C2_5
#define CPUAMCNTENCLR1_EL0				S3_3_C15_C3_0
#define CPUAMCNTENSET1_EL0				S3_3_C15_C3_1

#define CORTEX_A78_AMU_GROUP0_MASK			U(0xF)
#define CORTEX_A78_AMU_GROUP1_MASK			U(0x7)

#endif /* CORTEX_A78_H */
