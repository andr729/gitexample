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
* `git branch addition_fix`
* `git checkout addition_fix`  
Aby stworzyć gałąź i od razu się na nią przenieść, można użyć
`git checkout -b new_brach`  
* Odpowiednia modyfikacja
* `git checkout master`
* `git merge addition_fix`  
Wprowadza zmiany z `addition_fix` do `master`.

## Gałęzie - merge conflict
* `git checkout merge_conflict`
* Spróbujmy teraz wprowadzić zmiany z `merge_conflict_other`  
`git merge merge_conflict_other`
* `git status`
* Jak wyglądają pliki?  
`git merge` pozostawi zmodyfikowane pliki - my możemy zrobić z nimi co chcemy, a 
kończymy `merge` commit-ująć zmiany.



## Coś więcej

### reset

### checkout, log, reflog

### rebase
* `git checkout rebase_A`
* Teraz zamienimy „podstawę” branch-a `rebase_A`, ma `rebase_B`.  
W praktyce, ma to podobny efekty, co `merge`, ale zupełnie inaczej będzie wyglądać w repozytorium.  
* Wizualizacja...  
* Bardziej formalnie można myśleć tak: jeśli `p = lca(A, B)`, to commit-y od `p`, do `A`, zostaną
dodane do `B` (bez modyfikacji pozycji `B`), a następnie `A` zostanie przesunięte na ostatni dodany commit. 
* `git rebase rebase_B`
* Mamy konflikt...  
Możemy zobaczyć go poprzez `git am --show-current-patch`, a rozwiązujemy go analogicznie jak merge conflict. Modyfikujemy pliki, zatwierdzamy, przez `add`, a następnie możemy kontynuować poprzez:
`git rebase --continue`.  
Dostępne jest także `--skip` oraz `--abort`.

### bisect
* `git checkout bisect`
* Idziemy do góry repo...
* `git bisect start`  
Rozpoczyna „sesję” bisect, czyli wyszukiwanie binarne pierwszego commit-a, który coś zmienił.
* `git reflog` lub `git log`
* `git bisect new/bad commit_id`  
Przekazujemy git-owi informacje o ostatnim złym commit-cie, o którym wiemy.
* `git bisect old/good commit_id`  
Przekazujemy git-owi informacje pierwszym dobrym commit-cie, o którym wiemy.  
Teraz git przeniesie nas na pewien commit, a my będziemy musieli stwierdzić czy dana zmiana/bug
w nim występuje. Po tym wpisujemy odpowiednio:  
`git bisect good/old` lub `git bisect bad/new`.
* Na końcu git poinformuje nas o znalezionym commit-cie, oraz pozostawi tam HEAD.

### submodule