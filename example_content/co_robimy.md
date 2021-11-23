## Setup lokalnego repo
* „fork” na github  
    Tworzy kopię repozytorium. Zachowuje się podobnie do nowej gałęzi.
    Możliwe jest wprowadzenia zmian z fork-a
    do pierwotnego repozytorium.

* `git clone git@github.com:[twój username]/gitexample.git`  
    Klonuje repozytorium z github-a na maszynę lokalną.

## Podstawowe działania na repozytorium - status, add, rm, commit, push
* `git checkout basic`
* Modyfikacja plików lokalnie
Np plik `addition.cpp`:
```
    #include <iostream>
    #include "addition.hpp"

    // making changes

    int add(int a, int b) {
        return a + b;
    }
```
* `git status`  
Pokazuje stan repozytorium lokalnego, oraz plików lokalnych
* `git add addition.cpp`  
Dodaje plik `addition.cpp` do obserwowanych plików.  
Analogicznie `git rm addition.cpp` go usuwa.  
Jeśli plik już występuje w repozytorium, możemy go usunąć poprzez `git rm --cached addition.cpp`.  
`git rm` nie usuwa pliku, ale jedynie powoduje, że `git` przestaje go śledzić.
* `git commit -m "quick explanation" -m "more text"`.  
Dodaje zmiany do lokalnego repozytorium.
* `git push`  
Dodaje zmiany do repozytorium zdalnego.

## Pobieranie danych z repozytorium - fetch, pull, stash
* `git checkout get_data`
* przykład na żywo

## Gałęzie - branch, checkout, merge
* `git checkout basic_branch`
* `git branch basic_branch_fix`
* `git checkout basic_branch_fix`  
Aby 
* Odpowiednia modyfikacja
* *

## Gałęzie - merge conflict
* `git checkout merge_conflict`


## Coś więcej

### reset

### checkout, log, reflog

### rebase

### bisect

### submodule