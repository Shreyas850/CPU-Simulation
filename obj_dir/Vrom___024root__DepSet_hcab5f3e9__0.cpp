// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vrom.h for the primary calling header

#include "Vrom__pch.h"
#include "Vrom___024root.h"

void Vrom___024root___ico_sequent__TOP__0(Vrom___024root* vlSelf);

void Vrom___024root___eval_ico(Vrom___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vrom__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vrom___024root___eval_ico\n"); );
    // Body
    if ((1ULL & vlSelf->__VicoTriggered.word(0U))) {
        Vrom___024root___ico_sequent__TOP__0(vlSelf);
    }
}

VL_INLINE_OPT void Vrom___024root___ico_sequent__TOP__0(Vrom___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vrom__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vrom___024root___ico_sequent__TOP__0\n"); );
    // Body
    vlSelf->instruction = ((0U == (IData)(vlSelf->address))
                            ? 0xa105U : ((1U == (IData)(vlSelf->address))
                                          ? 0xa20aU
                                          : ((2U == (IData)(vlSelf->address))
                                              ? 0x8012U
                                              : ((3U 
                                                  == (IData)(vlSelf->address))
                                                  ? 0xffffU
                                                  : 0U))));
}

void Vrom___024root___eval_triggers__ico(Vrom___024root* vlSelf);

bool Vrom___024root___eval_phase__ico(Vrom___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vrom__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vrom___024root___eval_phase__ico\n"); );
    // Init
    CData/*0:0*/ __VicoExecute;
    // Body
    Vrom___024root___eval_triggers__ico(vlSelf);
    __VicoExecute = vlSelf->__VicoTriggered.any();
    if (__VicoExecute) {
        Vrom___024root___eval_ico(vlSelf);
    }
    return (__VicoExecute);
}

void Vrom___024root___eval_act(Vrom___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vrom__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vrom___024root___eval_act\n"); );
}

void Vrom___024root___eval_nba(Vrom___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vrom__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vrom___024root___eval_nba\n"); );
}

void Vrom___024root___eval_triggers__act(Vrom___024root* vlSelf);

bool Vrom___024root___eval_phase__act(Vrom___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vrom__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vrom___024root___eval_phase__act\n"); );
    // Init
    VlTriggerVec<0> __VpreTriggered;
    CData/*0:0*/ __VactExecute;
    // Body
    Vrom___024root___eval_triggers__act(vlSelf);
    __VactExecute = vlSelf->__VactTriggered.any();
    if (__VactExecute) {
        __VpreTriggered.andNot(vlSelf->__VactTriggered, vlSelf->__VnbaTriggered);
        vlSelf->__VnbaTriggered.thisOr(vlSelf->__VactTriggered);
        Vrom___024root___eval_act(vlSelf);
    }
    return (__VactExecute);
}

bool Vrom___024root___eval_phase__nba(Vrom___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vrom__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vrom___024root___eval_phase__nba\n"); );
    // Init
    CData/*0:0*/ __VnbaExecute;
    // Body
    __VnbaExecute = vlSelf->__VnbaTriggered.any();
    if (__VnbaExecute) {
        Vrom___024root___eval_nba(vlSelf);
        vlSelf->__VnbaTriggered.clear();
    }
    return (__VnbaExecute);
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vrom___024root___dump_triggers__ico(Vrom___024root* vlSelf);
#endif  // VL_DEBUG
#ifdef VL_DEBUG
VL_ATTR_COLD void Vrom___024root___dump_triggers__nba(Vrom___024root* vlSelf);
#endif  // VL_DEBUG
#ifdef VL_DEBUG
VL_ATTR_COLD void Vrom___024root___dump_triggers__act(Vrom___024root* vlSelf);
#endif  // VL_DEBUG

void Vrom___024root___eval(Vrom___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vrom__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vrom___024root___eval\n"); );
    // Init
    IData/*31:0*/ __VicoIterCount;
    CData/*0:0*/ __VicoContinue;
    IData/*31:0*/ __VnbaIterCount;
    CData/*0:0*/ __VnbaContinue;
    // Body
    __VicoIterCount = 0U;
    vlSelf->__VicoFirstIteration = 1U;
    __VicoContinue = 1U;
    while (__VicoContinue) {
        if (VL_UNLIKELY((0x64U < __VicoIterCount))) {
#ifdef VL_DEBUG
            Vrom___024root___dump_triggers__ico(vlSelf);
#endif
            VL_FATAL_MT("rom.v", 1, "", "Input combinational region did not converge.");
        }
        __VicoIterCount = ((IData)(1U) + __VicoIterCount);
        __VicoContinue = 0U;
        if (Vrom___024root___eval_phase__ico(vlSelf)) {
            __VicoContinue = 1U;
        }
        vlSelf->__VicoFirstIteration = 0U;
    }
    __VnbaIterCount = 0U;
    __VnbaContinue = 1U;
    while (__VnbaContinue) {
        if (VL_UNLIKELY((0x64U < __VnbaIterCount))) {
#ifdef VL_DEBUG
            Vrom___024root___dump_triggers__nba(vlSelf);
#endif
            VL_FATAL_MT("rom.v", 1, "", "NBA region did not converge.");
        }
        __VnbaIterCount = ((IData)(1U) + __VnbaIterCount);
        __VnbaContinue = 0U;
        vlSelf->__VactIterCount = 0U;
        vlSelf->__VactContinue = 1U;
        while (vlSelf->__VactContinue) {
            if (VL_UNLIKELY((0x64U < vlSelf->__VactIterCount))) {
#ifdef VL_DEBUG
                Vrom___024root___dump_triggers__act(vlSelf);
#endif
                VL_FATAL_MT("rom.v", 1, "", "Active region did not converge.");
            }
            vlSelf->__VactIterCount = ((IData)(1U) 
                                       + vlSelf->__VactIterCount);
            vlSelf->__VactContinue = 0U;
            if (Vrom___024root___eval_phase__act(vlSelf)) {
                vlSelf->__VactContinue = 1U;
            }
        }
        if (Vrom___024root___eval_phase__nba(vlSelf)) {
            __VnbaContinue = 1U;
        }
    }
}

#ifdef VL_DEBUG
void Vrom___024root___eval_debug_assertions(Vrom___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vrom__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vrom___024root___eval_debug_assertions\n"); );
}
#endif  // VL_DEBUG
