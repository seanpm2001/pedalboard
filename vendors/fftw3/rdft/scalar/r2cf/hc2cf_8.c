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
/* Generated on Tue Sep 14 10:46:31 EDT 2021 */

#include "rdft/codelet-rdft.h"

#if defined(ARCH_PREFERS_FMA) || defined(ISA_EXTENSION_PREFERS_FMA)

/* Generated by: ../../../genfft/gen_hc2c.native -fma -compact -variables 4
 * -pipeline-latency 4 -n 8 -dit -name hc2cf_8 -include rdft/scalar/hc2cf.h */

/*
 * This function contains 66 FP additions, 36 FP multiplications,
 * (or, 44 additions, 14 multiplications, 22 fused multiply/add),
 * 34 stack variables, 1 constants, and 32 memory accesses
 */
#include "rdft/scalar/hc2cf.h"

static void hc2cf_8(R *Rp, R *Ip, R *Rm, R *Im, const R *W, stride rs, INT mb,
                    INT me, INT ms) {
  DK(KP707106781, +0.707106781186547524400844362104849039284835938);
  {
    INT m;
    for (m = mb, W = W + ((mb - 1) * 14); m < me; m = m + 1, Rp = Rp + ms,
        Ip = Ip + ms, Rm = Rm - ms, Im = Im - ms, W = W + 14,
        MAKE_VOLATILE_STRIDE(32, rs)) {
      E T1, T1m, T7, T1l, Tk, TS, Te, TQ, TF, T14, TL, T16, T12, T17, Ts;
      E TX, Ty, TZ, TV, T10;
      T1 = Rp[0];
      T1m = Rm[0];
      {
        E T3, T6, T4, T1k, T2, T5;
        T3 = Rp[WS(rs, 2)];
        T6 = Rm[WS(rs, 2)];
        T2 = W[6];
        T4 = T2 * T3;
        T1k = T2 * T6;
        T5 = W[7];
        T7 = FMA(T5, T6, T4);
        T1l = FNMS(T5, T3, T1k);
      }
      {
        E Tg, Tj, Th, TR, Tf, Ti;
        Tg = Rp[WS(rs, 3)];
        Tj = Rm[WS(rs, 3)];
        Tf = W[10];
        Th = Tf * Tg;
        TR = Tf * Tj;
        Ti = W[11];
        Tk = FMA(Ti, Tj, Th);
        TS = FNMS(Ti, Tg, TR);
      }
      {
        E Ta, Td, Tb, TP, T9, Tc;
        Ta = Rp[WS(rs, 1)];
        Td = Rm[WS(rs, 1)];
        T9 = W[2];
        Tb = T9 * Ta;
        TP = T9 * Td;
        Tc = W[3];
        Te = FMA(Tc, Td, Tb);
        TQ = FNMS(Tc, Ta, TP);
      }
      {
        E TB, TE, TC, T13, TH, TK, TI, T15, TA, TG, TD, TJ;
        TB = Ip[WS(rs, 3)];
        TE = Im[WS(rs, 3)];
        TA = W[12];
        TC = TA * TB;
        T13 = TA * TE;
        TH = Ip[WS(rs, 1)];
        TK = Im[WS(rs, 1)];
        TG = W[4];
        TI = TG * TH;
        T15 = TG * TK;
        TD = W[13];
        TF = FMA(TD, TE, TC);
        T14 = FNMS(TD, TB, T13);
        TJ = W[5];
        TL = FMA(TJ, TK, TI);
        T16 = FNMS(TJ, TH, T15);
        T12 = TF - TL;
        T17 = T14 - T16;
      }
      {
        E To, Tr, Tp, TW, Tu, Tx, Tv, TY, Tn, Tt, Tq, Tw;
        To = Ip[0];
        Tr = Im[0];
        Tn = W[0];
        Tp = Tn * To;
        TW = Tn * Tr;
        Tu = Ip[WS(rs, 2)];
        Tx = Im[WS(rs, 2)];
        Tt = W[8];
        Tv = Tt * Tu;
        TY = Tt * Tx;
        Tq = W[1];
        Ts = FMA(Tq, Tr, Tp);
        TX = FNMS(Tq, To, TW);
        Tw = W[9];
        Ty = FMA(Tw, Tx, Tv);
        TZ = FNMS(Tw, Tu, TY);
        TV = Ts - Ty;
        T10 = TX - TZ;
      }
      {
        E TU, T1a, T1t, T1v, T19, T1w, T1d, T1u;
        {
          E TO, TT, T1r, T1s;
          TO = T1 - T7;
          TT = TQ - TS;
          TU = TO + TT;
          T1a = TO - TT;
          T1r = T1m - T1l;
          T1s = Te - Tk;
          T1t = T1r - T1s;
          T1v = T1s + T1r;
        }
        {
          E T11, T18, T1b, T1c;
          T11 = TV + T10;
          T18 = T12 - T17;
          T19 = T11 + T18;
          T1w = T18 - T11;
          T1b = T10 - TV;
          T1c = T12 + T17;
          T1d = T1b - T1c;
          T1u = T1b + T1c;
        }
        Rm[WS(rs, 2)] = FNMS(KP707106781, T19, TU);
        Im[WS(rs, 2)] = FMS(KP707106781, T1u, T1t);
        Rp[WS(rs, 1)] = FMA(KP707106781, T19, TU);
        Ip[WS(rs, 1)] = FMA(KP707106781, T1u, T1t);
        Rm[0] = FNMS(KP707106781, T1d, T1a);
        Im[0] = FMS(KP707106781, T1w, T1v);
        Rp[WS(rs, 3)] = FMA(KP707106781, T1d, T1a);
        Ip[WS(rs, 3)] = FMA(KP707106781, T1w, T1v);
      }
      {
        E Tm, T1e, T1o, T1q, TN, T1p, T1h, T1i;
        {
          E T8, Tl, T1j, T1n;
          T8 = T1 + T7;
          Tl = Te + Tk;
          Tm = T8 + Tl;
          T1e = T8 - Tl;
          T1j = TQ + TS;
          T1n = T1l + T1m;
          T1o = T1j + T1n;
          T1q = T1n - T1j;
        }
        {
          E Tz, TM, T1f, T1g;
          Tz = Ts + Ty;
          TM = TF + TL;
          TN = Tz + TM;
          T1p = TM - Tz;
          T1f = TX + TZ;
          T1g = T14 + T16;
          T1h = T1f - T1g;
          T1i = T1f + T1g;
        }
        Rm[WS(rs, 3)] = Tm - TN;
        Im[WS(rs, 3)] = T1i - T1o;
        Rp[0] = Tm + TN;
        Ip[0] = T1i + T1o;
        Rm[WS(rs, 1)] = T1e - T1h;
        Im[WS(rs, 1)] = T1p - T1q;
        Rp[WS(rs, 2)] = T1e + T1h;
        Ip[WS(rs, 2)] = T1p + T1q;
      }
    }
  }
}

