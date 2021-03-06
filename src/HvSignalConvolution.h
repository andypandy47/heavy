/**
 * Copyright (c) 2014-2017 Enzien Audio Ltd.
 *
 * Permission to use, copy, modify, and/or distribute this software for any
 * purpose with or without fee is hereby granted, provided that the above
 * copyright notice and this permission notice appear in all copies.
 *
 * THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES WITH
 * REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF MERCHANTABILITY
 * AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY SPECIAL, DIRECT,
 * INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING FROM
 * LOSS OF USE, DATA OR PROFITS, WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE OR
 * OTHER TORTIOUS ACTION, ARISING OUT OF OR IN CONNECTION WITH THE USE OR
 * PERFORMANCE OF THIS SOFTWARE.
 */

#ifndef _SIGNAL_CONVOLUTION_H_
#define _SIGNAL_CONVOLUTION_H_

#include "HvHeavyInternal.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct SignalConvolution {
  struct HvTable *table;
  struct HvTable inputs;
} SignalConvolution;

hv_size_t sConv_init(SignalConvolution *o, struct HvTable *coeffs, const int size);

void sConv_free(SignalConvolution *o);

void sConv_onMessage(HeavyContextInterface *_c, SignalConvolution *o, int letIndex,
    const HvMessage *m, void *sendMessage);

void __hv_conv_f(SignalConvolution *o, hv_bInf_t bIn, hv_bOutf_t bOut);

#ifdef __cplusplus
} // extern "C"
#endif

#endif // _SIGNAL_CONVOLUTION_H_
