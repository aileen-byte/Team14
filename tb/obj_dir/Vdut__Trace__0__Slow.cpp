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
    tracep->declBit(c+67,"clk", false,-1);
    tracep->declBit(c+68,"rst", false,-1);
    tracep->declBit(c+69,"trigger", false,-1);
    tracep->declBus(c+70,"x0", false,-1, 31,0);
    tracep->declBus(c+71,"t0", false,-1, 31,0);
    tracep->declBus(c+72,"t1", false,-1, 31,0);
    tracep->declBus(c+73,"t2", false,-1, 31,0);
    tracep->declBus(c+74,"t3", false,-1, 31,0);
    tracep->declBus(c+75,"t4", false,-1, 31,0);
    tracep->declBus(c+76,"a1", false,-1, 31,0);
    tracep->declBus(c+77,"a2", false,-1, 31,0);
    tracep->declBus(c+78,"a3", false,-1, 31,0);
    tracep->declBus(c+79,"a4", false,-1, 31,0);
    tracep->declBus(c+80,"a5", false,-1, 31,0);
    tracep->declBus(c+81,"a6", false,-1, 31,0);
    tracep->declBus(c+82,"a0", false,-1, 31,0);
    tracep->pushNamePrefix("top ");
    tracep->declBus(c+83,"DATA_WIDTH", false,-1, 31,0);
    tracep->declBit(c+67,"clk", false,-1);
    tracep->declBit(c+68,"rst", false,-1);
    tracep->declBit(c+69,"trigger", false,-1);
    tracep->declBus(c+70,"x0", false,-1, 31,0);
    tracep->declBus(c+71,"t0", false,-1, 31,0);
    tracep->declBus(c+72,"t1", false,-1, 31,0);
    tracep->declBus(c+73,"t2", false,-1, 31,0);
    tracep->declBus(c+74,"t3", false,-1, 31,0);
    tracep->declBus(c+75,"t4", false,-1, 31,0);
    tracep->declBus(c+76,"a1", false,-1, 31,0);
    tracep->declBus(c+77,"a2", false,-1, 31,0);
    tracep->declBus(c+78,"a3", false,-1, 31,0);
    tracep->declBus(c+79,"a4", false,-1, 31,0);
    tracep->declBus(c+80,"a5", false,-1, 31,0);
    tracep->declBus(c+81,"a6", false,-1, 31,0);
    tracep->declBus(c+82,"a0", false,-1, 31,0);
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
    tracep->declBus(c+14,"LoadSize", false,-1, 1,0);
    tracep->declBit(c+15,"Zero", false,-1);
    tracep->declBus(c+16,"WD3", false,-1, 31,0);
    tracep->declBus(c+17,"RD1", false,-1, 31,0);
    tracep->declBus(c+18,"RD2", false,-1, 31,0);
    tracep->declBus(c+19,"ReadData", false,-1, 31,0);
    tracep->declBus(c+20,"load_data", false,-1, 31,0);
    tracep->declBus(c+21,"ALUop2", false,-1, 31,0);
    tracep->declBus(c+22,"ALUout", false,-1, 31,0);
    tracep->declBus(c+23,"ImmOp", false,-1, 31,0);
    tracep->declBus(c+24,"jalrPC", false,-1, 31,0);
    tracep->declBit(c+69,"auto_trigger", false,-1);
    tracep->pushNamePrefix("ADD4 ");
    tracep->declBus(c+83,"DATA_WIDTH", false,-1, 31,0);
    tracep->declBus(c+5,"pc", false,-1, 31,0);
    tracep->declBus(c+2,"inc_pc", false,-1, 31,0);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("ALUMUX ");
    tracep->declBus(c+83,"DATA_WIDTH", false,-1, 31,0);
    tracep->declBus(c+18,"in0", false,-1, 31,0);
    tracep->declBus(c+23,"in1", false,-1, 31,0);
    tracep->declBit(c+9,"sel", false,-1);
    tracep->declBus(c+21,"out", false,-1, 31,0);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("BRADD ");
    tracep->declBus(c+83,"DATA_WIDTH", false,-1, 31,0);
    tracep->declBus(c+5,"pc", false,-1, 31,0);
    tracep->declBus(c+23,"ImmOp", false,-1, 31,0);
    tracep->declBus(c+3,"branch_pc", false,-1, 31,0);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("CU ");
    tracep->declBus(c+25,"op", false,-1, 6,0);
    tracep->declBus(c+26,"funct3", false,-1, 2,0);
    tracep->declBit(c+27,"funct7b5", false,-1);
    tracep->declBit(c+15,"Zero", false,-1);
    tracep->declBus(c+1,"PCSrc", false,-1, 1,0);
    tracep->declBus(c+11,"ResultSrc", false,-1, 1,0);
    tracep->declBit(c+12,"MemWrite", false,-1);
    tracep->declBus(c+13,"MemWriteSize", false,-1, 1,0);
    tracep->declBus(c+14,"LoadSize", false,-1, 1,0);
    tracep->declBus(c+8,"ALUctrl", false,-1, 2,0);
    tracep->declBit(c+9,"ALUSrc", false,-1);
    tracep->declBus(c+10,"ImmSrc", false,-1, 2,0);
    tracep->declBit(c+7,"RegWrite", false,-1);
    tracep->declBus(c+84,"ALU_ADD", false,-1, 2,0);
    tracep->declBus(c+85,"ALU_SUB", false,-1, 2,0);
    tracep->declBus(c+86,"ALU_XOR", false,-1, 2,0);
    tracep->declBus(c+84,"I_TYPE", false,-1, 2,0);
    tracep->declBus(c+85,"S_TYPE", false,-1, 2,0);
    tracep->declBus(c+87,"B_TYPE", false,-1, 2,0);
    tracep->declBus(c+86,"J_TYPE", false,-1, 2,0);
    tracep->declBus(c+88,"U_TYPE", false,-1, 2,0);
    tracep->declBus(c+89,"ALU", false,-1, 1,0);
    tracep->declBus(c+90,"Memory", false,-1, 1,0);
    tracep->declBus(c+91,"PCPlus4", false,-1, 1,0);
    tracep->declBus(c+92,"UpperImmediate", false,-1, 1,0);
    tracep->declBus(c+89,"Normal", false,-1, 1,0);
    tracep->declBus(c+90,"Immediate", false,-1, 1,0);
    tracep->declBus(c+91,"JALR", false,-1, 1,0);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("DM ");
    tracep->declBus(c+83,"DATA_WIDTH", false,-1, 31,0);
    tracep->declBus(c+93,"MEMORY_WIDTH", false,-1, 31,0);
    tracep->declBit(c+67,"clk", false,-1);
    tracep->declBus(c+22,"ALUResult", false,-1, 31,0);
    tracep->declBus(c+18,"WriteData", false,-1, 31,0);
    tracep->declBit(c+12,"WE", false,-1);
    tracep->declBus(c+13,"MemWriteSize", false,-1, 1,0);
    tracep->declBus(c+19,"RD", false,-1, 31,0);
    tracep->declBus(c+28,"word_base", false,-1, 31,0);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("IMEM ");
    tracep->declBus(c+83,"DATA_WIDTH", false,-1, 31,0);
    tracep->declBus(c+94,"MEMORY_WIDTH", false,-1, 31,0);
    tracep->declBus(c+5,"A", false,-1, 31,0);
    tracep->declBus(c+6,"RD", false,-1, 31,0);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("LS ");
    tracep->declBus(c+83,"DATA_WIDTH", false,-1, 31,0);
    tracep->declBus(c+14,"size", false,-1, 1,0);
    tracep->declBus(c+29,"byte_num", false,-1, 1,0);
    tracep->declBus(c+19,"mem_data", false,-1, 31,0);
    tracep->declBus(c+20,"load_data", false,-1, 31,0);
    tracep->declBus(c+30,"selected_byte", false,-1, 7,0);
    tracep->declBus(c+95,"selected_half", false,-1, 15,0);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("PCMUX ");
    tracep->declBus(c+83,"DATA_WIDTH", false,-1, 31,0);
    tracep->declBus(c+2,"in0", false,-1, 31,0);
    tracep->declBus(c+3,"in1", false,-1, 31,0);
    tracep->declBus(c+24,"in2", false,-1, 31,0);
    tracep->declBus(c+96,"in3", false,-1, 31,0);
    tracep->declBus(c+1,"sel", false,-1, 1,0);
    tracep->declBus(c+4,"out", false,-1, 31,0);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("PCREG ");
    tracep->declBus(c+83,"DATA_WIDTH", false,-1, 31,0);
    tracep->declBit(c+67,"clk", false,-1);
    tracep->declBit(c+68,"rst", false,-1);
    tracep->declBus(c+4,"next_pc", false,-1, 31,0);
    tracep->declBus(c+5,"pc", false,-1, 31,0);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("RESULT_MUX ");
    tracep->declBus(c+83,"DATA_WIDTH", false,-1, 31,0);
    tracep->declBus(c+22,"in0", false,-1, 31,0);
    tracep->declBus(c+20,"in1", false,-1, 31,0);
    tracep->declBus(c+2,"in2", false,-1, 31,0);
    tracep->declBus(c+23,"in3", false,-1, 31,0);
    tracep->declBus(c+11,"sel", false,-1, 1,0);
    tracep->declBus(c+16,"out", false,-1, 31,0);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("RF ");
    tracep->declBus(c+83,"DATA_WIDTH", false,-1, 31,0);
    tracep->declBit(c+67,"clk", false,-1);
    tracep->declBus(c+31,"AD1", false,-1, 4,0);
    tracep->declBus(c+32,"AD2", false,-1, 4,0);
    tracep->declBus(c+33,"AD3", false,-1, 4,0);
    tracep->declBit(c+7,"WE3", false,-1);
    tracep->declBus(c+16,"WD3", false,-1, 31,0);
    tracep->declBus(c+17,"RD1", false,-1, 31,0);
    tracep->declBus(c+18,"RD2", false,-1, 31,0);
    tracep->declBus(c+70,"x0", false,-1, 31,0);
    tracep->declBus(c+71,"t0", false,-1, 31,0);
    tracep->declBus(c+72,"t1", false,-1, 31,0);
    tracep->declBus(c+73,"t2", false,-1, 31,0);
    tracep->declBus(c+74,"t3", false,-1, 31,0);
    tracep->declBus(c+75,"t4", false,-1, 31,0);
    tracep->declBus(c+76,"a1", false,-1, 31,0);
    tracep->declBus(c+77,"a2", false,-1, 31,0);
    tracep->declBus(c+78,"a3", false,-1, 31,0);
    tracep->declBus(c+79,"a4", false,-1, 31,0);
    tracep->declBus(c+80,"a5", false,-1, 31,0);
    tracep->declBus(c+81,"a6", false,-1, 31,0);
    tracep->declBus(c+82,"a0", false,-1, 31,0);
    for (int i = 0; i < 32; ++i) {
        tracep->declBus(c+34+i*1,"regs", true,(i+0), 31,0);
    }
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("SE ");
    tracep->declBus(c+66,"instr", false,-1, 31,7);
    tracep->declBus(c+10,"ImmSrc", false,-1, 2,0);
    tracep->declBus(c+23,"ImmOp", false,-1, 31,0);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("jalr ");
    tracep->declBus(c+83,"DATA_WIDTH", false,-1, 31,0);
    tracep->declBus(c+22,"ALUPC", false,-1, 31,0);
    tracep->declBus(c+24,"jalrPC", false,-1, 31,0);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("myALU ");
    tracep->declBus(c+83,"DATA_WIDTH", false,-1, 31,0);
    tracep->declBus(c+17,"ALUop1", false,-1, 31,0);
    tracep->declBus(c+21,"ALUop2", false,-1, 31,0);
    tracep->declBus(c+8,"ALUctrl", false,-1, 2,0);
    tracep->declBus(c+22,"ALUout", false,-1, 31,0);
    tracep->declBit(c+15,"Zero", false,-1);
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
    bufp->fullCData(oldp+14,(vlSelf->top__DOT__LoadSize),2);
    bufp->fullBit(oldp+15,(vlSelf->top__DOT__Zero));
    bufp->fullIData(oldp+16,(((2U & (IData)(vlSelf->top__DOT__ResultSrc))
                               ? ((1U & (IData)(vlSelf->top__DOT__ResultSrc))
                                   ? vlSelf->top__DOT__ImmOp
                                   : ((IData)(4U) + vlSelf->top__DOT__pc))
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
                                           : ((2U == (IData)(vlSelf->top__DOT__LoadSize))
                                               ? vlSelf->top__DOT__ReadData
                                               : 0U)))
                                   : vlSelf->top__DOT__ALUout))),32);
    bufp->fullIData(oldp+17,(vlSelf->top__DOT__RD1),32);
    bufp->fullIData(oldp+18,(vlSelf->top__DOT__RD2),32);
    bufp->fullIData(oldp+19,(vlSelf->top__DOT__ReadData),32);
    bufp->fullIData(oldp+20,(((0U == (IData)(vlSelf->top__DOT__LoadSize))
                               ? (IData)(vlSelf->top__DOT__LS__DOT__selected_byte)
                               : ((1U == (IData)(vlSelf->top__DOT__LoadSize))
                                   ? (((- (IData)((1U 
                                                   & ((IData)(vlSelf->top__DOT__LS__DOT__selected_byte) 
                                                      >> 7U)))) 
                                       << 8U) | (IData)(vlSelf->top__DOT__LS__DOT__selected_byte))
                                   : ((2U == (IData)(vlSelf->top__DOT__LoadSize))
                                       ? vlSelf->top__DOT__ReadData
                                       : 0U)))),32);
    bufp->fullIData(oldp+21,(vlSelf->top__DOT__ALUop2),32);
    bufp->fullIData(oldp+22,(vlSelf->top__DOT__ALUout),32);
    bufp->fullIData(oldp+23,(vlSelf->top__DOT__ImmOp),32);
    bufp->fullIData(oldp+24,((0xfffffffeU & vlSelf->top__DOT__ALUout)),32);
    bufp->fullCData(oldp+25,((0x7fU & vlSelf->top__DOT__instr)),7);
    bufp->fullCData(oldp+26,((7U & (vlSelf->top__DOT__instr 
                                    >> 0xcU))),3);
    bufp->fullBit(oldp+27,((1U & (vlSelf->top__DOT__instr 
                                  >> 0x1eU))));
    bufp->fullIData(oldp+28,((0xfffffffcU & vlSelf->top__DOT__ALUout)),32);
    bufp->fullCData(oldp+29,((3U & vlSelf->top__DOT__ALUout)),2);
    bufp->fullCData(oldp+30,(vlSelf->top__DOT__LS__DOT__selected_byte),8);
    bufp->fullCData(oldp+31,((0x1fU & (vlSelf->top__DOT__instr 
                                       >> 0xfU))),5);
    bufp->fullCData(oldp+32,((0x1fU & (vlSelf->top__DOT__instr 
                                       >> 0x14U))),5);
    bufp->fullCData(oldp+33,((0x1fU & (vlSelf->top__DOT__instr 
                                       >> 7U))),5);
    bufp->fullIData(oldp+34,(vlSelf->top__DOT__RF__DOT__regs[0]),32);
    bufp->fullIData(oldp+35,(vlSelf->top__DOT__RF__DOT__regs[1]),32);
    bufp->fullIData(oldp+36,(vlSelf->top__DOT__RF__DOT__regs[2]),32);
    bufp->fullIData(oldp+37,(vlSelf->top__DOT__RF__DOT__regs[3]),32);
    bufp->fullIData(oldp+38,(vlSelf->top__DOT__RF__DOT__regs[4]),32);
    bufp->fullIData(oldp+39,(vlSelf->top__DOT__RF__DOT__regs[5]),32);
    bufp->fullIData(oldp+40,(vlSelf->top__DOT__RF__DOT__regs[6]),32);
    bufp->fullIData(oldp+41,(vlSelf->top__DOT__RF__DOT__regs[7]),32);
    bufp->fullIData(oldp+42,(vlSelf->top__DOT__RF__DOT__regs[8]),32);
    bufp->fullIData(oldp+43,(vlSelf->top__DOT__RF__DOT__regs[9]),32);
    bufp->fullIData(oldp+44,(vlSelf->top__DOT__RF__DOT__regs[10]),32);
    bufp->fullIData(oldp+45,(vlSelf->top__DOT__RF__DOT__regs[11]),32);
    bufp->fullIData(oldp+46,(vlSelf->top__DOT__RF__DOT__regs[12]),32);
    bufp->fullIData(oldp+47,(vlSelf->top__DOT__RF__DOT__regs[13]),32);
    bufp->fullIData(oldp+48,(vlSelf->top__DOT__RF__DOT__regs[14]),32);
    bufp->fullIData(oldp+49,(vlSelf->top__DOT__RF__DOT__regs[15]),32);
    bufp->fullIData(oldp+50,(vlSelf->top__DOT__RF__DOT__regs[16]),32);
    bufp->fullIData(oldp+51,(vlSelf->top__DOT__RF__DOT__regs[17]),32);
    bufp->fullIData(oldp+52,(vlSelf->top__DOT__RF__DOT__regs[18]),32);
    bufp->fullIData(oldp+53,(vlSelf->top__DOT__RF__DOT__regs[19]),32);
    bufp->fullIData(oldp+54,(vlSelf->top__DOT__RF__DOT__regs[20]),32);
    bufp->fullIData(oldp+55,(vlSelf->top__DOT__RF__DOT__regs[21]),32);
    bufp->fullIData(oldp+56,(vlSelf->top__DOT__RF__DOT__regs[22]),32);
    bufp->fullIData(oldp+57,(vlSelf->top__DOT__RF__DOT__regs[23]),32);
    bufp->fullIData(oldp+58,(vlSelf->top__DOT__RF__DOT__regs[24]),32);
    bufp->fullIData(oldp+59,(vlSelf->top__DOT__RF__DOT__regs[25]),32);
    bufp->fullIData(oldp+60,(vlSelf->top__DOT__RF__DOT__regs[26]),32);
    bufp->fullIData(oldp+61,(vlSelf->top__DOT__RF__DOT__regs[27]),32);
    bufp->fullIData(oldp+62,(vlSelf->top__DOT__RF__DOT__regs[28]),32);
    bufp->fullIData(oldp+63,(vlSelf->top__DOT__RF__DOT__regs[29]),32);
    bufp->fullIData(oldp+64,(vlSelf->top__DOT__RF__DOT__regs[30]),32);
    bufp->fullIData(oldp+65,(vlSelf->top__DOT__RF__DOT__regs[31]),32);
    bufp->fullIData(oldp+66,((vlSelf->top__DOT__instr 
                              >> 7U)),25);
    bufp->fullBit(oldp+67,(vlSelf->clk));
    bufp->fullBit(oldp+68,(vlSelf->rst));
    bufp->fullBit(oldp+69,(vlSelf->trigger));
    bufp->fullIData(oldp+70,(vlSelf->x0),32);
    bufp->fullIData(oldp+71,(vlSelf->t0),32);
    bufp->fullIData(oldp+72,(vlSelf->t1),32);
    bufp->fullIData(oldp+73,(vlSelf->t2),32);
    bufp->fullIData(oldp+74,(vlSelf->t3),32);
    bufp->fullIData(oldp+75,(vlSelf->t4),32);
    bufp->fullIData(oldp+76,(vlSelf->a1),32);
    bufp->fullIData(oldp+77,(vlSelf->a2),32);
    bufp->fullIData(oldp+78,(vlSelf->a3),32);
    bufp->fullIData(oldp+79,(vlSelf->a4),32);
    bufp->fullIData(oldp+80,(vlSelf->a5),32);
    bufp->fullIData(oldp+81,(vlSelf->a6),32);
    bufp->fullIData(oldp+82,(vlSelf->a0),32);
    bufp->fullIData(oldp+83,(0x20U),32);
    bufp->fullCData(oldp+84,(0U),3);
    bufp->fullCData(oldp+85,(1U),3);
    bufp->fullCData(oldp+86,(3U),3);
    bufp->fullCData(oldp+87,(2U),3);
    bufp->fullCData(oldp+88,(4U),3);
    bufp->fullCData(oldp+89,(0U),2);
    bufp->fullCData(oldp+90,(1U),2);
    bufp->fullCData(oldp+91,(2U),2);
    bufp->fullCData(oldp+92,(3U),2);
    bufp->fullIData(oldp+93,(0x20000U),32);
    bufp->fullIData(oldp+94,(0x3e8U),32);
    bufp->fullSData(oldp+95,(vlSelf->top__DOT__LS__DOT__selected_half),16);
    bufp->fullIData(oldp+96,(0U),32);
}
