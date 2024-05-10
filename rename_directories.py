import os

def rename_directories(root_dir):
    for dirpath, dirnames, filenames in os.walk(root_dir):
        for dirname in dirnames:
            full_dir_path = os.path.join(dirpath, dirname)
            new_dirname = dirname.zfill(4)  # Переименовываем в формате с ведущими нулями
            new_full_dir_path = os.path.join(dirpath, new_dirname)

            # Удалить все файлы из целевой директории
            for filename in os.listdir(full_dir_path):
                file_path = os.path.join(full_dir_path, filename)
                if os.path.isfile(file_path):
                    os.remove(file_path)

            # Переименовать директорию
            os.rename(full_dir_path, new_full_dir_path)

if __name__ == "__main__":
    rename_directories('.')
