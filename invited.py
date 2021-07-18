guests = ['Dua Lipa', 'Gal Gadot', 'Ashley Frangipane', 'Scarlett Johanson']

for i in guests:
    print("Hi,", i+ "! You are invited to my B-Day!")

print('\nGal Gadot doesnt go:(, but u can invite someone else!\n')

guests.remove('Gal Gadot')
guests.append('Ariana Grande')


for i in guests:
    print("Hi,", i + "! You are invited to my B-Day!")

print("\nEEEy i can invite more people! I bought new table!\n")

guests.insert(0, 'Lexa Kom Trikru')
guests.insert(int(len(guests)/2), 'Clark Kom Skykru')
guests.append('Vasily Vlasov')


for i in guests:
    print("Hi,", i + "! You are invited to my B-Day!")


print("\nSheesh what hte hell! Where is my table! I can invite only two poeple..\n")

while len(guests)!=2:
    delGuest = guests.pop()
    print("Sorry!", delGuest,"I love u but my flat so small!")

print("\nthere is only two people he hee\n")
for i in guests:
    print("Hi,", i + "! You are still invited to my B-Day!")

del guests
print(guests)

