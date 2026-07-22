// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "Vcpu__Syms.h"


void Vcpu___024root__trace_chg_0_sub_0(Vcpu___024root* vlSelf, VerilatedVcd::Buffer* bufp);

void Vcpu___024root__trace_chg_0(void* voidSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vcpu___024root__trace_chg_0\n"); );
    // Init
    Vcpu___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vcpu___024root*>(voidSelf);
    Vcpu__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    if (VL_UNLIKELY(!vlSymsp->__Vm_activity)) return;
    // Body
    Vcpu___024root__trace_chg_0_sub_0((&vlSymsp->TOP), bufp);
}

void Vcpu___024root__trace_chg_0_sub_0(Vcpu___024root* vlSelf, VerilatedVcd::Buffer* bufp) {
    (void)vlSelf;  // Prevent unused variable warning
    Vcpu__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vcpu___024root__trace_chg_0_sub_0\n"); );
    // Init
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode + 1);
    // Body
    if (VL_UNLIKELY(vlSelf->__Vm_traceActivity[1U])) {
        bufp->chgCData(oldp+0,(vlSelf->cpu__DOT__pc_addr),8);
        bufp->chgSData(oldp+1,(vlSelf->cpu__DOT__instruction),16);
        bufp->chgCData(oldp+2,((0xfU & ((IData)(vlSelf->cpu__DOT__instruction) 
                                        >> 0xcU))),4);
        bufp->chgCData(oldp+3,((3U & ((IData)(vlSelf->cpu__DOT__instruction) 
                                      >> 8U))),2);
        bufp->chgCData(oldp+4,((3U & ((IData)(vlSelf->cpu__DOT__instruction) 
                                      >> 4U))),2);
        bufp->chgCData(oldp+5,((3U & (IData)(vlSelf->cpu__DOT__instruction))),2);
        bufp->chgCData(oldp+6,((0xffU & (IData)(vlSelf->cpu__DOT__instruction))),8);
        bufp->chgCData(oldp+7,(vlSelf->cpu__DOT__reg_out_a),8);
        bufp->chgCData(oldp+8,(vlSelf->cpu__DOT__reg_out_b),8);
        bufp->chgBit(oldp+9,(((0xaU == (0xfU & ((IData)(vlSelf->cpu__DOT__instruction) 
                                                >> 0xcU))) 
                              | ((8U == (0xfU & ((IData)(vlSelf->cpu__DOT__instruction) 
                                                 >> 0xcU))) 
                                 | ((9U == (0xfU & 
                                            ((IData)(vlSelf->cpu__DOT__instruction) 
                                             >> 0xcU))) 
                                    | (0xdU == (0xfU 
                                                & ((IData)(vlSelf->cpu__DOT__instruction) 
                                                   >> 0xcU))))))));
        bufp->chgCData(oldp+10,((0xffU & ((0xaU == 
                                           (0xfU & 
                                            ((IData)(vlSelf->cpu__DOT__instruction) 
                                             >> 0xcU)))
                                           ? (IData)(vlSelf->cpu__DOT__instruction)
                                           : ((0xdU 
                                               == (0xfU 
                                                   & ((IData)(vlSelf->cpu__DOT__instruction) 
                                                      >> 0xcU)))
                                               ? vlSelf->cpu__DOT__the_ram__DOT__memory
                                              [(0xffU 
                                                & (IData)(vlSelf->cpu__DOT__instruction))]
                                               : (IData)(vlSelf->cpu__DOT__alu_result))))),8);
        bufp->chgCData(oldp+11,(vlSelf->cpu__DOT__alu_result),8);
        bufp->chgCData(oldp+12,(vlSelf->cpu__DOT__the_ram__DOT__memory
                                [(0xffU & (IData)(vlSelf->cpu__DOT__instruction))]),8);
        bufp->chgBit(oldp+13,((0xcU == (0xfU & ((IData)(vlSelf->cpu__DOT__instruction) 
                                                >> 0xcU)))));
        bufp->chgBit(oldp+14,((0xeU == (0xfU & ((IData)(vlSelf->cpu__DOT__instruction) 
                                                >> 0xcU)))));
        bufp->chgBit(oldp+15,((0xfU == (0xfU & ((IData)(vlSelf->cpu__DOT__instruction) 
                                                >> 0xcU)))));
        bufp->chgBit(oldp+16,((0U == (IData)(vlSelf->cpu__DOT__alu_result))));
        bufp->chgCData(oldp+17,(((9U == (0xfU & ((IData)(vlSelf->cpu__DOT__instruction) 
                                                 >> 0xcU)))
                                  ? 1U : 0U)),2);
        bufp->chgCData(oldp+18,(vlSelf->cpu__DOT__the_regs__DOT__registers[0]),8);
        bufp->chgCData(oldp+19,(vlSelf->cpu__DOT__the_regs__DOT__registers[1]),8);
        bufp->chgCData(oldp+20,(vlSelf->cpu__DOT__the_regs__DOT__registers[2]),8);
        bufp->chgCData(oldp+21,(vlSelf->cpu__DOT__the_regs__DOT__registers[3]),8);
    }
    bufp->chgBit(oldp+22,(vlSelf->clk));
    bufp->chgBit(oldp+23,(vlSelf->reset));
}

void Vcpu___024root__trace_cleanup(void* voidSelf, VerilatedVcd* /*unused*/) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vcpu___024root__trace_cleanup\n"); );
    // Init
    Vcpu___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vcpu___024root*>(voidSelf);
    Vcpu__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    // Body
    vlSymsp->__Vm_activity = false;
    vlSymsp->TOP.__Vm_traceActivity[0U] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[1U] = 0U;
}
