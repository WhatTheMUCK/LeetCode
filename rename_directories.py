import os
import re

def rename_directories(path):
    for dir_name in os.listdir(path):
        full_dir_path = os.path.join(path, dir_name)
        if os.path.isdir(full_dir_path):
            match = re.match(r'^(\d+)(-.*)$', dir_name)
            if match:
                number_part = match.group(1)
                rest_part = match.group(2)
                new_number_part = number_part.zfill(4)
                new_dir_name = f"{new_number_part}{rest_part}"
                new_full_dir_path = os.path.join(path, new_dir_name)
                os.rename(full_dir_path, new_full_dir_path)
                print(f"Renamed '{full_dir_path}' to '{new_full_dir_path}'")

if __name__ == '__main__':
    rename_directories('.')
