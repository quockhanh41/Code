#!/usr/bin/env python3
"""
Fixed Course Monitor
Uses the exact same approach as the working scraper but simplified for monitoring.
"""

import requests
from bs4 import BeautifulSoup
import json
import time
from datetime import datetime
import getpass
import sys
import os
import subprocess

class WorkingCourseMonitor:
    def __init__(self, username, password):
        self.username = username
        self.password = password
        
        self.login_url = "https://portal.ctdb.hcmus.edu.vn/Login"
        self.target_url = "https://portal.ctdb.hcmus.edu.vn/dang-ky-hoc-phan/sinh-vien-clc"
        
        self.session = None
        self.csrf_token = None
        self.student_info = None
    
    def beep_alert(self, count=3):
        """Play beep sound alert with multiple methods for macOS"""
        print(f"🔊 Playing {count} beep(s)...")
        
        try:
            for i in range(count):
                # Method 1: macOS say command (most reliable)
                try:
                    subprocess.run(['say', 'beep'], check=True, capture_output=True)
                except:
                    # Method 2: macOS afplay with system sound
                    try:
                        subprocess.run(['afplay', '/System/Library/Sounds/Glass.aiff'], 
                                     check=True, capture_output=True)
                    except:
                        # Method 3: Terminal bell
                        try:
                            print('\a', end='', flush=True)
                            sys.stdout.flush()
                        except:
                            # Method 4: osascript (AppleScript)
                            try:
                                subprocess.run(['osascript', '-e', 'beep'], 
                                             check=True, capture_output=True)
                            except:
                                print(f"🔊 BEEP {i+1}/{count} (visual alert)")
                
                if i < count - 1:  # Don't sleep after the last beep
                    time.sleep(0.5)
                    
        except Exception as e:
            print(f"⚠️ Could not play beep: {e}")
            # Visual fallback
            for i in range(count):
                print(f"🔊 BEEP {i+1}/{count}!")
                time.sleep(0.3)
    
    def create_new_session(self):
        """Create fresh session with proper headers"""
        self.session = requests.Session()
        self.session.headers.update({
            'User-Agent': 'Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/140.0.0.0 Safari/537.36 Edg/140.0.0.0',
        })
    
    def login(self):
        """Login using exact method from working scraper"""
        print(f"🔐 Logging in as {self.username}...")
        
        try:
            # Create new session
            self.create_new_session()
            
            # Get login page
            login_page = self.session.get(self.login_url)
            login_page.raise_for_status()
            
            # Parse hidden form fields
            soup = BeautifulSoup(login_page.text, 'html.parser')
            hidden_tags = soup.find_all('input', type='hidden')
            login_payload = {tag['name']: tag.get('value', '') for tag in hidden_tags}
            
            # Add credentials
            login_payload.update({
                'dnn$ctr$Login$Login_DNN$txtUsername': self.username,
                'dnn$ctr$Login$Login_DNN$txtPassword': self.password,
                '__EVENTTARGET': 'dnn$ctr$Login$Login_DNN$cmdLogin'
            })
            
            # Submit login
            login_response = self.session.post(self.login_url, data=login_payload, allow_redirects=True)
            login_response.raise_for_status()
            
            # Check if login was successful
            if "Login" in login_response.url and "returnurl" in login_response.url:
                print("❌ Login failed - invalid credentials")
                return False
            
            print("✅ Login successful!")
            return True
            
        except Exception as e:
            print(f"❌ Login error: {e}")
            return False
    
    def access_course_page(self):
        """Access course page and get CSRF token - exact copy from working scraper"""
        print("📄 Accessing course registration page...")
        
        try:
            response = self.session.get(self.target_url)
            response.raise_for_status()
            
            soup = BeautifulSoup(response.text, 'html.parser')
            title = soup.title.text.strip() if soup.title else "No title"
            
            if "Login" in title:
                print("❌ Redirected to login page - session expired")
                return False
            
            # Extract CSRF token
            token_input = soup.find('input', {'name': '__RequestVerificationToken'})
            if token_input:
                self.csrf_token = token_input.get('value')
                print("✅ CSRF token extracted")
            else:
                print("⚠️ Warning: No CSRF token found")
                return False
            
            print(f"✅ Successfully accessed: {title}")
            return True
            
        except Exception as e:
            print(f"❌ Page access error: {e}")
            return False
    
    def make_ajax_call(self, action, data=None):
        """Exact copy of AJAX method from working scraper"""
        headers = {
            'Accept': '*/*',
            'Accept-Language': 'en-US,en;q=0.9',
            'Origin': 'https://portal.ctdb.hcmus.edu.vn',
            'Referer': self.target_url,
            'X-OFFICIAL-REQUEST': 'TRUE',
            'X-Requested-With': 'XMLHttpRequest',
        }
        
        # Prepare FormData (equivalent to JavaScript FormData)
        files = {
            'action': (None, action),
            'data': (None, str(data) if data is not None else '')
        }
        
        # Add CSRF token if available
        if self.csrf_token:
            files['__RequestVerificationToken'] = (None, self.csrf_token)
        
        try:
            response = self.session.post(
                self.target_url,
                files=files,
                headers=headers,
                timeout=120
            )
            response.raise_for_status()
            
            # Clean response (remove footer injection as per Common.js)
            response_text = response.text
            footer_idx = response_text.find('<div class="Đối tác_footer" id="qnmb">')
            if footer_idx > 0:
                response_text = response_text[:footer_idx].strip()
            
            return response_text
            
        except Exception as e:
            print(f"❌ AJAX call error for {action}: {e}")
            return None
    
    def load_student_info(self):
        """Load student info - exact copy from working scraper"""
        print("👤 Loading student information...")
        
        result = self.make_ajax_call("loadSinhVienInfo")
        if result:
            try:
                data = json.loads(result)
                if data.get('Status') == 'OK':
                    self.student_info = data.get('Results', {})
                    student_name = self.student_info.get('HoTen', 'Unknown')
                    student_id = self.student_info.get('MSSV', 'Unknown')
                    
                    print(f"✅ Student: {student_name} (ID: {student_id})")
                    return True
                else:
                    print(f"❌ Failed to load student info: {data.get('Message', 'Unknown error')}")
                    return False
            except json.JSONDecodeError:
                print("❌ Invalid response format")
                return False
        return False
    
    def check_course_by_mamg(self, mamg):
        """Check course availability by MaMG"""
        if not self.student_info:
            return None
        
        student_id = self.student_info.get('MSSV')
        result = self.make_ajax_call("loadDangKyHocPhan", student_id)
        
        if result:
            try:
                data = json.loads(result)
                if data.get('Status') == 'OK':
                    courses = data['Results']['ListChuaDangKy']
                    
                    # Find course by MaMG
                    for course in courses:
                        if course.get('MaMG') == mamg:
                            # Parse capacity
                            so_sv_tt_str = str(course.get('SoSVTT', '0/0'))
                            if '/' in so_sv_tt_str:
                                parts = so_sv_tt_str.split('/')
                                current = int(parts[0])
                                max_students = int(parts[1]) if len(parts) > 1 else course.get('SoSVDK', 0)
                            else:
                                current = int(so_sv_tt_str) if so_sv_tt_str.isdigit() else 0
                                max_students = course.get('SoSVDK', 0)
                            
                            available_slots = max_students - current
                            
                            return {
                                'code': course['KyHieu'],
                                'name': course['TenMH'],
                                'current': current,
                                'max': max_students,
                                'available': available_slots,
                                'is_available': available_slots > 0,
                                'schedule': course.get('LichHocLT', 'N/A')
                            }
                    
                    return None  # Course not found
                    
            except json.JSONDecodeError:
                print("❌ Invalid JSON response")
                return None
        
        return None
    
    def ensure_session_valid(self):
        """Ensure session is valid, re-login if needed"""
        if not self.session or not self.csrf_token or not self.student_info:
            print("🔄 Initializing session...")
            return self.login() and self.access_course_page() and self.load_student_info()
        
        # Test session with a simple call
        try:
            result = self.make_ajax_call("loadSinhVienInfo")
            if result:
                data = json.loads(result)
                if data.get('Status') == 'OK':
                    return True
        except:
            pass
        
        # Re-login needed
        print("🔄 Session expired, re-logging in...")
        return self.login() and self.access_course_page() and self.load_student_info()
    
    def monitor_course(self, mamg, interval=300):
        """Monitor course with auto re-login"""
        print(f"🎯 Monitoring MaMG {mamg} every {interval//60} minutes")
        print("Press Ctrl+C to stop\n")
        
        # Initial setup
        if not self.ensure_session_valid():
            print("❌ Could not establish session")
            return
        
        # Get initial course info
        initial_result = self.check_course_by_mamg(mamg)
        if not initial_result:
            print(f"❌ Course MaMG {mamg} not found")
            return
        
        print(f"📚 Tracking: {initial_result['code']} - {initial_result['name']}")
        print(f"📅 Schedule: {initial_result['schedule']}")
        print(f"📊 Initial status: {initial_result['available']} slots available ({initial_result['current']}/{initial_result['max']})\n")
        
        previous_available = initial_result['is_available']
        
        try:
            while True:
                time.sleep(interval)
                
                timestamp = datetime.now().strftime("%H:%M:%S")
                print(f"[{timestamp}] 🔍 Checking course availability...")
                
                # Ensure session is valid
                if not self.ensure_session_valid():
                    print("❌ Could not maintain session")
                    continue
                
                # Check course
                result = self.check_course_by_mamg(mamg)
                if not result:
                    print("❌ Failed to check course")
                    continue
                
                current_available = result['is_available']
                
                if current_available and not previous_available:
                    # Became available!
                    print(f"🎉 COURSE AVAILABLE! {result['code']} - {result['name']}")
                    print(f"📊 {result['available']} slots now available ({result['current']}/{result['max']})")
                    
                    # Sound alert for newly available course
                    print("🔊 BEEP ALERT: Course just became available!")
                    self.beep_alert(5)  # 5 beeps for new availability
                    
                    # Try notification
                    try:
                        import plyer
                        plyer.notification.notify(
                            title="HCMUS Course Available!",
                            message=f"{result['code']} has {result['available']} slots",
                            timeout=15
                        )
                    except:
                        pass
                        
                elif current_available:
                    print(f"✅ {result['code']}: Available ({result['available']} slots)")
                    # Gentle beep reminder for ongoing availability
                    self.beep_alert(1)  # Single beep for reminder
                else:
                    if previous_available:
                        print(f"⚠️ {result['code']}: Became FULL")
                    else:
                        print(f"🔴 {result['code']}: Full ({result['current']}/{result['max']})")
                
                previous_available = current_available
                print(f"⏰ Next check in {interval//60} minutes...\n")
                
        except KeyboardInterrupt:
            print("\n👋 Monitoring stopped")

def main():
    """Main function"""
    print("🎓 Working HCMUS Course Monitor")
    print("Based on the proven working scraper")
    print("=" * 40)
    
    # Get credentials
    username = input("👤 Username: ").strip()
    password = getpass.getpass("🔐 Password: ")
    
    # Get MaMG
    print("\n📚 Enter MaMG number to monitor:")
    print("  5907 - CSC12005 (usually full)")
    print("  5930 - CSC15104 (varies)")
    print("  5838 - CSC13002 (varies)")
    
    try:
        mamg = int(input("🔢 MaMG: "))
    except ValueError:
        print("❌ Invalid MaMG")
        return
    
    # # Get interval
    # try:
    #     interval_input = input("⏰ Check interval in minutes (default 5): ").strip()
    #     interval = int(interval_input) * 60 if interval_input else 300
    # except ValueError:
    #     interval = 300
    
    # Start monitoring
    monitor = WorkingCourseMonitor(username, password)
    monitor.monitor_course(mamg, 30)

if __name__ == "__main__":
    main()
