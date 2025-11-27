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
    CData/*0:0*/ __Vdlyvdim0__top__DOT__DM__DOT__mem_array__v0;
    IData/*31:0*/ __Vdlyvval__top__DOT__DM__DOT__mem_array__v0;
    CData/*0:0*/ __Vdlyvset__top__DOT__DM__DOT__mem_array__v0;
    // Body
    __Vdlyvset__top__DOT__DM__DOT__mem_array__v0 = 0U;
    __Vdlyvset__top__DOT__RF__DOT__regs__v0 = 0U;
    if (vlSelf->top__DOT__MemWrite) {
        __Vdlyvval__top__DOT__DM__DOT__mem_array__v0 
            = vlSelf->top__DOT__RD2;
        __Vdlyvset__top__DOT__DM__DOT__mem_array__v0 = 1U;
        __Vdlyvdim0__top__DOT__DM__DOT__mem_array__v0 
            = (1U & ((IData)(1U) + vlSelf->top__DOT__ALUout));
    }
    if (vlSelf->top__DOT__RegWrite) {
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
                                                    vlSelf->top__DOT__DM__DOT__mem_array
                                                    [
                                                    (1U 
                                                     & ((IData)(1U) 
                                                        + vlSelf->top__DOT__ALUout))]
                                                     : vlSelf->top__DOT__ALUout));
        __Vdlyvset__top__DOT__RF__DOT__regs__v0 = 1U;
        __Vdlyvdim0__top__DOT__RF__DOT__regs__v0 = 
            (0x1fU & (vlSelf->top__DOT__instr >> 7U));
    }
    if (__Vdlyvset__top__DOT__DM__DOT__mem_array__v0) {
        vlSelf->top__DOT__DM__DOT__mem_array[__Vdlyvdim0__top__DOT__DM__DOT__mem_array__v0] 
            = __Vdlyvval__top__DOT__DM__DOT__mem_array__v0;
    }
    if (__Vdlyvset__top__DOT__RF__DOT__regs__v0) {
        vlSelf->top__DOT__RF__DOT__regs[__Vdlyvdim0__top__DOT__RF__DOT__regs__v0] 
            = __Vdlyvval__top__DOT__RF__DOT__regs__v0;
    }
    vlSelf->a0 = vlSelf->top__DOT__RF__DOT__regs[0xaU];
    vlSelf->top__DOT__pc = ((IData)(vlSelf->rst) ? 0U
                             : vlSelf->top__DOT__next_pc);
    vlSelf->top__DOT__instr = ((0x64U >= (0x7fU & (vlSelf->top__DOT__pc 
                                                   >> 2U)))
                                ? vlSelf->top__DOT__IMEM__DOT__memory
                               [(0x7fU & (vlSelf->top__DOT__pc 
                                          >> 2U))] : 0U);
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
    vlSelf->top__DOT__Zero = 0U;
    if ((4U & (IData)(vlSelf->top__DOT__ALUctrl))) {
        vlSelf->top__DOT__ALUout = ((2U & (IData)(vlSelf->top__DOT__ALUctrl))
                                     ? 0U : ((1U & (IData)(vlSelf->top__DOT__ALUctrl))
                                              ? 0U : 
                                             (vlSelf->top__DOT__RD1 
                                              ^ vlSelf->top__DOT__ALUop2)));
    } else if ((2U & (IData)(vlSelf->top__DOT__ALUctrl))) {
        vlSelf->top__DOT__ALUout = ((1U & (IData)(vlSelf->top__DOT__ALUctrl))
                                     ? (vlSelf->top__DOT__RD1 
                                        | vlSelf->top__DOT__ALUop2)
                                     : (vlSelf->top__DOT__RD1 
                                        & vlSelf->top__DOT__ALUop2));
    } else if ((1U & (IData)(vlSelf->top__DOT__ALUctrl))) {
        vlSelf->top__DOT__ALUout = (vlSelf->top__DOT__RD1 
                                    - vlSelf->top__DOT__ALUop2);
        vlSelf->top__DOT__Zero = (0U == vlSelf->top__DOT__ALUout);
    } else {
        vlSelf->top__DOT__ALUout = (vlSelf->top__DOT__RD1 
                                    + vlSelf->top__DOT__ALUop2);
    }
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
}
#endif  // VL_DEBUG
