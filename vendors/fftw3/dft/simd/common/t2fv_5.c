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
/* Generated on Tue Sep 14 10:45:44 EDT 2021 */

#include "dft/codelet-dft.h"

#if defined(ARCH_PREFERS_FMA) || defined(ISA_EXTENSION_PREFERS_FMA)

/* Generated by: ../../../genfft/gen_twiddle_c.native -fma -simd -compact
 * -variables 4 -pipeline-latency 8 -n 5 -name t2fv_5 -include dft/simd/t2f.h */

/*
 * This function contains 20 FP additions, 19 FP multiplications,
 * (or, 11 additions, 10 multiplications, 9 fused multiply/add),
 * 20 stack variables, 4 constants, and 10 memory accesses
 */
#include "dft/simd/t2f.h"

static void t2fv_5(R *ri, R *ii, const R *W, stride rs, INT mb, INT me,
                   INT ms) {
  DVK(KP559016994, +0.559016994374947424102293417182819058860154590);
  DVK(KP250000000, +0.250000000000000000000000000000000000000000000);
  DVK(KP618033988, +0.618033988749894848204586834365638117720309180);
  DVK(KP951056516, +0.951056516295153572116439333379382143405698634);
  {
    INT m;
    R *x;
    x = ri;
    for (m = mb, W = W + (mb * ((TWVL / VL) * 8)); m < me; m = m + VL,
        x = x + (VL * ms), W = W + (TWVL * 8), MAKE_VOLATILE_STRIDE(5, rs)) {
      V T1, Tg, Th, T6, Tb, Tc;
      T1 = LD(&(x[0]), ms, &(x[0]));
      {
        V T3, Ta, T5, T8;
        {
          V T2, T9, T4, T7;
          T2 = LD(&(x[WS(rs, 1)]), ms, &(x[WS(rs, 1)]));
          T3 = BYTWJ(&(W[0]), T2);
          T9 = LD(&(x[WS(rs, 3)]), ms, &(x[WS(rs, 1)]));
          Ta = BYTWJ(&(W[TWVL * 4]), T9);
          T4 = LD(&(x[WS(rs, 4)]), ms, &(x[0]));
          T5 = BYTWJ(&(W[TWVL * 6]), T4);
          T7 = LD(&(x[WS(rs, 2)]), ms, &(x[0]));
          T8 = BYTWJ(&(W[TWVL * 2]), T7);
        }
        Tg = VSUB(T3, T5);
        Th = VSUB(T8, Ta);
        T6 = VADD(T3, T5);
        Tb = VADD(T8, Ta);
        Tc = VADD(T6, Tb);
      }
      ST(&(x[0]), VADD(T1, Tc), ms, &(x[0]));
      {
        V Ti, Tk, Tf, Tj, Td, Te;
        Ti = VMUL(LDK(KP951056516), VFMA(LDK(KP618033988), Th, Tg));
        Tk = VMUL(LDK(KP951056516), VFNMS(LDK(KP618033988), Tg, Th));
        Td = VFNMS(LDK(KP250000000), Tc, T1);
        Te = VSUB(T6, Tb);
        Tf = VFMA(LDK(KP559016994), Te, Td);
        Tj = VFNMS(LDK(KP559016994), Te, Td);
        ST(&(x[WS(rs, 1)]), VFNMSI(Ti, Tf), ms, &(x[WS(rs, 1)]));
        ST(&(x[WS(rs, 3)]), VFNMSI(Tk, Tj), ms, &(x[WS(rs, 1)]));
        ST(&(x[WS(rs, 4)]), VFMAI(Ti, Tf), ms, &(x[0]));
        ST(&(x[WS(rs, 2)]), VFMAI(Tk, Tj), ms, &(x[0]));
      }
    }
  }
  VLEAVE();
}

static const tw_instr twinstr[] = {
    VTW(0, 1), VTW(0, 2), VTW(0, 3), VTW(0, 4), {TW_NEXT, VL, 0}};

static const ct_desc desc = {
    5, XSIMD_STRING("t2fv_5"), twinstr, &GENUS, {11, 10, 9, 0}, 0, 0, 0};

