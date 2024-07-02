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
/* Generated on Tue Sep 14 10:47:00 EDT 2021 */

#include "rdft/codelet-rdft.h"

#if defined(ARCH_PREFERS_FMA) || defined(ISA_EXTENSION_PREFERS_FMA)

/* Generated by: ../../../genfft/gen_r2cb.native -fma -compact -variables 4
 * -pipeline-latency 4 -sign 1 -n 10 -name r2cbIII_10 -dft-III -include
 * rdft/scalar/r2cbIII.h */

/*
 * This function contains 32 FP additions, 28 FP multiplications,
 * (or, 14 additions, 10 multiplications, 18 fused multiply/add),
 * 22 stack variables, 5 constants, and 20 memory accesses
 */
#include "rdft/scalar/r2cbIII.h"

static void r2cbIII_10(R *R0, R *R1, R *Cr, R *Ci, stride rs, stride csr,
                       stride csi, INT v, INT ivs, INT ovs) {
  DK(KP951056516, +0.951056516295153572116439333379382143405698634);
  DK(KP559016994, +0.559016994374947424102293417182819058860154590);
  DK(KP250000000, +0.250000000000000000000000000000000000000000000);
  DK(KP618033988, +0.618033988749894848204586834365638117720309180);
  DK(KP2_000000000, +2.000000000000000000000000000000000000000000000);
  {
    INT i;
    for (i = v; i > 0; i = i - 1, R0 = R0 + ovs, R1 = R1 + ovs, Cr = Cr + ivs,
        Ci = Ci + ivs, MAKE_VOLATILE_STRIDE(40, rs),
        MAKE_VOLATILE_STRIDE(40, csr), MAKE_VOLATILE_STRIDE(40, csi)) {
      E T1, To, T8, Tt, Ta, Ts, Te, Tq, Th, Tn;
      T1 = Cr[WS(csr, 2)];
      To = Ci[WS(csi, 2)];
      {
        E T2, T3, T4, T5, T6, T7;
        T2 = Cr[WS(csr, 4)];
        T3 = Cr[0];
        T4 = T2 + T3;
        T5 = Cr[WS(csr, 3)];
        T6 = Cr[WS(csr, 1)];
        T7 = T5 + T6;
        T8 = T4 + T7;
        Tt = T5 - T6;
        Ta = T7 - T4;
        Ts = T2 - T3;
      }
      {
        E Tc, Td, Tl, Tf, Tg, Tm;
        Tc = Ci[WS(csi, 3)];
        Td = Ci[WS(csi, 1)];
        Tl = Tc + Td;
        Tf = Ci[WS(csi, 4)];
        Tg = Ci[0];
        Tm = Tf + Tg;
        Te = Tc - Td;
        Tq = Tl + Tm;
        Th = Tf - Tg;
        Tn = Tl - Tm;
      }
      R0[0] = KP2_000000000 * (T1 + T8);
      R1[WS(rs, 2)] = KP2_000000000 * (Tn - To);
      {
        E Ti, Tk, Tb, Tj, T9;
        Ti = FMA(KP618033988, Th, Te);
        Tk = FNMS(KP618033988, Te, Th);
        T9 = FMS(KP250000000, T8, T1);
        Tb = FNMS(KP559016994, Ta, T9);
        Tj = FMA(KP559016994, Ta, T9);
        R0[WS(rs, 1)] = KP2_000000000 * (FMA(KP951056516, Ti, Tb));
        R0[WS(rs, 3)] = KP2_000000000 * (FMA(KP951056516, Tk, Tj));
        R0[WS(rs, 4)] = -(KP2_000000000 * (FNMS(KP951056516, Ti, Tb)));
        R0[WS(rs, 2)] = -(KP2_000000000 * (FNMS(KP951056516, Tk, Tj)));
      }
      {
        E Tu, Tw, Tr, Tv, Tp;
        Tu = FMA(KP618033988, Tt, Ts);
        Tw = FNMS(KP618033988, Ts, Tt);
        Tp = FMA(KP250000000, Tn, To);
        Tr = FMA(KP559016994, Tq, Tp);
        Tv = FNMS(KP559016994, Tq, Tp);
        R1[0] = -(KP2_000000000 * (FMA(KP951056516, Tu, Tr)));
        R1[WS(rs, 3)] = KP2_000000000 * (FNMS(KP951056516, Tw, Tv));
        R1[WS(rs, 4)] = -(KP2_000000000 * (FNMS(KP951056516, Tu, Tr)));
        R1[WS(rs, 1)] = KP2_000000000 * (FMA(KP951056516, Tw, Tv));
      }
    }
  }
}

