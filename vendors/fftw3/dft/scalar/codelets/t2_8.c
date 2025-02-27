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
/* Generated on Tue Sep 14 10:44:32 EDT 2021 */

#include "dft/codelet-dft.h"

#if defined(ARCH_PREFERS_FMA) || defined(ISA_EXTENSION_PREFERS_FMA)

/* Generated by: ../../../genfft/gen_twiddle.native -fma -compact -variables 4
 * -pipeline-latency 4 -twiddle-log3 -precompute-twiddles -n 8 -name t2_8
 * -include dft/scalar/t.h */

/*
 * This function contains 74 FP additions, 50 FP multiplications,
 * (or, 44 additions, 20 multiplications, 30 fused multiply/add),
 * 48 stack variables, 1 constants, and 32 memory accesses
 */
#include "dft/scalar/t.h"

static void t2_8(R *ri, R *ii, const R *W, stride rs, INT mb, INT me, INT ms) {
  DK(KP707106781, +0.707106781186547524400844362104849039284835938);
  {
    INT m;
    for (m = mb, W = W + (mb * 6); m < me; m = m + 1, ri = ri + ms,
        ii = ii + ms, W = W + 6, MAKE_VOLATILE_STRIDE(16, rs)) {
      E T2, T3, Tl, Tn, T5, T6, Tf, T7, Ts, Tb, To, Ti, TC, TG;
      {
        E T4, Tm, Tr, Ta, TB, TF;
        T2 = W[0];
        T3 = W[2];
        T4 = T2 * T3;
        Tl = W[4];
        Tm = T2 * Tl;
        Tn = W[5];
        Tr = T2 * Tn;
        T5 = W[1];
        T6 = W[3];
        Ta = T2 * T6;
        Tf = FMA(T5, T6, T4);
        T7 = FNMS(T5, T6, T4);
        Ts = FNMS(T5, Tl, Tr);
        Tb = FMA(T5, T3, Ta);
        To = FMA(T5, Tn, Tm);
        TB = Tf * Tl;
        TF = Tf * Tn;
        Ti = FNMS(T5, T3, Ta);
        TC = FMA(Ti, Tn, TB);
        TG = FNMS(Ti, Tl, TF);
      }
      {
        E T1, T1s, Td, T1r, Tu, TY, Tk, TW, TN, TR, T18, T1a, T1c, T1d, TA;
        E TI, T11, T13, T15, T16;
        T1 = ri[0];
        T1s = ii[0];
        {
          E T8, T9, Tc, T1q;
          T8 = ri[WS(rs, 4)];
          T9 = T7 * T8;
          Tc = ii[WS(rs, 4)];
          T1q = T7 * Tc;
          Td = FMA(Tb, Tc, T9);
          T1r = FNMS(Tb, T8, T1q);
        }
        {
          E Tp, Tq, Tt, TX;
          Tp = ri[WS(rs, 6)];
          Tq = To * Tp;
          Tt = ii[WS(rs, 6)];
          TX = To * Tt;
          Tu = FMA(Ts, Tt, Tq);
          TY = FNMS(Ts, Tp, TX);
        }
        {
          E Tg, Th, Tj, TV;
          Tg = ri[WS(rs, 2)];
          Th = Tf * Tg;
          Tj = ii[WS(rs, 2)];
          TV = Tf * Tj;
          Tk = FMA(Ti, Tj, Th);
          TW = FNMS(Ti, Tg, TV);
        }
        {
          E TK, TL, TM, T19, TO, TP, TQ, T1b;
          TK = ri[WS(rs, 7)];
          TL = Tl * TK;
          TM = ii[WS(rs, 7)];
          T19 = Tl * TM;
          TO = ri[WS(rs, 3)];
          TP = T3 * TO;
          TQ = ii[WS(rs, 3)];
          T1b = T3 * TQ;
          TN = FMA(Tn, TM, TL);
          TR = FMA(T6, TQ, TP);
          T18 = TN - TR;
          T1a = FNMS(Tn, TK, T19);
          T1c = FNMS(T6, TO, T1b);
          T1d = T1a - T1c;
        }
        {
          E Tx, Ty, Tz, T12, TD, TE, TH, T14;
          Tx = ri[WS(rs, 1)];
          Ty = T2 * Tx;
          Tz = ii[WS(rs, 1)];
          T12 = T2 * Tz;
          TD = ri[WS(rs, 5)];
          TE = TC * TD;
          TH = ii[WS(rs, 5)];
          T14 = TC * TH;
          TA = FMA(T5, Tz, Ty);
          TI = FMA(TG, TH, TE);
          T11 = TA - TI;
          T13 = FNMS(T5, Tx, T12);
          T15 = FNMS(TG, TD, T14);
          T16 = T13 - T15;
        }
        {
          E T10, T1g, T1z, T1B, T1f, T1C, T1j, T1A;
          {
            E TU, TZ, T1x, T1y;
            TU = T1 - Td;
            TZ = TW - TY;
            T10 = TU + TZ;
            T1g = TU - TZ;
            T1x = T1s - T1r;
            T1y = Tk - Tu;
            T1z = T1x - T1y;
            T1B = T1y + T1x;
          }
          {
            E T17, T1e, T1h, T1i;
            T17 = T11 + T16;
            T1e = T18 - T1d;
            T1f = T17 + T1e;
            T1C = T1e - T17;
            T1h = T16 - T11;
            T1i = T18 + T1d;
            T1j = T1h - T1i;
            T1A = T1h + T1i;
          }
          ri[WS(rs, 5)] = FNMS(KP707106781, T1f, T10);
          ii[WS(rs, 5)] = FNMS(KP707106781, T1A, T1z);
          ri[WS(rs, 1)] = FMA(KP707106781, T1f, T10);
          ii[WS(rs, 1)] = FMA(KP707106781, T1A, T1z);
          ri[WS(rs, 7)] = FNMS(KP707106781, T1j, T1g);
          ii[WS(rs, 7)] = FNMS(KP707106781, T1C, T1B);
          ri[WS(rs, 3)] = FMA(KP707106781, T1j, T1g);
          ii[WS(rs, 3)] = FMA(KP707106781, T1C, T1B);
        }
        {
          E Tw, T1k, T1u, T1w, TT, T1v, T1n, T1o;
          {
            E Te, Tv, T1p, T1t;
            Te = T1 + Td;
            Tv = Tk + Tu;
            Tw = Te + Tv;
            T1k = Te - Tv;
            T1p = TW + TY;
            T1t = T1r + T1s;
            T1u = T1p + T1t;
            T1w = T1t - T1p;
          }
          {
            E TJ, TS, T1l, T1m;
            TJ = TA + TI;
            TS = TN + TR;
            TT = TJ + TS;
            T1v = TS - TJ;
            T1l = T13 + T15;
            T1m = T1a + T1c;
            T1n = T1l - T1m;
            T1o = T1l + T1m;
          }
          ri[WS(rs, 4)] = Tw - TT;
          ii[WS(rs, 4)] = T1u - T1o;
          ri[0] = Tw + TT;
          ii[0] = T1o + T1u;
          ri[WS(rs, 6)] = T1k - T1n;
          ii[WS(rs, 6)] = T1w - T1v;
          ri[WS(rs, 2)] = T1k + T1n;
          ii[WS(rs, 2)] = T1v + T1w;
        }
      }
    }
  }
}

