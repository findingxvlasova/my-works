word = input("Enter your word: ")

letters = list(word)

life = 3
while True:
    letter = input("Guess the word (enter letter by letter, u have only 3 lifes): ")
    if letter in letters:
        print(letter," is in this word! ")
        letters.remove(letter)
        if len(letters) == 0 and life >= 0:
            print("You are win!\nThe word was" , word)
            break
    else:
        print("No, -1 life :)\n")
        life -= 1
        if life == 0:
            print("Game over. ")
            break