static const kr2c_desc desc = {10, "r2cbIII_10", {14, 10, 18, 0}, &GENUS};

void X(codelet_r2cbIII_10)(planner *p) {
  X(kr2c_register)(p, r2cbIII_10, &desc);
}

#else

/* Generated by: ../../../genfft/gen_r2cb.native -compact -variables 4
 * -pipeline-latency 4 -sign 1 -n 10 -name r2cbIII_10 -dft-III -include
 * rdft/scalar/r2cbIII.h */

/*
 * This function contains 32 FP additions, 16 FP multiplications,
 * (or, 26 additions, 10 multiplications, 6 fused multiply/add),
 * 22 stack variables, 5 constants, and 20 memory accesses
 */
#include "rdft/scalar/r2cbIII.h"

static void r2cbIII_10(R *R0, R *R1, R *Cr, R *Ci, stride rs, stride csr,
                       stride csi, INT v, INT ivs, INT ovs) {
  DK(KP500000000, +0.500000000000000000000000000000000000000000000);
  DK(KP1_902113032, +1.902113032590307144232878666758764286811397268);
  DK(KP1_175570504, +1.175570504584946258337411909278145537195304875);
  DK(KP2_000000000, +2.000000000000000000000000000000000000000000000);
  DK(KP1_118033988, +1.118033988749894848204586834365638117720309180);
  {
    INT i;
    for (i = v; i > 0; i = i - 1, R0 = R0 + ovs, R1 = R1 + ovs, Cr = Cr + ivs,
        Ci = Ci + ivs, MAKE_VOLATILE_STRIDE(40, rs),
        MAKE_VOLATILE_STRIDE(40, csr), MAKE_VOLATILE_STRIDE(40, csi)) {
      E T1, To, T8, Tq, Ta, Tp, Te, Ts, Th, Tn;
      T1 = Cr[WS(csr, 2)];
      To = Ci[WS(csi, 2)];
      {
        E T2, T3, T4, T5, T6, T7;
        T2 = Cr[WS(csr, 4)];
        T3 = Cr[0];
        T4 = T2 + T3;
        T5 = Cr[WS(csr, 3)];
        T6 = Cr[WS(csr, 1)];
        T7 = T5 + T6;
        T8 = T4 + T7;
        Tq = T5 - T6;
        Ta = KP1_118033988 * (T7 - T4);
        Tp = T2 - T3;
      }
      {
        E Tc, Td, Tm, Tf, Tg, Tl;
        Tc = Ci[WS(csi, 4)];
        Td = Ci[0];
        Tm = Tc + Td;
        Tf = Ci[WS(csi, 1)];
        Tg = Ci[WS(csi, 3)];
        Tl = Tg + Tf;
        Te = Tc - Td;
        Ts = KP1_118033988 * (Tl + Tm);
        Th = Tf - Tg;
        Tn = Tl - Tm;
      }
      R0[0] = KP2_000000000 * (T1 + T8);
      R1[WS(rs, 2)] = KP2_000000000 * (Tn - To);
      {
        E Ti, Tj, Tb, Tk, T9;
        Ti = FNMS(KP1_902113032, Th, KP1_175570504 * Te);
        Tj = FMA(KP1_175570504, Th, KP1_902113032 * Te);
        T9 = FNMS(KP2_000000000, T1, KP500000000 * T8);
        Tb = T9 - Ta;
        Tk = T9 + Ta;
        R0[WS(rs, 1)] = Tb + Ti;
        R0[WS(rs, 3)] = Tk + Tj;
        R0[WS(rs, 4)] = Ti - Tb;
        R0[WS(rs, 2)] = Tj - Tk;
      }
      {
        E Tr, Tv, Tu, Tw, Tt;
        Tr = FMA(KP1_902113032, Tp, KP1_175570504 * Tq);
        Tv = FNMS(KP1_175570504, Tp, KP1_902113032 * Tq);
        Tt = FMA(KP500000000, Tn, KP2_000000000 * To);
        Tu = Ts + Tt;
        Tw = Tt - Ts;
        R1[0] = -(Tr + Tu);
        R1[WS(rs, 3)] = Tw - Tv;
        R1[WS(rs, 4)] = Tr - Tu;
        R1[WS(rs, 1)] = Tv + Tw;
      }
    }
  }
}

static const kr2c_desc desc = {10, "r2cbIII_10", {26, 10, 6, 0}, &GENUS};

void X(codelet_r2cbIII_10)(planner *p) {
  X(kr2c_register)(p, r2cbIII_10, &desc);
}

#endif
