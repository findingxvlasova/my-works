
while True:
    name = input("Tell me your name (orr enter 'q' to break): ")
    if name != 'q':
        message = 'Hi, '+name.title() + '!\n'
        print(message)
        with open('questBook.txt', 'a') as quests:
            quests.write(message)
    else:
