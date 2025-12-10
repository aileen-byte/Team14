// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "Vdut__Syms.h"


void Vdut___024root__trace_chg_sub_0(Vdut___024root* vlSelf, VerilatedVcd::Buffer* bufp);

void Vdut___024root__trace_chg_top_0(void* voidSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdut___024root__trace_chg_top_0\n"); );
    // Init
    Vdut___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vdut___024root*>(voidSelf);
    Vdut__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    if (VL_UNLIKELY(!vlSymsp->__Vm_activity)) return;
    // Body
    Vdut___024root__trace_chg_sub_0((&vlSymsp->TOP), bufp);
}

void Vdut___024root__trace_chg_sub_0(Vdut___024root* vlSelf, VerilatedVcd::Buffer* bufp) {
    if (false && vlSelf) {}  // Prevent unused
    Vdut__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdut___024root__trace_chg_sub_0\n"); );
    // Init
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode + 1);
    // Body
    if (VL_UNLIKELY(vlSelf->__Vm_traceActivity[1U])) {
        bufp->chgCData(oldp+0,(vlSelf->top__DOT__PCSrc),2);
        bufp->chgIData(oldp+1,(((IData)(4U) + vlSelf->top__DOT__pc)),32);
        bufp->chgIData(oldp+2,((vlSelf->top__DOT__pc 
                                + vlSelf->top__DOT__ImmOp)),32);
        bufp->chgIData(oldp+3,(((2U & (IData)(vlSelf->top__DOT__PCSrc))
                                 ? ((1U & (IData)(vlSelf->top__DOT__PCSrc))
                                     ? 0U : (0xfffffffeU 
                                             & vlSelf->top__DOT__ALUout))
                                 : ((1U & (IData)(vlSelf->top__DOT__PCSrc))
                                     ? (vlSelf->top__DOT__pc 
                                        + vlSelf->top__DOT__ImmOp)
                                     : ((IData)(4U) 
                                        + vlSelf->top__DOT__pc)))),32);
        bufp->chgIData(oldp+4,(vlSelf->top__DOT__pc),32);
        bufp->chgIData(oldp+5,(vlSelf->top__DOT__instr),32);
        bufp->chgBit(oldp+6,(vlSelf->top__DOT__RegWrite));
        bufp->chgCData(oldp+7,(vlSelf->top__DOT__ALUctrl),3);
        bufp->chgBit(oldp+8,(vlSelf->top__DOT__ALUSrc));
        bufp->chgCData(oldp+9,(vlSelf->top__DOT__ImmSrc),3);
        bufp->chgCData(oldp+10,(vlSelf->top__DOT__ResultSrc),2);
        bufp->chgBit(oldp+11,(vlSelf->top__DOT__MemWrite));
        bufp->chgCData(oldp+12,(vlSelf->top__DOT__MemWriteSize),2);
        bufp->chgCData(oldp+13,(vlSelf->top__DOT__LoadSize),2);
        bufp->chgBit(oldp+14,(vlSelf->top__DOT__Zero));
        bufp->chgIData(oldp+15,(((2U & (IData)(vlSelf->top__DOT__ResultSrc))
                                  ? ((1U & (IData)(vlSelf->top__DOT__ResultSrc))
                                      ? vlSelf->top__DOT__ImmOp
                                      : ((IData)(4U) 
                                         + vlSelf->top__DOT__pc))
                                  : ((1U & (IData)(vlSelf->top__DOT__ResultSrc))
                                      ? ((0U == (IData)(vlSelf->top__DOT__LoadSize))
                                          ? (IData)(vlSelf->top__DOT__LS__DOT__selected_byte)
                                          : ((1U == (IData)(vlSelf->top__DOT__LoadSize))
                                              ? (((- (IData)(
                                                             (1U 
                                                              & ((IData)(vlSelf->top__DOT__LS__DOT__selected_byte) 
                                                                 >> 7U)))) 
                                                  << 8U) 
                                                 | (IData)(vlSelf->top__DOT__LS__DOT__selected_byte))
                                              : ((2U 
                                                  == (IData)(vlSelf->top__DOT__LoadSize))
                                                  ? vlSelf->top__DOT__ReadData
                                                  : 0U)))
                                      : vlSelf->top__DOT__ALUout))),32);
        bufp->chgIData(oldp+16,(vlSelf->top__DOT__RD1),32);
        bufp->chgIData(oldp+17,(vlSelf->top__DOT__RD2),32);
        bufp->chgIData(oldp+18,(vlSelf->top__DOT__ReadData),32);
        bufp->chgIData(oldp+19,(((0U == (IData)(vlSelf->top__DOT__LoadSize))
                                  ? (IData)(vlSelf->top__DOT__LS__DOT__selected_byte)
                                  : ((1U == (IData)(vlSelf->top__DOT__LoadSize))
                                      ? (((- (IData)(
                                                     (1U 
                                                      & ((IData)(vlSelf->top__DOT__LS__DOT__selected_byte) 
                                                         >> 7U)))) 
                                          << 8U) | (IData)(vlSelf->top__DOT__LS__DOT__selected_byte))
                                      : ((2U == (IData)(vlSelf->top__DOT__LoadSize))
                                          ? vlSelf->top__DOT__ReadData
                                          : 0U)))),32);
        bufp->chgIData(oldp+20,(vlSelf->top__DOT__ALUop2),32);
        bufp->chgIData(oldp+21,(vlSelf->top__DOT__ALUout),32);
        bufp->chgIData(oldp+22,(vlSelf->top__DOT__ImmOp),32);
        bufp->chgIData(oldp+23,((0xfffffffeU & vlSelf->top__DOT__ALUout)),32);
        bufp->chgCData(oldp+24,((0x7fU & vlSelf->top__DOT__instr)),7);
        bufp->chgCData(oldp+25,((7U & (vlSelf->top__DOT__instr 
                                       >> 0xcU))),3);
        bufp->chgBit(oldp+26,((1U & (vlSelf->top__DOT__instr 
                                     >> 0x1eU))));
        bufp->chgIData(oldp+27,((0xfffffffcU & vlSelf->top__DOT__ALUout)),32);
        bufp->chgCData(oldp+28,((3U & vlSelf->top__DOT__ALUout)),2);
        bufp->chgCData(oldp+29,(vlSelf->top__DOT__LS__DOT__selected_byte),8);
        bufp->chgCData(oldp+30,((0x1fU & (vlSelf->top__DOT__instr 
                                          >> 0xfU))),5);
        bufp->chgCData(oldp+31,((0x1fU & (vlSelf->top__DOT__instr 
                                          >> 0x14U))),5);
        bufp->chgCData(oldp+32,((0x1fU & (vlSelf->top__DOT__instr 
                                          >> 7U))),5);
        bufp->chgIData(oldp+33,(vlSelf->top__DOT__RF__DOT__regs[0]),32);
        bufp->chgIData(oldp+34,(vlSelf->top__DOT__RF__DOT__regs[1]),32);
        bufp->chgIData(oldp+35,(vlSelf->top__DOT__RF__DOT__regs[2]),32);
        bufp->chgIData(oldp+36,(vlSelf->top__DOT__RF__DOT__regs[3]),32);
        bufp->chgIData(oldp+37,(vlSelf->top__DOT__RF__DOT__regs[4]),32);
        bufp->chgIData(oldp+38,(vlSelf->top__DOT__RF__DOT__regs[5]),32);
        bufp->chgIData(oldp+39,(vlSelf->top__DOT__RF__DOT__regs[6]),32);
        bufp->chgIData(oldp+40,(vlSelf->top__DOT__RF__DOT__regs[7]),32);
        bufp->chgIData(oldp+41,(vlSelf->top__DOT__RF__DOT__regs[8]),32);
        bufp->chgIData(oldp+42,(vlSelf->top__DOT__RF__DOT__regs[9]),32);
        bufp->chgIData(oldp+43,(vlSelf->top__DOT__RF__DOT__regs[10]),32);
        bufp->chgIData(oldp+44,(vlSelf->top__DOT__RF__DOT__regs[11]),32);
        bufp->chgIData(oldp+45,(vlSelf->top__DOT__RF__DOT__regs[12]),32);
        bufp->chgIData(oldp+46,(vlSelf->top__DOT__RF__DOT__regs[13]),32);
        bufp->chgIData(oldp+47,(vlSelf->top__DOT__RF__DOT__regs[14]),32);
        bufp->chgIData(oldp+48,(vlSelf->top__DOT__RF__DOT__regs[15]),32);
        bufp->chgIData(oldp+49,(vlSelf->top__DOT__RF__DOT__regs[16]),32);
        bufp->chgIData(oldp+50,(vlSelf->top__DOT__RF__DOT__regs[17]),32);
        bufp->chgIData(oldp+51,(vlSelf->top__DOT__RF__DOT__regs[18]),32);
        bufp->chgIData(oldp+52,(vlSelf->top__DOT__RF__DOT__regs[19]),32);
        bufp->chgIData(oldp+53,(vlSelf->top__DOT__RF__DOT__regs[20]),32);
        bufp->chgIData(oldp+54,(vlSelf->top__DOT__RF__DOT__regs[21]),32);
        bufp->chgIData(oldp+55,(vlSelf->top__DOT__RF__DOT__regs[22]),32);
        bufp->chgIData(oldp+56,(vlSelf->top__DOT__RF__DOT__regs[23]),32);
        bufp->chgIData(oldp+57,(vlSelf->top__DOT__RF__DOT__regs[24]),32);
        bufp->chgIData(oldp+58,(vlSelf->top__DOT__RF__DOT__regs[25]),32);
        bufp->chgIData(oldp+59,(vlSelf->top__DOT__RF__DOT__regs[26]),32);
        bufp->chgIData(oldp+60,(vlSelf->top__DOT__RF__DOT__regs[27]),32);
        bufp->chgIData(oldp+61,(vlSelf->top__DOT__RF__DOT__regs[28]),32);
        bufp->chgIData(oldp+62,(vlSelf->top__DOT__RF__DOT__regs[29]),32);
        bufp->chgIData(oldp+63,(vlSelf->top__DOT__RF__DOT__regs[30]),32);
        bufp->chgIData(oldp+64,(vlSelf->top__DOT__RF__DOT__regs[31]),32);
        bufp->chgIData(oldp+65,((vlSelf->top__DOT__instr 
                                 >> 7U)),25);
    }
    bufp->chgBit(oldp+66,(vlSelf->clk));
    bufp->chgBit(oldp+67,(vlSelf->rst));
    bufp->chgBit(oldp+68,(vlSelf->trigger));
    bufp->chgIData(oldp+69,(vlSelf->x0),32);
    bufp->chgIData(oldp+70,(vlSelf->t0),32);
    bufp->chgIData(oldp+71,(vlSelf->t1),32);
    bufp->chgIData(oldp+72,(vlSelf->t2),32);
    bufp->chgIData(oldp+73,(vlSelf->t3),32);
    bufp->chgIData(oldp+74,(vlSelf->t4),32);
    bufp->chgIData(oldp+75,(vlSelf->a1),32);
    bufp->chgIData(oldp+76,(vlSelf->a2),32);
    bufp->chgIData(oldp+77,(vlSelf->a3),32);
    bufp->chgIData(oldp+78,(vlSelf->a4),32);
    bufp->chgIData(oldp+79,(vlSelf->a5),32);
    bufp->chgIData(oldp+80,(vlSelf->a6),32);
    bufp->chgIData(oldp+81,(vlSelf->a0),32);
}

void Vdut___024root__trace_cleanup(void* voidSelf, VerilatedVcd* /*unused*/) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdut___024root__trace_cleanup\n"); );
    // Init
    Vdut___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vdut___024root*>(voidSelf);
    Vdut__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    // Body
    vlSymsp->__Vm_activity = false;
    vlSymsp->TOP.__Vm_traceActivity[0U] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[1U] = 0U;
}
