student(alden, cs, 20).
student(sophia, chem, 18).
student(jacob, ce, 17).

college(cs, science).
college(it, science).
college(bio, science).
college(chem, science).
college(met, science).
college(ce, engineering).

student_in_college(Student, Department, _) :- 
    student(Student, Department, _).

student_in_college(Student, College, _) :-
    student(Student, Department, _),
    college(Department, College).

student_in_college_of_science(Student) :-
    student_in_college(Student, science, _).

pwedeng_uminom_na_student(Name, Course, Age) :-
    student(Name, Course, Age),
    Age >= 18.