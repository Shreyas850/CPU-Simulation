module rom (
    input      [7:0] address,
    output reg [15:0] instruction
);
    always @(*) begin
        case (address)
            8'd0: instruction = 16'hA105; // LOAD R1, 5
            8'd1: instruction = 16'hA205; // LOAD R2, 5
            8'd2: instruction = 16'h9012; // SUB R0, R1, R2
            8'd3: instruction = 16'hF006; // BEQ 6
            8'd4: instruction = 16'hA30A; // LOAD R3, 10
            8'd5: instruction = 16'hFFFF; // HALT
            8'd6: instruction = 16'hA3FF; // LOAD R3, 255
            8'd7: instruction = 16'hFFFF; // HALT
            default: instruction = 16'h0000;
        endcase
    end
endmodule
