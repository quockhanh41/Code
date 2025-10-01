# Linux System Administration & Container Commands

## Mục lục

1. [Xử lý Input/Output](#1-xử-lý-inputoutput)
   - [xargs - Build and execute commands from standard input](#xargs---build-and-execute-commands-from-standard-input)

2. [Xử lý Text/Log](#2-xử-lý-textlog)
   - [sort - Sort lines of text](#sort---sort-lines-of-text)
   - [uniq - Report or omit repeated lines](#uniq---report-or-omit-repeated-lines)
   - [wc - Word, line, character count](#wc---word-line-character-count)
   - [cut - Remove sections from lines](#cut---remove-sections-from-lines)
   - [tr - Translate or delete characters](#tr---translate-or-delete-characters)
   - [diff - Compare files line by line](#diff---compare-files-line-by-line)
   - [cmp - Compare two files byte by byte](#cmp---compare-two-files-byte-by-byte)

3. [Quản lý Permissions & Users](#3-quản-lý-permissions--users)
   - [chmod - Change file permissions](#chmod---change-file-permissions)
   - [chown - Change file owner and group](#chown---change-file-owner-and-group)
   - [useradd / adduser - Create new user](#useradd--adduser---create-new-user)
   - [groupadd - Create new group](#groupadd---create-new-group)

4. [Task Scheduling](#4-task-scheduling)
   - [crontab - Schedule tasks](#crontab---schedule-tasks)

---

## 1. Xử lý Input/Output

### **xargs** - Build and execute commands from standard input
**Syntax:**
```bash
xargs [options] [command]
```

**Options quan trọng:**
- `-n <num>` - Số arguments mỗi lần execute
- `-I {}` - Replace string placeholder
- `-P <num>` - Parallel execution (số processes)
- `-t` - Print command before executing (debug)
- `-p` - Prompt before executing
- `-0` - Input delimiter là null (dùng với find -print0)
- `-d <delim>` - Custom delimiter
- `-r` - Không chạy nếu input rỗng
- `-L <num>` - Số dòng input mỗi lần
- `-s <size>` - Max command line size

**Trường hợp sử dụng:**

```bash
# Basic usage - xóa nhiều files
echo "file1.txt file2.txt file3.txt" | xargs rm

# Với find - tìm và xóa
find . -name "*.tmp" | xargs rm

# Sử dụng placeholder {}
find . -name "*.log" | xargs -I {} cp {} /backup/

# Với -n: execute từng item riêng
echo "file1 file2 file3" | xargs -n 1 echo "Processing:"

# Parallel execution (4 processes đồng thời)
find . -name "*.jpg" | xargs -P 4 -I {} convert {} {}.png

# Safe với filenames có spaces (dùng null delimiter)
find . -name "*.txt" -print0 | xargs -0 rm

# Prompt before execution
echo "important.txt" | xargs -p rm

# Show command before running
find /var/log -name "*.log" | xargs -t gzip

# Grep trong nhiều files
find . -name "*.js" | xargs grep "function"

# Count lines in multiple files
find . -name "*.txt" | xargs wc -l

# Change permissions for multiple files
find /var/www -type f -name "*.php" | xargs chmod 644

# Download multiple URLs
cat urls.txt | xargs -n 1 -P 5 wget

# Create directories from list
cat dir_list.txt | xargs mkdir -p

# Kill multiple processes
ps aux | grep python | awk '{print $2}' | xargs kill -9

# Compress files individually
find /logs -name "*.log" -mtime +7 | xargs -n 1 gzip

# Execute with multiple arguments
cat servers.txt | xargs -I {} ssh {} "uptime"

# Limit command line length
find . -name "*.o" | xargs -s 1000 rm

# Max 2 arguments per command
cat files.txt | xargs -n 2 diff

# Process lines instead of words
cat commands.txt | xargs -L 1 bash -c

# With custom delimiter
echo "a:b:c" | xargs -d : -n 1 echo

# Backup múltiple databases
echo "db1 db2 db3" | xargs -n 1 -P 3 -I {} mysqldump {} > {}.sql

# Convert images in parallel
ls *.png | xargs -P 8 -I {} convert {} -resize 50% small_{}

# Rsync multiple directories
cat backup_dirs.txt | xargs -I {} rsync -av {} /backup/
```

**Ví dụ thực tế:**

```bash
# 1. Clean old Docker images
docker images | grep "months ago" | awk '{print $3}' | xargs docker rmi

# 2. Restart multiple services
echo "nginx mysql redis" | xargs -n 1 systemctl restart

# 3. Check disk usage of multiple directories
cat important_dirs.txt | xargs -I {} du -sh {}

# 4. SSH to multiple servers and execute command
cat servers.txt | xargs -I {} -P 10 ssh {} "df -h | grep sda1"

# 5. Find and replace in multiple files
find . -name "*.conf" | xargs sed -i 's/old_value/new_value/g'

# 6. Batch file processing
find /data -name "*.csv" -print0 | xargs -0 -P 4 -I {} python process.py {}

# 7. Test multiple URLs
cat urls.txt | xargs -n 1 -P 20 curl -I -s -o /dev/null -w "%{http_code} %{url_effective}\n"

# 8. Compress logs in parallel
find /var/log -name "*.log" -mtime +7 -print0 | xargs -0 -P 4 -n 1 gzip

# 9. Copy files to multiple servers
cat servers.txt | xargs -I {} scp backup.tar.gz {}:/tmp/

# 10. Kill processes by name
pgrep python | xargs kill -9
```

---

## 2. Xử lý Text/Log

### **sort** - Sort lines of text
**Syntax:**
```bash
sort [options] [file]
```

**Options:**
- `-r` - Reverse (descending)
- `-n` - Numeric sort
- `-h` - Human numeric sort (K, M, G)
- `-k <field>` - Sort by field/column
- `-t <delim>` - Field delimiter
- `-u` - Unique (remove duplicates)
- `-f` - Ignore case
- `-b` - Ignore leading blanks
- `-V` - Version sort
- `-c` - Check if sorted
- `-o <file>` - Output file
- `-R` - Random sort
- `-M` - Month sort

**Trường hợp sử dụng:**

```bash
# Basic sort
sort file.txt

# Reverse sort
sort -r file.txt

# Numeric sort
sort -n numbers.txt

# Human readable sort (1K, 2M, 3G)
du -h | sort -h

# Sort by specific column (space delimiter)
sort -k 2 data.txt

# Sort by column with custom delimiter
sort -t: -k 3 -n /etc/passwd

# Sort and remove duplicates
sort -u file.txt

# Case insensitive sort
sort -f file.txt

# Sort multiple columns (column 2, then column 3)
sort -k 2,2 -k 3,3n data.txt

# Sort in-place
sort -o file.txt file.txt

# Check if file is sorted
sort -c file.txt

# Reverse numeric sort
sort -rn numbers.txt

# Sort IPs correctly
sort -t . -k 1,1n -k 2,2n -k 3,3n -k 4,4n ips.txt

# Sort by file size
ls -lh | sort -k 5 -h

# Sort CSV by column 3
sort -t, -k 3 data.csv

# Month sort
sort -M months.txt

# Version number sort
sort -V versions.txt

# Random sort
sort -R file.txt

# Sort excluding first line (header)
(head -n 1 file.csv && tail -n +2 file.csv | sort -t, -k 2) > sorted.csv
```

**Ví dụ thực tế:**

```bash
# 1. Top 10 largest files
du -a /var | sort -rn | head -10

# 2. Sort access log by response time
awk '{print $NF, $0}' access.log | sort -rn | head -20

# 3. Sort by memory usage
ps aux | sort -k 4 -rn | head -10

# 4. Sort IPs by frequency
awk '{print $1}' access.log | sort | uniq -c | sort -rn

# 5. Sort processes by CPU
ps aux --sort=-%cpu | head -10
```

---

### **uniq** - Report or omit repeated lines
**Syntax:**
```bash
uniq [options] [input] [output]
```

**Options:**
- `-c` - Count occurrences
- `-d` - Only show duplicates
- `-u` - Only show unique lines
- `-i` - Ignore case
- `-f <n>` - Skip first n fields
- `-s <n>` - Skip first n characters
- `-w <n>` - Compare only first n characters

**Lưu ý:** `uniq` chỉ xóa duplicate lines **liên tiếp**, nên thường dùng với `sort` trước.

**Trường hợp sử dụng:**

```bash
# Remove duplicate lines (must be sorted first)
sort file.txt | uniq

# Count occurrences
sort file.txt | uniq -c

# Show only duplicates
sort file.txt | uniq -d

# Show only unique lines (no duplicates)
sort file.txt | uniq -u

# Count and sort by frequency
sort file.txt | uniq -c | sort -rn

# Case insensitive
sort file.txt | uniq -i

# Skip first field
sort data.txt | uniq -f 1

# Compare only first 10 characters
uniq -w 10 file.txt
```

**Ví dụ thực tế:**

```bash
# 1. Count unique IPs in access log
awk '{print $1}' access.log | sort | uniq -c | sort -rn

# 2. Find duplicate lines in config
sort config.txt | uniq -d

# 3. Count HTTP status codes
awk '{print $9}' access.log | sort | uniq -c

# 4. Unique users logged in
who | awk '{print $1}' | sort | uniq

# 5. Top 10 accessed URLs
awk '{print $7}' access.log | sort | uniq -c | sort -rn | head -10

# 6. Count error types
grep ERROR app.log | awk '{print $5}' | sort | uniq -c | sort -rn

# 7. Find duplicate files by name
find . -type f -printf "%f\n" | sort | uniq -d
```

---

### **wc** - Word, line, character count
**Syntax:**
```bash
wc [options] [file]
```

**Options:**
- `-l` - Count lines only
- `-w` - Count words only
- `-c` - Count bytes
- `-m` - Count characters
- `-L` - Length of longest line

**Trường hợp sử dụng:**

```bash
# Count lines
wc -l file.txt

# Count words
wc -w file.txt

# Count characters
wc -m file.txt

# Count bytes
wc -c file.txt

# All counts
wc file.txt

# Multiple files
wc -l *.txt

# Count files in directory
ls | wc -l

# Count processes
ps aux | wc -l

# Longest line
wc -L file.txt
```

**Ví dụ thực tế:**

```bash
# 1. Count log entries
wc -l /var/log/nginx/access.log

# 2. Count ERROR lines
grep ERROR app.log | wc -l

# 3. Count unique IPs
awk '{print $1}' access.log | sort -u | wc -l

# 4. Count files in directory tree
find . -type f | wc -l

# 5. Total size of code files
find . -name "*.js" -exec cat {} \; | wc -l

# 6. Count running Docker containers
docker ps | wc -l

# 7. Count users
cat /etc/passwd | wc -l
```

---

### **cut** - Remove sections from lines
**Syntax:**
```bash
cut [options] [file]
```

**Options:**
- `-f <fields>` - Select fields (columns)
- `-d <delim>` - Field delimiter (default: tab)
- `-c <chars>` - Select characters
- `-b <bytes>` - Select bytes
- `--complement` - Invert selection
- `--output-delimiter=<string>` - Output delimiter

**Trường hợp sử dụng:**

```bash
# Cut specific column (default: tab delimiter)
cut -f 1 data.txt

# Cut with custom delimiter
cut -d: -f 1 /etc/passwd

# Multiple columns
cut -d: -f 1,3,6 /etc/passwd

# Range of columns
cut -d: -f 1-3 /etc/passwd

# From column to end
cut -d: -f 3- /etc/passwd

# Characters position
cut -c 1-10 file.txt

# Specific characters
cut -c 1,5,9 file.txt

# Change output delimiter
cut -d: -f 1,3 --output-delimiter=, /etc/passwd

# Complement (all except specified)
cut -d: -f 1 --complement /etc/passwd
```

**Ví dụ thực tế:**

```bash
# 1. Extract usernames
cut -d: -f1 /etc/passwd

# 2. Extract IP from access log
cut -d' ' -f1 access.log | sort | uniq

# 3. CSV column extraction
cut -d, -f2,4 data.csv

# 4. Extract specific fields from ps output
ps aux | tr -s ' ' | cut -d' ' -f 2,11

# 5. Extract time from log
cut -d'[' -f2 app.log | cut -d']' -f1

# 6. Get UIDs
cut -d: -f3 /etc/passwd

# 7. Extract email domain
cut -d@ -f2 emails.txt | sort | uniq -c
```

---

### **tr** - Translate or delete characters
**Syntax:**
```bash
tr [options] SET1 [SET2]
```

**Options:**
- `-d` - Delete characters
- `-s` - Squeeze repeated characters
- `-c` - Complement SET1
- `-t` - Truncate SET1 to length of SET2

**Character sets:**
- `[:alnum:]` - Alphanumeric
- `[:alpha:]` - Alphabetic
- `[:digit:]` - Digits
- `[:lower:]` - Lowercase
- `[:upper:]` - Uppercase
- `[:space:]` - Whitespace
- `[:punct:]` - Punctuation

**Trường hợp sử dụng:**

```bash
# Lowercase to uppercase
echo "hello" | tr 'a-z' 'A-Z'

# Uppercase to lowercase
echo "HELLO" | tr 'A-Z' 'a-z'

# Delete specific characters
echo "hello123" | tr -d '0-9'

# Delete spaces
echo "hello world" | tr -d ' '

# Replace spaces with underscores
echo "hello world" | tr ' ' '_'

# Squeeze repeated spaces
echo "hello    world" | tr -s ' '

# Delete newlines
cat file.txt | tr -d '\n'

# Replace newlines with spaces
cat file.txt | tr '\n' ' '

# Delete all non-alphanumeric
echo "hello@123" | tr -cd '[:alnum:]'

# Remove carriage returns (Windows to Unix)
cat windows.txt | tr -d '\r' > unix.txt

# ROT13 encoding
echo "hello" | tr 'A-Za-z' 'N-ZA-Mn-za-m'

# Keep only digits
echo "Price: $123.45" | tr -cd '[:digit:]'

# Replace multiple characters
echo "hello" | tr 'helo' 'HELO'

# Complement - delete everything except
echo "hello123" | tr -cd '[:digit:]'
```

**Ví dụ thực tế:**

```bash
# 1. Clean CSV data
cat data.csv | tr -d '\r' | tr ',' '\t'

# 2. Convert DOS to Unix line endings
tr -d '\r' < dosfile.txt > unixfile.txt

# 3. Extract numbers from text
cat file.txt | tr -cd '[:digit:]' 

# 4. Replace tabs with spaces
cat file.txt | tr '\t' ' '

# 5. URL encode spaces
echo "hello world" | tr ' ' '+'

# 6. Squeeze multiple spaces in log
cat app.log | tr -s ' '

# 7. Create comma-separated list
ls | tr '\n' ','
```

---

### **diff** - Compare files line by line
**Syntax:**
```bash
diff [options] file1 file2
```

**Options:**
- `-u` - Unified format (most common)
- `-c` - Context format
- `-y` - Side by side
- `-i` - Ignore case
- `-w` - Ignore whitespace
- `-b` - Ignore changes in whitespace
- `-B` - Ignore blank lines
- `-r` - Recursive (directories)
- `-q` - Brief (only report if differ)
- `--color` - Colorize output

**Output symbols:**
- `<` - Line from file1
- `>` - Line from file2
- `a` - Add
- `c` - Change
- `d` - Delete

**Trường hợp sử dụng:**

```bash
# Basic diff
diff file1.txt file2.txt

# Unified format (best for patches)
diff -u old.txt new.txt

# Side by side
diff -y file1.txt file2.txt

# Ignore case
diff -i file1.txt file2.txt

# Ignore whitespace
diff -w file1.txt file2.txt

# Brief mode
diff -q file1.txt file2.txt

# Recursive directory comparison
diff -r dir1/ dir2/

# Create patch file
diff -u old.txt new.txt > changes.patch

# Apply patch
patch old.txt < changes.patch

# Colorized output
diff --color file1.txt file2.txt

# Context diff
diff -c file1.txt file2.txt

# Compare and ignore blank lines
diff -B file1.txt file2.txt
```

**Ví dụ thực tế:**

```bash
# 1. Compare config before/after
diff -u nginx.conf.bak nginx.conf

# 2. Compare deployed vs new version
diff -r /var/www/current /var/www/new

# 3. Check config changes
diff /etc/nginx/nginx.conf /backup/nginx.conf.bak

# 4. Generate deployment patch
diff -ru old_version/ new_version/ > deploy.patch

# 5. Compare database dumps
diff -u db_backup_old.sql db_backup_new.sql | less

# 6. Quick check if files differ
diff -q production.env staging.env

# 7. Compare directory structures only
diff -rq dir1/ dir2/ | grep -v "identical"
```

---

### **cmp** - Compare two files byte by byte
**Syntax:**
```bash
cmp [options] file1 file2
```

**Options:**
- `-l` - Print byte number and differing bytes
- `-s` - Silent (return exit code only)
- `-b` - Print differing bytes

**Trường hợp sử dụng:**

```bash
# Basic compare
cmp file1.txt file2.txt

# Show differences
cmp -l file1.txt file2.txt

# Silent mode (check in scripts)
if cmp -s file1.txt file2.txt; then
    echo "Files are identical"
fi

# Compare binary files
cmp binary1 binary2
```

**Ví dụ thực tế:**

```bash
# 1. Verify backup integrity
cmp original.tar.gz backup.tar.gz

# 2. Check binary files
cmp /usr/bin/program /backup/program

# 3. Verify file copy
cmp source.iso /mnt/destination.iso

# 4. In scripts
if ! cmp -s config.yml config.yml.bak; then
    echo "Config has changed!"
fi
```

---

## 3. Quản lý Permissions & Users

### **chmod** - Change file permissions
**Syntax:**
```bash
chmod [options] mode file
```

**Permission numbers:**
- `4` - Read (r)
- `2` - Write (w)
- `1` - Execute (x)

**Permission format:** `owner-group-others`
- `755` = rwxr-xr-x
- `644` = rw-r--r--
- `600` = rw-------
- `777` = rwxrwxrwx (dangerous!)

**Symbolic mode:**
- `u` - User/owner
- `g` - Group
- `o` - Others
- `a` - All
- `+` - Add permission
- `-` - Remove permission
- `=` - Set exact permission

**Options:**
- `-R` - Recursive
- `-v` - Verbose
- `-c` - Report changes only
- `--reference=<file>` - Copy permissions from file

**Trường hợp sử dụng:**

```bash
# Numeric mode
chmod 644 file.txt                    # rw-r--r--
chmod 755 script.sh                   # rwxr-xr-x
chmod 600 private.key                 # rw-------
chmod 700 secure_dir/                 # rwx------

# Make executable
chmod +x script.sh

# Remove execute
chmod -x file.txt

# Add write for group
chmod g+w file.txt

# Remove write for others
chmod o-w file.txt

# Set exact permissions
chmod u=rwx,g=rx,o=r file.txt

# Recursive
chmod -R 755 /var/www/html/

# Everyone can read
chmod a+r file.txt

# Copy permissions from another file
chmod --reference=template.txt newfile.txt

# Add execute only for directories
find . -type d -exec chmod 755 {} \;

# Set files to 644
find . -type f -exec chmod 644 {} \;

# SetUID (run as owner)
chmod u+s /usr/bin/program            # 4755

# SetGID (inherit group)
chmod g+s /shared/directory           # 2755

# Sticky bit (only owner can delete)
chmod +t /tmp/shared                  # 1777

# Verbose output
chmod -v 644 *.txt

# Report only changes
chmod -c 755 *.sh
```

**Common permission sets:**

```bash
# Web files
chmod 644 *.html *.css *.js           # Files
chmod 755 directories/                # Directories

# Scripts
chmod 755 script.sh                   # Executable scripts

# Private keys
chmod 600 ~/.ssh/id_rsa

# Config files
chmod 640 /etc/myapp/config.yml

# Shared directory
chmod 2775 /var/www/shared/           # SetGID + group write

# Public uploads (with sticky bit)
chmod 1777 /var/www/uploads/

# WordPress/PHP permissions
find /var/www -type d -exec chmod 755 {} \;
find /var/www -type f -exec chmod 644 {} \;
```

---

### **chown** - Change file owner and group
**Syntax:**
```bash
chown [options] owner[:group] file
```

**Options:**
- `-R` - Recursive
- `-v` - Verbose
- `-c` - Report changes only
- `--reference=<file>` - Copy ownership from file
- `-h` - Change symlink itself
- `--from=<current_owner>` - Change only if current owner matches

**Trường hợp sử dụng:**

```bash
# Change owner
chown user file.txt

# Change owner and group
chown user:group file.txt

# Change only group
chown :group file.txt
# or
chgrp group file.txt

# Recursive
chown -R www-data:www-data /var/www/

# Verbose
chown -v user:group file.txt

# Copy from reference file
chown --reference=template.txt newfile.txt

# Change from specific owner
chown --from=olduser newuser file.txt

# Change symlink itself
chown -h user symlink

# Multiple files
chown user:group file1.txt file2.txt file3.txt

# With find
find /var/www -type f -exec chown www-data:www-data {} \;
```

**Ví dụ thực tế:**

```bash
# 1. Web directory setup
chown -R www-data:www-data /var/www/html/

# 2. User home directory
chown -R username:username /home/username/

# 3. Application files
chown -R app:app /opt/application/

# 4. Fix WordPress permissions
chown -R www-data:www-data /var/www/wordpress/
find /var/www/wordpress -type d -exec chmod 755 {} \;
find /var/www/wordpress -type f -exec chmod 644 {} \;

# 5. Docker volume
chown -R 1000:1000 /var/lib/docker/volumes/myapp/

# 6. Shared directory
chown -R :developers /var/projects/
chmod -R 2775 /var/projects/

# 7. Log files
chown syslog:adm /var/log/application.log

# 8. SSH directory
chown -R user:user ~/.ssh/
chmod 700 ~/.ssh/
chmod 600 ~/.ssh/id_rsa
```

---

### **useradd / adduser** - Create new user
**Syntax:**
```bash
useradd [options] username
adduser username              # Interactive (Debian/Ubuntu)
```

**Options:**
- `-m` - Create home directory
- `-d <dir>` - Home directory path
- `-s <shell>` - Login shell
- `-g <group>` - Primary group
- `-G <groups>` - Secondary groups
- `-u <uid>` - User ID
- `-c <comment>` - Comment/full name
- `-e <date>` - Expiry date
- `-p <password>` - Encrypted password
- `-r` - System account

**Trường hợp sử dụng:**

```bash
# Basic user creation
useradd john

# With home directory
useradd -m john

# With specific shell
useradd -m -s /bin/bash john

# With primary and secondary groups
useradd -m -g users -G sudo,docker john

# With comment
useradd -m -c "John Doe" john

# Set password
useradd -m john
passwd john

# Create system user (no home, no login)
useradd -r -s /bin/false appuser

# With specific UID
useradd -m -u 1500 john

# With home directory path
useradd -m -d /home/custom/john john

# Copy skeleton files
useradd -m -k /etc/skel john

# With expiry date
useradd -m -e 2024-12-31 tempuser

# Interactive (Debian/Ubuntu - recommended)
adduser john
```

**User management commands:**

```bash
# Modify user
usermod -aG docker john              # Add to group
usermod -s /bin/zsh john             # Change shell
usermod -l newname oldname           # Rename
usermod -L john                      # Lock account
usermod -U john                      # Unlock account

# Delete user
userdel john                         # Keep home directory
userdel -r john                      # Remove home directory

# Change password
passwd john

# User info
id john
groups john
finger john

# List all users
cat /etc/passwd
cut -d: -f1 /etc/passwd
```

**Ví dụ thực tế:**

```bash
# 1. Create developer user
useradd -m -s /bin/bash -G sudo,docker developer
passwd developer

# 2. Create application user (no login)
useradd -r -s /bin/false -d /opt/myapp myapp

# 3. Create deployment user
useradd -m -s /bin/bash -G www-data deploy
mkdir /home/deploy/.ssh
# Add public key for SSH

# 4. Create database user
useradd -r -s /bin/false -d /var/lib/mysql mysql

# 5. Temporary user
useradd -m -e 2024-12-31 tempuser
passwd tempuser

# 6. Web application user
useradd -r -s /bin/false -d /var/www/app webapp
chown -R webapp:webapp /var/www/app

# 7. Add existing user to group
usermod -aG docker existing_user
```

---

### **groupadd** - Create new group
**Syntax:**
```bash
groupadd [options] groupname
```

**Options:**
- `-g <gid>` - Specify group ID
- `-r` - Create system group
- `-f` - Force (exit successfully if group exists)

**Trường hợp sử dụng:**

```bash
# Create group
groupadd developers

# With specific GID
groupadd -g 1500 developers

# System group
groupadd -r appgroup

# Add users to group
usermod -aG developers john
usermod -aG developers jane

# Create group and add users
groupadd developers
gpasswd -a john developers
gpasswd -a jane developers

# Remove user from group
gpasswd -d john developers

# Delete group
groupdel developers

# List groups
cat /etc/group
getent group

# List group members
getent group developers
```

**Ví dụ thực tế:**

```bash
# 1. Development team
groupadd developers
usermod -aG developers alice
usermod -aG developers bob
mkdir /var/projects
chown :developers /var/projects
chmod 2775 /var/projects

# 2. Docker users
groupadd docker
usermod -aG docker username

# 3. Web server group
groupadd www-data
useradd -r -g www-data www-data

# 4. Shared project
groupadd project-team
mkdir /shared/project
chown :project-team /shared/project
chmod 2775 /shared/project
```

---

## 4. Task Scheduling

### **crontab** - Schedule tasks
**Syntax:**
```bash
crontab [options]
```

**Options:**
- `-e` - Edit crontab
- `-l` - List crontab
- `-r` - Remove crontab
- `-u <user>` - Specify user (requires root)

**Cron format:**
```
* * * * * command
│ │ │ │ │
│ │ │ │ └─── Day of week (0-7, 0 and 7 = Sunday)
│ │ │ └───── Month (1-12)
│ │ └─────── Day of month (1-31)
│ └───────── Hour (0-23)
└─────────── Minute (0-59)
```

**Special strings:**
- `@reboot` - Run at startup
- `@yearly` or `@annually` - Run once a year (0 0 1 1 *)
- `@monthly` - Run once a month (0 0 1 * *)
- `@weekly` - Run once a week (0 0 * * 0)
- `@daily` or `@midnight` - Run once a day (0 0 * * *)
- `@hourly` - Run once an hour (0 * * * *)

**Trường hợp sử dụng:**

```bash
# Edit crontab
crontab -e

# List current crontab
crontab -l

# Remove crontab
crontab -r

# Edit for specific user (as root)
crontab -u username -e

# Basic examples:

# Every minute
* * * * * /path/to/script.sh

# Every 5 minutes
*/5 * * * * /path/to/script.sh

# Every hour
0 * * * * /path/to/script.