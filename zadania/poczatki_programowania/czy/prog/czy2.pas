(*
 * Zadanie: Czy sie zatrzyma?
 *  Rozwiazanie alternatywne 2
 * Autor: Jakub Lacki
 *)

var n : int64;

begin
	readln(n);
	while n > 1 do begin
		if n mod 2 = 0 then
			n := n div 2
		else begin
			writeln('NIE');
			exit;
		end;
	end;
	writeln('TAK');
end.
