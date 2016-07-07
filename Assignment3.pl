/* room(Room,Plume,Puffs,Guest). */ 

roomList([room(_,_,6,_),room(_,_,7,_),room(_,_,8,_),room(_,_,9,_),room(_,_,10,_)]).

solution(A) :- roomList(A),
	       member(room(_,_,_,keith), A),
	       member(room(diningroom,_,_,_), A),
	       member(room(_,summer-joy,_,_), A),
	       member(room(den,_,_,pedro), A),                 /* Rule 1 */
	       member(room(_,_,8,daniela), A),                 /* Rule 2 */
               member(room(livingroom,mystery-glen,_,_), A),   /* Rule 3 */
	       member(room(_,desert-flora,7,_), A),            /* Rule 4 */
	       member(room(bathroom,_,V,_), A),                /* Rule 5 */
	       member(room(_,_,P,renee), A),                   /* Rule 5 */
	       member(room(_,papaya-paradise,E,_), A), P=:=E-1, /* Rule 5 */
	       member(room(_,papaya-paradise,E,_), A), V=:=E+1, /* Rule 5 */
	       member(room(_,_,H,tina), A),                    /* Rule 6 */
	       member(room(kitchen,_,L,_), A),                 /* Rule 6 */
	       member(room(_,sweet-breeze,T,_), A), H>T,        /* Rule 6 */
	       member(room(_,sweet-breeze,J,_), A), L=:=J-1.    /* Rule 6 */
	       
	       

