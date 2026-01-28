        IDENTIFICATION DIVISION.
        PROGRAM-ID. PRACTICE3.

        DATA DIVISION.
        WORKING-STORAGE SECTION.
        01 GRADE PIC 999.

        PROCEDURE DIVISION.
            DISPLAY "Input your grade: " WITH NO ADVANCING.
            ACCEPT GRADE.

            IF GRADE IS GREATER THAN OR EQUAL TO 075 THEN
                DISPLAY "You passed!"
            END-IF.

            IF GRADE IS LESS THAN 075 THEN
                DISPLAY "You failed!"
            END-IF.

            STOP RUN.
