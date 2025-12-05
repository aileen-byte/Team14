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
    tracep->declBit(c+64,"clk", false,-1);
    tracep->declBit(c+65,"rst", false,-1);
    tracep->declBit(c+66,"trigger", false,-1);
    tracep->declBus(c+67,"x0", false,-1, 31,0);
    tracep->declBus(c+68,"t0", false,-1, 31,0);
    tracep->declBus(c+69,"t1", false,-1, 31,0);
    tracep->declBus(c+70,"t3", false,-1, 31,0);
    tracep->declBus(c+71,"t4", false,-1, 31,0);
    tracep->declBus(c+72,"a1", false,-1, 31,0);
    tracep->declBus(c+73,"a2", false,-1, 31,0);
    tracep->declBus(c+74,"a3", false,-1, 31,0);
    tracep->declBus(c+75,"a4", false,-1, 31,0);
    tracep->declBus(c+76,"a5", false,-1, 31,0);
    tracep->declBus(c+77,"a6", false,-1, 31,0);
    tracep->declBus(c+78,"a0", false,-1, 31,0);
    tracep->pushNamePrefix("top ");
    tracep->declBus(c+79,"DATA_WIDTH", false,-1, 31,0);
    tracep->declBit(c+64,"clk", false,-1);
    tracep->declBit(c+65,"rst", false,-1);
    tracep->declBit(c+66,"trigger", false,-1);
    tracep->declBus(c+67,"x0", false,-1, 31,0);
    tracep->declBus(c+68,"t0", false,-1, 31,0);
    tracep->declBus(c+69,"t1", false,-1, 31,0);
    tracep->declBus(c+70,"t3", false,-1, 31,0);
    tracep->declBus(c+71,"t4", false,-1, 31,0);
    tracep->declBus(c+72,"a1", false,-1, 31,0);
    tracep->declBus(c+73,"a2", false,-1, 31,0);
    tracep->declBus(c+74,"a3", false,-1, 31,0);
    tracep->declBus(c+75,"a4", false,-1, 31,0);
    tracep->declBus(c+76,"a5", false,-1, 31,0);
    tracep->declBus(c+77,"a6", false,-1, 31,0);
    tracep->declBus(c+78,"a0", false,-1, 31,0);
    tracep->declBus(c+1,"PCSrc", false,-1, 1,0);
    tracep->declBus(c+2,"inc_pc", false,-1, 31,0);
    tracep->declBus(c+3,"branch_pc", false,-1, 31,0);
    tracep->declBus(c+4,"next_pc", false,-1, 31,0);
    tracep->declBus(c+5,"pc", false,-1, 31,0);
    tracep->declBus(c+6,"instr", false,-1, 31,0);
    tracep->declBit(c+7,"RegWrite", false,-1);
    tracep->declBus(c+8,"ALUctrl", false,-1, 2,0);
    tracep->declBit(c+9,"ALUSrc", false,-1);
    tracep->declBus(c+10,"ImmSrc", false,-1, 2,0);
    tracep->declBus(c+11,"ResultSrc", false,-1, 1,0);
    tracep->declBit(c+12,"MemWrite", false,-1);
    tracep->declBus(c+13,"MemWriteSize", false,-1, 1,0);
    tracep->declBit(c+14,"Zero", false,-1);
    tracep->declBus(c+15,"WD3", false,-1, 31,0);
    tracep->declBus(c+16,"RD1", false,-1, 31,0);
    tracep->declBus(c+17,"RD2", false,-1, 31,0);
    tracep->declBus(c+18,"ReadData", false,-1, 31,0);
    tracep->declBus(c+19,"load_data", false,-1, 31,0);
    tracep->declBus(c+20,"ALUop2", false,-1, 31,0);
    tracep->declBus(c+21,"ALUout", false,-1, 31,0);
    tracep->declBus(c+22,"ImmOp", false,-1, 31,0);
    tracep->declBus(c+23,"jalrPC", false,-1, 31,0);
    tracep->pushNamePrefix("ADD4 ");
    tracep->declBus(c+79,"DATA_WIDTH", false,-1, 31,0);
    tracep->declBus(c+5,"pc", false,-1, 31,0);
    tracep->declBus(c+2,"inc_pc", false,-1, 31,0);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("ALUMUX ");
    tracep->declBus(c+79,"DATA_WIDTH", false,-1, 31,0);
    tracep->declBus(c+17,"in0", false,-1, 31,0);
    tracep->declBus(c+22,"in1", false,-1, 31,0);
    tracep->declBit(c+9,"sel", false,-1);
    tracep->declBus(c+20,"out", false,-1, 31,0);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("BRADD ");
    tracep->declBus(c+79,"DATA_WIDTH", false,-1, 31,0);
    tracep->declBus(c+5,"pc", false,-1, 31,0);
    tracep->declBus(c+22,"ImmOp", false,-1, 31,0);
    tracep->declBus(c+3,"branch_pc", false,-1, 31,0);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("CU ");
    tracep->declBus(c+24,"op", false,-1, 6,0);
    tracep->declBus(c+25,"funct3", false,-1, 2,0);
    tracep->declBit(c+26,"funct7b5", false,-1);
    tracep->declBit(c+14,"Zero", false,-1);
    tracep->declBus(c+1,"PCSrc", false,-1, 1,0);
    tracep->declBus(c+11,"ResultSrc", false,-1, 1,0);
    tracep->declBit(c+12,"MemWrite", false,-1);
    tracep->declBus(c+13,"MemWriteSize", false,-1, 1,0);
    tracep->declBus(c+8,"ALUctrl", false,-1, 2,0);
    tracep->declBit(c+9,"ALUSrc", false,-1);
    tracep->declBus(c+10,"ImmSrc", false,-1, 2,0);
    tracep->declBit(c+7,"RegWrite", false,-1);
    tracep->declBus(c+80,"ALU_ADD", false,-1, 2,0);
    tracep->declBus(c+81,"ALU_SUB", false,-1, 2,0);
    tracep->declBus(c+82,"ALU_ORI", false,-1, 2,0);
    tracep->declBus(c+80,"I_TYPE", false,-1, 2,0);
    tracep->declBus(c+81,"S_TYPE", false,-1, 2,0);
    tracep->declBus(c+83,"B_TYPE", false,-1, 2,0);
    tracep->declBus(c+84,"J_TYPE", false,-1, 2,0);
    tracep->declBus(c+85,"U_TYPE", false,-1, 2,0);
    tracep->declBus(c+86,"ALU", false,-1, 1,0);
    tracep->declBus(c+87,"Memory", false,-1, 1,0);
    tracep->declBus(c+88,"PCPlus4", false,-1, 1,0);
    tracep->declBus(c+89,"UpperImmediate", false,-1, 1,0);
    tracep->declBus(c+86,"Normal", false,-1, 1,0);
    tracep->declBus(c+87,"Immediate", false,-1, 1,0);
    tracep->declBus(c+88,"JALR", false,-1, 1,0);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("DM ");
    tracep->declBus(c+79,"DATA_WIDTH", false,-1, 31,0);
    tracep->declBus(c+90,"MEMORY_WIDTH", false,-1, 31,0);
    tracep->declBit(c+64,"clk", false,-1);
    tracep->declBus(c+21,"ALUResult", false,-1, 31,0);
    tracep->declBus(c+17,"WriteData", false,-1, 31,0);
    tracep->declBit(c+12,"WE", false,-1);
    tracep->declBus(c+13,"MemWriteSize", false,-1, 1,0);
    tracep->declBus(c+18,"RD", false,-1, 31,0);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("IMEM ");
    tracep->declBus(c+79,"DATA_WIDTH", false,-1, 31,0);
    tracep->declBus(c+91,"MEMORY_WIDTH", false,-1, 31,0);
    tracep->declBus(c+5,"A", false,-1, 31,0);
    tracep->declBus(c+6,"RD", false,-1, 31,0);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("LS ");
    tracep->declBus(c+79,"DATA_WIDTH", false,-1, 31,0);
    tracep->declBus(c+25,"funct3", false,-1, 2,0);
    tracep->declBus(c+27,"byte_num", false,-1, 1,0);
    tracep->declBus(c+18,"mem_data", false,-1, 31,0);
    tracep->declBus(c+19,"load_data", false,-1, 31,0);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("PCMUX ");
    tracep->declBus(c+79,"DATA_WIDTH", false,-1, 31,0);
    tracep->declBus(c+2,"in0", false,-1, 31,0);
    tracep->declBus(c+3,"in1", false,-1, 31,0);
    tracep->declBus(c+23,"in2", false,-1, 31,0);
    tracep->declBus(c+92,"in3", false,-1, 31,0);
    tracep->declBus(c+1,"sel", false,-1, 1,0);
    tracep->declBus(c+4,"out", false,-1, 31,0);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("PCREG ");
    tracep->declBus(c+79,"DATA_WIDTH", false,-1, 31,0);
    tracep->declBit(c+64,"clk", false,-1);
    tracep->declBit(c+65,"rst", false,-1);
    tracep->declBus(c+4,"next_pc", false,-1, 31,0);
    tracep->declBus(c+5,"pc", false,-1, 31,0);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("RESULT_MUX ");
    tracep->declBus(c+79,"DATA_WIDTH", false,-1, 31,0);
    tracep->declBus(c+21,"in0", false,-1, 31,0);
    tracep->declBus(c+19,"in1", false,-1, 31,0);
    tracep->declBus(c+2,"in2", false,-1, 31,0);
    tracep->declBus(c+22,"in3", false,-1, 31,0);
    tracep->declBus(c+11,"sel", false,-1, 1,0);
    tracep->declBus(c+15,"out", false,-1, 31,0);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("RF ");
    tracep->declBus(c+79,"DATA_WIDTH", false,-1, 31,0);
    tracep->declBit(c+64,"clk", false,-1);
    tracep->declBus(c+28,"AD1", false,-1, 4,0);
    tracep->declBus(c+29,"AD2", false,-1, 4,0);
    tracep->declBus(c+30,"AD3", false,-1, 4,0);
    tracep->declBit(c+7,"WE3", false,-1);
    tracep->declBus(c+15,"WD3", false,-1, 31,0);
    tracep->declBus(c+16,"RD1", false,-1, 31,0);
    tracep->declBus(c+17,"RD2", false,-1, 31,0);
    tracep->declBus(c+67,"x0", false,-1, 31,0);
    tracep->declBus(c+68,"t0", false,-1, 31,0);
    tracep->declBus(c+69,"t1", false,-1, 31,0);
    tracep->declBus(c+70,"t3", false,-1, 31,0);
    tracep->declBus(c+71,"t4", false,-1, 31,0);
    tracep->declBus(c+72,"a1", false,-1, 31,0);
    tracep->declBus(c+73,"a2", false,-1, 31,0);
    tracep->declBus(c+74,"a3", false,-1, 31,0);
    tracep->declBus(c+75,"a4", false,-1, 31,0);
    tracep->declBus(c+76,"a5", false,-1, 31,0);
    tracep->declBus(c+77,"a6", false,-1, 31,0);
    tracep->declBus(c+78,"a0", false,-1, 31,0);
    for (int i = 0; i < 32; ++i) {
        tracep->declBus(c+31+i*1,"regs", true,(i+0), 31,0);
    }
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("SE ");
    tracep->declBus(c+63,"instr", false,-1, 31,7);
    tracep->declBus(c+10,"ImmSrc", false,-1, 2,0);
    tracep->declBus(c+22,"ImmOp", false,-1, 31,0);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("jalr ");
    tracep->declBus(c+79,"DATA_WIDTH", false,-1, 31,0);
    tracep->declBus(c+21,"ALUPC", false,-1, 31,0);
    tracep->declBus(c+23,"jalrPC", false,-1, 31,0);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("myALU ");
    tracep->declBus(c+79,"DATA_WIDTH", false,-1, 31,0);
    tracep->declBus(c+16,"ALUop1", false,-1, 31,0);
    tracep->declBus(c+20,"ALUop2", false,-1, 31,0);
    tracep->declBus(c+8,"ALUctrl", false,-1, 2,0);
    tracep->declBus(c+21,"ALUout", false,-1, 31,0);
    tracep->declBit(c+14,"Zero", false,-1);
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
    bufp->fullIData(oldp+2,(((IData)(4U) + vlSelf->top__DOT__pc)),32);
    bufp->fullIData(oldp+3,((vlSelf->top__DOT__pc + vlSelf->top__DOT__ImmOp)),32);
    bufp->fullIData(oldp+4,(((2U & (IData)(vlSelf->top__DOT__PCSrc))
                              ? ((1U & (IData)(vlSelf->top__DOT__PCSrc))
                                  ? 0U : (0xfffffffeU 
                                          & vlSelf->top__DOT__ALUout))
                              : ((1U & (IData)(vlSelf->top__DOT__PCSrc))
                                  ? (vlSelf->top__DOT__pc 
                                     + vlSelf->top__DOT__ImmOp)
                                  : ((IData)(4U) + vlSelf->top__DOT__pc)))),32);
    bufp->fullIData(oldp+5,(vlSelf->top__DOT__pc),32);
    bufp->fullIData(oldp+6,(vlSelf->top__DOT__instr),32);
    bufp->fullBit(oldp+7,(vlSelf->top__DOT__RegWrite));
    bufp->fullCData(oldp+8,(vlSelf->top__DOT__ALUctrl),3);
    bufp->fullBit(oldp+9,(vlSelf->top__DOT__ALUSrc));
    bufp->fullCData(oldp+10,(vlSelf->top__DOT__ImmSrc),3);
    bufp->fullCData(oldp+11,(vlSelf->top__DOT__ResultSrc),2);
    bufp->fullBit(oldp+12,(vlSelf->top__DOT__MemWrite));
    bufp->fullCData(oldp+13,(vlSelf->top__DOT__MemWriteSize),2);
    bufp->fullBit(oldp+14,(vlSelf->top__DOT__Zero));
    bufp->fullIData(oldp+15,(((2U & (IData)(vlSelf->top__DOT__ResultSrc))
                               ? ((1U & (IData)(vlSelf->top__DOT__ResultSrc))
                                   ? vlSelf->top__DOT__ImmOp
                                   : ((IData)(4U) + vlSelf->top__DOT__pc))
                               : ((1U & (IData)(vlSelf->top__DOT__ResultSrc))
                                   ? ((0x4000U & vlSelf->top__DOT__instr)
                                       ? ((0x2000U 
                                           & vlSelf->top__DOT__instr)
                                           ? 0U : (
                                                   (0x1000U 
                                                    & vlSelf->top__DOT__instr)
                                                    ? 
                                                   (0xffffU 
                                                    & vlSelf->top__DOT__ReadData)
                                                    : 
                                                   (0xffU 
                                                    & vlSelf->top__DOT__ReadData)))
                                       : ((0x2000U 
                                           & vlSelf->top__DOT__instr)
                                           ? ((0x1000U 
                                               & vlSelf->top__DOT__instr)
                                               ? 0U
                                               : vlSelf->top__DOT__ReadData)
                                           : ((0x1000U 
                                               & vlSelf->top__DOT__instr)
                                               ? ((
                                                   (- (IData)(
                                                              (1U 
                                                               & (vlSelf->top__DOT__ReadData 
                                                                  >> 0xfU)))) 
                                                   << 0x10U) 
                                                  | (0xffffU 
                                                     & vlSelf->top__DOT__ReadData))
                                               : ((
                                                   (- (IData)(
                                                              (1U 
                                                               & (vlSelf->top__DOT__ReadData 
                                                                  >> 7U)))) 
                                                   << 8U) 
                                                  | (0xffU 
                                                     & vlSelf->top__DOT__ReadData)))))
                                   : vlSelf->top__DOT__ALUout))),32);
    bufp->fullIData(oldp+16,(vlSelf->top__DOT__RD1),32);
    bufp->fullIData(oldp+17,(vlSelf->top__DOT__RD2),32);
    bufp->fullIData(oldp+18,(vlSelf->top__DOT__ReadData),32);
    bufp->fullIData(oldp+19,(((0x4000U & vlSelf->top__DOT__instr)
                               ? ((0x2000U & vlSelf->top__DOT__instr)
                                   ? 0U : ((0x1000U 
                                            & vlSelf->top__DOT__instr)
                                            ? (0xffffU 
                                               & vlSelf->top__DOT__ReadData)
                                            : (0xffU 
                                               & vlSelf->top__DOT__ReadData)))
                               : ((0x2000U & vlSelf->top__DOT__instr)
                                   ? ((0x1000U & vlSelf->top__DOT__instr)
                                       ? 0U : vlSelf->top__DOT__ReadData)
                                   : ((0x1000U & vlSelf->top__DOT__instr)
                                       ? (((- (IData)(
                                                      (1U 
                                                       & (vlSelf->top__DOT__ReadData 
                                                          >> 0xfU)))) 
                                           << 0x10U) 
                                          | (0xffffU 
                                             & vlSelf->top__DOT__ReadData))
                                       : (((- (IData)(
                                                      (1U 
                                                       & (vlSelf->top__DOT__ReadData 
                                                          >> 7U)))) 
                                           << 8U) | 
                                          (0xffU & vlSelf->top__DOT__ReadData)))))),32);
    bufp->fullIData(oldp+20,(vlSelf->top__DOT__ALUop2),32);
    bufp->fullIData(oldp+21,(vlSelf->top__DOT__ALUout),32);
    bufp->fullIData(oldp+22,(vlSelf->top__DOT__ImmOp),32);
    bufp->fullIData(oldp+23,((0xfffffffeU & vlSelf->top__DOT__ALUout)),32);
    bufp->fullCData(oldp+24,((0x7fU & vlSelf->top__DOT__instr)),7);
    bufp->fullCData(oldp+25,((7U & (vlSelf->top__DOT__instr 
                                    >> 0xcU))),3);
    bufp->fullBit(oldp+26,((1U & (vlSelf->top__DOT__instr 
                                  >> 0x1eU))));
    bufp->fullCData(oldp+27,((3U & vlSelf->top__DOT__ALUout)),2);
    bufp->fullCData(oldp+28,((0x1fU & (vlSelf->top__DOT__instr 
                                       >> 0xfU))),5);
    bufp->fullCData(oldp+29,((0x1fU & (vlSelf->top__DOT__instr 
                                       >> 0x14U))),5);
    bufp->fullCData(oldp+30,((0x1fU & (vlSelf->top__DOT__instr 
                                       >> 7U))),5);
    bufp->fullIData(oldp+31,(vlSelf->top__DOT__RF__DOT__regs[0]),32);
    bufp->fullIData(oldp+32,(vlSelf->top__DOT__RF__DOT__regs[1]),32);
    bufp->fullIData(oldp+33,(vlSelf->top__DOT__RF__DOT__regs[2]),32);
    bufp->fullIData(oldp+34,(vlSelf->top__DOT__RF__DOT__regs[3]),32);
    bufp->fullIData(oldp+35,(vlSelf->top__DOT__RF__DOT__regs[4]),32);
    bufp->fullIData(oldp+36,(vlSelf->top__DOT__RF__DOT__regs[5]),32);
    bufp->fullIData(oldp+37,(vlSelf->top__DOT__RF__DOT__regs[6]),32);
    bufp->fullIData(oldp+38,(vlSelf->top__DOT__RF__DOT__regs[7]),32);
    bufp->fullIData(oldp+39,(vlSelf->top__DOT__RF__DOT__regs[8]),32);
    bufp->fullIData(oldp+40,(vlSelf->top__DOT__RF__DOT__regs[9]),32);
    bufp->fullIData(oldp+41,(vlSelf->top__DOT__RF__DOT__regs[10]),32);
    bufp->fullIData(oldp+42,(vlSelf->top__DOT__RF__DOT__regs[11]),32);
    bufp->fullIData(oldp+43,(vlSelf->top__DOT__RF__DOT__regs[12]),32);
    bufp->fullIData(oldp+44,(vlSelf->top__DOT__RF__DOT__regs[13]),32);
    bufp->fullIData(oldp+45,(vlSelf->top__DOT__RF__DOT__regs[14]),32);
    bufp->fullIData(oldp+46,(vlSelf->top__DOT__RF__DOT__regs[15]),32);
    bufp->fullIData(oldp+47,(vlSelf->top__DOT__RF__DOT__regs[16]),32);
    bufp->fullIData(oldp+48,(vlSelf->top__DOT__RF__DOT__regs[17]),32);
    bufp->fullIData(oldp+49,(vlSelf->top__DOT__RF__DOT__regs[18]),32);
    bufp->fullIData(oldp+50,(vlSelf->top__DOT__RF__DOT__regs[19]),32);
    bufp->fullIData(oldp+51,(vlSelf->top__DOT__RF__DOT__regs[20]),32);
    bufp->fullIData(oldp+52,(vlSelf->top__DOT__RF__DOT__regs[21]),32);
    bufp->fullIData(oldp+53,(vlSelf->top__DOT__RF__DOT__regs[22]),32);
    bufp->fullIData(oldp+54,(vlSelf->top__DOT__RF__DOT__regs[23]),32);
    bufp->fullIData(oldp+55,(vlSelf->top__DOT__RF__DOT__regs[24]),32);
    bufp->fullIData(oldp+56,(vlSelf->top__DOT__RF__DOT__regs[25]),32);
    bufp->fullIData(oldp+57,(vlSelf->top__DOT__RF__DOT__regs[26]),32);
    bufp->fullIData(oldp+58,(vlSelf->top__DOT__RF__DOT__regs[27]),32);
    bufp->fullIData(oldp+59,(vlSelf->top__DOT__RF__DOT__regs[28]),32);
    bufp->fullIData(oldp+60,(vlSelf->top__DOT__RF__DOT__regs[29]),32);
    bufp->fullIData(oldp+61,(vlSelf->top__DOT__RF__DOT__regs[30]),32);
    bufp->fullIData(oldp+62,(vlSelf->top__DOT__RF__DOT__regs[31]),32);
    bufp->fullIData(oldp+63,((vlSelf->top__DOT__instr 
                              >> 7U)),25);
    bufp->fullBit(oldp+64,(vlSelf->clk));
    bufp->fullBit(oldp+65,(vlSelf->rst));
    bufp->fullBit(oldp+66,(vlSelf->trigger));
    bufp->fullIData(oldp+67,(vlSelf->x0),32);
    bufp->fullIData(oldp+68,(vlSelf->t0),32);
    bufp->fullIData(oldp+69,(vlSelf->t1),32);
    bufp->fullIData(oldp+70,(vlSelf->t3),32);
    bufp->fullIData(oldp+71,(vlSelf->t4),32);
    bufp->fullIData(oldp+72,(vlSelf->a1),32);
    bufp->fullIData(oldp+73,(vlSelf->a2),32);
    bufp->fullIData(oldp+74,(vlSelf->a3),32);
    bufp->fullIData(oldp+75,(vlSelf->a4),32);
    bufp->fullIData(oldp+76,(vlSelf->a5),32);
    bufp->fullIData(oldp+77,(vlSelf->a6),32);
    bufp->fullIData(oldp+78,(vlSelf->a0),32);
    bufp->fullIData(oldp+79,(0x20U),32);
    bufp->fullCData(oldp+80,(0U),3);
    bufp->fullCData(oldp+81,(1U),3);
    bufp->fullCData(oldp+82,(6U),3);
    bufp->fullCData(oldp+83,(2U),3);
    bufp->fullCData(oldp+84,(3U),3);
    bufp->fullCData(oldp+85,(4U),3);
    bufp->fullCData(oldp+86,(0U),2);
    bufp->fullCData(oldp+87,(1U),2);
    bufp->fullCData(oldp+88,(2U),2);
    bufp->fullCData(oldp+89,(3U),2);
    bufp->fullIData(oldp+90,(0x20000U),32);
    bufp->fullIData(oldp+91,(0x3e8U),32);
    bufp->fullIData(oldp+92,(0U),32);
}
