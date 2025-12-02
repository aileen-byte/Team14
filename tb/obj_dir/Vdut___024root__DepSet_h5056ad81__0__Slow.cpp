// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vdut.h for the primary calling header

#include "verilated.h"

#include "Vdut___024root.h"

VL_ATTR_COLD void Vdut___024root___initial__TOP__0(Vdut___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vdut__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdut___024root___initial__TOP__0\n"); );
    // Init
    VlWide<5>/*159:0*/ __Vtemp_hbdd2015e__0;
    // Body
    __Vtemp_hbdd2015e__0[0U] = 0x2e686578U;
    __Vtemp_hbdd2015e__0[1U] = 0x6772616dU;
    __Vtemp_hbdd2015e__0[2U] = 0x2f70726fU;
    __Vtemp_hbdd2015e__0[3U] = 0x2f72746cU;
    __Vtemp_hbdd2015e__0[4U] = 0x2e2eU;
    VL_READMEM_N(true, 8, 100, 0, VL_CVT_PACK_STR_NW(5, __Vtemp_hbdd2015e__0)
                 ,  &(vlSelf->top__DOT__IMEM__DOT__memory)
                 , 0, ~0ULL);
}

VL_ATTR_COLD void Vdut___024root___settle__TOP__0(Vdut___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vdut__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdut___024root___settle__TOP__0\n"); );
    // Body
    vlSelf->a0 = vlSelf->top__DOT__RF__DOT__regs[0xaU];
    vlSelf->t1 = vlSelf->top__DOT__RF__DOT__regs[6U];
    vlSelf->t2 = vlSelf->top__DOT__RF__DOT__regs[7U];
    vlSelf->t3 = vlSelf->top__DOT__RF__DOT__regs[0x1cU];
    vlSelf->top__DOT__instr = ((((0x63U >= (0x7fU & 
                                            ((IData)(3U) 
                                             + vlSelf->pc)))
                                  ? vlSelf->top__DOT__IMEM__DOT__memory
                                 [(0x7fU & ((IData)(3U) 
                                            + vlSelf->pc))]
                                  : 0U) << 0x18U) | 
                               ((((0x63U >= (0x7fU 
                                             & ((IData)(2U) 
                                                + vlSelf->pc)))
                                   ? vlSelf->top__DOT__IMEM__DOT__memory
                                  [(0x7fU & ((IData)(2U) 
                                             + vlSelf->pc))]
                                   : 0U) << 0x10U) 
                                | ((((0x63U >= (0x7fU 
                                                & ((IData)(1U) 
                                                   + vlSelf->pc)))
                                      ? vlSelf->top__DOT__IMEM__DOT__memory
                                     [(0x7fU & ((IData)(1U) 
                                                + vlSelf->pc))]
                                      : 0U) << 8U) 
                                   | ((0x63U >= (0x7fU 
                                                 & vlSelf->pc))
                                       ? vlSelf->top__DOT__IMEM__DOT__memory
                                      [(0x7fU & vlSelf->pc)]
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
                                         ? 0U : (vlSelf->top__DOT__RD1 
                                                 | vlSelf->top__DOT__ALUop2))
                                     : ((1U & (IData)(vlSelf->top__DOT__ALUctrl))
                                         ? 0U : (vlSelf->top__DOT__RD1 
                                                 ^ vlSelf->top__DOT__ALUop2)))
                                 : ((2U & (IData)(vlSelf->top__DOT__ALUctrl))
                                     ? ((1U & (IData)(vlSelf->top__DOT__ALUctrl))
                                         ? (vlSelf->top__DOT__RD1 
                                            | vlSelf->top__DOT__ALUop2)
                                         : (vlSelf->top__DOT__RD1 
                                            & vlSelf->top__DOT__ALUop2))
                                     : ((1U & (IData)(vlSelf->top__DOT__ALUctrl))
                                         ? (vlSelf->top__DOT__RD1 
                                            - vlSelf->top__DOT__ALUop2)
                                         : (vlSelf->top__DOT__RD1 
                                            + vlSelf->top__DOT__ALUop2))));
    vlSelf->Zero = (0U == vlSelf->top__DOT__ALUout);
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
                                    if ((1U & (~ (IData)(vlSelf->Zero)))) {
                                        vlSelf->top__DOT__PCSrc = 1U;
                                    }
                                }
                                if ((0U == (7U & (vlSelf->top__DOT__instr 
                                                  >> 0xcU)))) {
                                    if (vlSelf->Zero) {
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
                                      ? (vlSelf->pc 
                                         + vlSelf->top__DOT__ImmOp)
                                      : ((IData)(4U) 
                                         + vlSelf->pc)));
}

