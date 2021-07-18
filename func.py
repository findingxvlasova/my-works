'''def person(first_name, last_name, age = ''):
    if age:
        person = {'first': first_name, 'last': last_name, 'age': age}
    else:
        person = {'first': first_name, 'last': last_name}
    return person


musician = person('vasil', 'vlasov')
print(musician)

programer = person('katia', 'vlasova', 19)
print(programer)

'''
'''
def greet(names):
    for name in names:
        print('hello,', name.title())

fam = ['vasia', 'katia']


greet(fam)'''


'''
def something(*top):
    print(top)

fam = ['vasia', 'katia']

something(fam)
something('i wanna be your slaver')
'''

'''def makeProfile(firstName, lastNmae, **info):
    profile = {}
    profile['firstName'] = firstName
    profile['lastName'] = lastNmae

    for key, val in  info.items():
        profile[key] = val
    return profile


katia = makeProfile('katia', 'vlasova', workplace = 'home', studieplace = 'uni')
print(katia)
'''

'''
def sendwich(*components):
    print('your sendwich made frome:\n')
    for component in components:
        print(component, end='; ')


sendwich('pasta', 'pomidori','cheese')'''

'''
def myOwnCar(brand, modAAAel, **otherInfo):
    carPRofile = {}
    carPRofile['brand'] = brand
    carPRofile['madel'] = model

    for key, value in otherInfo.items():
        carPRofile[key] = value
    return carPRofile

audi = myOwnCar('audi', 'a5', owner = 'Pasha Vlasov')

print(audi)

car = myOwnCar('subaru', 'outback', color='blue', tow_package=True)
print(car)
'''
