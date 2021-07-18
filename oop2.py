class Horse:
    def __init__(self, name, color, owner):
        self.name = name
        self. color = color
        self.owner = owner


class Rider:
    def __init__(self, name):
        self.name = name


indian = Rider('John')
spirit = Horse('Spirirt', 'brown', indian)

print(spirit.owner.name)
