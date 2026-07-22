module cpu (
    input clk,
    input reset
);

    wire [7:0]  pc_addr;
    wire [15:0] instruction;
    wire [3:0]  opcode;
    wire [1:0]  rd, rs1, rs2;
    wire [7:0]  imm;
    
    wire [7:0]  reg_out_a, reg_out_b;
    wire        reg_write_enable;
    wire [7:0]  reg_write_data;
    wire [7:0]  alu_result;
    
    wire [7:0]  ram_read_data;
    wire        ram_write_enable;

    // --- NEW: LOGIC WIRES ---
    wire        jump_enable   = (opcode == 4'hE); 
    wire        branch_enable = (opcode == 4'hF); // Opcode F is BEQ
    wire        zero_flag;                        // Wire coming from ALU
    wire [1:0]  alu_ctrl      = (opcode == 4'h9) ? 2'b01 : 2'b00; // 9 = SUB, everything else defaults to ADD

    // --- CONTROL LOGIC ---
    // Save to register on A(Load), 8(Add), 9(Subtract), or D(Ram Load)
    assign reg_write_enable = (opcode == 4'hA) || (opcode == 4'h8) || (opcode == 4'h9) || (opcode == 4'hD);
    assign ram_write_enable = (opcode == 4'hC);
    
    assign reg_write_data = (opcode == 4'hA) ? imm :
                            (opcode == 4'hD) ? ram_read_data :
                                               alu_result;

    // --- HARDWARE PLACEMENT ---
    
    pc the_pc (
        .clk(clk), .reset(reset), 
        .jump_enable(jump_enable), .branch_enable(branch_enable), 
        .zero_flag(zero_flag), .target_addr(imm), 
        .pc_out(pc_addr)
    );
    
    rom the_rom (.address(pc_addr), .instruction(instruction));
    decoder the_decoder (.instruction(instruction), .opcode(opcode), .rd(rd), .rs1(rs1), .rs2(rs2), .imm(imm));
    
    register_file the_regs (
        .clk(clk), .write_enable(reg_write_enable), .write_addr(rd), 
        .write_data(reg_write_data), .read_addr_a(rs1), .read_addr_b(rs2), 
        .read_data_a(reg_out_a), .read_data_b(reg_out_b)
    );
    
    alu the_alu (
        .a(reg_out_a), .b(reg_out_b), 
        .op(alu_ctrl), // Dynamic ALU control!
        .out(alu_result), 
        .zero(zero_flag) // Hook up the new zero wire
    );
    
    ram the_ram (.clk(clk), .write_enable(ram_write_enable), .address(imm), .write_data(reg_out_a), .read_data(ram_read_data));

endmodule