VL_ATTR_COLD void Vdut___024root___eval_initial(Vdut___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vdut__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdut___024root___eval_initial\n"); );
    // Body
    Vdut___024root___initial__TOP__0(vlSelf);
    vlSelf->__Vclklast__TOP__clk = vlSelf->clk;
}

VL_ATTR_COLD void Vdut___024root___eval_settle(Vdut___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vdut__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdut___024root___eval_settle\n"); );
    // Body
    Vdut___024root___settle__TOP__0(vlSelf);
    vlSelf->__Vm_traceActivity[1U] = 1U;
    vlSelf->__Vm_traceActivity[0U] = 1U;
}

VL_ATTR_COLD void Vdut___024root___final(Vdut___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vdut__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdut___024root___final\n"); );
}

VL_ATTR_COLD void Vdut___024root___ctor_var_reset(Vdut___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vdut__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdut___024root___ctor_var_reset\n"); );
    // Body
    vlSelf->clk = VL_RAND_RESET_I(1);
    vlSelf->rst = VL_RAND_RESET_I(1);
    vlSelf->t1 = VL_RAND_RESET_I(32);
    vlSelf->t2 = VL_RAND_RESET_I(32);
    vlSelf->t3 = VL_RAND_RESET_I(32);
    vlSelf->Zero = VL_RAND_RESET_I(1);
    vlSelf->pc = VL_RAND_RESET_I(32);
    vlSelf->a0 = VL_RAND_RESET_I(32);
    vlSelf->top__DOT__PCSrc = VL_RAND_RESET_I(2);
    vlSelf->top__DOT__next_pc = VL_RAND_RESET_I(32);
    vlSelf->top__DOT__instr = VL_RAND_RESET_I(32);
    vlSelf->top__DOT__RegWrite = VL_RAND_RESET_I(1);
    vlSelf->top__DOT__ALUctrl = VL_RAND_RESET_I(3);
    vlSelf->top__DOT__ALUSrc = VL_RAND_RESET_I(1);
    vlSelf->top__DOT__ImmSrc = VL_RAND_RESET_I(3);
    vlSelf->top__DOT__ResultSrc = VL_RAND_RESET_I(2);
    vlSelf->top__DOT__MemWrite = VL_RAND_RESET_I(1);
    vlSelf->top__DOT__RD1 = VL_RAND_RESET_I(32);
    vlSelf->top__DOT__RD2 = VL_RAND_RESET_I(32);
    vlSelf->top__DOT__ALUop2 = VL_RAND_RESET_I(32);
    vlSelf->top__DOT__ALUout = VL_RAND_RESET_I(32);
    vlSelf->top__DOT__ImmOp = VL_RAND_RESET_I(32);
    for (int __Vi0=0; __Vi0<100; ++__Vi0) {
        vlSelf->top__DOT__IMEM__DOT__memory[__Vi0] = VL_RAND_RESET_I(8);
    }
    for (int __Vi0=0; __Vi0<32; ++__Vi0) {
        vlSelf->top__DOT__RF__DOT__regs[__Vi0] = VL_RAND_RESET_I(32);
    }
    for (int __Vi0=0; __Vi0<100; ++__Vi0) {
        vlSelf->top__DOT__DM__DOT__mem_array[__Vi0] = VL_RAND_RESET_I(8);
    }
    vlSelf->top__DOT__DM__DOT____Vlvbound_h51e3f0c4__0 = VL_RAND_RESET_I(8);
    vlSelf->top__DOT__DM__DOT____Vlvbound_h35022570__0 = VL_RAND_RESET_I(8);
    vlSelf->top__DOT__DM__DOT____Vlvbound_h35021543__0 = VL_RAND_RESET_I(8);
    vlSelf->top__DOT__DM__DOT____Vlvbound_h3501834e__0 = VL_RAND_RESET_I(8);
    for (int __Vi0=0; __Vi0<2; ++__Vi0) {
        vlSelf->__Vm_traceActivity[__Vi0] = VL_RAND_RESET_I(1);
    }
}
