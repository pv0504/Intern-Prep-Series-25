## 🔀 git merge: Combine with context

### 📌 Scenario:

You're working on a feature in feature/login-ui, and now you want to bring your work into main.

bash

CopyEdit

`git checkout main
git merge feature/login-ui` 

✅ *Pros*:

-   Keeps full history. Great when you want context of how things came together.
    
-   Easy and safe. No rewriting.
    

❗*Merge Conflict?*  
Git will shout:

text

CopyEdit

CONFLICT (content): Merge conflict in Login.js 

Solve manually → git add → git commit

🛠 *Fix tip*: Use VS Code or a GUI tool for your first few merge conflicts!

----------

## 🪄 git rebase: Rewrite for clarity

### 📌 Scenario:

You’re 10 commits into feature/login-ui. But the main branch moved on. You want your changes to appear like they were built on top of the latest main.

bash

CopyEdit

`git checkout feature/login-ui
git rebase main` 

This:

1.  Re-applies your commits on top of main
    
2.  Makes the history linear, clean
    

🧠 Use when:

-   You want a clean commit history.
    
-   BEFORE merging feature → main.
    
-   Working *solo* or *before push* (never rebase shared history)
    

❗ If you see:

bash

CopyEdit

CONFLICT (content): Merge conflict in Login.js 

Same as merge: fix → git add → git rebase --continue

----------

## 🧳 git stash: Your code’s “locker room”

### 📌 Scenario:

You’re halfway into something, and suddenly your mentor says:

> "Switch to the hotfix/footer-bug branch, NOW."

You can’t commit unfinished junk.

bash

CopyEdit

git stash 

Boom—your changes are safely tucked away.

Now switch:

bash

CopyEdit

git checkout hotfix/footer-bug 

Come back later:

bash

CopyEdit

git stash pop 

✅ Also great if your changes are breaking stuff and you want to quickly reset.

----------

## 🌱 Practical Branching Workflow

### Real-world branch naming:

Purpose

Example Branch Name

Feature

feature/signup-form

Bugfix

bugfix/navbar-overlap

Hotfix

hotfix/prod-crash

Experimental

wip/test-new-ui

Workflow:

bash

CopyEdit

`# Create and switch git checkout -b feature/signup-form # Work, commit git add .
git commit -m "Add basic signup UI"  # Stay updated git pull origin main --rebase # Final merge (back to main) git checkout main
git merge feature/signup-form` 

----------

## 🧠 Core Concepts You MUST Know

Concept

Description

clone

Copy repo from remote

pull

Fetch + merge changes

fetch

Just get remote changes, don’t merge

add

Stage files

commit

Snapshot staged changes

push

Upload local commits to remote

log

Show commit history

diff

See what's changed

status

See current changes

revert

Undo a commit (safe)

reset

Rewind history (destructive)

----------

## ❗ Pro Tips for Internship-Ready Git Users

🔥 DO THIS

🚫 AVOID THIS

Pull often with rebase: git pull --rebase

Merging without understanding

Write useful commit messages

commit -m "fix" everywhere

Use feature branches

Commit directly to main

Practice resolving conflicts

Panic at merge conflicts

Use stash when in-between

Force commit broken code

Clean up with interactive rebase

Push messy, spammy commit logs

----------

## ✅ Wrap-up: How to Practice

1.  *Every new task* → make a new branch.
    
2.  Pair up with a friend: one merges, other rebases. Trigger & resolve conflicts.
    
3.  Build a habit: git pull --rebase, stash, merge, log, diff, and reset on toy projects.
    
4.  Learn one Git GUI tool (like GitKraken, SourceTree, or VS Code Git Panel).
    
5.  Do 1 Git Kata every day for 10 minutes: [https://github.com/praqma-training/git-katas](https://github.com/praqma-training/git-katas)
