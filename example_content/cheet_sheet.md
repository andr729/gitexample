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
* `git merge name1 name2` - merge-uje `name` do aktualnej gałęzi. (aktualna gałąź jest modyfikowana)
* `--no-commit` - nie tworzy commit-a. Użytkownik może zweryfikować, czy merge był poprawny i samemu dodać commit.

### git reflog

### git bisect
* Najpierw `git bisect start`
* Potem `git bisect bad commit`
* Potem `git bisect good commit`
* Wtedy zaczyna się „sesja” bisect.
* Git automatycznie będzie przenosić nas na commit-y, a my musimy mówić `good/old` oraz `bad/new`. 
* Gdy git znajdzie pierwszy commit, który wprowadził zmianę zostaniemy o tym poinformowani.

