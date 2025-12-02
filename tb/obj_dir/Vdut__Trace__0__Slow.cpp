// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "Vdut__Syms.h"


VL_ATTR_COLD void Vdut___024root__trace_init_sub__TOP__0(Vdut___024root* vlSelf, VerilatedVcd* tracep) {
    if (false && vlSelf) {}  // Prevent unused
    Vdut__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdut___024root__trace_init_sub__TOP__0\n"); );
    // Init
    const int c = vlSymsp->__Vm_baseCode;
    // Body
    tracep->declBit(c+55,"clk", false,-1);
    tracep->declBit(c+56,"rst", false,-1);
    tracep->declBus(c+57,"t1", false,-1, 31,0);
    tracep->declBus(c+58,"t2", false,-1, 31,0);
    tracep->declBus(c+59,"t3", false,-1, 31,0);
    tracep->declBit(c+60,"Zero", false,-1);
    tracep->declBus(c+61,"pc", false,-1, 31,0);
    tracep->declBus(c+62,"a0", false,-1, 31,0);
    tracep->pushNamePrefix("top ");
    tracep->declBus(c+67,"DATA_WIDTH", false,-1, 31,0);
    tracep->declBit(c+55,"clk", false,-1);
    tracep->declBit(c+56,"rst", false,-1);
    tracep->declBus(c+57,"t1", false,-1, 31,0);
    tracep->declBus(c+58,"t2", false,-1, 31,0);
    tracep->declBus(c+59,"t3", false,-1, 31,0);
    tracep->declBit(c+60,"Zero", false,-1);
    tracep->declBus(c+61,"pc", false,-1, 31,0);
    tracep->declBus(c+62,"a0", false,-1, 31,0);
    tracep->declBus(c+1,"PCSrc", false,-1, 1,0);
    tracep->declBus(c+63,"inc_pc", false,-1, 31,0);
    tracep->declBus(c+64,"branch_pc", false,-1, 31,0);
    tracep->declBus(c+65,"next_pc", false,-1, 31,0);
    tracep->declBus(c+2,"instr", false,-1, 31,0);
    tracep->declBit(c+3,"RegWrite", false,-1);
    tracep->declBus(c+4,"ALUctrl", false,-1, 2,0);
    tracep->declBit(c+5,"ALUSrc", false,-1);
    tracep->declBus(c+6,"ImmSrc", false,-1, 2,0);
    tracep->declBus(c+7,"ResultSrc", false,-1, 1,0);
    tracep->declBit(c+8,"MemWrite", false,-1);
    tracep->declBus(c+66,"WD3", false,-1, 31,0);
    tracep->declBus(c+9,"RD1", false,-1, 31,0);
    tracep->declBus(c+10,"RD2", false,-1, 31,0);
    tracep->declBus(c+11,"ReadData", false,-1, 31,0);
    tracep->declBus(c+12,"ALUop2", false,-1, 31,0);
    tracep->declBus(c+13,"ALUout", false,-1, 31,0);
    tracep->declBus(c+14,"ImmOp", false,-1, 31,0);
    tracep->declBus(c+15,"jalrPC", false,-1, 31,0);
    tracep->pushNamePrefix("ADD4 ");
    tracep->declBus(c+67,"DATA_WIDTH", false,-1, 31,0);
    tracep->declBus(c+61,"pc", false,-1, 31,0);
    tracep->declBus(c+63,"inc_pc", false,-1, 31,0);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("ALUMUX ");
    tracep->declBus(c+67,"DATA_WIDTH", false,-1, 31,0);
    tracep->declBus(c+10,"in0", false,-1, 31,0);
    tracep->declBus(c+14,"in1", false,-1, 31,0);
    tracep->declBit(c+5,"sel", false,-1);
    tracep->declBus(c+12,"out", false,-1, 31,0);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("BRADD ");
    tracep->declBus(c+67,"DATA_WIDTH", false,-1, 31,0);
    tracep->declBus(c+61,"pc", false,-1, 31,0);
    tracep->declBus(c+14,"ImmOp", false,-1, 31,0);
    tracep->declBus(c+64,"branch_pc", false,-1, 31,0);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("CU ");
    tracep->declBus(c+16,"op", false,-1, 6,0);
    tracep->declBus(c+17,"funct3", false,-1, 2,0);
    tracep->declBit(c+18,"funct7b5", false,-1);
    tracep->declBit(c+60,"Zero", false,-1);
    tracep->declBus(c+1,"PCSrc", false,-1, 1,0);
    tracep->declBus(c+7,"ResultSrc", false,-1, 1,0);
    tracep->declBit(c+8,"MemWrite", false,-1);
    tracep->declBus(c+4,"ALUctrl", false,-1, 2,0);
    tracep->declBit(c+5,"ALUSrc", false,-1);
    tracep->declBus(c+6,"ImmSrc", false,-1, 2,0);
    tracep->declBit(c+3,"RegWrite", false,-1);
    tracep->declBus(c+68,"ALU_ADD", false,-1, 2,0);
    tracep->declBus(c+69,"ALU_SUB", false,-1, 2,0);
    tracep->declBus(c+70,"ALU_ORI", false,-1, 2,0);
    tracep->declBus(c+68,"I_TYPE", false,-1, 2,0);
    tracep->declBus(c+69,"S_TYPE", false,-1, 2,0);
    tracep->declBus(c+71,"B_TYPE", false,-1, 2,0);
    tracep->declBus(c+72,"J_TYPE", false,-1, 2,0);
    tracep->declBus(c+73,"U_TYPE", false,-1, 2,0);
    tracep->declBus(c+74,"ALU", false,-1, 1,0);
    tracep->declBus(c+75,"Memory", false,-1, 1,0);
    tracep->declBus(c+76,"PCPlus4", false,-1, 1,0);
    tracep->declBus(c+77,"UpperImmediate", false,-1, 1,0);
    tracep->declBus(c+74,"Normal", false,-1, 1,0);
    tracep->declBus(c+75,"Immediate", false,-1, 1,0);
    tracep->declBus(c+76,"JALR", false,-1, 1,0);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("DM ");
    tracep->declBus(c+67,"DATA_WIDTH", false,-1, 31,0);
    tracep->declBus(c+78,"MEMORY_WIDTH", false,-1, 31,0);
    tracep->declBit(c+55,"clk", false,-1);
    tracep->declBus(c+13,"ALUResult", false,-1, 31,0);
    tracep->declBus(c+10,"WriteData", false,-1, 31,0);
    tracep->declBit(c+8,"WE", false,-1);
    tracep->declBus(c+11,"RD", false,-1, 31,0);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("IMEM ");
    tracep->declBus(c+67,"DATA_WIDTH", false,-1, 31,0);
    tracep->declBus(c+78,"MEMORY_WIDTH", false,-1, 31,0);
    tracep->declBus(c+61,"A", false,-1, 31,0);
    tracep->declBus(c+2,"RD", false,-1, 31,0);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("PCMUX ");
    tracep->declBus(c+67,"DATA_WIDTH", false,-1, 31,0);
    tracep->declBus(c+63,"in0", false,-1, 31,0);
    tracep->declBus(c+64,"in1", false,-1, 31,0);
    tracep->declBus(c+15,"in2", false,-1, 31,0);
    tracep->declBus(c+79,"in3", false,-1, 31,0);
    tracep->declBus(c+1,"sel", false,-1, 1,0);
    tracep->declBus(c+65,"out", false,-1, 31,0);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("PCREG ");
    tracep->declBus(c+67,"DATA_WIDTH", false,-1, 31,0);
    tracep->declBit(c+55,"clk", false,-1);
    tracep->declBit(c+56,"rst", false,-1);
    tracep->declBus(c+65,"next_pc", false,-1, 31,0);
    tracep->declBus(c+61,"pc", false,-1, 31,0);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("RESULT_MUX ");
    tracep->declBus(c+67,"DATA_WIDTH", false,-1, 31,0);
    tracep->declBus(c+13,"in0", false,-1, 31,0);
    tracep->declBus(c+11,"in1", false,-1, 31,0);
    tracep->declBus(c+63,"in2", false,-1, 31,0);
    tracep->declBus(c+14,"in3", false,-1, 31,0);
    tracep->declBus(c+7,"sel", false,-1, 1,0);
    tracep->declBus(c+66,"out", false,-1, 31,0);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("RF ");
    tracep->declBus(c+67,"DATA_WIDTH", false,-1, 31,0);
    tracep->declBit(c+55,"clk", false,-1);
    tracep->declBus(c+19,"AD1", false,-1, 4,0);
    tracep->declBus(c+20,"AD2", false,-1, 4,0);
    tracep->declBus(c+21,"AD3", false,-1, 4,0);
    tracep->declBit(c+3,"WE3", false,-1);
    tracep->declBus(c+66,"WD3", false,-1, 31,0);
    tracep->declBus(c+9,"RD1", false,-1, 31,0);
    tracep->declBus(c+10,"RD2", false,-1, 31,0);
    tracep->declBus(c+57,"t1", false,-1, 31,0);
    tracep->declBus(c+58,"t2", false,-1, 31,0);
    tracep->declBus(c+59,"t3", false,-1, 31,0);
    tracep->declBus(c+62,"a0", false,-1, 31,0);
    for (int i = 0; i < 32; ++i) {
        tracep->declBus(c+22+i*1,"regs", true,(i+0), 31,0);
    }
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("SE ");
    tracep->declBus(c+54,"instr", false,-1, 31,7);
    tracep->declBus(c+6,"ImmSrc", false,-1, 2,0);
    tracep->declBus(c+14,"ImmOp", false,-1, 31,0);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("jalr ");
    tracep->declBus(c+67,"DATA_WIDTH", false,-1, 31,0);
    tracep->declBus(c+13,"ALUPC", false,-1, 31,0);
    tracep->declBus(c+15,"jalrPC", false,-1, 31,0);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("myALU ");
    tracep->declBus(c+67,"DATA_WIDTH", false,-1, 31,0);
    tracep->declBus(c+9,"ALUop1", false,-1, 31,0);
    tracep->declBus(c+12,"ALUop2", false,-1, 31,0);
    tracep->declBus(c+4,"ALUctrl", false,-1, 2,0);
    tracep->declBus(c+13,"ALUout", false,-1, 31,0);
    tracep->declBit(c+60,"Zero", false,-1);
    tracep->popNamePrefix(2);
}

