// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vdut.h for the primary calling header

#include "verilated.h"

#include "Vdut___024root.h"

VL_INLINE_OPT void Vdut___024root___sequent__TOP__0(Vdut___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vdut__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdut___024root___sequent__TOP__0\n"); );
    // Init
    CData/*4:0*/ __Vdlyvdim0__top__DOT__RF__DOT__regs__v0;
    IData/*31:0*/ __Vdlyvval__top__DOT__RF__DOT__regs__v0;
    CData/*0:0*/ __Vdlyvset__top__DOT__RF__DOT__regs__v0;
    IData/*16:0*/ __Vdlyvdim0__top__DOT__DM__DOT__mem_array__v0;
    CData/*7:0*/ __Vdlyvval__top__DOT__DM__DOT__mem_array__v0;
    CData/*0:0*/ __Vdlyvset__top__DOT__DM__DOT__mem_array__v0;
    IData/*16:0*/ __Vdlyvdim0__top__DOT__DM__DOT__mem_array__v1;
    CData/*7:0*/ __Vdlyvval__top__DOT__DM__DOT__mem_array__v1;
    CData/*0:0*/ __Vdlyvset__top__DOT__DM__DOT__mem_array__v1;
    IData/*16:0*/ __Vdlyvdim0__top__DOT__DM__DOT__mem_array__v2;
    CData/*7:0*/ __Vdlyvval__top__DOT__DM__DOT__mem_array__v2;
    IData/*16:0*/ __Vdlyvdim0__top__DOT__DM__DOT__mem_array__v3;
    CData/*7:0*/ __Vdlyvval__top__DOT__DM__DOT__mem_array__v3;
    CData/*0:0*/ __Vdlyvset__top__DOT__DM__DOT__mem_array__v3;
    IData/*16:0*/ __Vdlyvdim0__top__DOT__DM__DOT__mem_array__v4;
    CData/*7:0*/ __Vdlyvval__top__DOT__DM__DOT__mem_array__v4;
    IData/*16:0*/ __Vdlyvdim0__top__DOT__DM__DOT__mem_array__v5;
    CData/*7:0*/ __Vdlyvval__top__DOT__DM__DOT__mem_array__v5;
    IData/*16:0*/ __Vdlyvdim0__top__DOT__DM__DOT__mem_array__v6;
    CData/*7:0*/ __Vdlyvval__top__DOT__DM__DOT__mem_array__v6;
    // Body
    __Vdlyvset__top__DOT__DM__DOT__mem_array__v0 = 0U;
    __Vdlyvset__top__DOT__DM__DOT__mem_array__v1 = 0U;
    __Vdlyvset__top__DOT__DM__DOT__mem_array__v3 = 0U;
    __Vdlyvset__top__DOT__RF__DOT__regs__v0 = 0U;
    if (vlSelf->top__DOT__MemWrite) {
        if ((0U == (IData)(vlSelf->top__DOT__MemWriteSize))) {
            __Vdlyvval__top__DOT__DM__DOT__mem_array__v0 
                = (0xffU & vlSelf->top__DOT__RD2);
            __Vdlyvset__top__DOT__DM__DOT__mem_array__v0 = 1U;
            __Vdlyvdim0__top__DOT__DM__DOT__mem_array__v0 
                = (0x1ffffU & vlSelf->top__DOT__ALUout);
        } else if ((1U == (IData)(vlSelf->top__DOT__MemWriteSize))) {
            __Vdlyvval__top__DOT__DM__DOT__mem_array__v1 
                = (0xffU & vlSelf->top__DOT__RD2);
            __Vdlyvset__top__DOT__DM__DOT__mem_array__v1 = 1U;
            __Vdlyvdim0__top__DOT__DM__DOT__mem_array__v1 
                = (0x1ffffU & vlSelf->top__DOT__ALUout);
            __Vdlyvval__top__DOT__DM__DOT__mem_array__v2 
                = (0xffU & (vlSelf->top__DOT__RD2 >> 8U));
            __Vdlyvdim0__top__DOT__DM__DOT__mem_array__v2 
                = (0x1ffffU & ((IData)(1U) + vlSelf->top__DOT__ALUout));
        } else if ((2U == (IData)(vlSelf->top__DOT__MemWriteSize))) {
            __Vdlyvval__top__DOT__DM__DOT__mem_array__v3 
                = (0xffU & vlSelf->top__DOT__RD2);
            __Vdlyvset__top__DOT__DM__DOT__mem_array__v3 = 1U;
            __Vdlyvdim0__top__DOT__DM__DOT__mem_array__v3 
                = (0x1ffffU & vlSelf->top__DOT__ALUout);
            __Vdlyvval__top__DOT__DM__DOT__mem_array__v4 
                = (0xffU & (vlSelf->top__DOT__RD2 >> 8U));
            __Vdlyvdim0__top__DOT__DM__DOT__mem_array__v4 
                = (0x1ffffU & ((IData)(1U) + vlSelf->top__DOT__ALUout));
            __Vdlyvval__top__DOT__DM__DOT__mem_array__v5 
                = (0xffU & (vlSelf->top__DOT__RD2 >> 0x10U));
            __Vdlyvdim0__top__DOT__DM__DOT__mem_array__v5 
                = (0x1ffffU & ((IData)(2U) + vlSelf->top__DOT__ALUout));
            __Vdlyvval__top__DOT__DM__DOT__mem_array__v6 
                = (vlSelf->top__DOT__RD2 >> 0x18U);
            __Vdlyvdim0__top__DOT__DM__DOT__mem_array__v6 
                = (0x1ffffU & ((IData)(3U) + vlSelf->top__DOT__ALUout));
        }
    }
    if (((IData)(vlSelf->top__DOT__RegWrite) & (0U 
                                                != 
                                                (0x1fU 
                                                 & (vlSelf->top__DOT__instr 
                                                    >> 7U))))) {
        __Vdlyvval__top__DOT__RF__DOT__regs__v0 = (
                                                   (2U 
                                                    & (IData)(vlSelf->top__DOT__ResultSrc))
                                                    ? 
                                                   ((1U 
                                                     & (IData)(vlSelf->top__DOT__ResultSrc))
                                                     ? vlSelf->top__DOT__ImmOp
                                                     : 
                                                    ((IData)(4U) 
                                                     + vlSelf->top__DOT__pc))
                                                    : 
                                                   ((1U 
                                                     & (IData)(vlSelf->top__DOT__ResultSrc))
                                                     ? 
                                                    ((0x4000U 
                                                      & vlSelf->top__DOT__instr)
                                                      ? 
                                                     ((0x2000U 
                                                       & vlSelf->top__DOT__instr)
                                                       ? 0U
                                                       : 
                                                      ((0x1000U 
                                                        & vlSelf->top__DOT__instr)
                                                        ? 
                                                       (0xffffU 
                                                        & vlSelf->top__DOT__ReadData)
                                                        : 
                                                       (0xffU 
                                                        & vlSelf->top__DOT__ReadData)))
                                                      : 
                                                     ((0x2000U 
                                                       & vlSelf->top__DOT__instr)
                                                       ? 
                                                      ((0x1000U 
                                                        & vlSelf->top__DOT__instr)
                                                        ? 0U
                                                        : vlSelf->top__DOT__ReadData)
                                                       : 
                                                      ((0x1000U 
                                                        & vlSelf->top__DOT__instr)
                                                        ? 
                                                       (((- (IData)(
                                                                    (1U 
                                                                     & (vlSelf->top__DOT__ReadData 
                                                                        >> 0xfU)))) 
                                                         << 0x10U) 
                                                        | (0xffffU 
                                                           & vlSelf->top__DOT__ReadData))
                                                        : 
                                                       (((- (IData)(
                                                                    (1U 
                                                                     & (vlSelf->top__DOT__ReadData 
                                                                        >> 7U)))) 
                                                         << 8U) 
                                                        | (0xffU 
                                                           & vlSelf->top__DOT__ReadData)))))
                                                     : vlSelf->top__DOT__ALUout));
        __Vdlyvset__top__DOT__RF__DOT__regs__v0 = 1U;
        __Vdlyvdim0__top__DOT__RF__DOT__regs__v0 = 
            (0x1fU & (vlSelf->top__DOT__instr >> 7U));
    }
    if (__Vdlyvset__top__DOT__DM__DOT__mem_array__v0) {
        vlSelf->top__DOT__DM__DOT__mem_array[__Vdlyvdim0__top__DOT__DM__DOT__mem_array__v0] 
            = __Vdlyvval__top__DOT__DM__DOT__mem_array__v0;
    }
    if (__Vdlyvset__top__DOT__DM__DOT__mem_array__v1) {
        vlSelf->top__DOT__DM__DOT__mem_array[__Vdlyvdim0__top__DOT__DM__DOT__mem_array__v1] 
            = __Vdlyvval__top__DOT__DM__DOT__mem_array__v1;
        vlSelf->top__DOT__DM__DOT__mem_array[__Vdlyvdim0__top__DOT__DM__DOT__mem_array__v2] 
            = __Vdlyvval__top__DOT__DM__DOT__mem_array__v2;
    }
    if (__Vdlyvset__top__DOT__DM__DOT__mem_array__v3) {
        vlSelf->top__DOT__DM__DOT__mem_array[__Vdlyvdim0__top__DOT__DM__DOT__mem_array__v3] 
            = __Vdlyvval__top__DOT__DM__DOT__mem_array__v3;
        vlSelf->top__DOT__DM__DOT__mem_array[__Vdlyvdim0__top__DOT__DM__DOT__mem_array__v4] 
            = __Vdlyvval__top__DOT__DM__DOT__mem_array__v4;
        vlSelf->top__DOT__DM__DOT__mem_array[__Vdlyvdim0__top__DOT__DM__DOT__mem_array__v5] 
            = __Vdlyvval__top__DOT__DM__DOT__mem_array__v5;
        vlSelf->top__DOT__DM__DOT__mem_array[__Vdlyvdim0__top__DOT__DM__DOT__mem_array__v6] 
            = __Vdlyvval__top__DOT__DM__DOT__mem_array__v6;
    }
    if (__Vdlyvset__top__DOT__RF__DOT__regs__v0) {
        vlSelf->top__DOT__RF__DOT__regs[__Vdlyvdim0__top__DOT__RF__DOT__regs__v0] 
            = __Vdlyvval__top__DOT__RF__DOT__regs__v0;
    }
    vlSelf->a0 = vlSelf->top__DOT__RF__DOT__regs[0xaU];
    vlSelf->x0 = vlSelf->top__DOT__RF__DOT__regs[0U];
    vlSelf->t0 = vlSelf->top__DOT__RF__DOT__regs[5U];
    vlSelf->t1 = vlSelf->top__DOT__RF__DOT__regs[6U];
    vlSelf->t3 = vlSelf->top__DOT__RF__DOT__regs[0x1cU];
    vlSelf->t4 = vlSelf->top__DOT__RF__DOT__regs[0x1dU];
    vlSelf->a1 = vlSelf->top__DOT__RF__DOT__regs[0xbU];
    vlSelf->a2 = vlSelf->top__DOT__RF__DOT__regs[0xcU];
    vlSelf->a3 = vlSelf->top__DOT__RF__DOT__regs[0xdU];
    vlSelf->a4 = vlSelf->top__DOT__RF__DOT__regs[0xeU];
    vlSelf->a5 = vlSelf->top__DOT__RF__DOT__regs[0xfU];
    vlSelf->a6 = vlSelf->top__DOT__RF__DOT__regs[0x10U];
    vlSelf->top__DOT__pc = ((IData)(vlSelf->rst) ? 0U
                             : vlSelf->top__DOT__next_pc);
    vlSelf->top__DOT__instr = ((((0x3e7U >= (0x3ffU 
                                             & ((IData)(3U) 
                                                + vlSelf->top__DOT__pc)))
                                  ? vlSelf->top__DOT__IMEM__DOT__memory
                                 [(0x3ffU & ((IData)(3U) 
                                             + vlSelf->top__DOT__pc))]
                                  : 0U) << 0x18U) | 
                               ((((0x3e7U >= (0x3ffU 
                                              & ((IData)(2U) 
                                                 + vlSelf->top__DOT__pc)))
                                   ? vlSelf->top__DOT__IMEM__DOT__memory
                                  [(0x3ffU & ((IData)(2U) 
                                              + vlSelf->top__DOT__pc))]
                                   : 0U) << 0x10U) 
                                | ((((0x3e7U >= (0x3ffU 
                                                 & ((IData)(1U) 
                                                    + vlSelf->top__DOT__pc)))
                                      ? vlSelf->top__DOT__IMEM__DOT__memory
                                     [(0x3ffU & ((IData)(1U) 
                                                 + vlSelf->top__DOT__pc))]
                                      : 0U) << 8U) 
                                   | ((0x3e7U >= (0x3ffU 
                                                  & vlSelf->top__DOT__pc))
                                       ? vlSelf->top__DOT__IMEM__DOT__memory
                                      [(0x3ffU & vlSelf->top__DOT__pc)]
                                       : 0U))));
    vlSelf->top__DOT__RD1 = vlSelf->top__DOT__RF__DOT__regs
        [(0x1fU & (vlSelf->top__DOT__instr >> 0xfU))];
    vlSelf->top__DOT__RD2 = vlSelf->top__DOT__RF__DOT__regs
        [(0x1fU & (vlSelf->top__DOT__instr >> 0x14U))];
    vlSelf->top__DOT__ImmSrc = 0U;
    if (((((((((0x33U == (0x7fU & vlSelf->top__DOT__instr)) 
               | (0x67U == (0x7fU & vlSelf->top__DOT__instr))) 
              | (3U == (0x7fU & vlSelf->top__DOT__instr))) 
             | (0x13U == (0x7fU & vlSelf->top__DOT__instr))) 
            | (0x37U == (0x7fU & vlSelf->top__DOT__instr))) 
           | (0x23U == (0x7fU & vlSelf->top__DOT__instr))) 
          | (0x63U == (0x7fU & vlSelf->top__DOT__instr))) 
         | (0x6fU == (0x7fU & vlSelf->top__DOT__instr)))) {
        if ((0x33U == (0x7fU & vlSelf->top__DOT__instr))) {
            if ((0U == (7U & (vlSelf->top__DOT__instr 
                              >> 0xcU)))) {
                vlSelf->top__DOT__ResultSrc = 0U;
                vlSelf->top__DOT__RegWrite = 1U;
                vlSelf->top__DOT__MemWrite = 0U;
                vlSelf->top__DOT__ALUctrl = ((0x40000000U 
                                              & vlSelf->top__DOT__instr)
                                              ? 1U : 0U);
                vlSelf->top__DOT__ALUSrc = 0U;
            }
        } else {
            if ((0x67U == (0x7fU & vlSelf->top__DOT__instr))) {
                vlSelf->top__DOT__ResultSrc = 2U;
                vlSelf->top__DOT__ALUctrl = 0U;
                vlSelf->top__DOT__ALUSrc = 1U;
            } else if ((3U == (0x7fU & vlSelf->top__DOT__instr))) {
                vlSelf->top__DOT__ResultSrc = 1U;
                vlSelf->top__DOT__ALUctrl = 0U;
                vlSelf->top__DOT__ALUSrc = 1U;
            } else if ((0x13U == (0x7fU & vlSelf->top__DOT__instr))) {
                vlSelf->top__DOT__ResultSrc = 0U;
                if ((0U == (7U & (vlSelf->top__DOT__instr 
                                  >> 0xcU)))) {
                    vlSelf->top__DOT__ALUctrl = 0U;
                }
                if ((6U == (7U & (vlSelf->top__DOT__instr 
                                  >> 0xcU)))) {
                    vlSelf->top__DOT__ALUctrl = 6U;
                }
                vlSelf->top__DOT__ALUSrc = 1U;
            } else {
                if ((0x37U == (0x7fU & vlSelf->top__DOT__instr))) {
                    vlSelf->top__DOT__ResultSrc = 3U;
                } else if ((0x23U != (0x7fU & vlSelf->top__DOT__instr))) {
                    if ((0x63U != (0x7fU & vlSelf->top__DOT__instr))) {
                        vlSelf->top__DOT__ResultSrc = 2U;
                    }
                }
                if ((0x37U != (0x7fU & vlSelf->top__DOT__instr))) {
                    if ((0x23U == (0x7fU & vlSelf->top__DOT__instr))) {
                        vlSelf->top__DOT__ALUctrl = 0U;
                        vlSelf->top__DOT__ALUSrc = 1U;
                    } else if ((0x63U == (0x7fU & vlSelf->top__DOT__instr))) {
                        if ((1U == (7U & (vlSelf->top__DOT__instr 
                                          >> 0xcU)))) {
                            vlSelf->top__DOT__ALUctrl = 1U;
                        }
                        if ((0U == (7U & (vlSelf->top__DOT__instr 
                                          >> 0xcU)))) {
                            vlSelf->top__DOT__ALUctrl = 1U;
                        }
                        vlSelf->top__DOT__ALUSrc = 0U;
                    }
                }
            }
            vlSelf->top__DOT__RegWrite = ((0x67U == 
                                           (0x7fU & vlSelf->top__DOT__instr)) 
                                          | ((3U == 
                                              (0x7fU 
                                               & vlSelf->top__DOT__instr)) 
                                             | ((0x13U 
                                                 == 
                                                 (0x7fU 
                                                  & vlSelf->top__DOT__instr)) 
                                                | ((0x37U 
                                                    == 
                                                    (0x7fU 
                                                     & vlSelf->top__DOT__instr)) 
                                                   | ((0x23U 
                                                       != 
                                                       (0x7fU 
                                                        & vlSelf->top__DOT__instr)) 
                                                      & (0x63U 
                                                         != 
                                                         (0x7fU 
                                                          & vlSelf->top__DOT__instr)))))));
            vlSelf->top__DOT__MemWrite = ((0x67U != 
                                           (0x7fU & vlSelf->top__DOT__instr)) 
                                          & ((3U != 
                                              (0x7fU 
                                               & vlSelf->top__DOT__instr)) 
                                             & ((0x13U 
                                                 != 
                                                 (0x7fU 
                                                  & vlSelf->top__DOT__instr)) 
                                                & ((0x37U 
                                                    != 
                                                    (0x7fU 
                                                     & vlSelf->top__DOT__instr)) 
                                                   & (0x23U 
                                                      == 
                                                      (0x7fU 
                                                       & vlSelf->top__DOT__instr))))));
        }
        if ((0x33U != (0x7fU & vlSelf->top__DOT__instr))) {
            if ((0x67U != (0x7fU & vlSelf->top__DOT__instr))) {
                if ((3U != (0x7fU & vlSelf->top__DOT__instr))) {
                    if ((0x13U != (0x7fU & vlSelf->top__DOT__instr))) {
                        if ((0x37U != (0x7fU & vlSelf->top__DOT__instr))) {
                            if ((0x23U == (0x7fU & vlSelf->top__DOT__instr))) {
                                vlSelf->top__DOT__MemWriteSize = 0U;
                            }
                        }
                    }
                }
            }
            vlSelf->top__DOT__ImmSrc = ((0x67U == (0x7fU 
                                                   & vlSelf->top__DOT__instr))
                                         ? 0U : ((3U 
                                                  == 
                                                  (0x7fU 
                                                   & vlSelf->top__DOT__instr))
                                                  ? 0U
                                                  : 
                                                 ((0x13U 
                                                   == 
                                                   (0x7fU 
                                                    & vlSelf->top__DOT__instr))
                                                   ? 0U
                                                   : 
                                                  ((0x37U 
                                                    == 
                                                    (0x7fU 
                                                     & vlSelf->top__DOT__instr))
                                                    ? 4U
                                                    : 
                                                   ((0x23U 
                                                     == 
                                                     (0x7fU 
                                                      & vlSelf->top__DOT__instr))
                                                     ? 1U
                                                     : 
                                                    ((0x63U 
                                                      == 
                                                      (0x7fU 
                                                       & vlSelf->top__DOT__instr))
                                                      ? 2U
                                                      : 3U))))));
        }
    }
    vlSelf->top__DOT__ImmOp = ((4U & (IData)(vlSelf->top__DOT__ImmSrc))
                                ? ((2U & (IData)(vlSelf->top__DOT__ImmSrc))
                                    ? 0U : ((1U & (IData)(vlSelf->top__DOT__ImmSrc))
                                             ? 0U : 
                                            (0xfffff000U 
                                             & vlSelf->top__DOT__instr)))
                                : ((2U & (IData)(vlSelf->top__DOT__ImmSrc))
                                    ? ((1U & (IData)(vlSelf->top__DOT__ImmSrc))
                                        ? (((- (IData)(
                                                       (vlSelf->top__DOT__instr 
                                                        >> 0x1fU))) 
                                            << 0x15U) 
                                           | ((0x100000U 
                                               & (vlSelf->top__DOT__instr 
                                                  >> 0xbU)) 
                                              | ((0xff000U 
                                                  & vlSelf->top__DOT__instr) 
                                                 | ((0x800U 
                                                     & (vlSelf->top__DOT__instr 
                                                        >> 9U)) 
                                                    | (0x7feU 
                                                       & (vlSelf->top__DOT__instr 
                                                          >> 0x14U))))))
                                        : (((- (IData)(
                                                       (vlSelf->top__DOT__instr 
                                                        >> 0x1fU))) 
                                            << 0xdU) 
                                           | ((0x1000U 
                                               & (vlSelf->top__DOT__instr 
                                                  >> 0x13U)) 
                                              | ((0x800U 
                                                  & (vlSelf->top__DOT__instr 
                                                     << 4U)) 
                                                 | ((0x7e0U 
                                                     & (vlSelf->top__DOT__instr 
                                                        >> 0x14U)) 
                                                    | (0x1eU 
                                                       & (vlSelf->top__DOT__instr 
                                                          >> 7U)))))))
                                    : ((1U & (IData)(vlSelf->top__DOT__ImmSrc))
                                        ? (((- (IData)(
                                                       (vlSelf->top__DOT__instr 
                                                        >> 0x1fU))) 
                                            << 0xcU) 
                                           | ((0xfe0U 
                                               & (vlSelf->top__DOT__instr 
                                                  >> 0x14U)) 
                                              | (0x1fU 
                                                 & (vlSelf->top__DOT__instr 
                                                    >> 7U))))
                                        : (((- (IData)(
                                                       (vlSelf->top__DOT__instr 
                                                        >> 0x1fU))) 
                                            << 0xcU) 
                                           | (vlSelf->top__DOT__instr 
                                              >> 0x14U)))));
    vlSelf->top__DOT__ALUop2 = ((IData)(vlSelf->top__DOT__ALUSrc)
                                 ? vlSelf->top__DOT__ImmOp
                                 : vlSelf->top__DOT__RD2);
    vlSelf->top__DOT__ALUout = ((4U & (IData)(vlSelf->top__DOT__ALUctrl))
                                 ? ((2U & (IData)(vlSelf->top__DOT__ALUctrl))
                                     ? ((1U & (IData)(vlSelf->top__DOT__ALUctrl))
                                         ? (vlSelf->top__DOT__RD1 
                                            & vlSelf->top__DOT__ALUop2)
                                         : (vlSelf->top__DOT__RD1 
                                            | vlSelf->top__DOT__ALUop2))
                                     : ((1U & (IData)(vlSelf->top__DOT__ALUctrl))
                                         ? 0U : (vlSelf->top__DOT__RD1 
                                                 ^ vlSelf->top__DOT__ALUop2)))
                                 : ((2U & (IData)(vlSelf->top__DOT__ALUctrl))
                                     ? 0U : ((1U & (IData)(vlSelf->top__DOT__ALUctrl))
                                              ? (vlSelf->top__DOT__RD1 
                                                 - vlSelf->top__DOT__ALUop2)
                                              : (vlSelf->top__DOT__RD1 
                                                 + vlSelf->top__DOT__ALUop2))));
    vlSelf->top__DOT__Zero = (0U == vlSelf->top__DOT__ALUout);
    vlSelf->top__DOT__ReadData = ((vlSelf->top__DOT__DM__DOT__mem_array
                                   [(0x1ffffU & ((IData)(3U) 
                                                 + vlSelf->top__DOT__ALUout))] 
                                   << 0x18U) | ((vlSelf->top__DOT__DM__DOT__mem_array
                                                 [(0x1ffffU 
                                                   & ((IData)(2U) 
                                                      + vlSelf->top__DOT__ALUout))] 
                                                 << 0x10U) 
                                                | ((vlSelf->top__DOT__DM__DOT__mem_array
                                                    [
                                                    (0x1ffffU 
                                                     & ((IData)(1U) 
                                                        + vlSelf->top__DOT__ALUout))] 
                                                    << 8U) 
                                                   | vlSelf->top__DOT__DM__DOT__mem_array
                                                   [
                                                   (0x1ffffU 
                                                    & vlSelf->top__DOT__ALUout)])));
    vlSelf->top__DOT__PCSrc = 0U;
    if (((((((((0x33U == (0x7fU & vlSelf->top__DOT__instr)) 
               | (0x67U == (0x7fU & vlSelf->top__DOT__instr))) 
              | (3U == (0x7fU & vlSelf->top__DOT__instr))) 
             | (0x13U == (0x7fU & vlSelf->top__DOT__instr))) 
            | (0x37U == (0x7fU & vlSelf->top__DOT__instr))) 
           | (0x23U == (0x7fU & vlSelf->top__DOT__instr))) 
          | (0x63U == (0x7fU & vlSelf->top__DOT__instr))) 
         | (0x6fU == (0x7fU & vlSelf->top__DOT__instr)))) {
        if ((0x33U != (0x7fU & vlSelf->top__DOT__instr))) {
            if ((0x67U == (0x7fU & vlSelf->top__DOT__instr))) {
                vlSelf->top__DOT__PCSrc = 2U;
            } else if ((3U != (0x7fU & vlSelf->top__DOT__instr))) {
                if ((0x13U != (0x7fU & vlSelf->top__DOT__instr))) {
                    if ((0x37U != (0x7fU & vlSelf->top__DOT__instr))) {
                        if ((0x23U != (0x7fU & vlSelf->top__DOT__instr))) {
                            if ((0x63U == (0x7fU & vlSelf->top__DOT__instr))) {
                                if ((1U == (7U & (vlSelf->top__DOT__instr 
                                                  >> 0xcU)))) {
                                    if ((1U & (~ (IData)(vlSelf->top__DOT__Zero)))) {
                                        vlSelf->top__DOT__PCSrc = 1U;
                                    }
                                }
                                if ((0U == (7U & (vlSelf->top__DOT__instr 
                                                  >> 0xcU)))) {
                                    if (vlSelf->top__DOT__Zero) {
                                        vlSelf->top__DOT__PCSrc = 1U;
                                    }
                                }
                            } else {
                                vlSelf->top__DOT__PCSrc = 1U;
                            }
                        }
                    }
                }
            }
        }
    }
    vlSelf->top__DOT__next_pc = ((2U & (IData)(vlSelf->top__DOT__PCSrc))
                                  ? ((1U & (IData)(vlSelf->top__DOT__PCSrc))
                                      ? 0U : (0xfffffffeU 
                                              & vlSelf->top__DOT__ALUout))
                                  : ((1U & (IData)(vlSelf->top__DOT__PCSrc))
                                      ? (vlSelf->top__DOT__pc 
                                         + vlSelf->top__DOT__ImmOp)
                                      : ((IData)(4U) 
                                         + vlSelf->top__DOT__pc)));
}

void Vdut___024root___eval(Vdut___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vdut__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdut___024root___eval\n"); );
    // Body
    if (((IData)(vlSelf->clk) & (~ (IData)(vlSelf->__Vclklast__TOP__clk)))) {
        Vdut___024root___sequent__TOP__0(vlSelf);
        vlSelf->__Vm_traceActivity[1U] = 1U;
    }
    // Final
    vlSelf->__Vclklast__TOP__clk = vlSelf->clk;
}

#ifdef VL_DEBUG
void Vdut___024root___eval_debug_assertions(Vdut___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vdut__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdut___024root___eval_debug_assertions\n"); );
    // Body
    if (VL_UNLIKELY((vlSelf->clk & 0xfeU))) {
        Verilated::overWidthError("clk");}
    if (VL_UNLIKELY((vlSelf->rst & 0xfeU))) {
        Verilated::overWidthError("rst");}
    if (VL_UNLIKELY((vlSelf->trigger & 0xfeU))) {
        Verilated::overWidthError("trigger");}
}
#endif  // VL_DEBUG
