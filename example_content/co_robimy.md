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
* `git checkout basic_branch`
* `git merge addition_fix`  
Wprowadza zmiany z `addition_fix` do `basic_branch`.

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
* `git checkout "reset_branch"`
* `git log...`  
Chcemy usunąć ostatni commit.
* `git reset HEAD~1`  
`HEAD~1`, czyli jeden wcześniej niż `HEAD`. [Więcej o tym tu.](https://git-scm.com/book/en/v2/Git-Tools-Revision-Selection)  
Zauważmy, że usunięte zmiany pozostały w working tree. Aby się ich pozbyć, należy użyć flagi `--hard`.  
* `git reset HEAD --hard`.  
Pozostawia gałąź w tym samym miejscu, ale usuwa zmiany nie dodane do repozytorium.

Reset jest szczególnie przydatny, gdu niechcący dodaliśmy commit na złą gałąź.

### checkout, log, reflog
* Pozwala przejść do dowolnego commit-a (gałęzie są jedynie wskaźnikami na commit-y).
* `git checkout checkout_new_branch`
* `git log`
* `git log --format=online`
* `git log --format=online -n 10`
* `git log --pretty=format:'%C(yellow)%h %Cred%ad %Cblue%an%Cgreen%d %Creset%s' --date=short -n 10`
* `git checkout 6cd112b` („added todo”)
* You are in 'detached HEAD' state....
* modyfikacja 
* `git add -A`
* `git commit -m "todo done"`
* `git switch -c fix_todo`

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

### rebase - interactive, squash
* `git checkout rebase_squash`
* `git log...`  
Występują 3 commit-y debug obok siebie. Wolelibyśmy zamienić je wraz z ostatnim commit-em w jeden.  
Chcemy więc połączyć ostatnie 4 commit-y w jeden - użyjemy do tego rebase.
* `git rebase --interactive a88215da`, a88215da czyli „Added feature: mul” (hash coomit-u tuż przed ostatnim łączonym commit-em).  
Chcemy zmienić bazę, na commit, który występuje na ścieżce do korzenia.  
Bez `--interactive` nie powinno to mieć efektu.
* a co z `--interactive`
Pojawi się edytor, w którym określamy co dokładnie git powinien zrobić z każdym commit-em.  
Git napiszę nam także w komentarzu podpowiedz, jakie są opcje oraz co robią.  
Uwaga: Starsze commit-y znajdują się na początku listy.  
Ustawmy opcje na: `pick`, `squash`, ..., `squash`.
* Zatwierdzamy  
Git będzie chciał zrobić teraz commit, który będzie naszym połączonym commit-em. Jako, że nie zna jego opisu, ponownie wyświetli edytor, w którym tym razem wpisujemy opis commit-u.  
Można wpisać np „Implemented and tested mul”
* Zatwierdzamy ponownie
* `git log...`

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