# Linux Commands - Xử lý dữ liệu & Thao tác file nâng cao

## Mục lục

- [Linux Commands - Xử lý dữ liệu \& Thao tác file nâng cao](#linux-commands---xử-lý-dữ-liệu--thao-tác-file-nâng-cao)
  - [Mục lục](#mục-lục)
  - [1. Xử lý Text \& Data](#1-xử-lý-text--data)
    - [**awk** - Pattern scanning and processing](#awk---pattern-scanning-and-processing)
    - [**sed** - Stream editor](#sed---stream-editor)
  - [2. Tìm kiếm File](#2-tìm-kiếm-file)
    - [**find** - Search for files in directory hierarchy](#find---search-for-files-in-directory-hierarchy)
    - [**locate** - Find files by name (faster than find)](#locate---find-files-by-name-faster-than-find)
  - [3. Nén \& Giải nén](#3-nén--giải-nén)
    - [**tar** - Archive utility](#tar---archive-utility)
    - [**gzip / gunzip** - Compress/decompress files](#gzip--gunzip---compressdecompress-files)
    - [**zip / unzip** - ZIP archive utility](#zip--unzip---zip-archive-utility)
- [Create zip](#create-zip)
- [Recursive zip](#recursive-zip)
- [Create with password](#create-with-password)
- [Maximum compression](#maximum-compression)
- [Add to existing zip](#add-to-existing-zip)
- [Update changed files](#update-changed-files)
- [Exclude files](#exclude-files)
- [List contents](#list-contents)
- [Test integrity](#test-integrity)
- [Extract](#extract)
- [Extract to specific directory](#extract-to-specific-directory)
- [Extract specific file](#extract-specific-file)
- [Extract without prompting](#extract-without-prompting)
- [Extract with password](#extract-with-password)
- [Quiet extraction](#quiet-extraction)
- [View file from zip](#view-file-from-zip)
- [Split large zip](#split-large-zip)
- [Merge split zip](#merge-split-zip)
- [Delete from zip](#delete-from-zip)

---

## 1. Xử lý Text & Data

### **awk** - Pattern scanning and processing
**Syntax:**
```bash
awk [options] 'pattern {action}' file
```

**Concepts cơ bản:**
- `$0` - Toàn bộ dòng
- `$1, $2, $3...` - Cột 1, 2, 3...
- `NR` - Số dòng hiện tại (Number of Record)
- `NF` - Số cột trong dòng (Number of Fields)
- `FS` - Field Separator (mặc định: space/tab)
- `OFS` - Output Field Separator
- `BEGIN {}` - Execute trước khi đọc file
- `END {}` - Execute sau khi đọc xong

**Options phổ biến:**
- `-F <delimiter>` - Đặt field separator
- `-v var=value` - Set variable
- `-f <script>` - Đọc awk script từ file

**Trường hợp sử dụng:**

```bash
# Print cột 1 và 5
awk '{print $1, $5}' access.log

# Print với separator tùy chỉnh
awk -F: '{print $1, $3}' /etc/passwd

# Print với custom output separator
awk -F: 'BEGIN {OFS="|"} {print $1, $3, $7}' /etc/passwd

# Lọc theo điều kiện
awk '$5 > 1000 {print $1, $5}' file.txt

# Print dòng chứa pattern
awk '/ERROR/ {print $0}' app.log

# Print số dòng và nội dung
awk '{print NR, $0}' file.txt

# Sum cột số
awk '{sum += $3} END {print "Total:", sum}' numbers.txt

# Calculate average
awk '{sum+=$1; count++} END {print sum/count}' numbers.txt

# Print last column
awk '{print $NF}' file.txt

# Print second to last column
awk '{print $(NF-1)}' file.txt

# Count occurrences
awk '{count[$1]++} END {for (word in count) print word, count[word]}' file.txt

# Filter log by time range
awk '$4 >= "10:00:00" && $4 <= "11:00:00"' log.txt

# Print lines longer than 80 characters
awk 'length($0) > 80' file.txt

# Print specific range of lines
awk 'NR>=10 && NR<=20' file.txt

# CSV processing với comma separator
awk -F, '{print $2, $4}' data.csv

# Multiple conditions
awk '$3 == "ERROR" && $5 > 100 {print $1, $2}' log.txt

# String concatenation
awk '{print $1 "-" $2 "-" $3}' file.txt

# Using variables
awk -v threshold=1000 '$5 > threshold {print $0}' file.txt

# Format output với printf
awk '{printf "%-20s %10.2f\n", $1, $2}' file.txt

# Process multiple files
awk '{sum+=$1} END {print FILENAME, sum}' file1.txt file2.txt

# Extract IP addresses from access log
awk '{print $1}' access.log | sort | uniq -c | sort -rn

# Calculate response time statistics
awk '{sum+=$NF; count++} END {print "Avg:", sum/count, "Count:", count}' response_times.log

# Group by and sum
awk '{arr[$1]+=$2} END {for (i in arr) print i, arr[i]}' sales.txt

# Advanced: Parse JSON-like logs
awk -F'"' '{print $4}' json_log.txt

# Count HTTP status codes
awk '{print $9}' access.log | sort | uniq -c | sort -rn

# Filter by date and count
awk -F'[: ]' '$1=="2024-01-15" {count++} END {print count}' app.log

# Extract email addresses
awk '/[A-Za-z0-9._%+-]+@[A-Za-z0-9.-]+\.[A-Z|a-z]{2,}/' file.txt

# Calculate percentiles (simplified)
awk '{a[NR]=$1} END {print a[int(NR*0.95)]}' sorted_numbers.txt

# Multi-line records
awk 'BEGIN {RS=""; FS="\n"} {print $1, $3}' multi_line.txt
```

**Ví dụ thực tế cho DevOps:**

```bash
# 1. Phân tích access log - Top 10 IPs
awk '{print $1}' access.log | sort | uniq -c | sort -rn | head -10

# 2. Tính bandwidth sử dụng
awk '{sum+=$10} END {print "Total:", sum/1024/1024, "MB"}' access.log

# 3. Error rate by hour
awk -F'[: []' '/ERROR/ {print $4}' app.log | sort | uniq -c

# 4. Response time > 1s
awk '$NF > 1000 {print $0}' response_times.log

# 5. Parse nginx access log
awk '{print $1, $7, $9, $NF}' access.log

# 6. Memory usage per process
ps aux | awk '{mem[$11]+=$6} END {for (i in mem) print i, mem[i]/1024 "MB"}'

# 7. Disk usage alert
df -h | awk '+$5 > 80 {print "Alert:", $0}'

# 8. Count 4xx and 5xx errors
awk '$9 ~ /^[45]/ {count++} END {print "Errors:", count}' access.log

# 9. Average request duration per endpoint
awk '{endpoint=$7; sum[endpoint]+=$NF; count[endpoint]++} 
     END {for (e in sum) print e, sum[e]/count[e]}' access.log

# 10. Parse JSON logs (extract specific field)
awk -F'"' '/timestamp/ {print $4}' app.json
```

---

### **sed** - Stream editor
**Syntax:**
```bash
sed [options] 'command' file
```

**Options phổ biến:**
- `-i` - In-place editing (sửa trực tiếp file)
- `-i.bak` - In-place với backup
- `-e` - Multiple commands
- `-n` - Suppress default output (dùng với `p`)
- `-r` hoặc `-E` - Extended regex

**Commands chính:**
- `s/pattern/replacement/` - Substitute
- `d` - Delete
- `p` - Print
- `a` - Append
- `i` - Insert
- `c` - Change line
- `y` - Transform characters

**Flags cho substitute:**
- `g` - Global (tất cả occurrences trong dòng)
- `i` - Case insensitive
- `p` - Print matched lines
- `w file` - Write matches to file
- `<number>` - Replace nth occurrence

**Trường hợp sử dụng:**

```bash
# Thay thế cơ bản (chỉ lần đầu tiên trong mỗi dòng)
sed 's/http/https/' config.yaml

# Thay thế tất cả trong dòng (global)
sed 's/http/https/g' config.yaml

# In-place editing (sửa trực tiếp file)
sed -i 's/http/https/g' config.yaml

# In-place với backup
sed -i.bak 's/http/https/g' config.yaml

# Case insensitive
sed 's/error/ERROR/gi' log.txt

# Thay thế chỉ dòng cụ thể
sed '5s/old/new/' file.txt

# Thay thế trong range dòng
sed '10,20s/old/new/g' file.txt

# Xóa dòng
sed '5d' file.txt                    # Xóa dòng 5
sed '10,20d' file.txt                # Xóa dòng 10-20
sed '/pattern/d' file.txt            # Xóa dòng chứa pattern
sed '/^$/d' file.txt                 # Xóa dòng trống
sed '/^#/d' file.txt                 # Xóa comment lines

# Print specific lines
sed -n '10,20p' file.txt             # Print dòng 10-20
sed -n '/ERROR/p' log.txt            # Print dòng chứa ERROR

# Insert before line
sed '5i\New line text' file.txt

# Append after line
sed '5a\New line text' file.txt

# Replace entire line
sed '5c\Completely new line' file.txt

# Multiple commands
sed -e 's/foo/bar/g' -e 's/baz/qux/g' file.txt

# Using regex groups
sed 's/\([0-9]\{3\}\)-\([0-9]\{4\}\)/(\1) \2/' phone.txt

# Remove leading whitespace
sed 's/^[ \t]*//' file.txt

# Remove trailing whitespace
sed 's/[ \t]*$//' file.txt

# Remove both leading and trailing
sed 's/^[ \t]*//; s/[ \t]*$//' file.txt

# Double space a file
sed 'G' file.txt

# Delete blank lines
sed '/^$/d' file.txt

# Add line numbers
sed = file.txt | sed 'N;s/\n/\t/'

# Replace only on lines matching pattern
sed '/pattern/s/old/new/g' file.txt

# Replace except on lines matching pattern
sed '/pattern/!s/old/new/g' file.txt

# Change delimiter (useful khi có /)
sed 's|/var/www|/var/html|g' config.txt

# Extract text between patterns
sed -n '/START/,/END/p' file.txt

# Transform characters
sed 'y/abc/ABC/' file.txt

# Comment out lines
sed 's/^/# /' file.txt

# Uncomment lines
sed 's/^# //' file.txt

# Add text at beginning of each line
sed 's/^/PREFIX: /' file.txt

# Add text at end of each line
sed 's/$/ SUFFIX/' file.txt

# Replace nth occurrence
sed 's/old/new/2' file.txt           # Thay thế lần xuất hiện thứ 2

# Print only matched part
sed -n 's/.*\(pattern\).*/\1/p' file.txt
```

**Ví dụ thực tế cho DevOps:**

```bash
# 1. Update configuration files
sed -i 's/PORT=3000/PORT=8080/g' .env

# 2. Replace environment variables
sed -i "s/\${OLD_VAR}/${NEW_VAR}/g" config.yml

# 3. Remove DEBUG logs
sed -i '/DEBUG/d' app.log

# 4. Change domain in nginx config
sed -i 's/old-domain\.com/new-domain.com/g' /etc/nginx/sites-enabled/default

# 5. Update database connection string
sed -i 's/localhost:3306/db-server:3306/g' application.properties

# 6. Add trailing slash to URLs
sed -i 's|url = \(.*[^/]\)$|url = \1/|' config.txt

# 7. Extract and modify version numbers
sed -n 's/version: \([0-9.]*\)/\1/p' package.yaml

# 8. Disable specific features
sed -i '/feature_x/s/enabled: true/enabled: false/' features.conf

# 9. Batch rename in scripts
sed -i 's/old_function_name/new_function_name/g' *.sh

# 10. Format log timestamps
sed 's/\([0-9]\{4\}\)\([0-9]\{2\}\)\([0-9]\{2\}\)/\1-\2-\3/' log.txt

# 11. Remove sensitive data
sed -i 's/password=.*/password=***REDACTED***/g' debug.log

# 12. Update IP addresses
sed -i 's/192\.168\.1\./10.0.0./g' hosts.txt

# 13. Convert Windows line endings to Unix
sed -i 's/\r$//' windows_file.txt

# 14. Add quotes around values
sed 's/=/="/' config.txt | sed 's/$/"/'

# 15. Extract URLs from HTML
sed -n 's/.*href="\([^"]*\).*/\1/p' index.html
```

**Sed scripts phức tạp:**

```bash
# Multi-line processing
sed ':a;N;$!ba;s/\n/ /g' file.txt    # Join all lines

# Conditional replacement
sed '/pattern/{n;s/old/new/}' file.txt

# Print lines between two patterns
sed -n '/START/,/END/p' file.txt

# Delete lines between two patterns
sed '/START/,/END/d' file.txt
```

---

## 2. Tìm kiếm File

### **find** - Search for files in directory hierarchy
**Syntax:**
```bash
find [path] [options] [tests] [actions]
```

**Tests (điều kiện tìm kiếm):**
- `-name <pattern>` - Tên file (case sensitive)
- `-iname <pattern>` - Tên file (case insensitive)
- `-type <type>` - Type: f (file), d (directory), l (link)
- `-size <size>` - Kích thước: +100M, -1G, 50k
- `-mtime <days>` - Modified time: -7 (trong 7 ngày), +30 (hơn 30 ngày)
- `-atime <days>` - Access time
- `-ctime <days>` - Change time
- `-mmin <minutes>` - Modified trong n phút
- `-user <username>` - Owner
- `-group <groupname>` - Group
- `-perm <mode>` - Permissions
- `-empty` - Empty files/directories
- `-executable` - Executable files

**Actions:**
- `-print` - Print path (default)
- `-delete` - Delete files
- `-exec <command> {} \;` - Execute command
- `-exec <command> {} +` - Execute với multiple files
- `-ok <command> {} \;` - Execute với confirmation
- `-ls` - List chi tiết

**Operators:**
- `-and` hoặc `-a` - AND (default)
- `-or` hoặc `-o` - OR
- `-not` hoặc `!` - NOT
- `()` - Grouping

**Trường hợp sử dụng:**

```bash
# Tìm file theo tên
find /var/log -name "*.log"

# Case insensitive
find . -iname "readme.md"

# Tìm directories
find /var -type d -name "logs"

# Tìm files
find . -type f -name "*.conf"

# Tìm symbolic links
find /etc -type l

# Tìm files lớn hơn 100MB
find / -type f -size +100M

# Tìm files nhỏ hơn 1KB
find . -type f -size -1k

# Tìm files trong khoảng size
find . -type f -size +10M -size -100M

# Tìm files modified trong 7 ngày
find /var/log -type f -mtime -7

# Tìm files modified hơn 30 ngày
find /tmp -type f -mtime +30

# Tìm files modified hôm nay
find . -type f -mtime 0

# Tìm files accessed trong 60 phút
find /var -type f -amin -60

# Tìm files của user
find /home -user nginx

# Tìm files của group
find /var -group www-data

# Tìm files với permissions cụ thể
find . -type f -perm 0644

# Tìm files writable by others (security issue)
find / -type f -perm -002

# Tìm SUID files (security check)
find / -type f -perm -4000

# Tìm empty files
find /tmp -type f -empty

# Tìm empty directories
find /var -type d -empty

# Tìm executable files
find /usr/bin -type f -executable

# Delete files
find /tmp -type f -name "*.tmp" -delete

# Execute command trên mỗi file
find . -type f -name "*.log" -exec gzip {} \;

# Execute với multiple files (faster)
find . -type f -name "*.txt" -exec grep "pattern" {} +

# Execute với confirmation
find . -type f -name "*.bak" -ok rm {} \;

# Multiple conditions (AND)
find . -type f -name "*.log" -size +10M

# OR condition
find . -type f \( -name "*.log" -o -name "*.txt" \)

# NOT condition
find . -type f ! -name "*.log"

# Complex combinations
find . -type f \( -name "*.log" -o -name "*.txt" \) -size +1M

# Find and count
find . -type f -name "*.js" | wc -l

# Find and list details
find /var/log -name "*.log" -ls

# Find files modified today and show size
find . -type f -mtime 0 -exec ls -lh {} \;

# Find và copy
find . -name "*.conf" -exec cp {} /backup/ \;

# Find và change permissions
find . -type f -name "*.sh" -exec chmod +x {} \;

# Find và change owner
find /var/www -type f -exec chown www-data:www-data {} \;

# Find files không thuộc về user nào
find / -nouser

# Find files không thuộc về group nào
find / -nogroup

# Max depth (không đệ quy sâu)
find . -maxdepth 2 -name "*.log"

# Min depth
find . -mindepth 2 -name "*.conf"

# Exclude directories
find . -path ./node_modules -prune -o -name "*.js" -print

# Find và sort by size
find . -type f -exec ls -lh {} \; | sort -k5 -h

# Find files modified between dates
find . -type f -newermt "2024-01-01" ! -newermt "2024-02-01"

# Find broken symlinks
find /etc -type l ! -exec test -e {} \; -print

# Find duplicate files by name
find . -type f -printf "%f\n" | sort | uniq -d

# Find files by inode
find . -inum 12345

# Find files and show path only
find /var -name "error.log" -print 2>/dev/null

# Find world-writable directories
find / -type d -perm -0002

# Find files without specific permission
find . -type f ! -perm 0644
```

**Ví dụ thực tế cho DevOps:**

```bash
# 1. Clean old log files (older than 30 days)
find /var/log -name "*.log" -mtime +30 -delete

# 2. Find large files consuming disk space
find / -type f -size +500M -exec ls -lh {} \; 2>/dev/null

# 3. Find and compress old logs
find /var/log -name "*.log" -mtime +7 -exec gzip {} \;

# 4. Find files modified in last hour (for debugging)
find /var/www -type f -mmin -60

# 5. Security audit - find world-writable files
find /var -type f -perm -002 -exec ls -l {} \;

# 6. Find and remove temporary files
find /tmp -type f -name "tmp*" -mtime +1 -delete

# 7. Find core dumps
find / -name "core.*" -o -name "core" -type f

# 8. Find files owned by removed users
find / -nouser -exec ls -l {} \;

# 9. Backup specific files
find /etc -name "*.conf" -exec cp {} /backup/configs/ \;

# 10. Find PHP files modified today (after deployment)
find /var/www -name "*.php" -mtime 0

# 11. Find and fix permissions
find /var/www/html -type f -exec chmod 644 {} \;
find /var/www/html -type d -exec chmod 755 {} \;

# 12. Find config files for inventory
find /etc -name "*.conf" -o -name "*.yaml" -o -name "*.yml"

# 13. Find empty log files to remove
find /var/log -type f -empty -delete

# 14. Find recently accessed files (intrusion detection)
find /etc -type f -amin -30

# 15. Generate file list for backup
find /var/www -type f -newer /tmp/last_backup.timestamp > files_to_backup.txt

# 16. Find files by extension and count
find . -name "*.js" -type f | wc -l

# 17. Find and archive old files
find /data -name "*.dat" -mtime +90 -exec tar -czf archive.tar.gz {} +

# 18. Find files excluding certain directories
find / -path /proc -prune -o -path /sys -prune -o -name "*.conf" -print

# 19. Find files and grep content
find . -name "*.yml" -exec grep -l "production" {} \;

# 20. Find and verify checksums
find /var/www -type f -name "*.php" -exec md5sum {} \; > checksums.txt
```

---

### **locate** - Find files by name (faster than find)
**Syntax:**
```bash
locate [options] pattern
```

**Options:**
- `-i` - Case insensitive
- `-c` - Count matches
- `-l <num>` - Limit results
- `-r <regex>` - Use regex
- `-b` - Match only basename
- `--existing` - Chỉ show files tồn tại
- `-S` - Show database statistics

**Trường hợp sử dụng:**

```bash
# Tìm file cơ bản (rất nhanh)
locate nginx.conf

# Case insensitive
locate -i readme.md

# Count results
locate -c "*.log"

# Limit results
locate -l 10 config

# Only basename
locate -b '\nginx.conf'

# Regex search
locate -r '\.conf$'

# Check if files still exist
locate --existing nginx.conf

# Multiple patterns
locate -i "error" | grep "log"

# Update database (cần sudo)
sudo updatedb

# Show database info
locate -S

# Find in specific directory
locate /etc | grep nginx
```

**Lưu ý:**
- `locate` dùng database (updatedb), cần update định kỳ
- Nhanh hơn `find` nhưng không real-time
- Không thể tìm theo size, time, permissions như `find`

---

## 3. Nén & Giải nén

### **tar** - Archive utility
**Syntax:**
```bash
tar [options] archive_name files
```

**Options chính:**
- `-c` - Create archive
- `-x` - Extract archive
- `-t` - List contents
- `-f <file>` - Archive filename
- `-v` - Verbose
- `-z` - gzip compression (.tar.gz, .tgz)
- `-j` - bzip2 compression (.tar.bz2)
- `-J` - xz compression (.tar.xz)
- `-C <dir>` - Change to directory
- `--exclude=<pattern>` - Exclude files
- `-p` - Preserve permissions
- `--remove-files` - Remove files after archiving

**Trường hợp sử dụng:**

```bash
# Create tar archive
tar -cf archive.tar files/

# Create with verbose
tar -cvf archive.tar files/

# Create gzip compressed
tar -czf archive.tar.gz files/

# Create bzip2 compressed (better compression)
tar -cjf archive.tar.bz2 files/

# Create xz compressed (best compression)
tar -cJf archive.tar.xz files/

# Extract tar
tar -xf archive.tar

# Extract tar.gz
tar -xzf archive.tar.gz

# Extract to specific directory
tar -xzf archive.tar.gz -C /destination/

# List contents
tar -tzf archive.tar.gz

# List verbose
tar -tzvf archive.tar.gz

# Extract specific file
tar -xzf archive.tar.gz path/to/file

# Create excluding files
tar -czf backup.tar.gz --exclude='*.log' --exclude='node_modules' /var/www/

# Create excluding multiple patterns
tar -czf backup.tar.gz --exclude='*.log' --exclude='*.tmp' --exclude='.git' /data/

# Append files to existing tar
tar -rf archive.tar newfile.txt

# Extract preserving permissions
tar -xpzf archive.tar.gz

# Create with date in filename
tar -czf backup-$(date +%Y%m%d).tar.gz /var/www/

# Verify archive integrity
tar -tzf archive.tar.gz > /dev/null

# Split large archives
tar -czf - /large/dir | split -b 1G - backup.tar.gz.part

# Restore from split archives
cat backup.tar.gz.part* | tar -xzf -

# Create with progress (pv)
tar -czf - /data | pv > backup.tar.gz

# Remote backup via SSH
tar -czf - /data | ssh user@remote 'cat > backup.tar.gz'

# Backup with exclusion list from file
tar -czf backup.tar.gz -X exclude-list.txt /data/

# Incremental backup
tar -czf incremental.tar.gz --listed-incremental=snapshot.file /data/

# Extract and show progress
pv archive.tar.gz | tar -xzf -

# Create archive of modified files
find /var/www -mtime -1 -type f | tar -czf recent.tar.gz -T -

# Compare archive with filesystem
tar -df archive.tar

# Extract tar.bz2
tar -xjf archive.tar.bz2

# Extract tar.xz
tar -xJf archive.tar.xz
```

**Ví dụ backup scripts:**

```bash
# Daily backup script
#!/bin/bash
BACKUP_DIR="/backup"
DATE=$(date +%Y%m%d_%H%M%S)
tar -czf $BACKUP_DIR/website-$DATE.tar.gz \
    --exclude='/var/www/cache' \
    --exclude='/var/www/tmp' \
    /var/www/

# Keep only last 7 days
find $BACKUP_DIR -name "website-*.tar.gz" -mtime +7 -delete

# Database + files backup
tar -czf backup-$DATE.tar.gz /var/www/ /etc/nginx/
mysqldump -u root -p database > db-$DATE.sql
gzip db-$DATE.sql
```

---

### **gzip / gunzip** - Compress/decompress files
**Syntax:**
```bash
gzip [options] files
gunzip [options] files
```

**Options:**
- `-c` - Write to stdout (keep original)
- `-d` - Decompress (gunzip)
- `-k` - Keep original file
- `-r` - Recursive
- `-v` - Verbose
- `-1` to `-9` - Compression level (1=fast, 9=best)
- `-t` - Test integrity

**Trường hợp sử dụng:**

```bash
# Compress file
gzip file.txt                      # Creates file.txt.gz, removes original

# Compress keeping original
gzip -c file.txt > file.txt.gz

# Keep original (newer gzip)
gzip -k file.txt

# Best compression
gzip -9 file.txt

# Fast compression
gzip -1 file.txt

# Decompress
gunzip file.txt.gz

# Decompress keeping .gz
gunzip -c file.txt.gz > file.txt

# Decompress keeping original
gunzip -k file.txt.gz

# Test integrity
gzip -t file.txt.gz

# Compress multiple files
gzip file1.txt file2.txt file3.txt

# Recursive compress
gzip -r logs/

# View compressed file
zcat file.txt.gz
zless file.txt.gz
zgrep "pattern" file.txt.gz

# Compress and show ratio
gzip -v file.txt

# Decompress to stdout and pipe
gunzip -c access.log.gz | grep "ERROR"

# Recompress with better ratio
gunzip -c file.gz | gzip -9 > file_better.gz

# Compress log files older than 7 days
find /var/log -name "*.log" -mtime +7 -exec gzip {} \;
```

---

### **zip / unzip** - ZIP archive utility
**Syntax:**
```bash
zip [options] archive.zip files
unzip [options] archive.zip
```

**Zip Options:**
- `-r` - Recursive
- `-e` - Encrypt with password
- `-q` - Quiet
- `-v` - Verbose
- `-<1-9>` - Compression level
- `-x <pattern>` - Exclude files
- `-u` - Update existing archive
- `-d` - Delete from archive

**Unzip Options:**
- `-l` - List contents
- `-t` - Test integrity
- `-d <dir>` - Extract to directory
- `-o` - Overwrite without prompting
- `-n` - Never overwrite
- `-q` - Quiet
- `-P <password>` - Password

**Trường hợp sử dụng:**

```bash
# Create zip
zip archive.zip file.txt

# Recursive zip
zip -r website.zip /var/www/

# Create with password
zip -e -r secure.zip /data/

# Maximum compression
zip -9 -r archive.zip files/

# Add to existing zip
zip -r archive.zip newfile.txt

# Update changed files
zip -r -u archive.zip files/

# Exclude files
zip -r backup.zip /var/www/ -x "*.log" "*.tmp"

# List contents
unzip -l archive.zip

# Test integrity
unzip -t archive.zip

# Extract
unzip archive.zip

# Extract to specific directory
unzip archive.zip -d /destination/

# Extract specific file
unzip archive.zip path/to/file.txt

# Extract without prompting
unzip -o archive.zip

# Extract with password
unzip -P mypassword secure.zip

# Quiet extraction
unzip -q archive.zip

# View file from zip
unzip -p archive.zip file.txt

# Split large zip
zip -s 100m -r large.zip /big/directory/

# Merge split zip
zip -F large.zip --out merged.zip

# Delete from zip
zip -d archive.zip unwanted_