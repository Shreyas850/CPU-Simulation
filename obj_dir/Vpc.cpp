// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Model implementation (design independent parts)

#include "Vpc__pch.h"
#include "verilated_vcd_c.h"

//============================================================
// Constructors

Vpc::Vpc(VerilatedContext* _vcontextp__, const char* _vcname__)
    : VerilatedModel{*_vcontextp__}
    , vlSymsp{new Vpc__Syms(contextp(), _vcname__, this)}
    , clk{vlSymsp->TOP.clk}
    , reset{vlSymsp->TOP.reset}
    , pc_out{vlSymsp->TOP.pc_out}
    , rootp{&(vlSymsp->TOP)}
{
    // Register model with the context
    contextp()->addModel(this);
    contextp()->traceBaseModelCbAdd(
        [this](VerilatedTraceBaseC* tfp, int levels, int options) { traceBaseModel(tfp, levels, options); });
}

Vpc::Vpc(const char* _vcname__)
    : Vpc(Verilated::threadContextp(), _vcname__)
{
}

//============================================================
// Destructor

Vpc::~Vpc() {
    delete vlSymsp;
}

//============================================================
// Evaluation function

#ifdef VL_DEBUG
void Vpc___024root___eval_debug_assertions(Vpc___024root* vlSelf);
#endif  // VL_DEBUG
void Vpc___024root___eval_static(Vpc___024root* vlSelf);
void Vpc___024root___eval_initial(Vpc___024root* vlSelf);
void Vpc___024root___eval_settle(Vpc___024root* vlSelf);
void Vpc___024root___eval(Vpc___024root* vlSelf);

void Vpc::eval_step() {
    VL_DEBUG_IF(VL_DBG_MSGF("+++++TOP Evaluate Vpc::eval_step\n"); );
#ifdef VL_DEBUG
    // Debug assertions
    Vpc___024root___eval_debug_assertions(&(vlSymsp->TOP));
#endif  // VL_DEBUG
    vlSymsp->__Vm_activity = true;
    vlSymsp->__Vm_deleter.deleteAll();
    if (VL_UNLIKELY(!vlSymsp->__Vm_didInit)) {
        vlSymsp->__Vm_didInit = true;
        VL_DEBUG_IF(VL_DBG_MSGF("+ Initial\n"););
        Vpc___024root___eval_static(&(vlSymsp->TOP));
        Vpc___024root___eval_initial(&(vlSymsp->TOP));
        Vpc___024root___eval_settle(&(vlSymsp->TOP));
    }
    VL_DEBUG_IF(VL_DBG_MSGF("+ Eval\n"););
    Vpc___024root___eval(&(vlSymsp->TOP));
    // Evaluate cleanup
    Verilated::endOfEval(vlSymsp->__Vm_evalMsgQp);
}

//============================================================
// Events and timing
bool Vpc::eventsPending() { return false; }

uint64_t Vpc::nextTimeSlot() {
    VL_FATAL_MT(__FILE__, __LINE__, "", "%Error: No delays in the design");
    return 0;
}

//============================================================
// Utilities

const char* Vpc::name() const {
    return vlSymsp->name();
}

//============================================================
// Invoke final blocks

void Vpc___024root___eval_final(Vpc___024root* vlSelf);

VL_ATTR_COLD void Vpc::final() {
    Vpc___024root___eval_final(&(vlSymsp->TOP));
}

//============================================================
// Implementations of abstract methods from VerilatedModel

const char* Vpc::hierName() const { return vlSymsp->name(); }
const char* Vpc::modelName() const { return "Vpc"; }
unsigned Vpc::threads() const { return 1; }
void Vpc::prepareClone() const { contextp()->prepareClone(); }
void Vpc::atClone() const {
    contextp()->threadPoolpOnClone();
}
std::unique_ptr<VerilatedTraceConfig> Vpc::traceConfig() const {
    return std::unique_ptr<VerilatedTraceConfig>{new VerilatedTraceConfig{false, false, false}};
};

//============================================================
// Trace configuration

void Vpc___024root__trace_decl_types(VerilatedVcd* tracep);

void Vpc___024root__trace_init_top(Vpc___024root* vlSelf, VerilatedVcd* tracep);

VL_ATTR_COLD static void trace_init(void* voidSelf, VerilatedVcd* tracep, uint32_t code) {
    // Callback from tracep->open()
    Vpc___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vpc___024root*>(voidSelf);
    Vpc__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    if (!vlSymsp->_vm_contextp__->calcUnusedSigs()) {
        VL_FATAL_MT(__FILE__, __LINE__, __FILE__,
            "Turning on wave traces requires Verilated::traceEverOn(true) call before time 0.");
    }
    vlSymsp->__Vm_baseCode = code;
    tracep->pushPrefix(std::string{vlSymsp->name()}, VerilatedTracePrefixType::SCOPE_MODULE);
    Vpc___024root__trace_decl_types(tracep);
    Vpc___024root__trace_init_top(vlSelf, tracep);
    tracep->popPrefix();
}

VL_ATTR_COLD void Vpc___024root__trace_register(Vpc___024root* vlSelf, VerilatedVcd* tracep);

VL_ATTR_COLD void Vpc::traceBaseModel(VerilatedTraceBaseC* tfp, int levels, int options) {
    (void)levels; (void)options;
    VerilatedVcdC* const stfp = dynamic_cast<VerilatedVcdC*>(tfp);
    if (VL_UNLIKELY(!stfp)) {
        vl_fatal(__FILE__, __LINE__, __FILE__,"'Vpc::trace()' called on non-VerilatedVcdC object;"
            " use --trace-fst with VerilatedFst object, and --trace with VerilatedVcd object");
    }
    stfp->spTrace()->addModel(this);
    stfp->spTrace()->addInitCb(&trace_init, &(vlSymsp->TOP));
    Vpc___024root__trace_register(&(vlSymsp->TOP), stfp->spTrace());
}
