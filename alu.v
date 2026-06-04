module alu (
    input  [7:0] a,      // 8-bit input A
    input  [7:0] b,      // 8-bit input B
    input  [1:0] op,     // 2-bit operation code
    output reg [7:0] out // 8-bit output
);

    // This block executes whenever any input (a, b, or op) changes
    always @(*) begin
        case (op)
            2'b00: out = a + b;   // Opcode 0: ADD
            2'b01: out = a - b;   // Opcode 1: SUBTRACT
            2'b10: out = a & b;   // Opcode 2: BITWISE AND
            2'b11: out = a | b;   // Opcode 3: BITWISE OR
            default: out = 8'b0;  // Fallback
        endcase
    end

endmodule