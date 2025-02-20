/*
 * Copyright (c) 2003, 2007-14 Matteo Frigo
 * Copyright (c) 2003, 2007-14 Massachusetts Institute of Technology
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301 USA
 *
 */

/* This file was automatically generated --- DO NOT EDIT */
/* Generated on Tue Sep 14 10:45:23 EDT 2021 */

#include "dft/codelet-dft.h"

#if defined(ARCH_PREFERS_FMA) || defined(ISA_EXTENSION_PREFERS_FMA)

/* Generated by: ../../../genfft/gen_notw.native -fma -simd -compact -variables
 * 4 -pipeline-latency 8 -n 4 -name n2sv_4 -with-ostride 1 -include
 * dft/simd/n2s.h -store-multiple 4 */

/*
 * This function contains 16 FP additions, 0 FP multiplications,
 * (or, 16 additions, 0 multiplications, 0 fused multiply/add),
 * 17 stack variables, 0 constants, and 18 memory accesses
 */
#include "dft/simd/n2s.h"

static void n2sv_4(const R *ri, const R *ii, R *ro, R *io, stride is, stride os,
                   INT v, INT ivs, INT ovs) {
  {
    INT i;
    for (i = v; i > 0; i = i - (2 * VL), ri = ri + ((2 * VL) * ivs),
        ii = ii + ((2 * VL) * ivs), ro = ro + ((2 * VL) * ovs),
        io = io + ((2 * VL) * ovs), MAKE_VOLATILE_STRIDE(16, is),
        MAKE_VOLATILE_STRIDE(16, os)) {
      V T3, Tb, T9, Tf, T6, Ta, Te, Tg;
      {
        V T1, T2, T7, T8;
        T1 = LD(&(ri[0]), ivs, &(ri[0]));
        T2 = LD(&(ri[WS(is, 2)]), ivs, &(ri[0]));
        T3 = VADD(T1, T2);
        Tb = VSUB(T1, T2);
        T7 = LD(&(ii[0]), ivs, &(ii[0]));
        T8 = LD(&(ii[WS(is, 2)]), ivs, &(ii[0]));
        T9 = VSUB(T7, T8);
        Tf = VADD(T7, T8);
      }
      {
        V T4, T5, Tc, Td;
        T4 = LD(&(ri[WS(is, 1)]), ivs, &(ri[WS(is, 1)]));
        T5 = LD(&(ri[WS(is, 3)]), ivs, &(ri[WS(is, 1)]));
        T6 = VADD(T4, T5);
        Ta = VSUB(T4, T5);
        Tc = LD(&(ii[WS(is, 1)]), ivs, &(ii[WS(is, 1)]));
        Td = LD(&(ii[WS(is, 3)]), ivs, &(ii[WS(is, 1)]));
        Te = VSUB(Tc, Td);
        Tg = VADD(Tc, Td);
      }
      {
        V Th, Ti, Tj, Tk;
        Th = VSUB(T3, T6);
        STM4(&(ro[2]), Th, ovs, &(ro[0]));
        Ti = VSUB(Tf, Tg);
        STM4(&(io[2]), Ti, ovs, &(io[0]));
        Tj = VADD(T3, T6);
        STM4(&(ro[0]), Tj, ovs, &(ro[0]));
        Tk = VADD(Tf, Tg);
        STM4(&(io[0]), Tk, ovs, &(io[0]));
        {
          V Tl, Tm, Tn, To;
          Tl = VSUB(T9, Ta);
          STM4(&(io[1]), Tl, ovs, &(io[1]));
          Tm = VADD(Tb, Te);
          STM4(&(ro[1]), Tm, ovs, &(ro[1]));
          Tn = VADD(Ta, T9);
          STM4(&(io[3]), Tn, ovs, &(io[1]));
          STN4(&(io[0]), Tk, Tl, Ti, Tn, ovs);
          To = VSUB(Tb, Te);
          STM4(&(ro[3]), To, ovs, &(ro[1]));
          STN4(&(ro[0]), Tj, Tm, Th, To, ovs);
        }
      }
    }
  }
  VLEAVE();
}

