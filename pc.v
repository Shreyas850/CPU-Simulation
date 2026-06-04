module pc (
    input            clk,    // The heartbeat
    input            reset,  // 1 = back to 0, 0 = run normally
    output reg [7:0] pc_out  // The current instruction address
);

    // Trigger on the rising edge of the clock
    always @(posedge clk) begin
        if (reset) begin
            pc_out <= 8'b0;      // Reboot to address 0
        end else begin
            pc_out <= pc_out + 1; // Step to the next instruction
        end
    end

endmodule