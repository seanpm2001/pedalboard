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
/* Generated on Tue Sep 14 10:47:22 EDT 2021 */

#include "rdft/codelet-rdft.h"

#if defined(ARCH_PREFERS_FMA) || defined(ISA_EXTENSION_PREFERS_FMA)

/* Generated by: ../../../genfft/gen_hc2cdft_c.native -fma -simd -compact
 * -variables 4 -pipeline-latency 8 -trivial-stores -variables 32
 * -no-generate-bytw -n 4 -dif -sign 1 -name hc2cbdftv_4 -include
 * rdft/simd/hc2cbv.h */

/*
 * This function contains 15 FP additions, 12 FP multiplications,
 * (or, 9 additions, 6 multiplications, 6 fused multiply/add),
 * 20 stack variables, 0 constants, and 8 memory accesses
 */
#include "rdft/simd/hc2cbv.h"

static void hc2cbdftv_4(R *Rp, R *Ip, R *Rm, R *Im, const R *W, stride rs,
                        INT mb, INT me, INT ms) {
  {
    INT m;
    for (m = mb, W = W + ((mb - 1) * ((TWVL / VL) * 6)); m < me; m = m + VL,
        Rp = Rp + (VL * ms), Ip = Ip + (VL * ms), Rm = Rm - (VL * ms),
        Im = Im - (VL * ms), W = W + (TWVL * 6), MAKE_VOLATILE_STRIDE(16, rs)) {
      V Th, Tg, T8, Tc, T4, Ta, T7, Tb, T2, T3, T5, T6, Tf, T1, T9;
      V Td, Tj, Te, Ti;
      T2 = LD(&(Rp[0]), ms, &(Rp[0]));
      T3 = LD(&(Rm[WS(rs, 1)]), -ms, &(Rm[WS(rs, 1)]));
      T4 = VFNMSCONJ(T3, T2);
      Ta = VFMACONJ(T3, T2);
      T5 = LD(&(Rp[WS(rs, 1)]), ms, &(Rp[WS(rs, 1)]));
      T6 = LD(&(Rm[0]), -ms, &(Rm[0]));
      T7 = VFNMSCONJ(T6, T5);
      Tb = VFMACONJ(T6, T5);
      Th = VADD(Ta, Tb);
      Tf = LDW(&(W[0]));
      Tg = VZMULI(Tf, VFMAI(T7, T4));
      T1 = LDW(&(W[TWVL * 4]));
      T8 = VZMULI(T1, VFNMSI(T7, T4));
      T9 = LDW(&(W[TWVL * 2]));
      Tc = VZMUL(T9, VSUB(Ta, Tb));
      Td = VADD(T8, Tc);
      ST(&(Rp[WS(rs, 1)]), Td, ms, &(Rp[WS(rs, 1)]));
      Tj = VCONJ(VSUB(Th, Tg));
      ST(&(Rm[0]), Tj, -ms, &(Rm[0]));
      Te = VCONJ(VSUB(Tc, T8));
      ST(&(Rm[WS(rs, 1)]), Te, -ms, &(Rm[WS(rs, 1)]));
      Ti = VADD(Tg, Th);
      ST(&(Rp[0]), Ti, ms, &(Rp[0]));
    }
  }
  VLEAVE();
}

static const tw_instr twinstr[] = {
    VTW(1, 1), VTW(1, 2), VTW(1, 3), {TW_NEXT, VL, 0}};

static const hc2c_desc desc = {
    4, XSIMD_STRING("hc2cbdftv_4"), twinstr, &GENUS, {9, 6, 6, 0}};

void XSIMD(codelet_hc2cbdftv_4)(planner *p) {
  X(khc2c_register)(p, hc2cbdftv_4, &desc, HC2C_VIA_DFT);
}
#else

/* Generated by: ../../../genfft/gen_hc2cdft_c.native -simd -compact -variables
 * 4 -pipeline-latency 8 -trivial-stores -variables 32 -no-generate-bytw -n 4
 * -dif -sign 1 -name hc2cbdftv_4 -include rdft/simd/hc2cbv.h */

/*
 * This function contains 15 FP additions, 6 FP multiplications,
 * (or, 15 additions, 6 multiplications, 0 fused multiply/add),
 * 22 stack variables, 0 constants, and 8 memory accesses
 */
#include "rdft/simd/hc2cbv.h"

static void hc2cbdftv_4(R *Rp, R *Ip, R *Rm, R *Im, const R *W, stride rs,
                        INT mb, INT me, INT ms) {
  {
    INT m;
    for (m = mb, W = W + ((mb - 1) * ((TWVL / VL) * 6)); m < me; m = m + VL,
        Rp = Rp + (VL * ms), Ip = Ip + (VL * ms), Rm = Rm - (VL * ms),
        Im = Im - (VL * ms), W = W + (TWVL * 6), MAKE_VOLATILE_STRIDE(16, rs)) {
      V T5, Tc, T9, Td, T2, T4, T3, T6, T8, T7, Tj, Ti, Th, Tk, Tl;
      V Ta, Te, T1, Tb, Tf, Tg;
      T2 = LD(&(Rp[0]), ms, &(Rp[0]));
      T3 = LD(&(Rm[WS(rs, 1)]), -ms, &(Rm[WS(rs, 1)]));
      T4 = VCONJ(T3);
      T5 = VSUB(T2, T4);
      Tc = VADD(T2, T4);
      T6 = LD(&(Rp[WS(rs, 1)]), ms, &(Rp[WS(rs, 1)]));
      T7 = LD(&(Rm[0]), -ms, &(Rm[0]));
      T8 = VCONJ(T7);
      T9 = VBYI(VSUB(T6, T8));
      Td = VADD(T6, T8);
      Tj = VADD(Tc, Td);
      Th = LDW(&(W[0]));
      Ti = VZMULI(Th, VADD(T5, T9));
      Tk = VADD(Ti, Tj);
      ST(&(Rp[0]), Tk, ms, &(Rp[0]));
      Tl = VCONJ(VSUB(Tj, Ti));
      ST(&(Rm[0]), Tl, -ms, &(Rm[0]));
      T1 = LDW(&(W[TWVL * 4]));
      Ta = VZMULI(T1, VSUB(T5, T9));
      Tb = LDW(&(W[TWVL * 2]));
      Te = VZMUL(Tb, VSUB(Tc, Td));
      Tf = VADD(Ta, Te);
      ST(&(Rp[WS(rs, 1)]), Tf, ms, &(Rp[WS(rs, 1)]));
      Tg = VCONJ(VSUB(Te, Ta));
      ST(&(Rm[WS(rs, 1)]), Tg, -ms, &(Rm[WS(rs, 1)]));
    }
  }
  VLEAVE();
}

static const tw_instr twinstr[] = {
    VTW(1, 1), VTW(1, 2), VTW(1, 3), {TW_NEXT, VL, 0}};

static const hc2c_desc desc = {
    4, XSIMD_STRING("hc2cbdftv_4"), twinstr, &GENUS, {15, 6, 0, 0}};

void XSIMD(codelet_hc2cbdftv_4)(planner *p) {
  X(khc2c_register)(p, hc2cbdftv_4, &desc, HC2C_VIA_DFT);
}
#endif
