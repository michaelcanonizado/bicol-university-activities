% People present in the mansion
was_in_mansion(derek).
was_in_mansion(jomar).
was_in_mansion(bryan).
was_in_mansion(don).

 % People who ate beans
ate_beans(jomar).
ate_beans(bryan).

 % People feeling gassy
feeling_gassy(derek).
feeling_gassy(bryan).
feeling_gassy(jomar).

 % People who left the room l
left_room(derek).
left_room(don).

umutot(X) :- 
    was_in_mansion(X),
    ate_beans(X),
    feeling_gassy(X),
    \+ left_room(X).