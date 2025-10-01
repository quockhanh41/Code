# Complete Linux Commands Guide - Hướng dẫn toàn diện các lệnh Linux

## Mục lục tổng hợp

### **PHẦN I: Lệnh Linux hàng ngày (Daily Commands)**
- [Complete Linux Commands Guide - Hướng dẫn toàn diện các lệnh Linux](#complete-linux-commands-guide---hướng-dẫn-toàn-diện-các-lệnh-linux)
  - [Mục lục tổng hợp](#mục-lục-tổng-hợp)
    - [**PHẦN I: Lệnh Linux hàng ngày (Daily Commands)**](#phần-i-lệnh-linux-hàng-ngày-daily-commands)
    - [**PHẦN II: Xử lý dữ liệu \& Thao tác file nâng cao (Common Commands)**](#phần-ii-xử-lý-dữ-liệu--thao-tác-file-nâng-cao-common-commands)
    - [**PHẦN III: System Administration \& Container Commands (Advanced)**](#phần-iii-system-administration--container-commands-advanced)
- [PHẦN I: LỆNH LINUX HÀNG NGÀY](#phần-i-lệnh-linux-hàng-ngày)
  - [1. Kết nối \& Truyền file](#1-kết-nối--truyền-file)
    - [**ssh** - Kết nối remote server](#ssh---kết-nối-remote-server)
    - [**scp** - Copy file qua SSH](#scp---copy-file-qua-ssh)
    - [**sftp** - FTP qua SSH](#sftp---ftp-qua-ssh)
  - [2. Quản lý File/Folder](#2-quản-lý-filefolder)
    - [**ls** - List files](#ls---list-files)
    - [**cd** - Change directory](#cd---change-directory)
    - [**pwd** - Print working directory](#pwd---print-working-directory)
    - [**cp** - Copy files/folders](#cp---copy-filesfolders)
    - [**mv** - Move/rename files](#mv---moverename-files)
    - [**rm** - Remove files/folders](#rm---remove-filesfolders)
    - [**mkdir** - Make directory](#mkdir---make-directory)
    - [**touch** - Create/update file timestamp](#touch---createupdate-file-timestamp)
  - [3. Đọc File/Log](#3-đọc-filelog)
    - [**cat** - Concatenate and display files](#cat---concatenate-and-display-files)
    - [**less** - View file với pagination](#less---view-file-với-pagination)
    - [**tail** - Xem cuối file](#tail---xem-cuối-file)
    - [**head** - Xem đầu file](#head---xem-đầu-file)
  - [4. Tìm kiếm trong File](#4-tìm-kiếm-trong-file)
    - [**grep** - Search patterns in files](#grep---search-patterns-in-files)
  - [5. Theo dõi Tài nguyên](#5-theo-dõi-tài-nguyên)
    - [**ps** - Process status](#ps---process-status)
    - [**top** - Real-time process viewer](#top---real-time-process-viewer)
    - [**htop** - Enhanced top](#htop---enhanced-top)
    - [**df** - Disk filesystem usage](#df---disk-filesystem-usage)
    - [**du** - Disk usage of files/folders](#du---disk-usage-of-filesfolders)
    - [**free** - Memory usage](#free---memory-usage)
    - [**uptime** - System uptime và load average](#uptime---system-uptime-và-load-average)
  - [6. Quản lý Services](#6-quản-lý-services)
    - [**systemctl** - Systemd control](#systemctl---systemd-control)
    - [**service** - Legacy service control](#service---legacy-service-control)
    - [**journalctl** - Systemd journal logs](#journalctl---systemd-journal-logs)
  - [7. Tips \& Best Practices Daily](#7-tips--best-practices-daily)
    - [**Combining Commands**](#combining-commands)
    - [**Aliases hữu ích**](#aliases-hữu-ích)
    - [**Safety Tips**](#safety-tips)
- [PHẦN II: XỬ LÝ DỮ LIỆU \& THAO TÁC FILE NÂNG CAO](#phần-ii-xử-lý-dữ-liệu--thao-tác-file-nâng-cao)
  - [8. Xử lý Text \& Data](#8-xử-lý-text--data)
    - [**awk** - Pattern scanning and processing](#awk---pattern-scanning-and-processing)
    - [**sed** - Stream editor](#sed---stream-editor)
  - [9. Tìm kiếm File nâng cao](#9-tìm-kiếm-file-nâng-cao)
    - [**find** - Search for files in directory hierarchy](#find---search-for-files-in-directory-hierarchy)
    - [**locate** - Find files by name (faster than find)](#locate---find-files-by-name-faster-than-find)
  - [10. Nén \& Giải nén](#10-nén--giải-nén)
    - [**tar** - Archive utility](#tar---archive-utility)
    - [**gzip / gunzip** - Compress/decompress files](#gzip--gunzip---compressdecompress-files)
    - [**zip / unzip** - ZIP archive utility](#zip--unzip---zip-archive-utility)
  - [12. Xử lý Text/Log nâng cao](#12-xử-lý-textlog-nâng-cao)
    - [**sort** - Sort lines of text](#sort---sort-lines-of-text)
    - [**uniq** - Report or omit repeated lines](#uniq---report-or-omit-repeated-lines)
    - [**wc** - Word, line, character count](#wc---word-line-character-count)
    - [**cut** - Remove sections from lines](#cut---remove-sections-from-lines)
    - [**tr** - Translate or delete characters](#tr---translate-or-delete-characters)
    - [**diff** - Compare files line by line](#diff---compare-files-line-by-line)
    - [**cmp** - Compare two files byte by byte](#cmp---compare-two-files-byte-by-byte)
  - [13. Quản lý Permissions \& Users](#13-quản-lý-permissions--users)
    - [**chmod** - Change file permissions](#chmod---change-file-permissions)
    - [**chown** - Change file owner and group](#chown---change-file-owner-and-group)
    - [**useradd / adduser** - Create new user](#useradd--adduser---create-new-user)
    - [**groupadd** - Create new group](#groupadd---create-new-group)
  - [14. Task Scheduling](#14-task-scheduling)
    - [**crontab** - Schedule tasks](#crontab---schedule-tasks)

### **PHẦN II: Xử lý dữ liệu & Thao tác file nâng cao (Common Commands)**
8. [Xử lý Text & Data](#8-xử-lý-text--data)
   - [awk - Pattern scanning and processing](#awk---pattern-scanning-and-processing)
   - [sed - Stream editor](#sed---stream-editor)

9. [Tìm kiếm File nâng cao](#9-tìm-kiếm-file-nâng-cao)
   - [find - Search for files in directory hierarchy](#find---search-for-files-in-directory-hierarchy)
   - [locate - Find files by name (faster than find)](#locate---find-files-by-name-faster-than-find)

10. [Nén & Giải nén](#10-nén--giải-nén)
    - [tar - Archive utility](#tar---archive-utility)
    - [gzip / gunzip - Compress/decompress files](#gzip--gunzip---compressdecompress-files)
    - [zip / unzip - ZIP archive utility](#zip--unzip---zip-archive-utility)

### **PHẦN III: System Administration & Container Commands (Advanced)**
11. [Xử lý Input/Output](#11-xử-lý-inputoutput)
    - [xargs - Build and execute commands from standard input](#xargs---build-and-execute-commands-from-standard-input)

12. [Xử lý Text/Log nâng cao](#12-xử-lý-textlog-nâng-cao)
    - [sort - Sort lines of text](#sort---sort-lines-of-text)
    - [uniq - Report or omit repeated lines](#uniq---report-or-omit-repeated-lines)
    - [wc - Word, line, character count](#wc---word-line-character-count)
    - [cut - Remove sections from lines](#cut---remove-sections-from-lines)
    - [tr - Translate or delete characters](#tr---translate-or-delete-characters)
    - [diff - Compare files line by line](#diff---compare-files-line-by-line)
    - [cmp - Compare two files byte by byte](#cmp---compare-two-files-byte-by-byte)

13. [Quản lý Permissions & Users](#13-quản-lý-permissions--users)
    - [chmod - Change file permissions](#chmod---change-file-permissions)
    - [chown - Change file owner and group](#chown---change-file-owner-and-group)
    - [useradd / adduser - Create new user](#useradd--adduser---create-new-user)
    - [groupadd - Create new group](#groupadd---create-new-group)

14. [Task Scheduling](#14-task-scheduling)
    - [crontab - Schedule tasks](#crontab---schedule-tasks)

---

# PHẦN I: LỆNH LINUX HÀNG NGÀY

## 1. Kết nối & Truyền file

### **ssh** - Kết nối remote server
**Syntax:**
```bash
ssh [options] [user@]hostname [command]
```

**Options phổ biến:**
- `-p <port>` - Chỉ định port (mặc định 22)
- `-i <private_key>` - Dùng SSH key file
- `-L <local_port>:<remote_host>:<remote_port>` - Port forwarding local
- `-R <remote_port>:<local_host>:<local_port>` - Port forwarding remote
- `-D <port>` - Dynamic port forwarding (SOCKS proxy)
- `-v` - Verbose mode (debug)
- `-X` - Enable X11 forwarding
- `-N` - Không execute command (dùng với port forwarding)

**Trường hợp sử dụng:**
```bash
# Kết nối cơ bản
ssh user@192.168.1.100

# Kết nối với port và key
ssh -p 2222 -i ~/.ssh/my_key.pem ubuntu@server.com

# Execute command từ xa
ssh user@server 'df -h'

# Port forwarding - truy cập database local qua SSH
ssh -L 3306:localhost:3306 user@db-server

# Copy SSH key lên server
ssh-copy-id -i ~/.ssh/id_rsa.pub user@server
```

---

### **scp** - Copy file qua SSH
**Syntax:**
```bash
scp [options] source destination
```

**Options phổ biến:**
- `-P <port>` - Port SSH (chú ý: chữ P hoa)
- `-i <key>` - SSH key
- `-r` - Recursive (copy thư mục)
- `-C` - Compress data
- `-v` - Verbose
- `-p` - Preserve timestamps/permissions
- `-l <limit>` - Giới hạn bandwidth (Kbit/s)

**Trường hợp sử dụng:**
```bash
# Copy file từ local lên server
scp app.zip user@server:/var/www/

# Copy file từ server về local
scp user@server:/var/log/app.log ./logs/

# Copy thư mục
scp -r ./website user@server:/var/www/html/

# Copy với port và key
scp -P 2222 -i key.pem file.tar.gz user@server:/tmp/

# Copy giữa 2 servers (từ máy local)
scp user1@server1:/path/file user2@server2:/path/
```

---

### **sftp** - FTP qua SSH
**Syntax:**
```bash
sftp [options] [user@]host
```

**Options:**
- `-P <port>` - Port
- `-i <key>` - SSH key
- `-b <batchfile>` - Batch mode với file commands

**Commands trong SFTP:**
- `ls, cd, pwd` - Navigate remote
- `lls, lcd, lpwd` - Navigate local
- `get <file>` - Download
- `put <file>` - Upload
- `mget, mput` - Multiple files
- `mkdir, rmdir` - Quản lý thư mục
- `bye, exit` - Thoát

**Trường hợp sử dụng:**
```bash
# Kết nối SFTP
sftp user@server

# Trong SFTP session:
sftp> ls                    # List remote files
sftp> cd /var/www          # Change remote dir
sftp> lcd ~/Downloads      # Change local dir
sftp> get backup.sql       # Download file
sftp> put app.tar.gz       # Upload file
sftp> mget *.log           # Download multiple files

# Batch mode
echo "get /logs/*.log" | sftp user@server
```

---

## 2. Quản lý File/Folder

### **ls** - List files
**Syntax:**
```bash
ls [options] [path]
```

**Options:**
- `-l` - Long format (permissions, owner, size, date)
- `-a` - Show hidden files (bắt đầu bằng .)
- `-h` - Human readable sizes (KB, MB, GB)
- `-t` - Sort by modification time
- `-r` - Reverse order
- `-S` - Sort by size
- `-R` - Recursive
- `-i` - Show inode numbers
- `--color=auto` - Colorize output

**Trường hợp sử dụng:**
```bash
# List chi tiết, dễ đọc
ls -lah

# Sắp xếp theo thời gian, mới nhất trước
ls -lth

# Sắp xếp theo size, lớn nhất trước
ls -lhS

# List file log gần nhất
ls -lt /var/log/*.log | head

# Hiển thị tree structure
ls -R | grep ":$" | sed -e 's/:$//' -e 's/[^-][^\/]*\//--/g'
```

---

### **cd** - Change directory
**Syntax:**
```bash
cd [path]
```

**Shortcuts:**
- `cd ~` hoặc `cd` - Home directory
- `cd -` - Previous directory
- `cd ..` - Parent directory
- `cd ../..` - Up 2 levels

**Trường hợp sử dụng:**
```bash
cd /var/www/html        # Absolute path
cd logs                 # Relative path
cd ~ubuntu              # User's home
cd -                    # Quay lại thư mục trước
```

---

### **pwd** - Print working directory
**Syntax:**
```bash
pwd [options]
```

**Options:**
- `-P` - Physical path (không follow symlinks)
- `-L` - Logical path (follow symlinks)

**Trường hợp sử dụng:**
```bash
pwd                     # Xem thư mục hiện tại
echo "Current: $(pwd)"  # Dùng trong script
```

---

### **cp** - Copy files/folders
**Syntax:**
```bash
cp [options] source destination
```

**Options:**
- `-r` hoặc `-R` - Recursive (copy thư mục)
- `-i` - Interactive (hỏi trước khi overwrite)
- `-f` - Force overwrite
- `-p` - Preserve attributes (permissions, timestamps)
- `-a` - Archive mode (-dpR, preserve everything)
- `-v` - Verbose
- `-u` - Update (chỉ copy nếu source mới hơn)
- `-n` - No clobber (không overwrite)

**Trường hợp sử dụng:**
```bash
# Copy file cơ bản
cp config.yml config.yml.bak

# Copy thư mục, giữ permissions
cp -rp /var/www/app /backup/

# Copy với confirmation
cp -i important.conf /etc/

# Backup với timestamp
cp app.log app.log.$(date +%Y%m%d_%H%M%S)

# Copy nhiều files
cp file1.txt file2.txt file3.txt /destination/
```

---

### **mv** - Move/rename files
**Syntax:**
```bash
mv [options] source destination
```

**Options:**
- `-i` - Interactive
- `-f` - Force
- `-n` - No overwrite
- `-v` - Verbose
- `-u` - Update only

**Trường hợp sử dụng:**
```bash
# Rename file
mv old_name.txt new_name.txt

# Move file
mv report.pdf /home/user/documents/

# Move nhiều files
mv *.log /var/log/archive/

# Move với backup nếu tồn tại
mv -b config.yml /etc/app/

# Rename hàng loạt (dùng với loop)
for f in *.jpeg; do mv "$f" "${f%.jpeg}.jpg"; done
```

---

### **rm** - Remove files/folders
**Syntax:**
```bash
rm [options] file/folder
```

**Options:**
- `-r` hoặc `-R` - Recursive (xóa thư mục)
- `-f` - Force (không hỏi, ignore không tồn tại)
- `-i` - Interactive
- `-v` - Verbose
- `-d` - Remove empty directories

**Trường hợp sử dụng:**
```bash
# Xóa file
rm file.txt

# Xóa thư mục
rm -rf old_project/

# Xóa với confirmation
rm -i *.conf

# Xóa files cũ hơn 30 ngày
find /var/log -type f -mtime +30 -delete

# Xóa an toàn (hỏi cho files > 3 nếu recursive)
rm -rI large_folder/

# CẢNH BÁO: Lệnh nguy hiểm
rm -rf /    # XÓA HẾT HỆ THỐNG - ĐỪNG BAO GIỜ CHẠY!
```

---

### **mkdir** - Make directory
**Syntax:**
```bash
mkdir [options] directory
```

**Options:**
- `-p` - Tạo parent directories nếu cần
- `-m <mode>` - Set permissions
- `-v` - Verbose

**Trường hợp sử dụng:**
```bash
# Tạo thư mục đơn
mkdir projects

# Tạo nested directories
mkdir -p app/src/components/ui

# Tạo với permissions
mkdir -m 755 public_html

# Tạo nhiều thư mục
mkdir logs cache temp

# Tạo structure cho project
mkdir -p {src,tests,docs}/{js,css,img}
```

---

### **touch** - Create/update file timestamp
**Syntax:**
```bash
touch [options] file
```

**Options:**
- `-a` - Chỉ update access time
- `-m` - Chỉ update modification time
- `-c` - Không tạo file mới nếu không tồn tại
- `-t <timestamp>` - Set specific time (YYYYMMDDhhmm.ss)
- `-r <reference>` - Dùng timestamp của file khác

**Trường hợp sử dụng:**
```bash
# Tạo file rỗng
touch newfile.txt

# Tạo nhiều files
touch file1.txt file2.txt file3.txt

# Update timestamp
touch existing_file.log

# Tạo file với timestamp cụ thể
touch -t 202401150930.00 old_file.txt

# Dùng trong script để check directory writable
touch /var/www/test && rm /var/www/test || echo "Not writable"
```

---

## 3. Đọc File/Log

### **cat** - Concatenate and display files
**Syntax:**
```bash
cat [options] [file...]
```

**Options:**
- `-n` - Đánh số dòng
- `-b` - Đánh số dòng không rỗng
- `-s` - Squeeze multiple blank lines
- `-A` - Show all (tabs, end of lines)
- `-E` - Show line endings ($)
- `-T` - Show tabs (^I)

**Trường hợp sử dụng:**
```bash
# Xem file
cat config.yml

# Xem nhiều files
cat file1.txt file2.txt

# Với số dòng
cat -n error.log

# Tạo file nhanh (Ctrl+D để kết thúc)
cat > newfile.txt
This is content
^D

# Append vào file
cat >> existing.txt
More content
^D

# Merge files
cat part1.txt part2.txt > complete.txt

# Xem file binary có chứa text
cat binary.log | strings

# Here document trong script
cat << EOF > config.conf
server {
    listen 80;
    server_name example.com;
}
EOF
```

---

### **less** - View file với pagination
**Syntax:**
```bash
less [options] file
```

**Options:**
- `-N` - Show line numbers
- `-S` - Chop long lines (không wrap)
- `-i` - Case-insensitive search
- `-F` - Exit nếu nội dung vừa 1 screen
- `+F` - Follow mode (như tail -f)
- `-X` - Không clear screen khi exit

**Keyboard commands trong less:**
- `Space`, `f` - Next page
- `b` - Previous page
- `/pattern` - Search forward
- `?pattern` - Search backward
- `n` - Next match
- `N` - Previous match
- `g` - Go to start
- `G` - Go to end
- `q` - Quit
- `&pattern` - Show only matching lines
- `F` - Follow mode

**Trường hợp sử dụng:**
```bash
# Xem file lớn
less large_log.log

# Với line numbers
less -N app.log

# Follow log real-time
less +F /var/log/syslog

# Không wrap dòng dài
less -S access.log

# Xem output của command
ps aux | less

# Colorize log
less -R colored_output.log
```

---

### **tail** - Xem cuối file
**Syntax:**
```bash
tail [options] [file...]
```

**Options:**
- `-n <num>` - Số dòng (mặc định 10)
- `-f` - Follow (theo dõi real-time)
- `-F` - Follow và retry nếu file rotate
- `-c <num>` - Số bytes
- `-q` - Quiet (không show headers)
- `--pid=<pid>` - Stop khi process chết
- `-s <seconds>` - Sleep interval khi follow

**Trường hợp sử dụng:**
```bash
# 10 dòng cuối
tail error.log

# 50 dòng cuối
tail -n 50 access.log

# Follow log real-time
tail -f /var/log/nginx/error.log

# Follow nhiều files
tail -f app.log error.log

# Follow với line highlight
tail -f app.log | grep --color=always ERROR

# Follow và handle rotation
tail -F /var/log/app.log

# Kết hợp với grep
tail -f access.log | grep "404"

# Stop follow khi process kết thúc
tail -f --pid=1234 app.log
```

---

### **head** - Xem đầu file
**Syntax:**
```bash
head [options] [file...]
```

**Options:**
- `-n <num>` - Số dòng (mặc định 10)
- `-c <num>` - Số bytes
- `-q` - Quiet mode

**Trường hợp sử dụng:**
```bash
# 10 dòng đầu
head config.yml

# 100 dòng đầu
head -n 100 large_file.log

# Xem header của CSV
head -n 1 data.csv

# Kết hợp head và tail - xem dòng 20-30
head -n 30 file.txt | tail -n 11

# So sánh đầu 2 files
head file1.txt file2.txt
```

---

## 4. Tìm kiếm trong File

### **grep** - Search patterns in files
**Syntax:**
```bash
grep [options] pattern [file...]
```

**Options quan trọng:**
- `-i` - Case insensitive
- `-v` - Invert match (hiện dòng KHÔNG match)
- `-r` hoặc `-R` - Recursive search
- `-n` - Show line numbers
- `-c` - Count matches
- `-l` - Chỉ show filenames có match
- `-L` - Show filenames KHÔNG có match
- `-w` - Match whole word
- `-x` - Match whole line
- `-A <num>` - Show N lines After match
- `-B <num>` - Show N lines Before match
- `-C <num>` - Show N lines Context (before+after)
- `-E` - Extended regex (hoặc dùng `egrep`)
- `-F` - Fixed strings (không dùng regex)
- `-o` - Chỉ show phần match
- `--color=auto` - Highlight matches
- `-q` - Quiet (chỉ return exit code)

**Trường hợp sử dụng:**
```bash
# Tìm cơ bản
grep "ERROR" app.log

# Case insensitive
grep -i "error" app.log

# Với số dòng
grep -n "exception" error.log

# Recursive trong thư mục
grep -r "TODO" ./src/

# Count occurrences
grep -c "200 OK" access.log

# Show 3 dòng context
grep -C 3 "OutOfMemory" app.log

# Multiple patterns
grep -E "ERROR|FATAL|CRITICAL" app.log

# Match whole word
grep -w "test" file.txt  # khớp "test" không khớp "testing"

# Invert match - loại bỏ dòng
grep -v "DEBUG" app.log | grep -v "INFO"

# Chỉ show filename
grep -l "password" *.conf

# Recursive với file pattern
grep -r --include="*.java" "public static void" ./

# Show chỉ IP addresses
grep -oE "\b([0-9]{1,3}\.){3}[0-9]{1,3}\b" access.log

# Tìm empty lines
grep "^$" file.txt

# Combine với pipes
tail -f app.log | grep --color=always "ERROR"

# Dùng trong scripts
if grep -q "error" log.txt; then
    echo "Errors found!"
fi

# Complex regex
grep -E "^[A-Z]{3}[0-9]{4}$" codes.txt

# Count unique IPs in access log
grep -oE "\b([0-9]{1,3}\.){3}[0-9]{1,3}\b" access.log | sort | uniq -c

# Tìm files modified today có chứa pattern
find . -type f -mtime 0 -exec grep -l "config" {} \;
```

---

## 5. Theo dõi Tài nguyên

### **ps** - Process status
**Syntax:**
```bash
ps [options]
```

**Options phổ biến:**
- `aux` - All processes, user-oriented
- `-ef` - All processes, full format
- `-u <user>` - Processes của user
- `-p <pid>` - Process cụ thể
- `--sort=-%cpu` - Sắp xếp theo CPU
- `--forest` - Tree view

**Trường hợp sử dụng:**
```bash
# Tất cả processes
ps aux

# Full format
ps -ef

# Của user cụ thể
ps -u nginx

# Process tree
ps auxf

# Sắp xếp theo memory
ps aux --sort=-%mem | head

# Tìm process cụ thể
ps aux | grep nginx

# Show threads
ps -eLf

# Custom output
ps -eo pid,ppid,cmd,%mem,%cpu --sort=-%mem | head

# Watch specific process
watch -n 1 'ps aux | grep [n]ginx'
```

---

### **top** - Real-time process viewer
**Syntax:**
```bash
top [options]
```

**Options:**
- `-d <seconds>` - Update delay
- `-u <user>` - Chỉ show user
- `-p <pid>` - Monitor specific PIDs
- `-n <num>` - Number of iterations (dùng trong script)
- `-b` - Batch mode (không interactive)

**Keyboard commands trong top:**
- `h` - Help
- `k` - Kill process
- `r` - Renice process
- `M` - Sort by memory
- `P` - Sort by CPU
- `T` - Sort by time
- `c` - Toggle command line
- `1` - Toggle CPU cores
- `q` - Quit

**Trường hợp sử dụng:**
```bash
# Basic top
top

# Chỉ user nginx
top -u nginx

# Update mỗi 2 giây
top -d 2

# Batch mode - log snapshot
top -b -n 1 > top_snapshot.txt

# Monitor specific processes
top -p 1234,5678
```

---

### **htop** - Enhanced top
**Syntax:**
```bash
htop [options]
```

**Features:**
- Visual CPU, memory, swap meters
- Tree view of processes
- Mouse support
- Easier to kill/nice processes
- Search và filter

**Keyboard shortcuts:**
- `F1` - Help
- `F2` - Setup
- `F3` - Search
- `F4` - Filter
- `F5` - Tree view
- `F6` - Sort by
- `F9` - Kill
- `F10` - Quit
- `Space` - Tag process
- `/` - Search

**Trường hợp sử dụng:**
```bash
# Run htop
htop

# Chỉ user cụ thể
htop -u nginx

# Tree view
htop -t

# Sort by memory
htop --sort-key=PERCENT_MEM
```

---

### **df** - Disk filesystem usage
**Syntax:**
```bash
df [options] [filesystem...]
```

**Options:**
- `-h` - Human readable
- `-T` - Show filesystem type
- `-i` - Show inode information
- `-x <type>` - Exclude filesystem type
- `-t <type>` - Chỉ show type
- `--total` - Show total

**Trường hợp sử dụng:**
```bash
# Disk usage readable
df -h

# Với filesystem type
df -hT

# Inode usage (quan trọng!)
df -i

# Chỉ local filesystems
df -hlT -x tmpfs -x devtmpfs

# Check specific mount
df -h /var/log

# Alert nếu disk > 80%
df -h | awk '$5 > 80 {print $0}'
```

---

### **du** - Disk usage of files/folders
**Syntax:**
```bash
du [options] [path...]
```

**Options:**
- `-h` - Human readable
- `-s` - Summary (tổng only)
- `-a` - All files (không chỉ folders)
- `-c` - Grand total
- `-d <depth>` - Max depth
- `--max-depth=N` - Tương tự -d
- `-x` - Stay on one filesystem
- `--exclude=<pattern>` - Exclude

**Trường hợp sử dụng:**
```bash
# Size của thư mục hiện tại
du -sh .

# Top 10 folders lớn nhất
du -h --max-depth=1 | sort -hr | head -10

# Tất cả files trong /var/log
du -ah /var/log | sort -hr | head -20

# Exclude một số folders
du -sh --exclude=node_modules --exclude=.git .

# Size các folders level 1
du -h --max-depth=1 /var/

# Find files lớn hơn 100MB
find / -type f -size +100M -exec du -h {} \; 2>/dev/null

# Total size của nhiều folders
du -shc /var/log /var/cache /tmp
```

---

### **free** - Memory usage
**Syntax:**
```bash
free [options]
```

**Options:**
- `-h` - Human readable
- `-m` - Show in MB
- `-g` - Show in GB
- `-s <seconds>` - Continuous updates
- `-t` - Show totals
- `-w` - Wide mode (separate buffers/cache)

**Trường hợp sử dụng:**
```bash
# Memory usage
free -h

# Update mỗi 2 giây
free -h -s 2

# Với totals
free -ht

# Chỉ show available memory
free -h | awk 'NR==2{print $7}'

# Alert nếu memory < 10%
free | awk 'NR==2{if($4/$2*100<10) print "Low memory!"}'
```

---

### **uptime** - System uptime và load average
**Syntax:**
```bash
uptime [options]
```

**Options:**
- `-p` - Pretty format
- `-s` - Since (thời gian boot)

**Trường hợp sử dụng:**
```bash
# System uptime
uptime
# Output: 10:30:15 up 45 days, 3:25, 2 users, load average: 0.15, 0.10, 0.05

# Pretty format
uptime -p
# Output: up 45 days, 3 hours, 25 minutes

# Boot time
uptime -s
# Output: 2024-08-15 07:05:03

# Explain load average:
# 3 numbers: 1-min, 5-min, 15-min average
# Rule: Load < số CPU cores = OK
# Load > số cores = overloaded
```

---

## 6. Quản lý Services

### **systemctl** - Systemd control
**Syntax:**
```bash
systemctl [command] [service]
```

**Commands chính:**
- `start` - Start service
- `stop` - Stop service
- `restart` - Restart service
- `reload` - Reload config (không stop)
- `enable` - Enable auto-start
- `disable` - Disable auto-start
- `status` - Show status
- `is-active` - Check if running
- `is-enabled` - Check if enabled
- `list-units` - List all units
- `daemon-reload` - Reload systemd configs

**Trường hợp sử dụng:**
```bash
# Start service
systemctl start nginx

# Stop service
systemctl stop apache2

# Restart service
systemctl restart mysql

# Reload config không downtime
systemctl reload nginx

# Check status
systemctl status docker

# Enable auto-start on boot
systemctl enable redis

# Disable auto-start
systemctl disable mongodb

# Check if running
systemctl is-active nginx

# Check if enabled
systemctl is-enabled ssh

# List all services
systemctl list-units --type=service

# List failed services
systemctl --failed

# Reload systemd daemon (sau khi sửa .service file)
systemctl daemon-reload

# Show service dependencies
systemctl list-dependencies nginx

# Mask service (không cho start)
systemctl mask apache2

# Edit service file
systemctl edit nginx

# View service file
systemctl cat nginx
```

---

### **service** - Legacy service control
**Syntax:**
```bash
service <service> <command>
```

**Commands:**
- `start`, `stop`, `restart`, `status`, `reload`

**Trường hợp sử dụng:**
```bash
# Dùng trên hệ thống cũ không có systemd
service nginx start
service mysql restart
service ssh status

# List all services
service --status-all
```

---

### **journalctl** - Systemd journal logs
**Syntax:**
```bash
journalctl [options]
```

**Options quan trọng:**
- `-u <unit>` - Logs của service
- `-f` - Follow (real-time)
- `-n <num>` - Số dòng cuối
- `-r` - Reverse (mới nhất trước)
- `--since` - Từ thời điểm
- `--until` - Đến thời điểm
- `-p <priority>` - Priority level (emerg, alert, crit, err, warning, notice, info, debug)
- `-b` - Logs của boot hiện tại
- `-b -1` - Boot trước
- `--disk-usage` - Disk usage của logs
- `--vacuum-size` - Clean old logs
- `-k` - Kernel messages
- `-o <format>` - Output format

**Trường hợp sử dụng:**
```bash
# Logs của service
journalctl -u nginx

# Follow logs
journalctl -u nginx -f

# 100 dòng cuối
journalctl -u docker -n 100

# Logs hôm nay
journalctl --since today

# Logs từ thời điểm cụ thể
journalctl --since "2024-01-15 10:00:00"

# Logs giữa 2 thời điểm
journalctl --since "2024-01-15" --until "2024-01-16"

# Chỉ errors
journalctl -p err -u nginx

# Chỉ crit và cao hơn
journalctl -p crit

# Logs của boot hiện tại
journalctl -b

# Logs của boot trước (troubleshoot crash)
journalctl -b -1

# Kernel messages
journalctl -k

# JSON output
journalctl -u nginx -o json-pretty

# Check disk usage
journalctl --disk-usage

# Clean logs, giữ 100MB
journalctl --vacuum-size=100M

# Clean logs cũ hơn 7 ngày
journalctl --vacuum-time=7d

# Logs của multiple services
journalctl -u nginx -u mysql

# Grep trong logs
journalctl -u nginx | grep "404"

# Export logs
journalctl -u nginx --since today > nginx_today.log

# Real-time với grep
journalctl -u nginx -f | grep --color=always "error"
```

---

## 7. Tips & Best Practices Daily

### **Combining Commands**
```bash
# Pipeline cơ bản
ps aux | grep nginx | grep -v grep

# Tìm process và kill
ps aux | grep python | awk '{print $2}' | xargs kill

# Find và xóa files cũ
find /var/log -name "*.log" -mtime +30 -exec rm {} \;

# Disk usage sorted
du -h / | sort -hr | head -20

# Count log levels
grep -oE "ERROR|WARN|INFO" app.log | sort | uniq -c

# Monitor command output
watch -n 1 'df -h | grep sda1'
```

### **Aliases hữu ích**
```bash
# Thêm vào ~/.bashrc
alias ll='ls -lah'
alias ports='netstat -tulanp'
alias meminfo='free -h -l -t'
alias psg='ps aux | grep -v grep | grep -i -e VSZ -e'
alias update='sudo apt update && sudo apt upgrade'
```

### **Safety Tips**
```bash
# Always test với -i (interactive)
rm -i important_file

# Backup trước khi sửa
cp config.yml config.yml.backup

# Dùng screen/tmux cho long-running commands
screen -S deployment

# Log output của scripts
./deploy.sh 2>&1 | tee deploy.log
```

---



# PHẦN II: XỬ LÝ DỮ LIỆU & THAO TÁC FILE NÂNG CAO
---

## 8. Xử lý Text & Data

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

## 9. Tìm kiếm File nâng cao

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

## 10. Nén & Giải nén

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

# PHẦN III: SYSTEM ADMINISTRATION & CONTAINER COMMANDS

---

## 11. Xử lý Input/Output

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

## 12. Xử lý Text/Log nâng cao

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

## 13. Quản lý Permissions & Users

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

## 14. Task Scheduling

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

