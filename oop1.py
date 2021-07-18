class Shape():
    def what_i_am(self):
        print("I am shape\n")


class Rectangle(Shape):

    def __init__(self, width, height):
        self.width = width
        self.height = height

    def calculate_perimeter(self):
        perimeter = (self.width+self.height)*2
        return perimeter

class Square(Shape):

    def __init__(self, side_length):
        self.side_length = side_length


    def calculate_perimeter(self):
        perimeter = self.side_length*4
        return perimeter

    def change_size(self, change_side):
            self.side_length += change_side



a = Rectangle(4, 5)

b = Square(4)

perA = a.calculate_perimeter()
perB = b.calculate_perimeter()
print('perA = ', perA)
print('perB = ', perB)

b.change_size(3)
print(b.side_length)
b.change_size(-3)
print(b.side_length)

a.what_i_am()