void XSIMD(codelet_t2fv_5)(planner *p) {
  X(kdft_dit_register)(p, t2fv_5, &desc);
}
#else

/* Generated by: ../../../genfft/gen_twiddle_c.native -simd -compact -variables
 * 4 -pipeline-latency 8 -n 5 -name t2fv_5 -include dft/simd/t2f.h */

/*
 * This function contains 20 FP additions, 14 FP multiplications,
 * (or, 17 additions, 11 multiplications, 3 fused multiply/add),
 * 20 stack variables, 4 constants, and 10 memory accesses
 */
#include "dft/simd/t2f.h"

static void t2fv_5(R *ri, R *ii, const R *W, stride rs, INT mb, INT me,
                   INT ms) {
  DVK(KP250000000, +0.250000000000000000000000000000000000000000000);
  DVK(KP559016994, +0.559016994374947424102293417182819058860154590);
  DVK(KP587785252, +0.587785252292473129168705954639072768597652438);
  DVK(KP951056516, +0.951056516295153572116439333379382143405698634);
  {
    INT m;
    R *x;
    x = ri;
    for (m = mb, W = W + (mb * ((TWVL / VL) * 8)); m < me; m = m + VL,
        x = x + (VL * ms), W = W + (TWVL * 8), MAKE_VOLATILE_STRIDE(5, rs)) {
      V Tc, Tg, Th, T5, Ta, Td;
      Tc = LD(&(x[0]), ms, &(x[0]));
      {
        V T2, T9, T4, T7;
        {
          V T1, T8, T3, T6;
          T1 = LD(&(x[WS(rs, 1)]), ms, &(x[WS(rs, 1)]));
          T2 = BYTWJ(&(W[0]), T1);
          T8 = LD(&(x[WS(rs, 3)]), ms, &(x[WS(rs, 1)]));
          T9 = BYTWJ(&(W[TWVL * 4]), T8);
          T3 = LD(&(x[WS(rs, 4)]), ms, &(x[0]));
          T4 = BYTWJ(&(W[TWVL * 6]), T3);
          T6 = LD(&(x[WS(rs, 2)]), ms, &(x[0]));
          T7 = BYTWJ(&(W[TWVL * 2]), T6);
        }
        Tg = VSUB(T2, T4);
        Th = VSUB(T7, T9);
        T5 = VADD(T2, T4);
        Ta = VADD(T7, T9);
        Td = VADD(T5, Ta);
      }
      ST(&(x[0]), VADD(Tc, Td), ms, &(x[0]));
      {
        V Ti, Tj, Tf, Tk, Tb, Te;
        Ti = VBYI(VFMA(LDK(KP951056516), Tg, VMUL(LDK(KP587785252), Th)));
        Tj = VBYI(VFNMS(LDK(KP587785252), Tg, VMUL(LDK(KP951056516), Th)));
        Tb = VMUL(LDK(KP559016994), VSUB(T5, Ta));
        Te = VFNMS(LDK(KP250000000), Td, Tc);
        Tf = VADD(Tb, Te);
        Tk = VSUB(Te, Tb);
        ST(&(x[WS(rs, 1)]), VSUB(Tf, Ti), ms, &(x[WS(rs, 1)]));
        ST(&(x[WS(rs, 3)]), VSUB(Tk, Tj), ms, &(x[WS(rs, 1)]));
        ST(&(x[WS(rs, 4)]), VADD(Ti, Tf), ms, &(x[0]));
        ST(&(x[WS(rs, 2)]), VADD(Tj, Tk), ms, &(x[0]));
      }
    }
  }
  VLEAVE();
}

static const tw_instr twinstr[] = {
    VTW(0, 1), VTW(0, 2), VTW(0, 3), VTW(0, 4), {TW_NEXT, VL, 0}};

static const ct_desc desc = {
    5, XSIMD_STRING("t2fv_5"), twinstr, &GENUS, {17, 11, 3, 0}, 0, 0, 0};

void XSIMD(codelet_t2fv_5)(planner *p) {
  X(kdft_dit_register)(p, t2fv_5, &desc);
}
#endif
