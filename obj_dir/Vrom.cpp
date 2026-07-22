// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Model implementation (design independent parts)

#include "Vrom__pch.h"
#include "verilated_vcd_c.h"

//============================================================
// Constructors

Vrom::Vrom(VerilatedContext* _vcontextp__, const char* _vcname__)
    : VerilatedModel{*_vcontextp__}
    , vlSymsp{new Vrom__Syms(contextp(), _vcname__, this)}
    , address{vlSymsp->TOP.address}
    , instruction{vlSymsp->TOP.instruction}
    , rootp{&(vlSymsp->TOP)}
{
    // Register model with the context
    contextp()->addModel(this);
    contextp()->traceBaseModelCbAdd(
        [this](VerilatedTraceBaseC* tfp, int levels, int options) { traceBaseModel(tfp, levels, options); });
}

Vrom::Vrom(const char* _vcname__)
    : Vrom(Verilated::threadContextp(), _vcname__)
{
}

//============================================================
// Destructor

Vrom::~Vrom() {
    delete vlSymsp;
}

//============================================================
// Evaluation function

#ifdef VL_DEBUG
void Vrom___024root___eval_debug_assertions(Vrom___024root* vlSelf);
#endif  // VL_DEBUG
void Vrom___024root___eval_static(Vrom___024root* vlSelf);
void Vrom___024root___eval_initial(Vrom___024root* vlSelf);
void Vrom___024root___eval_settle(Vrom___024root* vlSelf);
void Vrom___024root___eval(Vrom___024root* vlSelf);

void Vrom::eval_step() {
    VL_DEBUG_IF(VL_DBG_MSGF("+++++TOP Evaluate Vrom::eval_step\n"); );
#ifdef VL_DEBUG
    // Debug assertions
    Vrom___024root___eval_debug_assertions(&(vlSymsp->TOP));
#endif  // VL_DEBUG
    vlSymsp->__Vm_activity = true;
    vlSymsp->__Vm_deleter.deleteAll();
    if (VL_UNLIKELY(!vlSymsp->__Vm_didInit)) {
        vlSymsp->__Vm_didInit = true;
        VL_DEBUG_IF(VL_DBG_MSGF("+ Initial\n"););
        Vrom___024root___eval_static(&(vlSymsp->TOP));
        Vrom___024root___eval_initial(&(vlSymsp->TOP));
        Vrom___024root___eval_settle(&(vlSymsp->TOP));
    }
    VL_DEBUG_IF(VL_DBG_MSGF("+ Eval\n"););
    Vrom___024root___eval(&(vlSymsp->TOP));
    // Evaluate cleanup
    Verilated::endOfEval(vlSymsp->__Vm_evalMsgQp);
}

//============================================================
// Events and timing
bool Vrom::eventsPending() { return false; }

uint64_t Vrom::nextTimeSlot() {
    VL_FATAL_MT(__FILE__, __LINE__, "", "%Error: No delays in the design");
    return 0;
}

//============================================================
// Utilities

const char* Vrom::name() const {
    return vlSymsp->name();
}

//============================================================
// Invoke final blocks

void Vrom___024root___eval_final(Vrom___024root* vlSelf);

VL_ATTR_COLD void Vrom::final() {
    Vrom___024root___eval_final(&(vlSymsp->TOP));
}

//============================================================
// Implementations of abstract methods from VerilatedModel

const char* Vrom::hierName() const { return vlSymsp->name(); }
const char* Vrom::modelName() const { return "Vrom"; }
unsigned Vrom::threads() const { return 1; }
void Vrom::prepareClone() const { contextp()->prepareClone(); }
void Vrom::atClone() const {
    contextp()->threadPoolpOnClone();
}
std::unique_ptr<VerilatedTraceConfig> Vrom::traceConfig() const {
    return std::unique_ptr<VerilatedTraceConfig>{new VerilatedTraceConfig{false, false, false}};
};

//============================================================
// Trace configuration

void Vrom___024root__trace_decl_types(VerilatedVcd* tracep);

void Vrom___024root__trace_init_top(Vrom___024root* vlSelf, VerilatedVcd* tracep);

VL_ATTR_COLD static void trace_init(void* voidSelf, VerilatedVcd* tracep, uint32_t code) {
    // Callback from tracep->open()
    Vrom___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vrom___024root*>(voidSelf);
    Vrom__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    if (!vlSymsp->_vm_contextp__->calcUnusedSigs()) {
        VL_FATAL_MT(__FILE__, __LINE__, __FILE__,
            "Turning on wave traces requires Verilated::traceEverOn(true) call before time 0.");
    }
    vlSymsp->__Vm_baseCode = code;
    tracep->pushPrefix(std::string{vlSymsp->name()}, VerilatedTracePrefixType::SCOPE_MODULE);
    Vrom___024root__trace_decl_types(tracep);
    Vrom___024root__trace_init_top(vlSelf, tracep);
    tracep->popPrefix();
}

VL_ATTR_COLD void Vrom___024root__trace_register(Vrom___024root* vlSelf, VerilatedVcd* tracep);

VL_ATTR_COLD void Vrom::traceBaseModel(VerilatedTraceBaseC* tfp, int levels, int options) {
    (void)levels; (void)options;
    VerilatedVcdC* const stfp = dynamic_cast<VerilatedVcdC*>(tfp);
    if (VL_UNLIKELY(!stfp)) {
        vl_fatal(__FILE__, __LINE__, __FILE__,"'Vrom::trace()' called on non-VerilatedVcdC object;"
            " use --trace-fst with VerilatedFst object, and --trace with VerilatedVcd object");
    }
    stfp->spTrace()->addModel(this);
    stfp->spTrace()->addInitCb(&trace_init, &(vlSymsp->TOP));
    Vrom___024root__trace_register(&(vlSymsp->TOP), stfp->spTrace());
}