static const kdft_desc desc = {
    4, XSIMD_STRING("n2sv_4"), {16, 0, 0, 0}, &GENUS, 0, 1, 0, 0};

void XSIMD(codelet_n2sv_4)(planner *p) { X(kdft_register)(p, n2sv_4, &desc); }

#else

/* Generated by: ../../../genfft/gen_notw.native -simd -compact -variables 4
 * -pipeline-latency 8 -n 4 -name n2sv_4 -with-ostride 1 -include dft/simd/n2s.h
 * -store-multiple 4 */

/*
 * This function contains 16 FP additions, 0 FP multiplications,
 * (or, 16 additions, 0 multiplications, 0 fused multiply/add),
 * 17 stack variables, 0 constants, and 18 memory accesses
 */
#include "dft/simd/n2s.h"

static void n2sv_4(const R *ri, const R *ii, R *ro, R *io, stride is, stride os,
                   INT v, INT ivs, INT ovs) {
  {
    INT i;
    for (i = v; i > 0; i = i - (2 * VL), ri = ri + ((2 * VL) * ivs),
        ii = ii + ((2 * VL) * ivs), ro = ro + ((2 * VL) * ovs),
        io = io + ((2 * VL) * ovs), MAKE_VOLATILE_STRIDE(16, is),
        MAKE_VOLATILE_STRIDE(16, os)) {
      V T3, Tb, T9, Tf, T6, Ta, Te, Tg;
      {
        V T1, T2, T7, T8;
        T1 = LD(&(ri[0]), ivs, &(ri[0]));
        T2 = LD(&(ri[WS(is, 2)]), ivs, &(ri[0]));
        T3 = VADD(T1, T2);
        Tb = VSUB(T1, T2);
        T7 = LD(&(ii[0]), ivs, &(ii[0]));
        T8 = LD(&(ii[WS(is, 2)]), ivs, &(ii[0]));
        T9 = VSUB(T7, T8);
        Tf = VADD(T7, T8);
      }
      {
        V T4, T5, Tc, Td;
        T4 = LD(&(ri[WS(is, 1)]), ivs, &(ri[WS(is, 1)]));
        T5 = LD(&(ri[WS(is, 3)]), ivs, &(ri[WS(is, 1)]));
        T6 = VADD(T4, T5);
        Ta = VSUB(T4, T5);
        Tc = LD(&(ii[WS(is, 1)]), ivs, &(ii[WS(is, 1)]));
        Td = LD(&(ii[WS(is, 3)]), ivs, &(ii[WS(is, 1)]));
        Te = VSUB(Tc, Td);
        Tg = VADD(Tc, Td);
      }
      {
        V Th, Ti, Tj, Tk;
        Th = VSUB(T3, T6);
        STM4(&(ro[2]), Th, ovs, &(ro[0]));
        Ti = VSUB(Tf, Tg);
        STM4(&(io[2]), Ti, ovs, &(io[0]));
        Tj = VADD(T3, T6);
        STM4(&(ro[0]), Tj, ovs, &(ro[0]));
        Tk = VADD(Tf, Tg);
        STM4(&(io[0]), Tk, ovs, &(io[0]));
        {
          V Tl, Tm, Tn, To;
          Tl = VSUB(T9, Ta);
          STM4(&(io[1]), Tl, ovs, &(io[1]));
          Tm = VADD(Tb, Te);
          STM4(&(ro[1]), Tm, ovs, &(ro[1]));
          Tn = VADD(Ta, T9);
          STM4(&(io[3]), Tn, ovs, &(io[1]));
          STN4(&(io[0]), Tk, Tl, Ti, Tn, ovs);
          To = VSUB(Tb, Te);
          STM4(&(ro[3]), To, ovs, &(ro[1]));
          STN4(&(ro[0]), Tj, Tm, Th, To, ovs);
        }
      }
    }
  }
  VLEAVE();
}

static const kdft_desc desc = {
    4, XSIMD_STRING("n2sv_4"), {16, 0, 0, 0}, &GENUS, 0, 1, 0, 0};

void XSIMD(codelet_n2sv_4)(planner *p) { X(kdft_register)(p, n2sv_4, &desc); }

#endif
