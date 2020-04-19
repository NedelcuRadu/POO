# Tema 12. Grafuri

_Se dau urmatoarele clase:_
- Matrice (int **a) – matrice de adiacenta
- Vector (int *v, int dim)
- Lista (Vector *l) – lista de adiacenta
- Graf (int nr_noduri) – clasa abstracta
- Graf_Neorientat(Lista L) : Graf
- Graf_Orientat (Matrice A) :Graf  


Clasele derivate trebuie sa contina constructor parametrizat prin care sa se evidentieze
transmiterea parametrilor catre constructorul din clasa de baza, destructor si o metoda
care sa afiseze vectorul de tati, dacă pentru un Graf Orientat se verifica conexitatea lui
și se da un nod de plecare pe post de rădăcina.

_Cerinte comune tuturor temelor / in principal temelor 1-17:_
1. Toate clase vor conține obligatoriu constructori de inițializare, parametrizati și de
copiere, destructor, iar operatorii >>,<<,= să fie supraincarcati;
2. Clasele derivate trebuie sa contina constructori prin care sa se evidentieze transmiterea
parametrilor către constructorul din clasa de baza;
3. Ilustrarea conceptelor de moștenire și functii virtuale (pure – unde se considera mai
natural);
4. Tratarea exceptiilor;
5. Citirea informațiilor complete a N obiecte, memorarea și afisarea acestora.

## Bonus:
- [X] Move Semantics (using Copy And Swap Idiom)
- [X] Template Functions
- [X] Encapsulation via headers
- [X] Custom exception class
- [ ] Diamond Inheritance