VL_ATTR_COLD void Vdut___024root__trace_init_top(Vdut___024root* vlSelf, VerilatedVcd* tracep) {
    if (false && vlSelf) {}  // Prevent unused
    Vdut__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdut___024root__trace_init_top\n"); );
    // Body
    Vdut___024root__trace_init_sub__TOP__0(vlSelf, tracep);
}

VL_ATTR_COLD void Vdut___024root__trace_full_top_0(void* voidSelf, VerilatedVcd::Buffer* bufp);
void Vdut___024root__trace_chg_top_0(void* voidSelf, VerilatedVcd::Buffer* bufp);
void Vdut___024root__trace_cleanup(void* voidSelf, VerilatedVcd* /*unused*/);

VL_ATTR_COLD void Vdut___024root__trace_register(Vdut___024root* vlSelf, VerilatedVcd* tracep) {
    if (false && vlSelf) {}  // Prevent unused
    Vdut__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdut___024root__trace_register\n"); );
    // Body
    tracep->addFullCb(&Vdut___024root__trace_full_top_0, vlSelf);
    tracep->addChgCb(&Vdut___024root__trace_chg_top_0, vlSelf);
    tracep->addCleanupCb(&Vdut___024root__trace_cleanup, vlSelf);
}

VL_ATTR_COLD void Vdut___024root__trace_full_sub_0(Vdut___024root* vlSelf, VerilatedVcd::Buffer* bufp);

