// TEST PROGRAM: Branching Logic
LOAD R1, 5
LOAD R2, 5
SUB R0, R1, R2
BEQ 6          // If R1 - R2 == 0, jump to line 6
LOAD R3, 10    // This line gets skipped!
HALT
LOAD R3, 255   // Line 6: Safe landing zone!
HALT