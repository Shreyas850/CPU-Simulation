module rom (
    input      [7:0] address,
    output reg [15:0] instruction
);
    always @(*) begin
        case (address)
            8'd0: instruction = 16'hA105; // LOAD R1, 5
            8'd1: instruction = 16'hA201; // LOAD R2, 1
            8'd2: instruction = 16'h9112; // SUB R1, R1, R2
            8'd3: instruction = 16'hF005; // BEQ 5
            8'd4: instruction = 16'hE002; // JUMP 2
            8'd5: instruction = 16'hFFFF; // HALT
            default: instruction = 16'h0000;
        endcase
    end
endmodule
