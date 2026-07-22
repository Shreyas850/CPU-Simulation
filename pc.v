module pc (
    input            clk,
    input            reset,
    input            jump_enable,   // Unconditional Jump (Opcode E)
    input            branch_enable, // Conditional Branch (Opcode F)
    input            zero_flag,     // From the ALU
    input      [7:0] target_addr,   // Where to teleport to
    output reg [7:0] pc_out
);

    always @(posedge clk) begin
        if (reset) begin
            pc_out <= 8'b0;
        // Jump if Opcode E, OR if Opcode F AND the ALU output is zero
        end else if (jump_enable || (branch_enable && zero_flag)) begin
            pc_out <= target_addr;
        end else begin
            pc_out <= pc_out + 1;
        end
    end

endmodule