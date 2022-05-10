/*
 * Copyright (c) 2017-2021, ARM Limited and Contributors. All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include <stdbool.h>

#include <arch.h>
#include <arch_helpers.h>
#include <lib/el3_runtime/pubsub.h>
#include <lib/extensions/sve.h>

/*
 * Converts SVE vector size restriction in bytes to LEN according to ZCR_EL3 documentation.
 * VECTOR_SIZE = (LEN+1) * 128
 */
#define CONVERT_SVE_LENGTH(x)	(((x / 128) - 1))

static bool sve_supported(void)
{
	uint64_t features;

	features = read_id_aa64pfr0_el1() >> ID_AA64PFR0_SVE_SHIFT;
	return (features & ID_AA64PFR0_SVE_MASK) == 1U;
}

void sve_enable(cpu_context_t *context)
{
	u_register_t cptr_el3;

	if (!sve_supported()) {
		return;
	}

	cptr_el3 = read_ctx_reg(get_el3state_ctx(context), CTX_CPTR_EL3);

	/* Enable access to SVE functionality for all ELs. */
	cptr_el3 = (cptr_el3 | CPTR_EZ_BIT) & ~(TFP_BIT);
	write_ctx_reg(get_el3state_ctx(context), CTX_CPTR_EL3, cptr_el3);

	/* Restrict maximum SVE vector length (SVE_VECTOR_LENGTH+1) * 128. */
	write_ctx_reg(get_el3state_ctx(context), CTX_ZCR_EL3,
		(ZCR_EL3_LEN_MASK & CONVERT_SVE_LENGTH(512)));
}
