// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vcpu.h for the primary calling header

#include "Vcpu__pch.h"
#include "Vcpu___024root.h"

void Vcpu___024root___eval_act(Vcpu___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vcpu__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vcpu___024root___eval_act\n"); );
}

void Vcpu___024root___nba_sequent__TOP__0(Vcpu___024root* vlSelf);

void Vcpu___024root___eval_nba(Vcpu___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vcpu__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vcpu___024root___eval_nba\n"); );
    // Body
    if ((1ULL & vlSelf->__VnbaTriggered.word(0U))) {
        Vcpu___024root___nba_sequent__TOP__0(vlSelf);
        vlSelf->__Vm_traceActivity[1U] = 1U;
    }
}

extern const VlUnpacked<SData/*15:0*/, 256> Vcpu__ConstPool__TABLE_h242fd4b0_0;

VL_INLINE_OPT void Vcpu___024root___nba_sequent__TOP__0(Vcpu___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vcpu__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vcpu___024root___nba_sequent__TOP__0\n"); );
    // Init
    CData/*7:0*/ __Vtableidx1;
    __Vtableidx1 = 0;
    CData/*7:0*/ __VdlyVal__cpu__DOT__the_regs__DOT__registers__v0;
    __VdlyVal__cpu__DOT__the_regs__DOT__registers__v0 = 0;
    CData/*1:0*/ __VdlyDim0__cpu__DOT__the_regs__DOT__registers__v0;
    __VdlyDim0__cpu__DOT__the_regs__DOT__registers__v0 = 0;
    CData/*7:0*/ __VdlyVal__cpu__DOT__the_ram__DOT__memory__v0;
    __VdlyVal__cpu__DOT__the_ram__DOT__memory__v0 = 0;
    CData/*7:0*/ __VdlyDim0__cpu__DOT__the_ram__DOT__memory__v0;
    __VdlyDim0__cpu__DOT__the_ram__DOT__memory__v0 = 0;
    CData/*0:0*/ __VdlySet__cpu__DOT__the_regs__DOT__registers__v0;
    __VdlySet__cpu__DOT__the_regs__DOT__registers__v0 = 0;
    CData/*0:0*/ __VdlySet__cpu__DOT__the_ram__DOT__memory__v0;
    __VdlySet__cpu__DOT__the_ram__DOT__memory__v0 = 0;
    // Body
    __VdlySet__cpu__DOT__the_ram__DOT__memory__v0 = 0U;
    __VdlySet__cpu__DOT__the_regs__DOT__registers__v0 = 0U;
    if ((0xcU == (0xfU & ((IData)(vlSelf->cpu__DOT__instruction) 
                          >> 0xcU)))) {
        __VdlyVal__cpu__DOT__the_ram__DOT__memory__v0 
            = vlSelf->cpu__DOT__reg_out_a;
        __VdlyDim0__cpu__DOT__the_ram__DOT__memory__v0 
            = (0xffU & (IData)(vlSelf->cpu__DOT__instruction));
        __VdlySet__cpu__DOT__the_ram__DOT__memory__v0 = 1U;
    }
    vlSelf->cpu__DOT__pc_addr = ((IData)(vlSelf->reset)
                                  ? 0U : (0xffU & (
                                                   ((0xeU 
                                                     == 
                                                     (0xfU 
                                                      & ((IData)(vlSelf->cpu__DOT__instruction) 
                                                         >> 0xcU))) 
                                                    | (IData)(
                                                              ((0xf000U 
                                                                == 
                                                                (0xf000U 
                                                                 & (IData)(vlSelf->cpu__DOT__instruction))) 
                                                               & (0U 
                                                                  == (IData)(vlSelf->cpu__DOT__alu_result)))))
                                                    ? (IData)(vlSelf->cpu__DOT__instruction)
                                                    : 
                                                   ((IData)(1U) 
                                                    + (IData)(vlSelf->cpu__DOT__pc_addr)))));
    if (((0xaU == (0xfU & ((IData)(vlSelf->cpu__DOT__instruction) 
                           >> 0xcU))) | ((8U == (0xfU 
                                                 & ((IData)(vlSelf->cpu__DOT__instruction) 
                                                    >> 0xcU))) 
                                         | ((9U == 
                                             (0xfU 
                                              & ((IData)(vlSelf->cpu__DOT__instruction) 
                                                 >> 0xcU))) 
                                            | (0xdU 
                                               == (0xfU 
                                                   & ((IData)(vlSelf->cpu__DOT__instruction) 
                                                      >> 0xcU))))))) {
        __VdlyVal__cpu__DOT__the_regs__DOT__registers__v0 
            = (0xffU & ((0xaU == (0xfU & ((IData)(vlSelf->cpu__DOT__instruction) 
                                          >> 0xcU)))
                         ? (IData)(vlSelf->cpu__DOT__instruction)
                         : ((0xdU == (0xfU & ((IData)(vlSelf->cpu__DOT__instruction) 
                                              >> 0xcU)))
                             ? vlSelf->cpu__DOT__the_ram__DOT__memory
                            [(0xffU & (IData)(vlSelf->cpu__DOT__instruction))]
                             : (IData)(vlSelf->cpu__DOT__alu_result))));
        __VdlyDim0__cpu__DOT__the_regs__DOT__registers__v0 
            = (3U & ((IData)(vlSelf->cpu__DOT__instruction) 
                     >> 8U));
        __VdlySet__cpu__DOT__the_regs__DOT__registers__v0 = 1U;
    }
    if (__VdlySet__cpu__DOT__the_ram__DOT__memory__v0) {
        vlSelf->cpu__DOT__the_ram__DOT__memory[__VdlyDim0__cpu__DOT__the_ram__DOT__memory__v0] 
            = __VdlyVal__cpu__DOT__the_ram__DOT__memory__v0;
    }
    if (__VdlySet__cpu__DOT__the_regs__DOT__registers__v0) {
        vlSelf->cpu__DOT__the_regs__DOT__registers[__VdlyDim0__cpu__DOT__the_regs__DOT__registers__v0] 
            = __VdlyVal__cpu__DOT__the_regs__DOT__registers__v0;
    }
    __Vtableidx1 = vlSelf->cpu__DOT__pc_addr;
    vlSelf->cpu__DOT__instruction = Vcpu__ConstPool__TABLE_h242fd4b0_0
        [__Vtableidx1];
    vlSelf->cpu__DOT__reg_out_a = vlSelf->cpu__DOT__the_regs__DOT__registers
        [(3U & ((IData)(vlSelf->cpu__DOT__instruction) 
                >> 4U))];
    vlSelf->cpu__DOT__reg_out_b = vlSelf->cpu__DOT__the_regs__DOT__registers
        [(3U & (IData)(vlSelf->cpu__DOT__instruction))];
    vlSelf->cpu__DOT__alu_result = (0xffU & (((9U == 
                                               (0xfU 
                                                & ((IData)(vlSelf->cpu__DOT__instruction) 
                                                   >> 0xcU)))
                                               ? 1U
                                               : 0U)
                                              ? ((IData)(vlSelf->cpu__DOT__reg_out_a) 
                                                 - (IData)(vlSelf->cpu__DOT__reg_out_b))
                                              : ((IData)(vlSelf->cpu__DOT__reg_out_a) 
                                                 + (IData)(vlSelf->cpu__DOT__reg_out_b))));
}

