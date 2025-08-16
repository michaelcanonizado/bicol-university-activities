        identification division.
        PROGRAM-ID. PRACTICE2.

        DATA DIVISION.
        WORKING-STORAGE SECTION.
        01 NUMOFLINES PIC 99.
        01 COUNTER PIC 99.

        PROCEDURE DIVISION.
            DISPLAY "Number: " WITH NO ADVANCING.
            ACCEPT NUMOFLINES.
            
            MOVE 0 TO COUNTER.
            PERFORM LOOP-VIRUS UNTIL COUNTER IS EQUAL TO NUMOFLINES.
            STOP RUN.
            
        LOOP-VIRUS.
            ADD 1 TO COUNTER.
            DISPLAY "Hello World".
