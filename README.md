				__Echipa: BreakIt__
					Membri: Apostu Diana
						Orzata Miruna
						Dobrete Vlad


	__Instructiuni de compilare__
Pentru a putea compila proiectul, se apeleaza fisierul Makefile cu regula make.
Dupa acest pas, apeland make run se va rula executabilul.

       __PUNCTAJ__
Am rulat de 20 de ori cele 10 runde si media de puncte obtinuta este de cel putin 5,5.

	__Detalii despre structura proiectului si implementare__
Pentru a putea face posibila implementarea cat mai eficienta a jocului de sah,
am creat o clasa generala pentru piese intitulata Piece. Aceasta contine toate
atributele necesare unei piese: culoare, id, tip de piese, coordonate
si desigur o variabila bool prin care vedem daca piesa este sau nu capturata.
Am ales sa facem clasa pentru a putea implementa functii necesare pe parcursul
jocului. Am creat un vector de piese si desigur, o tabla(matrice) de piese astfel
incat fiecare patratita sa fie ori o piesa de sah, ori o piesa NONE(patratica
goala).Dupa initializarea tablei de sah(SETBOARD), dupa regulile existente, am
implementat functiile:

-->mini si maxi alpha beta pruning: se cauta cea mai eficienta miscare.
Pentru fiecare miscare incercata, cream o tabla noua pentru a o trimte mai departe.
Generam miscarile in functie de raspunsul functiei care ne arata daca suntem sau nu
in sah.
Pornim recursivitatea doar daca miscarea setata nu ne baga in sah.

--> generateAllMoves : generam toate miscarile posibile pentru toate piesele. Avem cate o 
functie separata de generare pt fiecare piesa.
Sortam mereu lista obtinuta dupa miscarile care pot captura piese.

--> generateAllMovesForEscapingFromCheck: generam doar miscarile care scapa regele de sah/

-->isCheck: vedem daca regele este in sah cautand pe diagonale dupa nebuni, regina, pion sau
pe verticala si orizontala dupa ture sau regina.

-->setMove: functie care updateaza tabla cu miscarea primita/

-->make Move: apeleaza maxi si trimite la xboard miscarea aleasa ca fiind cea mai eficienta/
Trimite resign daca nu mai avem miscari/

--> evaluate: contine euristici care fac robotul sa efectueze in prim plan rocadele
sau miscarile care aduc cele mai multe puncte din matricile de punctaje/

-->updatePiecesArray: updatam vectorul de piese dupa ce setam miscarile/

Cazurile de castling le tratam separat in functie de culoare si de tipul de rocada.


Cat despre legatura engine - xboard, am implementat comenzile cerute:

-->white && black: schimba culoarea botului
-->force: face mutarii cu ceasul oprit(botul doar updateaza tabla cu miscarile primite)
-->go : iese din force sau se da dupa ce se schimba culoarea
-->resign si quit
-->new: creeaza o tabla noua si reinitializeaza vectorul de piese
-->usermove: primeste de la xboard si se apeleaza functia setMOVE explicata mai sus pentru
a updata

Responsabilitatea membrilor:
__EFORT_COMUN__: Logica totala a jocului, legarea partilor de la toti membrii, debugging,
functiile principale (makeMove,setMove,minimax etc...).
-->Apostu Diana Croitoru: generarea miscarilor, sah, minimax, rocada
-->Dobrete Vlad-Gabriel: generarea miscarilor, rocada, euristica, minimax
-->Orzata Miruna-Narcisa: generarea miscarilor, en passant, minimax, sah



Surse de inspiratie:

-->Documentatie : https://www.gnu.org/software/xboard/engine-intf.html, stack overflow
		  https://helpmanual.io/man6/xboard/
-->Videoclipuri relevante xboard-ului : https://www.youtube.com/watch?v=N20YQZ7xmjE
					(how to use chess engines?)
