# Git Basics + Branching | Programming & Version Control

## 📚 Overview

**Git** is a distributed version control system that tracks changes in source code during software development. **Branching** is one of Git's most powerful features, allowing developers to diverge from the main line of development and work on features, experiments, or bug fixes in isolation.

## 🎯 Key Concepts

### Git Fundamentals
* **Working Directory**: Your local files and folders
* **Staging Area**: Temporary area where changes are prepared for commit  
* **Repository**: Contains all version history and metadata
* **Three-stage workflow**: Modify → Stage → Commit

### Branching
* **Branch**: A movable pointer to a specific commit
* **HEAD**: Points to the current branch you're working on
* **master/main**: Default branch in most repositories
* **Feature branches**: Isolated development environments

## 💡 Benefits

* **Parallel development** - Multiple features developed simultaneously
* **Experimentation safety** - Try changes without affecting main code
* **Collaboration efficiency** - Team members work independently
* **Version history** - Complete record of all changes

## 📖 Essential Reading

**[Git Handbook - GitHub](https://guides.github.com/introduction/git-handbook/)**  
A beginner-friendly guide that explains Git fundamentals, why version control matters, and walks through basic Git commands with clear examples.

## 🎥 Quick Video Tutorial

**[Git Explained in 2 Minutes](https://youtu.be/2ReR1YJrNOM) - Programming with Mosh**  
Perfect 2-minute introduction covering what Git is, why developers use it, and the basic concept of tracking changes in your code.

## 🔧 Quick Example

```bash
# Initialize repository
git init my-project
cd my-project

# Create and switch to feature branch
git checkout -b feature/user-login

# Make changes and commit
echo "Login functionality" > login.js
git add login.js
git commit -m "Add user login feature"

# Switch back to main and merge
git checkout main
git merge feature/user-login

# Clean up - delete feature branch
git branch -d feature/user-login
```

## 🚀 Hands-on Task

**Challenge**: Create a complete Git workflow for a team project with proper branching strategy.

```bash
# SCENARIO: You're building a web application
# Current state: Empty repository

# Your Task:
# 1. Initialize repository with main branch
# 2. Create develop branch for integration
# 3. Create feature branches for:
#    - User authentication
#    - Product catalog  
#    - Shopping cart
# 4. Simulate development with commits
# 5. Merge features through develop to main
# 6. Handle a merge conflict scenario
# 7. Create and apply a hotfix

# STARTER CODE - Complete this workflow:
git init ecommerce-app
cd ecommerce-app

# Create initial commit
echo "# E-commerce Application" > README.md
git add README.md
git commit -m "Initial commit"

# TODO: Implement the complete branching strategy
# Your implementation goes here...
```

**Your Task:**
1. Set up the branching structure (main → develop → feature branches)
2. Create realistic commits for each feature
3. Practice merging and handling conflicts
4. Implement a hotfix workflow
5. Use proper commit messages and branch naming

## 📋 Essential Commands Cheat Sheet

| Command | Purpose |
|---------|---------|
| `git init` | Initialize new repository |
| `git clone <url>` | Copy remote repository |
| `git status` | Check working directory status |
| `git add <file>` | Stage changes |
| `git commit -m "msg"` | Commit with message |
| `git branch` | List branches |
| `git branch <name>` | Create new branch |
| `git checkout <branch>` | Switch branches |
| `git checkout -b <name>` | Create and switch to branch |
| `git merge <branch>` | Merge branch into current |
| `git pull` | Fetch and merge from remote |
| `git push` | Upload commits to remote |
| `git log --oneline` | View commit history |

## ⚠️ Common Pitfalls

* **Committing directly to main** instead of using feature branches
* **Not pulling before pushing** leading to rejected pushes  
* **Force pushing without caution** (`git push --force`)
* **Forgetting to stage files** before committing
* **Poor commit messages** that don't explain changes
* **Creating branches from wrong base** 
* **Not cleaning up merged branches**

## 📖 Resources

### Interactive Learning
* [Learn Git Branching](https://learngitbranching.js.org/) - Visual Git tutorials
* [Git Immersion](http://gitimmersion.com/) - Step-by-step Git workshop
* [GitHub Skills](https://skills.github.com/) - Hands-on Git courses

### Documentation  
* [Pro Git Book](https://git-scm.com/book) - Complete Git reference
* [Atlassian Git Tutorials](https://www.atlassian.com/git/tutorials) - Comprehensive guides
* [GitHub Flow Guide](https://guides.github.com/introduction/flow/) - Branching workflow

### Video Tutorials
* [Git & GitHub for Beginners](https://youtu.be/RGOj5yH7evk) - freeCodeCamp
* [Git Branching Strategies](https://youtu.be/aJnFGMclhU8) - Tech With Tim
* [Advanced Git Workflows](https://youtu.be/Uszj_k0DGsg) - The Coding Train
