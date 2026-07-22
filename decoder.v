module decoder (
    input  [15:0] instruction,

    // Sliced Outputs
    output [3:0]  opcode,
    output [1:0]  rd,      // Destination Register (Only need 2 bits for 0-3)
    output [1:0]  rs1,     // Source Register 1
    output [1:0]  rs2,     // Source Register 2
    output [7:0]  imm      // Immediate Value
);

    // Hard-wire the slices directly to the outputs
    assign opcode = instruction[15:12];
    assign rd     = instruction[9:8];   // We only take the bottom 2 bits of this hex digit
    assign rs1    = instruction[5:4];   // We only take the bottom 2 bits of this hex digit
    assign rs2    = instruction[1:0];   // We only take the bottom 2 bits of this hex digit
    assign imm    = instruction[7:0];   // The bottom 8 bits form a number

endmodule