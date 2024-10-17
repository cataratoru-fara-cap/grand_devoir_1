# grand-devoir
Exercitii

Ex 1:
 
Am o clasa FlightBookingSystem care are 2 structuri, una struct Node si una struct Vol. Node contine un sir de caractere passangerName si adresa urmatorului nod si un constructor. struct Vol contine un pointer care memoreaza adresa unei liste inlantuite de nume si un pointer care trimite la urmatorul nod, un constructor si mai are o functie care verifica daca zborul e full. BookSeat() care are ca parametru un nume verifica daca lista de zboruri e vida sau daca zborul e full. In acest caz creeaza un nou zbor si il leaga de pointerul head. In caz contrar, creeaza un nod nou cu numele si il leaga de nodul anterior. Functia CancelBooking() are ca parametru numarul locului si verifica fiecare zbor in parte. Daca nodul corespunzator locului exista, este diferit de null, va fi eliberat din memorie, iar pasagerul anterior ii va ocupa locul. Functia DisplaySystem() afiseaza toate zborurile cu toti pasagerii, iar functia GetPassanger() care are ca parametru numarul locului cauta prin toate zborurile, iar daca pasagerul se afla la locul furnizat, numele acestuia va fi returnat de functie. Functia main() initializeaza sistemul si creeaza un meniu care poate fi accesat introducand de la tastatura indicii fiecarei linii.


Ex 2:

Codul foloseste o struct Oaza care contine parametrii din cerinta si o implementare a clasei Queue care are 2 variabile intregi cap si coada si un vector de clase Queue. Mai are un constructor care intializeaza capul si coada cu 0, o functie enqueue() care imi adauga element in finalul cozii si o functie dequeue care scoate elementul de la inceputul cozii, o functie peek() care verifica lungimea maxima a cozii. Apoi avem 4 functii care verifica daca e goala coada, imi returneaza marimea ei si inceputul si sfarsitul cozii: isEmpty(); size(); start(); end(). OptimalStart() e functia pentru a gasi oaza de plecare optima. In functia aceasta se sorteaza oazele in ordine crescatoare, apoi se calculeaza drumul cel mai scurt. Daca drumul poate fi parcurs returneaza nodul de plecare, daca nu returneaza -1. In functia main() declara si citeste oazele, apeleaza functia si va afisa valoarea returnata de functie sau mesajul “Nu exista oaza de placare optima.” in caz contrar.

Ex 3:

Codul din directory-ul 3 rezolva problema unui calculator aritmetic simplu, folosind transformarea in notatie aritmetica postfixata (reverse polish notation), inputul este primit in notatie aritmetica infixata (standard).

In redactarea acestui program ne-am asumat cateva "libertati" de la cerinta initiala
    -Am folosit stack-ul nu ca atribut al clasei calculator, ci ca variabila intr-o functie din header, logica din spate a fost ca dorim sa segmentam partea de verificare a alocarilor variabileor de parsarea expresiei aritmetice. Momentan codul din infixToPostfix nu verifica si validitatea expresiei
    -Erorile nu apar in fisierul de output, ci in consola, si verificam numai pentru erori de declaratie nu si pentru cele aritmetice
    -Am scris headere custom ca sa nu incarcam cu prea multe lini de cod ex3.cpp (Yey Abstractization)

Ce functioneaza codul:
    ./ex3.cpp = fisierul main pentru program, are definitia pt clasa Calculator si functia main, Clasa calculator preia imput, il proceseaza, si scuipa imput catre un fisier extern
        -Calculator are urmatorii membri:
            
            -pairs : vector <CharIntPair>
            -polish_line : str (contine notatia poloneza-inversa)
            -line : str (contine imputul linie cu linie)
            -letters : const str (avem nevoie pt checking)
            -operators : const str (avem nevoie pt checking)
            
            -readInput() : methoda care citeste inputul
            -execute() : metoda care executa calculul
            -writeOutput() : metoda care scrie rezultatul in fisier

    ./getValueByChar.h = fisier header care contine functia omonima care returneaza nr intreg asociat unui caracter 

    ./eval.h = fisier header care contine def pt functia evaluatePostfix care calculeaza expresia
    (folosind stack)


    ./infixtoPostfix.h = fisier header care contine definitia functiei Omonime care face conversia intre notatii (folosind stack)
    
Lucruri de imbunatatit:
    MORE ERROR HANDLING:
        -segmentation faults si erori legate de localizarea fisierului citit
        -cod care sa verifice validitatea expresiei aritmetice in timp ce o calculam si sa trimita un mesaj de eroare ca output gen "INVALID ARITHMETIC EXPRESSION"
        -extinderea verificarii erorilor de asignare, sa fie mai mult decat un mesaj in terminal, sa scrie in fisierul de output si sa si inchida TOT programul
    EFFICIENTA COD:
        - schimbat structul intr-un HashMap care sa aiba timp de cautare O(1) (momentan este O(n), yey efficiency...)
        - sters #include's care ar fi redundante
    UPGRADE TO USE FLOATS:
        -schimbat cateva lucruri minore in cum procesam imputul si cum evaluam expresia, deoarece la calcul facem schimbarea de la char in valoarea lui fix inainte sa o folosim