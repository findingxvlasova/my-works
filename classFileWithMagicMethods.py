import tempfile
import os.path

class File:
    def __init__(self, path_to_file):
        self.path_to_file = path_to_file
        self.current_position = 0

    def read(self):
        with open(self.path_to_file, 'r') as f:
            result = f.read()
        return result

    def write(self, text):
        with open(self.path_to_file, 'w') as f:
            f.write(text)


    def __add__(self, other):
        new_path = os.path.join(tempfile.gettempdir(), 'file3.txt')
        file3 = type(self)(new_path)
        file3.write(self.read() + other.read())
        return file3


    def __str__(self):
        return f"{self.path_to_file}"

    def __iter__(self):
        return self

    def __next__(self):
        with open(self.path_to_file, 'r') as f:
            f.seek(self.current_position)
            line = f.readline()
            if not line:
                self.current_position = 0
                raise StopIteration
            else:
                self.current_position = f.tell()
                return line





'''
- чтение из файла, метод read возвращает строку
с текущим содержанием файла

- запись в файл, метод write принимает в качестве
аргумента строку с новым содержанием файла

- сложение объектов типа File, результатом сложения
является объект класса File, при этом создается 
новый файл и файловый объект, 
в котором содержимое второго файла добавляется к 
содержимому первого файла. Новый файл должен создаваться 
в директории, полученной с помощью
функции tempfile.gettempdir. 
Для получения нового пути можно использовать os.path.join.

- возвращать в качестве строкового представления
объекта класса File полный путь до файла

- поддерживать протокол итерации, причем
итерация проходит по строкам файла
'''
