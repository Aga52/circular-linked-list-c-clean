
# C kalbos kodavimo stiliaus gairės

## 1. Pavadinimų sudarymo taisyklės

### 1.1. Kintamieji

Kintamųjų pavadinimai turi būti prasmingi ir aiškiai nusakyti jų paskirtį.

Naudojamas camelCase stilius: pirmasis žodis rašomas mažąja raide, o kiekvienas kitas prasideda didžiąja raide.

Geras pavyzdys:

```c
int targetValue;
int newValue;
Node *currentNode;
```

Blogas pavyzdys:

```c
int a;
int x;
Node *p;
```

### 1.2. Funkcijos

Funkcijų pavadinimams taip pat naudojamas camelCase stilius. Pavadinimas turi nusakyti atliekamą veiksmą.

Geras pavyzdys:

```c
createList();
insertBefore();
printList();
```

Blogas pavyzdys:

```c
func1();
doIt();
abc();
```


### 1.3. Struktūros

Struktūrų tipų pavadinimai rašomi PascalCase stiliumi – kiekvienas žodis prasideda didžiąja raide.

Geras pavyzdys:

```c
typedef struct Node
{
    int value;
    struct Node *next;
} Node;
```

Blogas pavyzdys:

```c
typedef struct node
{
    int x;
    struct node *p;
} node;
```

### 1.4. Konstantos

Konstantų ir makrokomandų pavadinimai rašomi didžiosiomis raidėmis, žodžius atskiriant pabraukimo simboliu (_).

Geras pavyzdys:

```c
#define MAX_INPUT_LENGTH 256
#define MAX_FILE_NAME 100
```

Blogas pavyzdys:

```c
#define maxInputLength 256
#define n 100
```

## 2. Kodo formatavimas

### 2.1. Įtraukos

Kiekvienam kodo blokui naudojami 4 tarpai. Tabuliacija kodo lygiavimui nenaudojama.

Geras pavyzdys:

```c
if (value > 0)
{
    printf("%d\n", value);
}
```

Blogas pavyzdys:

```c
if(value>0)
{
printf("%d\n",value);
}
```

### 2.2. Figūriniai skliaustai

Atidaromasis figūrinis skliaustas rašomas naujoje eilutėje. Uždaromasis skliaustas taip pat rašomas atskiroje eilutėje.

Figūriniai skliaustai naudojami net tada, kai sąlygos ar ciklo kūną sudaro tik vienas sakinys.

Geras pavyzdys:

```c
if (currentNode == NULL)
{
    return;
}
```

Blogas pavyzdys:

```c
if (currentNode == NULL) return;
```

### 2.3. Tarpai

Aplink priskyrimo ir palyginimo operatorius paliekami tarpai.

Po kablelio paliekamas vienas tarpas.

Tarp valdymo konstrukcijos pavadinimo ir atidaromojo skliausto paliekamas tarpas.

Geras pavyzdys:

```c
int sum = a + b;

if (sum == 10)
{
    printf("%d\n", sum);
}
```

Blogas pavyzdys:

```c
int sum=a+b;
if(sum==10)
{
    printf("%d\n",sum);
}
```

## 3. Funkcijų rašymo taisyklės

### 3.1. Funkcijų paskirtis

Kiekviena funkcija turi atlikti vieną aiškiai apibrėžtą užduotį.

Funkcijų pavadinimai turi nusakyti jų atliekamą veiksmą.

Geras pavyzdys:

```c
void printList(const Node *head, FILE *output);
void destroyList(Node **head);
```

Blogas pavyzdys:

```c
void doEverything();
```

### 3.2. Funkcijų deklaracijos

Viešai naudojamų funkcijų deklaracijos rašomos antraštiniuose failuose (.h). Tik viename .c faile naudojamos pagalbinės funkcijos gali būti deklaruojamos tame pačiame faile ir pažymimos static.

## 4. Rodyklių naudojimas

Rodyklės deklaruojamos rašant žvaigždutę (*) prie kintamojo pavadinimo.

Geras pavyzdys:

```c
Node *currentNode;
Node *newNode;
```

Blogas pavyzdys pagal pasirinktą stilių:

```c
Node* currentNode;
Node* newNode;
```

Prieš naudojant dinamiškai išskirtą atmintį, būtina patikrinti, ar jos išskyrimas pavyko.

## 5. Komentarai

Komentarai naudojami tik tada, kai reikia paaiškinti sudėtingesnę programos logiką.

Komentarai neturi kartoti to, kas jau aišku iš kodo.

Geras pavyzdys:

```c
// Paskutinis elementas rodo į pirmąjį.
lastNode->next = head;
```

Blogas pavyzdys:

```c
// Priskiriame 10 kintamajam value.
int value = 10;
```

## 6. Failų organizavimas

Programa skaidoma į atskirus failus pagal jų paskirtį.

- main.c – pagrindinė programa, vartotojo meniu ir darbas su failais.
- list.c – ciklinio vienpusio sąrašo funkcijų realizacijos.
- list.h – struktūrų apibrėžimai ir funkcijų deklaracijos.
- tests.c – vienetiniai testai naudojant assert.
- Makefile – programos ir testų kompiliavimas.

Antraštiniuose failuose naudojamos apsaugos nuo pakartotinio įtraukimo:

```c
#ifndef LIST_H
#define LIST_H

// Struktūros ir funkcijų deklaracijos.

#endif
```

## 7. Atminties valdymas

Dinaminė atmintis išskiriama naudojant malloc, calloc arba realloc.

Kiekvienas sėkmingas atminties išskyrimas turi turėti atitinkamą atlaisvinimą naudojant free.

Programa neturi palikti atminties nutekėjimų.

## 8. Kodo nuoseklumas

Visuose programos failuose laikomasi vienodo kodavimo stiliaus.

Negalima maišyti skirtingų pavadinimų sudarymo ar kodo lygiavimo būdų.