VL_ATTR_COLD void Vdut___024root__trace_full_top_0(void* voidSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdut___024root__trace_full_top_0\n"); );
    // Init
    Vdut___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vdut___024root*>(voidSelf);
    Vdut__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    // Body
    Vdut___024root__trace_full_sub_0((&vlSymsp->TOP), bufp);
}

VL_ATTR_COLD void Vdut___024root__trace_full_sub_0(Vdut___024root* vlSelf, VerilatedVcd::Buffer* bufp) {
    if (false && vlSelf) {}  // Prevent unused
    Vdut__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdut___024root__trace_full_sub_0\n"); );
    // Init
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode);
    // Body
    bufp->fullCData(oldp+1,(vlSelf->top__DOT__PCSrc),2);
    bufp->fullIData(oldp+2,(vlSelf->top__DOT__instr),32);
    bufp->fullBit(oldp+3,(vlSelf->top__DOT__RegWrite));
    bufp->fullCData(oldp+4,(vlSelf->top__DOT__ALUctrl),3);
    bufp->fullBit(oldp+5,(vlSelf->top__DOT__ALUSrc));
    bufp->fullCData(oldp+6,(vlSelf->top__DOT__ImmSrc),3);
    bufp->fullCData(oldp+7,(vlSelf->top__DOT__ResultSrc),2);
    bufp->fullBit(oldp+8,(vlSelf->top__DOT__MemWrite));
    bufp->fullIData(oldp+9,(vlSelf->top__DOT__RD1),32);
    bufp->fullIData(oldp+10,(vlSelf->top__DOT__RD2),32);
    bufp->fullIData(oldp+11,(((((0x63U >= (0x7fU & 
                                           ((IData)(3U) 
                                            + vlSelf->top__DOT__ALUout)))
                                 ? vlSelf->top__DOT__DM__DOT__mem_array
                                [(0x7fU & ((IData)(3U) 
                                           + vlSelf->top__DOT__ALUout))]
                                 : 0U) << 0x18U) | 
                              ((((0x63U >= (0x7fU & 
                                            ((IData)(2U) 
                                             + vlSelf->top__DOT__ALUout)))
                                  ? vlSelf->top__DOT__DM__DOT__mem_array
                                 [(0x7fU & ((IData)(2U) 
                                            + vlSelf->top__DOT__ALUout))]
                                  : 0U) << 0x10U) | 
                               ((((0x63U >= (0x7fU 
                                             & ((IData)(1U) 
                                                + vlSelf->top__DOT__ALUout)))
                                   ? vlSelf->top__DOT__DM__DOT__mem_array
                                  [(0x7fU & ((IData)(1U) 
                                             + vlSelf->top__DOT__ALUout))]
                                   : 0U) << 8U) | (
                                                   (0x63U 
                                                    >= 
                                                    (0x7fU 
                                                     & vlSelf->top__DOT__ALUout))
                                                    ? 
                                                   vlSelf->top__DOT__DM__DOT__mem_array
                                                   [
                                                   (0x7fU 
                                                    & vlSelf->top__DOT__ALUout)]
                                                    : 0U))))),32);
    bufp->fullIData(oldp+12,(vlSelf->top__DOT__ALUop2),32);
    bufp->fullIData(oldp+13,(vlSelf->top__DOT__ALUout),32);
    bufp->fullIData(oldp+14,(vlSelf->top__DOT__ImmOp),32);
    bufp->fullIData(oldp+15,((0xfffffffeU & vlSelf->top__DOT__ALUout)),32);
    bufp->fullCData(oldp+16,((0x7fU & vlSelf->top__DOT__instr)),7);
    bufp->fullCData(oldp+17,((7U & (vlSelf->top__DOT__instr 
                                    >> 0xcU))),3);
    bufp->fullBit(oldp+18,((1U & (vlSelf->top__DOT__instr 
                                  >> 0x1eU))));
    bufp->fullCData(oldp+19,((0x1fU & (vlSelf->top__DOT__instr 
                                       >> 0xfU))),5);
    bufp->fullCData(oldp+20,((0x1fU & (vlSelf->top__DOT__instr 
                                       >> 0x14U))),5);
    bufp->fullCData(oldp+21,((0x1fU & (vlSelf->top__DOT__instr 
                                       >> 7U))),5);
    bufp->fullIData(oldp+22,(vlSelf->top__DOT__RF__DOT__regs[0]),32);
    bufp->fullIData(oldp+23,(vlSelf->top__DOT__RF__DOT__regs[1]),32);
    bufp->fullIData(oldp+24,(vlSelf->top__DOT__RF__DOT__regs[2]),32);
    bufp->fullIData(oldp+25,(vlSelf->top__DOT__RF__DOT__regs[3]),32);
    bufp->fullIData(oldp+26,(vlSelf->top__DOT__RF__DOT__regs[4]),32);
    bufp->fullIData(oldp+27,(vlSelf->top__DOT__RF__DOT__regs[5]),32);
    bufp->fullIData(oldp+28,(vlSelf->top__DOT__RF__DOT__regs[6]),32);
    bufp->fullIData(oldp+29,(vlSelf->top__DOT__RF__DOT__regs[7]),32);
    bufp->fullIData(oldp+30,(vlSelf->top__DOT__RF__DOT__regs[8]),32);
    bufp->fullIData(oldp+31,(vlSelf->top__DOT__RF__DOT__regs[9]),32);
    bufp->fullIData(oldp+32,(vlSelf->top__DOT__RF__DOT__regs[10]),32);
    bufp->fullIData(oldp+33,(vlSelf->top__DOT__RF__DOT__regs[11]),32);
    bufp->fullIData(oldp+34,(vlSelf->top__DOT__RF__DOT__regs[12]),32);
    bufp->fullIData(oldp+35,(vlSelf->top__DOT__RF__DOT__regs[13]),32);
    bufp->fullIData(oldp+36,(vlSelf->top__DOT__RF__DOT__regs[14]),32);
    bufp->fullIData(oldp+37,(vlSelf->top__DOT__RF__DOT__regs[15]),32);
    bufp->fullIData(oldp+38,(vlSelf->top__DOT__RF__DOT__regs[16]),32);
    bufp->fullIData(oldp+39,(vlSelf->top__DOT__RF__DOT__regs[17]),32);
    bufp->fullIData(oldp+40,(vlSelf->top__DOT__RF__DOT__regs[18]),32);
    bufp->fullIData(oldp+41,(vlSelf->top__DOT__RF__DOT__regs[19]),32);
    bufp->fullIData(oldp+42,(vlSelf->top__DOT__RF__DOT__regs[20]),32);
    bufp->fullIData(oldp+43,(vlSelf->top__DOT__RF__DOT__regs[21]),32);
    bufp->fullIData(oldp+44,(vlSelf->top__DOT__RF__DOT__regs[22]),32);
    bufp->fullIData(oldp+45,(vlSelf->top__DOT__RF__DOT__regs[23]),32);
    bufp->fullIData(oldp+46,(vlSelf->top__DOT__RF__DOT__regs[24]),32);
    bufp->fullIData(oldp+47,(vlSelf->top__DOT__RF__DOT__regs[25]),32);
    bufp->fullIData(oldp+48,(vlSelf->top__DOT__RF__DOT__regs[26]),32);
    bufp->fullIData(oldp+49,(vlSelf->top__DOT__RF__DOT__regs[27]),32);
    bufp->fullIData(oldp+50,(vlSelf->top__DOT__RF__DOT__regs[28]),32);
    bufp->fullIData(oldp+51,(vlSelf->top__DOT__RF__DOT__regs[29]),32);
    bufp->fullIData(oldp+52,(vlSelf->top__DOT__RF__DOT__regs[30]),32);
    bufp->fullIData(oldp+53,(vlSelf->top__DOT__RF__DOT__regs[31]),32);
    bufp->fullIData(oldp+54,((vlSelf->top__DOT__instr 
                              >> 7U)),25);
    bufp->fullBit(oldp+55,(vlSelf->clk));
    bufp->fullBit(oldp+56,(vlSelf->rst));
    bufp->fullIData(oldp+57,(vlSelf->t1),32);
    bufp->fullIData(oldp+58,(vlSelf->t2),32);
    bufp->fullIData(oldp+59,(vlSelf->t3),32);
    bufp->fullBit(oldp+60,(vlSelf->Zero));
    bufp->fullIData(oldp+61,(vlSelf->pc),32);
    bufp->fullIData(oldp+62,(vlSelf->a0),32);
    bufp->fullIData(oldp+63,(((IData)(4U) + vlSelf->pc)),32);
    bufp->fullIData(oldp+64,((vlSelf->pc + vlSelf->top__DOT__ImmOp)),32);
    bufp->fullIData(oldp+65,(((2U & (IData)(vlSelf->top__DOT__PCSrc))
                               ? ((1U & (IData)(vlSelf->top__DOT__PCSrc))
                                   ? 0U : (0xfffffffeU 
                                           & vlSelf->top__DOT__ALUout))
                               : ((1U & (IData)(vlSelf->top__DOT__PCSrc))
                                   ? (vlSelf->pc + vlSelf->top__DOT__ImmOp)
                                   : ((IData)(4U) + vlSelf->pc)))),32);
    bufp->fullIData(oldp+66,(((2U & (IData)(vlSelf->top__DOT__ResultSrc))
                               ? ((1U & (IData)(vlSelf->top__DOT__ResultSrc))
                                   ? vlSelf->top__DOT__ImmOp
                                   : ((IData)(4U) + vlSelf->pc))
                               : ((1U & (IData)(vlSelf->top__DOT__ResultSrc))
                                   ? ((((0x63U >= (0x7fU 
                                                   & ((IData)(3U) 
                                                      + vlSelf->top__DOT__ALUout)))
                                         ? vlSelf->top__DOT__DM__DOT__mem_array
                                        [(0x7fU & ((IData)(3U) 
                                                   + vlSelf->top__DOT__ALUout))]
                                         : 0U) << 0x18U) 
                                      | ((((0x63U >= 
                                            (0x7fU 
                                             & ((IData)(2U) 
                                                + vlSelf->top__DOT__ALUout)))
                                            ? vlSelf->top__DOT__DM__DOT__mem_array
                                           [(0x7fU 
                                             & ((IData)(2U) 
                                                + vlSelf->top__DOT__ALUout))]
                                            : 0U) << 0x10U) 
                                         | ((((0x63U 
                                               >= (0x7fU 
                                                   & ((IData)(1U) 
                                                      + vlSelf->top__DOT__ALUout)))
                                               ? vlSelf->top__DOT__DM__DOT__mem_array
                                              [(0x7fU 
                                                & ((IData)(1U) 
                                                   + vlSelf->top__DOT__ALUout))]
                                               : 0U) 
                                             << 8U) 
                                            | ((0x63U 
                                                >= 
                                                (0x7fU 
                                                 & vlSelf->top__DOT__ALUout))
                                                ? vlSelf->top__DOT__DM__DOT__mem_array
                                               [(0x7fU 
                                                 & vlSelf->top__DOT__ALUout)]
                                                : 0U))))
                                   : vlSelf->top__DOT__ALUout))),32);
    bufp->fullIData(oldp+67,(0x20U),32);
    bufp->fullCData(oldp+68,(0U),3);
    bufp->fullCData(oldp+69,(1U),3);
    bufp->fullCData(oldp+70,(6U),3);
    bufp->fullCData(oldp+71,(2U),3);
    bufp->fullCData(oldp+72,(3U),3);
    bufp->fullCData(oldp+73,(4U),3);
    bufp->fullCData(oldp+74,(0U),2);
    bufp->fullCData(oldp+75,(1U),2);
    bufp->fullCData(oldp+76,(2U),2);
    bufp->fullCData(oldp+77,(3U),2);
    bufp->fullIData(oldp+78,(0x64U),32);
    bufp->fullIData(oldp+79,(0U),32);
}
