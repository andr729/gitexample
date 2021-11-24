### git status

### git add

### git rm

### git commit

### git push
* `git push -all` - commit-uje wszystkie branch-e.

### git pull

### git fetch

### git stash

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
* `-n 10` ogranicza do 10 ostatnich zmian.

### git reflog
* `git reflog` - wypisuje zmiany w HEAD
* `-n 10` ogranicza do 10 ostatnich zmian.

### git bisect
* Najpierw `git bisect start`
* Potem `git bisect bad commit`
* Potem `git bisect good commit`
* Wtedy zaczyna się „sesja” bisect.
* Git automatycznie będzie przenosić nas na commit-y, a my musimy mówić `good/old` oraz `bad/new`. 
* Gdy git znajdzie pierwszy commit, który wprowadził zmianę zostaniemy o tym poinformowani.

