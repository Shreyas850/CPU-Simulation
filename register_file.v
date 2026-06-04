module register_file (
    input        clk,           // The system heartbeat
    input        write_enable,  // 1 = Save data, 0 = Read only
    input  [1:0] write_addr,    // Which register to write to (0 to 3)
    input  [7:0] write_data,    // The actual 8-bit number to save
    input  [1:0] read_addr_a,   // Which register to send to Port A
    input  [1:0] read_addr_b,   // Which register to send to Port B
    output [7:0] read_data_a,   // Data out A (goes to ALU)
    output [7:0] read_data_b    // Data out B (goes to ALU)
);

    // This is the actual physical memory: An array of four 8-bit registers
    reg [7:0] registers [3:0];

    // READ LOGIC: Combinational (happens instantly, no clock needed)
    // Whatever address is requested, instantly output what is in that register.
    assign read_data_a = registers[read_addr_a];
    assign read_data_b = registers[read_addr_b];

    // WRITE LOGIC: Sequential (happens exactly on the clock tick)
    always @(posedge clk) begin
        if (write_enable) begin
            registers[write_addr] <= write_data;
        end
    end

endmodule