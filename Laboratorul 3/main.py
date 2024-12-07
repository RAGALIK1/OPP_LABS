import os
import time
from datetime import datetime
import threading

class BaseFile:
    def __init__(self, file_path):
        self.file_path = file_path
        self.name = os.path.basename(file_path)
        self.extension = os.path.splitext(file_path)[1]
        self.created_at = datetime.fromtimestamp(os.path.getctime(file_path))
        self.updated_at = datetime.fromtimestamp(os.path.getmtime(file_path))

    def details(self):
        return {
            "Name": self.name,
            "Extension": self.extension,
            "Created At": self.created_at,
            "Last Updated": self.updated_at,
        }

    def is_modified(self, snapshot_time):
        return self.updated_at > snapshot_time

class TextualFile(BaseFile):
    def details(self):
        file_info = super().details()
        with open(self.file_path, 'r') as file:
            content = file.read()
        lines = content.splitlines()
        file_info.update({
            "Total Lines": len(lines),
            "Word Count": sum(len(line.split()) for line in lines),
            "Character Count": len(content),
        })
        return file_info

class ImageFile(BaseFile):
    from PIL import Image

    def details(self):
        file_info = super().details()
        with Image.open(self.file_path) as image:
            file_info.update({
                "Resolution": f"{image.width}x{image.height}"
            })
        return file_info

class CodeFile(BaseFile):
    def details(self):
        file_info = super().details()
        with open(self.file_path, 'r') as file:
            lines = file.readlines()
        classes = sum(1 for line in lines if line.strip().startswith("class "))
        methods = sum(1 for line in lines if line.strip().startswith("def "))
        file_info.update({
            "Line Count": len(lines),
            "Class Definitions": classes,
            "Method Definitions": methods,
        })
        return file_info

class DirectoryWatcher:
    def __init__(self, directory):
        self.directory = directory
        self.last_snapshot = datetime.min
        self.files = self.scan_directory()
        self.previous_state = {file.name: file for file in self.files}
        self.active = True

    def scan_directory(self):
        detected_files = []
        for root, _, filenames in os.walk(self.directory):
            for filename in filenames:
                full_path = os.path.join(root, filename)
                extension = os.path.splitext(filename)[1].lower()
                if extension == ".txt":
                    detected_files.append(TextualFile(full_path))
                elif extension in [".png", ".jpg"]:
                    detected_files.append(ImageFile(full_path))
                elif extension in [".py", ".java"]:
                    detected_files.append(CodeFile(full_path))
                else:
                    detected_files.append(BaseFile(full_path))
        return detected_files

    def save_snapshot(self):
        self.last_snapshot = datetime.now()
        self.previous_state = {file.name: file for file in self.files}
        self.files = self.scan_directory()
        print("Snapshot saved. All files marked as up-to-date.")

    def file_info(self, file_name):
        for file in self.files:
            if file.name == file_name:
                details = file.details()
                for key, value in details.items():
                    print(f"{key}: {value}")
                return
        print("File not found in directory.")

    def check_status(self):
        current_files = {file.name: file for file in self.scan_directory()}
        new_files = set(current_files) - set(self.previous_state)
        removed_files = set(self.previous_state) - set(current_files)

        for new_file in new_files:
            print(f"{new_file} has been added.")

        for removed_file in removed_files:
            print(f"{removed_file} has been removed.")

        for file in self.files:
            if file.name in current_files and file.name not in new_files:
                status = "Modified" if file.is_modified(self.last_snapshot) else "Unchanged"
                print(f"{file.name}: {status}")

    def monitor_changes(self):
        while self.active:
            current_files = {file.name: file for file in self.scan_directory()}
            new_files = set(current_files) - set(self.previous_state)
            removed_files = set(self.previous_state) - set(current_files)

            for new_file in new_files:
                print(f"[Monitor] {new_file} has been added.")

            for removed_file in removed_files:
                print(f"[Monitor] {removed_file} has been removed.")

            for file in self.files:
                if file.name in current_files and file.name not in new_files:
                    if file.is_modified(self.last_snapshot):
                        print(f"[Monitor] {file.name} has been updated.")

            self.previous_state = current_files
            time.sleep(5)

    def stop_monitoring(self):
        self.active = False

# Directory Path
watch_directory = "/Users/basoccl/Desktop/cod/poo/lab3/save"
watcher = DirectoryWatcher(watch_directory)

# Start monitoring in a separate thread
monitor_thread = threading.Thread(target=watcher.monitor_changes, daemon=True)
monitor_thread.start()

while True:
    print("\nCommands: save | info <filename> | status | quit")
    user_input = input("Enter a command: ").strip().split()

    if not user_input:
        continue

    action = user_input[0].lower()

    if action == "save":
        watcher.save_snapshot()
    elif action == "info":
        if len(user_input) < 2:
            print("Usage: info <filename>")
        else:
            watcher.file_info(user_input[1])
    elif action == "status":
        watcher.check_status()
    elif action == "quit":
        watcher.stop_monitoring()
        break
    else:
        print("Invalid command.")
