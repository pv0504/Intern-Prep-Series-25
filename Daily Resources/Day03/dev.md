# Linux Shell & File Permissions Basics

## Table of Contents
- [Introduction](#introduction)
- [Getting Started with the Shell](#getting-started-with-the-shell)
- [Essential Navigation Commands](#essential-navigation-commands)
- [File and Directory Operations](#file-and-directory-operations)
- [Understanding File Permissions](#understanding-file-permissions)
- [Changing Permissions with chmod](#changing-permissions-with-chmod)
- [Changing File Ownership](#changing-file-ownership)
- [Hands-On Practice](#hands-on-practice)
- [Common Pitfalls and Safety Tips](#common-pitfalls-and-safety-tips)
- [Quick Reference](#quick-reference)
- [Additional Resources](#additional-resources)

---

## Introduction

The Linux shell is your gateway to powerful system control and automation. This guide will teach you the fundamentals of navigating the command line and managing file permissions - essential skills for any Linux user, developer, or system administrator.

**What you'll learn:**
- How to navigate the Linux filesystem using the command line
- Essential commands for file and directory management
- How Linux file permissions work and why they matter
- How to modify permissions and ownership
- Best practices and safety considerations

---

## Getting Started with the Shell

### What is the Shell?
The shell is a command-line interface that acts as a bridge between you and the Linux operating system. It interprets your commands and executes them.

### Opening the Terminal
- **Ubuntu/Debian**: Press `Ctrl + Alt + T` or search for "Terminal"
- **CentOS/RHEL**: Search for "Terminal" in applications
- **macOS**: Press `Cmd + Space`, type "Terminal"

### Command Structure
Linux commands follow this general pattern:
```bash
command [options] [arguments]
```

**Example:**
```bash
ls -la /home/user
```
- `ls` = command (list files)
- `-la` = options (long format + show all files)
- `/home/user` = argument (directory to list)

---

## Essential Navigation Commands

### Know Where You Are
```bash
pwd
# Output: /home/username
```
`pwd` (Print Working Directory) shows your current location in the filesystem.

### List Directory Contents
```bash
ls                    # Basic listing
ls -l                 # Long format (detailed info)
ls -a                 # Show all files (including hidden)
ls -la                # Long format + all files
ls /path/to/directory # List specific directory
```

### Navigate Between Directories
```bash
cd /home/user/documents    # Go to specific directory
cd ..                      # Go up one level (parent directory)
cd ~                       # Go to home directory
cd -                       # Go back to previous directory
cd                         # Also goes to home directory
```

**Pro Tip:** Use `Tab` key for auto-completion of file and directory names!

---

## File and Directory Operations

### Creating Files and Directories
```bash
mkdir my_project           # Create a directory
mkdir -p path/to/nested/dir # Create nested directories
touch file.txt             # Create empty file or update timestamp
```

### Copying and Moving
```bash
cp file.txt backup.txt           # Copy file
cp -r directory/ backup_dir/     # Copy directory recursively
mv old_name.txt new_name.txt     # Rename file
mv file.txt /path/to/destination/ # Move file
```

### Viewing File Contents
```bash
cat file.txt      # Display entire file
less file.txt     # View file page by page (q to quit)
head file.txt     # Show first 10 lines
tail file.txt     # Show last 10 lines
head -n 5 file.txt # Show first 5 lines
```

### Removing Files and Directories
```bash
rm file.txt              # Remove file
rm -r directory/         # Remove directory and contents recursively
rmdir empty_directory/   # Remove empty directory only
```

⚠️ **WARNING**: `rm` is permanent! There's no "trash" or "recycle bin" in Linux command line.

---

## Understanding File Permissions

### The Permission System
Every file and directory has permissions that control who can:
- **Read (r)**: View file contents or list directory contents
- **Write (w)**: Modify file contents or create/delete files in directory
- **Execute (x)**: Run file as program or enter directory

### User Categories
Permissions apply to three categories:
- **Owner (u)**: The user who owns the file
- **Group (g)**: Users belonging to the file's group
- **Others (o)**: All other users on the system

### Reading Permission Strings
When you run `ls -l`, you see permissions like this:
```bash
-rwxr-xr-- 1 user staff 1024 May 24 10:30 script.sh
```

Breaking down `-rwxr-xr--`:
- **Position 1**: File type (`-` = file, `d` = directory, `l` = link)
- **Positions 2-4**: Owner permissions (`rwx` = read, write, execute)
- **Positions 5-7**: Group permissions (`r-x` = read, execute only)
- **Positions 8-10**: Others permissions (`r--` = read only)

### Permission Examples
```bash
-rw-r--r--  # Owner: read/write, Group: read, Others: read
drwxr-xr-x  # Directory: Owner: full access, Group/Others: read/execute
-rwx------  # Owner: full access, Group/Others: no access
```

---

## Changing Permissions with chmod

### Symbolic Method (Recommended for Beginners)
More readable and intuitive:

```bash
chmod u+x file.txt    # Add execute permission for owner
chmod g-w file.txt    # Remove write permission from group
chmod o=r file.txt    # Set others to read-only
chmod a+r file.txt    # Add read permission for all (a = all)
chmod u+rwx,g+rx,o+r file.txt  # Multiple permissions at once
```

**Symbols:**
- `u` = owner, `g` = group, `o` = others, `a` = all
- `+` = add, `-` = remove, `=` = set exactly
- `r` = read, `w` = write, `x` = execute

### Numeric Method (Octal)
Each permission has a numeric value:
- Read (r) = 4
- Write (w) = 2
- Execute (x) = 1

Add values together for each user category:

```bash
chmod 755 file.txt    # Owner: 7(rwx), Group: 5(r-x), Others: 5(r-x)
chmod 644 file.txt    # Owner: 6(rw-), Group: 4(r--), Others: 4(r--)
chmod 600 file.txt    # Owner: 6(rw-), Group: 0(---), Others: 0(---)
```

### Common Permission Patterns
| Octal | Symbolic | Use Case |
|-------|----------|----------|
| 755   | rwxr-xr-x | Executable files, directories |
| 644   | rw-r--r-- | Regular files (documents, configs) |
| 600   | rw------- | Private files (passwords, keys) |
| 777   | rwxrwxrwx | Full access (rarely recommended) |

---

## Changing File Ownership

### Change Owner
```bash
sudo chown newowner file.txt              # Change owner
sudo chown newowner:newgroup file.txt     # Change owner and group
sudo chown -R newowner directory/         # Recursively change directory
```

### Change Group
```bash
sudo chgrp newgroup file.txt              # Change group only
sudo chgrp -R newgroup directory/         # Recursively change directory
```

**Note:** You typically need `sudo` (administrator privileges) to change ownership.

---

## Hands-On Practice

Follow these exercises to reinforce your learning:

### Exercise 1: Basic Navigation
```bash
# 1. Check your current location
pwd

# 2. List all files in your home directory (including hidden)
ls -la ~

# 3. Create a practice directory and enter it
mkdir ~/linux_practice
cd ~/linux_practice
```

### Exercise 2: File Operations
```bash
# 1. Create some files
touch file1.txt file2.txt script.sh

# 2. Create a directory
mkdir documents

# 3. Copy a file
cp file1.txt documents/

# 4. Check what you created
ls -la
ls -la documents/
```

### Exercise 3: Permissions Practice
```bash
# 1. Check current permissions
ls -l *.txt *.sh

# 2. Make script executable
chmod +x script.sh

# 3. Set file1.txt to read-only for everyone
chmod 444 file1.txt

# 4. Set file2.txt readable/writable for owner only
chmod 600 file2.txt

# 5. Verify changes
ls -l
```

### Exercise 4: Testing Permissions
```bash
# 1. Try to edit the read-only file
echo "test" >> file1.txt  # This should fail

# 2. Check if script is executable
ls -l script.sh  # Should show 'x' permissions

# 3. Add some content to executable file
echo "echo 'Hello World!'" > script.sh

# 4. Run the script
./script.sh
```

---

## Common Pitfalls and Safety Tips

### ⚠️ Critical Safety Rules

1. **Always double-check before using `rm -r`**
   ```bash
   # WRONG - could delete everything!
   rm -r / home/user/documents  # Space after / is dangerous!
   
   # RIGHT
   rm -r /home/user/documents
   ```

2. **Be careful with wildcards**
   ```bash
   # This deletes ALL files in current directory!
   rm *
   
   # Better to be specific
   rm *.txt
   ```

3. **Test commands in safe environments first**

4. **Use `ls` to verify before dangerous operations**
   ```bash
   # Check what will be affected first
   ls -la files_to_delete*
   # Then delete
   rm files_to_delete*
   ```

### Common Mistakes
- Forgetting `./` when running scripts: `./script.sh` not `script.sh`
- Using spaces in filenames without quotes: `"my file.txt"`
- Not understanding the difference between `rm` and `rmdir`
- Setting overly permissive permissions (777) unnecessarily

---

## Quick Reference

### Essential Commands Cheat Sheet
```bash
# Navigation
pwd                 # Current directory
ls -la              # List all files with details
cd directory        # Change directory
cd ..               # Go up one level
cd ~                # Go home

# File Operations
touch file          # Create empty file
mkdir directory     # Create directory
cp source dest      # Copy
mv source dest      # Move/rename
rm file             # Delete file
rm -r directory     # Delete directory

# Viewing Files
cat file            # Show entire file
less file           # Page through file
head file           # First 10 lines
tail file           # Last 10 lines

# Permissions
chmod 755 file      # Common executable permissions
chmod 644 file      # Common file permissions
chmod +x file       # Make executable
sudo chown user file # Change owner
```

### Permission Quick Reference
| Permission | Octal | Files | Directories |
|------------|-------|-------|-------------|
| r (read) | 4 | View content | List contents |
| w (write) | 2 | Modify content | Create/delete files |
| x (execute) | 1 | Run as program | Enter directory |

---

## Additional Resources

### Online Practice Environments
- [Replit](https://replit.com) - Create a Bash environment
- [Webminal](https://webminal.org) - Free online Linux terminal
- [JSLinux](https://bellard.org/jslinux/) - Linux emulator in browser

### Documentation and Help
```bash
man command         # Manual pages for any command
command --help      # Quick help for most commands
info command        # Detailed info pages
```

### Useful Websites
- [ExplainShell.com](https://explainshell.com) - Explains any shell command
- [Linux Journey](https://linuxjourney.com) - Interactive Linux learning
- [The Linux Documentation Project](https://tldp.org) - Comprehensive guides

### Books and Tutorials
- "The Linux Command Line" by William Shotts (free online)
- "Unix and Linux System Administration Handbook"
- [LinuxCommand.org](http://linuxcommand.org) - Beginner-friendly tutorials

---

Remember: The best way to learn Linux is by practicing! Start with simple commands and gradually work your way up to more complex operations. Don't be afraid to experiment, but always be cautious with file deletion commands.
