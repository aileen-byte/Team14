// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See Vdut.h for the primary calling header

#ifndef VERILATED_VDUT___024ROOT_H_
#define VERILATED_VDUT___024ROOT_H_  // guard

#include "verilated.h"

class Vdut__Syms;

class Vdut___024root final : public VerilatedModule {
  public:

    // DESIGN SPECIFIC STATE
    VL_IN8(clk,0,0);
    VL_IN8(rst,0,0);
    VL_OUT8(Zero,0,0);
    CData/*1:0*/ top__DOT__PCSrc;
    CData/*0:0*/ top__DOT__RegWrite;
    CData/*2:0*/ top__DOT__ALUctrl;
    CData/*0:0*/ top__DOT__ALUSrc;
    CData/*2:0*/ top__DOT__ImmSrc;
    CData/*1:0*/ top__DOT__ResultSrc;
    CData/*0:0*/ top__DOT__MemWrite;
    CData/*7:0*/ top__DOT__DM__DOT____Vlvbound_h51e3f0c4__0;
    CData/*7:0*/ top__DOT__DM__DOT____Vlvbound_h35022570__0;
    CData/*7:0*/ top__DOT__DM__DOT____Vlvbound_h35021543__0;
    CData/*7:0*/ top__DOT__DM__DOT____Vlvbound_h3501834e__0;
    CData/*0:0*/ __Vclklast__TOP__clk;
    VL_OUT(t1,31,0);
    VL_OUT(t2,31,0);
    VL_OUT(t3,31,0);
    VL_OUT(pc,31,0);
    VL_OUT(a0,31,0);
    IData/*31:0*/ top__DOT__next_pc;
    IData/*31:0*/ top__DOT__instr;
    IData/*31:0*/ top__DOT__RD1;
    IData/*31:0*/ top__DOT__RD2;
    IData/*31:0*/ top__DOT__ALUop2;
    IData/*31:0*/ top__DOT__ALUout;
    IData/*31:0*/ top__DOT__ImmOp;
    VlUnpacked<CData/*7:0*/, 100> top__DOT__IMEM__DOT__memory;
    VlUnpacked<IData/*31:0*/, 32> top__DOT__RF__DOT__regs;
    VlUnpacked<CData/*7:0*/, 100> top__DOT__DM__DOT__mem_array;
    VlUnpacked<CData/*0:0*/, 2> __Vm_traceActivity;

    // INTERNAL VARIABLES
    Vdut__Syms* const vlSymsp;

    // CONSTRUCTORS
    Vdut___024root(Vdut__Syms* symsp, const char* name);
    ~Vdut___024root();
    VL_UNCOPYABLE(Vdut___024root);

    // INTERNAL METHODS
    void __Vconfigure(bool first);
} VL_ATTR_ALIGNED(VL_CACHE_LINE_BYTES);


#endif  // guard
