### git clone
* `git clone --depth 10 remote-url` - do dużych repo, klonuje commit-y jedynie do głębokości 10.

### git status
* `-v` pokazuje diff-a dodanych plików.
* `-vv` dodatkowo pokazuje diff-a jeszcze nie dodanych plików.

### git add

### git rm

### git commit

### git push
* `git push -all` - commit-uje wszystkie branch-e.

### git pull

### git fetch

### git stash

### git checkout
* `git checkout branch_name/commit_hash`
* `git checkout -b new_branch_name`
* `git switch branch_name`
* `git switch -c new_branch_name`

### git branch
* `git branch name` - kopiuje aktualną gałąź.
* `git branch` - lista gałęzi.

### git merge
* `git merge name` - merge-uje `name` do aktualnej gałęzi. (aktualna gałąź jest modyfikowana)
* `--no-commit` - nie tworzy commit-a. Użytkownik może zweryfikować, czy merge był poprawny i samemu dodać commit.

### git rebase
* `git rebase name` - zmienia podstawę aktualnej gałęzi na `name`. (aktualna gałąź jest modyfikowana)
* `git rebase --continue` - kontynuuje rebase
* `git rebase --skip` - pomija commit, który spowodował konflikt
* `git rebase --abort` - przerywa rebase
* `git rebase --interactive` - pozwala wybrać commit-y, które dodamy.

### git log
* `git log` - wypisuje commit-y poprzedzające aktualną gałąź. 
* `git log --pretty=format:'%C(yellow)%h %Cred%ad %Cblue%an%Cgreen%d %Creset%s' --date=short` - ładne i krótkie wypisywanie.
* `git log --format=oneline` - jak wyżej, ale trochę gorsze.
* `-n 10` ogranicza do 10 ostatnich zmian.
* `--no-abbrev` - wypisuje pełne nazwy commit-ów.

### git reflog
* `git reflog` - wypisuje zmiany w HEAD
* Opcje takie same jak w `log`.

### git bisect
* Najpierw `git bisect start`
* Potem `git bisect bad commit`
* Potem `git bisect good commit`
* Wtedy zaczyna się „sesja” bisect.
* Git automatycznie będzie przenosić nas na commit-y, a my musimy mówić `good/old` oraz `bad/new`. 
* Gdy git znajdzie pierwszy commit, który wprowadził zmianę zostaniemy o tym poinformowani.

