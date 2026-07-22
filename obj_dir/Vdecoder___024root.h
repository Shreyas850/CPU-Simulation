// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See Vdecoder.h for the primary calling header

#ifndef VERILATED_VDECODER___024ROOT_H_
#define VERILATED_VDECODER___024ROOT_H_  // guard

#include "verilated.h"


class Vdecoder__Syms;

class alignas(VL_CACHE_LINE_BYTES) Vdecoder___024root final : public VerilatedModule {
  public:

    // DESIGN SPECIFIC STATE
    VL_OUT8(opcode,3,0);
    VL_OUT8(rd,1,0);
    VL_OUT8(rs1,1,0);
    VL_OUT8(rs2,1,0);
    VL_OUT8(imm,7,0);
    CData/*0:0*/ __VstlFirstIteration;
    CData/*0:0*/ __VicoFirstIteration;
    CData/*0:0*/ __VactContinue;
    VL_IN16(instruction,15,0);
    IData/*31:0*/ __VactIterCount;
    VlTriggerVec<1> __VstlTriggered;
    VlTriggerVec<1> __VicoTriggered;
    VlTriggerVec<0> __VactTriggered;
    VlTriggerVec<0> __VnbaTriggered;

    // INTERNAL VARIABLES
    Vdecoder__Syms* const vlSymsp;

    // CONSTRUCTORS
    Vdecoder___024root(Vdecoder__Syms* symsp, const char* v__name);
    ~Vdecoder___024root();
    VL_UNCOPYABLE(Vdecoder___024root);

    // INTERNAL METHODS
    void __Vconfigure(bool first);
};


#endif  // guard
