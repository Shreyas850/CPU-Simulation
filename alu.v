module alu (
    input  [7:0] a,
    input  [7:0] b,
    input  [1:0] op,
    output reg [7:0] out,
    output       zero      // NEW: The Zero Flag
);

    always @(*) begin
        case (op)
            2'b00: out = a + b;
            2'b01: out = a - b;
            2'b10: out = a & b;
            2'b11: out = a | b;
            default: out = 8'b0;
        endcase
    end

    // The zero flag is physically wired to check if all 8 bits of 'out' are 0
    assign zero = (out == 8'b0);

endmodule