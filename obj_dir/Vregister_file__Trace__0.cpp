// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "Vregister_file__Syms.h"


void Vregister_file___024root__trace_chg_0_sub_0(Vregister_file___024root* vlSelf, VerilatedVcd::Buffer* bufp);

void Vregister_file___024root__trace_chg_0(void* voidSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vregister_file___024root__trace_chg_0\n"); );
    // Init
    Vregister_file___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vregister_file___024root*>(voidSelf);
    Vregister_file__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    if (VL_UNLIKELY(!vlSymsp->__Vm_activity)) return;
    // Body
    Vregister_file___024root__trace_chg_0_sub_0((&vlSymsp->TOP), bufp);
}

void Vregister_file___024root__trace_chg_0_sub_0(Vregister_file___024root* vlSelf, VerilatedVcd::Buffer* bufp) {
    (void)vlSelf;  // Prevent unused variable warning
    Vregister_file__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vregister_file___024root__trace_chg_0_sub_0\n"); );
    // Init
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode + 1);
    // Body
    if (VL_UNLIKELY(vlSelf->__Vm_traceActivity[1U])) {
        bufp->chgCData(oldp+0,(vlSelf->register_file__DOT__registers[0]),8);
        bufp->chgCData(oldp+1,(vlSelf->register_file__DOT__registers[1]),8);
        bufp->chgCData(oldp+2,(vlSelf->register_file__DOT__registers[2]),8);
        bufp->chgCData(oldp+3,(vlSelf->register_file__DOT__registers[3]),8);
    }
    bufp->chgBit(oldp+4,(vlSelf->clk));
    bufp->chgBit(oldp+5,(vlSelf->write_enable));
    bufp->chgCData(oldp+6,(vlSelf->write_addr),2);
    bufp->chgCData(oldp+7,(vlSelf->write_data),8);
    bufp->chgCData(oldp+8,(vlSelf->read_addr_a),2);
    bufp->chgCData(oldp+9,(vlSelf->read_addr_b),2);
    bufp->chgCData(oldp+10,(vlSelf->read_data_a),8);
    bufp->chgCData(oldp+11,(vlSelf->read_data_b),8);
}

void Vregister_file___024root__trace_cleanup(void* voidSelf, VerilatedVcd* /*unused*/) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vregister_file___024root__trace_cleanup\n"); );
    // Init
    Vregister_file___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vregister_file___024root*>(voidSelf);
    Vregister_file__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    // Body
    vlSymsp->__Vm_activity = false;
    vlSymsp->TOP.__Vm_traceActivity[0U] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[1U] = 0U;
}