void Vcpu___024root___eval_triggers__act(Vcpu___024root* vlSelf);

bool Vcpu___024root___eval_phase__act(Vcpu___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vcpu__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vcpu___024root___eval_phase__act\n"); );
    // Init
    VlTriggerVec<1> __VpreTriggered;
    CData/*0:0*/ __VactExecute;
    // Body
    Vcpu___024root___eval_triggers__act(vlSelf);
    __VactExecute = vlSelf->__VactTriggered.any();
    if (__VactExecute) {
        __VpreTriggered.andNot(vlSelf->__VactTriggered, vlSelf->__VnbaTriggered);
        vlSelf->__VnbaTriggered.thisOr(vlSelf->__VactTriggered);
        Vcpu___024root___eval_act(vlSelf);
    }
    return (__VactExecute);
}

bool Vcpu___024root___eval_phase__nba(Vcpu___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vcpu__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vcpu___024root___eval_phase__nba\n"); );
    // Init
    CData/*0:0*/ __VnbaExecute;
    // Body
    __VnbaExecute = vlSelf->__VnbaTriggered.any();
    if (__VnbaExecute) {
        Vcpu___024root___eval_nba(vlSelf);
        vlSelf->__VnbaTriggered.clear();
    }
    return (__VnbaExecute);
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vcpu___024root___dump_triggers__nba(Vcpu___024root* vlSelf);
#endif  // VL_DEBUG
#ifdef VL_DEBUG
VL_ATTR_COLD void Vcpu___024root___dump_triggers__act(Vcpu___024root* vlSelf);
#endif  // VL_DEBUG

void Vcpu___024root___eval(Vcpu___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vcpu__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vcpu___024root___eval\n"); );
    // Init
    IData/*31:0*/ __VnbaIterCount;
    CData/*0:0*/ __VnbaContinue;
    // Body
    __VnbaIterCount = 0U;
    __VnbaContinue = 1U;
    while (__VnbaContinue) {
        if (VL_UNLIKELY((0x64U < __VnbaIterCount))) {
#ifdef VL_DEBUG
            Vcpu___024root___dump_triggers__nba(vlSelf);
#endif
            VL_FATAL_MT("cpu.v", 1, "", "NBA region did not converge.");
        }
        __VnbaIterCount = ((IData)(1U) + __VnbaIterCount);
        __VnbaContinue = 0U;
        vlSelf->__VactIterCount = 0U;
        vlSelf->__VactContinue = 1U;
        while (vlSelf->__VactContinue) {
            if (VL_UNLIKELY((0x64U < vlSelf->__VactIterCount))) {
#ifdef VL_DEBUG
                Vcpu___024root___dump_triggers__act(vlSelf);
#endif
                VL_FATAL_MT("cpu.v", 1, "", "Active region did not converge.");
            }
            vlSelf->__VactIterCount = ((IData)(1U) 
                                       + vlSelf->__VactIterCount);
            vlSelf->__VactContinue = 0U;
            if (Vcpu___024root___eval_phase__act(vlSelf)) {
                vlSelf->__VactContinue = 1U;
            }
        }
        if (Vcpu___024root___eval_phase__nba(vlSelf)) {
            __VnbaContinue = 1U;
        }
    }
}

#ifdef VL_DEBUG
void Vcpu___024root___eval_debug_assertions(Vcpu___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vcpu__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vcpu___024root___eval_debug_assertions\n"); );
    // Body
    if (VL_UNLIKELY((vlSelf->clk & 0xfeU))) {
        Verilated::overWidthError("clk");}
    if (VL_UNLIKELY((vlSelf->reset & 0xfeU))) {
        Verilated::overWidthError("reset");}
}
#endif  // VL_DEBUG
