# Chi tiết các lệnh Linux dùng hàng ngày  

## Mục lục

- [Chi tiết các lệnh Linux dùng hàng ngày](#chi-tiết-các-lệnh-linux-dùng-hàng-ngày)
  - [Mục lục](#mục-lục)
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
  - [Tips \& Best Practices](#tips--best-practices)
    - [**Combining Commands**](#combining-commands)
    - [**Aliases hữu ích**](#aliases-hữu-ích)
    - [**Safety Tips**](#safety-tips)
  - [Quick Reference Table](#quick-reference-table)

---

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

## Tips & Best Practices

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

## Quick Reference Table

| Lệnh | Mục đích |