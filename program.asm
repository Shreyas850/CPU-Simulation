// THE COUNTDOWN LOOP
LOAD R1, 5     // Line 0: Counter = 5
LOAD R2, 1     // Line 1: Decrement value = 1

// Loop Start
SUB R1, R1, R2 // Line 2: Counter = Counter - 1
BEQ 5          // Line 3: If Counter == 0, jump to HALT (Line 5)
JUMP 2         // Line 4: Otherwise, jump back to Line 2

HALT           // Line 5: End of program