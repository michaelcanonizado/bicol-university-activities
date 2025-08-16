        IDENTIFICATION DIVISION.
        PROGRAM-ID STRUCTURES.
      
        DATA DIVISION.
        WORKING-STORAGE SECTION.
        01 student-data.
            02 student OCCURS 10 TIMES.
                03 name PIC X(10).
                03 sex PIC X.
                03 bday.
                    04 bday_day PIC 99.
                    04 bday_month PIC 99.
                    04 bday_year PIC 9999.

        PROCEDURE DIVISION.
             MOVE "jack me hoff" TO name(1).
             MOVE "m" TO sex(1).
             MOVE 1 TO bday_day(1).
             MOVE 1 TO bday_month(1).
             MOVE 2025 TO bday_year(1).

             DISPLAY name(1).
             DISPLAY sex(1).
             DISPLAY bday_day 1).
             DISPLAY bday_month(1).
             DISPLAY bday_year(1).
             STOP RUN.

