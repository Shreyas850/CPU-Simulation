module ram (
    input        clk,
    input        write_enable,  // 1 = Save to RAM, 0 = Read from RAM
    input  [7:0] address,       // Which of the 256 slots to access
    input  [7:0] write_data,    // The data to save
    output [7:0] read_data      // The data coming out
);

    // Create 256 individual 8-bit memory slots
    reg [7:0] memory [255:0];

    // READ: Happens instantly based on the address wire
    assign read_data = memory[address];

    // WRITE: Happens exactly on the clock tick
    always @(posedge clk) begin
        if (write_enable) begin
            memory[address] <= write_data;
        end
    end

endmodule