static const tw_instr twinstr[] = {
    {TW_CEXP, 0, 1}, {TW_CEXP, 0, 3}, {TW_CEXP, 0, 7}, {TW_NEXT, 1, 0}};

static const ct_desc desc = {8, "t2_8", twinstr, &GENUS, {44, 20, 30, 0},
                             0, 0,      0};

void X(codelet_t2_8)(planner *p) { X(kdft_dit_register)(p, t2_8, &desc); }
#else

/* Generated by: ../../../genfft/gen_twiddle.native -compact -variables 4
 * -pipeline-latency 4 -twiddle-log3 -precompute-twiddles -n 8 -name t2_8
 * -include dft/scalar/t.h */

/*
 * This function contains 74 FP additions, 44 FP multiplications,
 * (or, 56 additions, 26 multiplications, 18 fused multiply/add),
 * 42 stack variables, 1 constants, and 32 memory accesses
 */
#include "dft/scalar/t.h"

static void t2_8(R *ri, R *ii, const R *W, stride rs, INT mb, INT me, INT ms) {
  DK(KP707106781, +0.707106781186547524400844362104849039284835938);
  {
    INT m;
    for (m = mb, W = W + (mb * 6); m < me; m = m + 1, ri = ri + ms,
        ii = ii + ms, W = W + 6, MAKE_VOLATILE_STRIDE(16, rs)) {
      E T2, T5, T3, T6, T8, Tc, Tg, Ti, Tl, Tm, Tn, Tz, Tp, Tx;
      {
        E T4, Tb, T7, Ta;
        T2 = W[0];
        T5 = W[1];
        T3 = W[2];
        T6 = W[3];
        T4 = T2 * T3;
        Tb = T5 * T3;
        T7 = T5 * T6;
        Ta = T2 * T6;
        T8 = T4 - T7;
        Tc = Ta + Tb;
        Tg = T4 + T7;
        Ti = Ta - Tb;
        Tl = W[4];
        Tm = W[5];
        Tn = FMA(T2, Tl, T5 * Tm);
        Tz = FNMS(Ti, Tl, Tg * Tm);
        Tp = FNMS(T5, Tl, T2 * Tm);
        Tx = FMA(Tg, Tl, Ti * Tm);
      }
      {
        E Tf, T1i, TL, T1d, TJ, T17, TV, TY, Ts, T1j, TO, T1a, TC, T16, TQ;
        E TT;
        {
          E T1, T1c, Te, T1b, T9, Td;
          T1 = ri[0];
          T1c = ii[0];
          T9 = ri[WS(rs, 4)];
          Td = ii[WS(rs, 4)];
          Te = FMA(T8, T9, Tc * Td);
          T1b = FNMS(Tc, T9, T8 * Td);
          Tf = T1 + Te;
          T1i = T1c - T1b;
          TL = T1 - Te;
          T1d = T1b + T1c;
        }
        {
          E TF, TW, TI, TX;
          {
            E TD, TE, TG, TH;
            TD = ri[WS(rs, 7)];
            TE = ii[WS(rs, 7)];
            TF = FMA(Tl, TD, Tm * TE);
            TW = FNMS(Tm, TD, Tl * TE);
            TG = ri[WS(rs, 3)];
            TH = ii[WS(rs, 3)];
            TI = FMA(T3, TG, T6 * TH);
            TX = FNMS(T6, TG, T3 * TH);
          }
          TJ = TF + TI;
          T17 = TW + TX;
          TV = TF - TI;
          TY = TW - TX;
        }
        {
          E Tk, TM, Tr, TN;
          {
            E Th, Tj, To, Tq;
            Th = ri[WS(rs, 2)];
            Tj = ii[WS(rs, 2)];
            Tk = FMA(Tg, Th, Ti * Tj);
            TM = FNMS(Ti, Th, Tg * Tj);
            To = ri[WS(rs, 6)];
            Tq = ii[WS(rs, 6)];
            Tr = FMA(Tn, To, Tp * Tq);
            TN = FNMS(Tp, To, Tn * Tq);
          }
          Ts = Tk + Tr;
          T1j = Tk - Tr;
          TO = TM - TN;
          T1a = TM + TN;
        }
        {
          E Tw, TR, TB, TS;
          {
            E Tu, Tv, Ty, TA;
            Tu = ri[WS(rs, 1)];
            Tv = ii[WS(rs, 1)];
            Tw = FMA(T2, Tu, T5 * Tv);
            TR = FNMS(T5, Tu, T2 * Tv);
            Ty = ri[WS(rs, 5)];
            TA = ii[WS(rs, 5)];
            TB = FMA(Tx, Ty, Tz * TA);
            TS = FNMS(Tz, Ty, Tx * TA);
          }
          TC = Tw + TB;
          T16 = TR + TS;
          TQ = Tw - TB;
          TT = TR - TS;
        }
        {
          E Tt, TK, T1f, T1g;
          Tt = Tf + Ts;
          TK = TC + TJ;
          ri[WS(rs, 4)] = Tt - TK;
          ri[0] = Tt + TK;
          {
            E T19, T1e, T15, T18;
            T19 = T16 + T17;
            T1e = T1a + T1d;
            ii[0] = T19 + T1e;
            ii[WS(rs, 4)] = T1e - T19;
            T15 = Tf - Ts;
            T18 = T16 - T17;
            ri[WS(rs, 6)] = T15 - T18;
            ri[WS(rs, 2)] = T15 + T18;
          }
          T1f = TJ - TC;
          T1g = T1d - T1a;
          ii[WS(rs, 2)] = T1f + T1g;
          ii[WS(rs, 6)] = T1g - T1f;
          {
            E T11, T1k, T14, T1h, T12, T13;
            T11 = TL - TO;
            T1k = T1i - T1j;
            T12 = TT - TQ;
            T13 = TV + TY;
            T14 = KP707106781 * (T12 - T13);
            T1h = KP707106781 * (T12 + T13);
            ri[WS(rs, 7)] = T11 - T14;
            ii[WS(rs, 5)] = T1k - T1h;
            ri[WS(rs, 3)] = T11 + T14;
            ii[WS(rs, 1)] = T1h + T1k;
          }
          {
            E TP, T1m, T10, T1l, TU, TZ;
            TP = TL + TO;
            T1m = T1j + T1i;
            TU = TQ + TT;
            TZ = TV - TY;
            T10 = KP707106781 * (TU + TZ);
            T1l = KP707106781 * (TZ - TU);
            ri[WS(rs, 5)] = TP - T10;
            ii[WS(rs, 7)] = T1m - T1l;
            ri[WS(rs, 1)] = TP + T10;
            ii[WS(rs, 3)] = T1l + T1m;
          }
        }
      }
    }
  }
}

static const tw_instr twinstr[] = {
    {TW_CEXP, 0, 1}, {TW_CEXP, 0, 3}, {TW_CEXP, 0, 7}, {TW_NEXT, 1, 0}};

static const ct_desc desc = {8, "t2_8", twinstr, &GENUS, {56, 26, 18, 0},
                             0, 0,      0};

void X(codelet_t2_8)(planner *p) { X(kdft_dit_register)(p, t2_8, &desc); }
#endif