static const tw_instr twinstr[] = {{TW_FULL, 1, 8}, {TW_NEXT, 1, 0}};

static const hc2c_desc desc = {8, "hc2cf_8", twinstr, &GENUS, {44, 14, 22, 0}};

void X(codelet_hc2cf_8)(planner *p) {
  X(khc2c_register)(p, hc2cf_8, &desc, HC2C_VIA_RDFT);
}
#else

/* Generated by: ../../../genfft/gen_hc2c.native -compact -variables 4
 * -pipeline-latency 4 -n 8 -dit -name hc2cf_8 -include rdft/scalar/hc2cf.h */

/*
 * This function contains 66 FP additions, 32 FP multiplications,
 * (or, 52 additions, 18 multiplications, 14 fused multiply/add),
 * 28 stack variables, 1 constants, and 32 memory accesses
 */
#include "rdft/scalar/hc2cf.h"

static void hc2cf_8(R *Rp, R *Ip, R *Rm, R *Im, const R *W, stride rs, INT mb,
                    INT me, INT ms) {
  DK(KP707106781, +0.707106781186547524400844362104849039284835938);
  {
    INT m;
    for (m = mb, W = W + ((mb - 1) * 14); m < me; m = m + 1, Rp = Rp + ms,
        Ip = Ip + ms, Rm = Rm - ms, Im = Im - ms, W = W + 14,
        MAKE_VOLATILE_STRIDE(32, rs)) {
      E T7, T1e, TH, T19, TF, T13, TR, TU, Ti, T1f, TK, T16, Tu, T12, TM;
      E TP;
      {
        E T1, T18, T6, T17;
        T1 = Rp[0];
        T18 = Rm[0];
        {
          E T3, T5, T2, T4;
          T3 = Rp[WS(rs, 2)];
          T5 = Rm[WS(rs, 2)];
          T2 = W[6];
          T4 = W[7];
          T6 = FMA(T2, T3, T4 * T5);
          T17 = FNMS(T4, T3, T2 * T5);
        }
        T7 = T1 + T6;
        T1e = T18 - T17;
        TH = T1 - T6;
        T19 = T17 + T18;
      }
      {
        E Tz, TS, TE, TT;
        {
          E Tw, Ty, Tv, Tx;
          Tw = Ip[WS(rs, 3)];
          Ty = Im[WS(rs, 3)];
          Tv = W[12];
          Tx = W[13];
          Tz = FMA(Tv, Tw, Tx * Ty);
          TS = FNMS(Tx, Tw, Tv * Ty);
        }
        {
          E TB, TD, TA, TC;
          TB = Ip[WS(rs, 1)];
          TD = Im[WS(rs, 1)];
          TA = W[4];
          TC = W[5];
          TE = FMA(TA, TB, TC * TD);
          TT = FNMS(TC, TB, TA * TD);
        }
        TF = Tz + TE;
        T13 = TS + TT;
        TR = Tz - TE;
        TU = TS - TT;
      }
      {
        E Tc, TI, Th, TJ;
        {
          E T9, Tb, T8, Ta;
          T9 = Rp[WS(rs, 1)];
          Tb = Rm[WS(rs, 1)];
          T8 = W[2];
          Ta = W[3];
          Tc = FMA(T8, T9, Ta * Tb);
          TI = FNMS(Ta, T9, T8 * Tb);
        }
        {
          E Te, Tg, Td, Tf;
          Te = Rp[WS(rs, 3)];
          Tg = Rm[WS(rs, 3)];
          Td = W[10];
          Tf = W[11];
          Th = FMA(Td, Te, Tf * Tg);
          TJ = FNMS(Tf, Te, Td * Tg);
        }
        Ti = Tc + Th;
        T1f = Tc - Th;
        TK = TI - TJ;
        T16 = TI + TJ;
      }
      {
        E To, TN, Tt, TO;
        {
          E Tl, Tn, Tk, Tm;
          Tl = Ip[0];
          Tn = Im[0];
          Tk = W[0];
          Tm = W[1];
          To = FMA(Tk, Tl, Tm * Tn);
          TN = FNMS(Tm, Tl, Tk * Tn);
        }
        {
          E Tq, Ts, Tp, Tr;
          Tq = Ip[WS(rs, 2)];
          Ts = Im[WS(rs, 2)];
          Tp = W[8];
          Tr = W[9];
          Tt = FMA(Tp, Tq, Tr * Ts);
          TO = FNMS(Tr, Tq, Tp * Ts);
        }
        Tu = To + Tt;
        T12 = TN + TO;
        TM = To - Tt;
        TP = TN - TO;
      }
      {
        E Tj, TG, T1b, T1c;
        Tj = T7 + Ti;
        TG = Tu + TF;
        Rm[WS(rs, 3)] = Tj - TG;
        Rp[0] = Tj + TG;
        {
          E T15, T1a, T11, T14;
          T15 = T12 + T13;
          T1a = T16 + T19;
          Im[WS(rs, 3)] = T15 - T1a;
          Ip[0] = T15 + T1a;
          T11 = T7 - Ti;
          T14 = T12 - T13;
          Rm[WS(rs, 1)] = T11 - T14;
          Rp[WS(rs, 2)] = T11 + T14;
        }
        T1b = TF - Tu;
        T1c = T19 - T16;
        Im[WS(rs, 1)] = T1b - T1c;
        Ip[WS(rs, 2)] = T1b + T1c;
        {
          E TX, T1g, T10, T1d, TY, TZ;
          TX = TH - TK;
          T1g = T1e - T1f;
          TY = TP - TM;
          TZ = TR + TU;
          T10 = KP707106781 * (TY - TZ);
          T1d = KP707106781 * (TY + TZ);
          Rm[0] = TX - T10;
          Ip[WS(rs, 1)] = T1d + T1g;
          Rp[WS(rs, 3)] = TX + T10;
          Im[WS(rs, 2)] = T1d - T1g;
        }
        {
          E TL, T1i, TW, T1h, TQ, TV;
          TL = TH + TK;
          T1i = T1f + T1e;
          TQ = TM + TP;
          TV = TR - TU;
          TW = KP707106781 * (TQ + TV);
          T1h = KP707106781 * (TV - TQ);
          Rm[WS(rs, 2)] = TL - TW;
          Ip[WS(rs, 3)] = T1h + T1i;
          Rp[WS(rs, 1)] = TL + TW;
          Im[0] = T1h - T1i;
        }
      }
    }
  }
}

static const tw_instr twinstr[] = {{TW_FULL, 1, 8}, {TW_NEXT, 1, 0}};

static const hc2c_desc desc = {8, "hc2cf_8", twinstr, &GENUS, {52, 18, 14, 0}};

void X(codelet_hc2cf_8)(planner *p) {
  X(khc2c_register)(p, hc2cf_8, &desc, HC2C_VIA_RDFT);
}
#endif
