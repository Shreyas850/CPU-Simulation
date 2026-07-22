import os

def assemble_instruction(line):
    # Strip out comments and whitespace
    line = line.split('//')[0].strip()
    if not line: 
        return None
    
    # Remove commas and split into parts (e.g., ["LOAD", "R1", "5"])
    parts = line.replace(',', '').split()
    cmd = parts[0].upper()
    
    try:
        if cmd == "LOAD":       return f"A{parts[1][-1]}{int(parts[2]):02X}"
        if cmd == "ADD":        return f"8{parts[1][-1]}{parts[2][-1]}{parts[3][-1]}"
        if cmd == "SUB":        return f"9{parts[1][-1]}{parts[2][-1]}{parts[3][-1]}"
        if cmd == "STORE":      return f"C{parts[1][-1]}{int(parts[2]):02X}"
        if cmd == "LOAD_RAM":   return f"D{parts[1][-1]}{int(parts[2]):02X}"
        if cmd == "JUMP":       return f"E0{int(parts[1]):02X}"
        if cmd == "BEQ":        return f"F0{int(parts[1]):02X}"
        if cmd == "HALT":       return "FFFF"
        return "0000"
    except Exception as e:
        print(f"Syntax Error on line: {line}")
        return "0000"

# 1. Read the Assembly File
with open("program.asm", "r") as f:
    lines = f.readlines()

# 2. Setup the Verilog Wrapper
verilog_code = [
    "module rom (",
    "    input      [7:0] address,",
    "    output reg [15:0] instruction",
    ");",
    "    always @(*) begin",
    "        case (address)"
]

# 3. Parse and Translate
addr = 0
for line in lines:
    hex_code = assemble_instruction(line)
    if hex_code:
        # Write the hardcoded Verilog line
        clean_line = line.split('//')[0].strip()
        verilog_code.append(f"            8'd{addr}: instruction = 16'h{hex_code}; // {clean_line}")
        addr += 1

# 4. Close the Verilog Wrapper
verilog_code.append("            default: instruction = 16'h0000;")
verilog_code.append("        endcase")
verilog_code.append("    end")
verilog_code.append("endmodule\n")

# 5. Overwrite rom.v
with open("rom.v", "w") as f:
    f.write("\n".join(verilog_code))

print(f"Success: Assembled {addr} instructions and generated rom.v!")