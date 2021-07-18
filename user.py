class User:
    def __init__(self, firstName, lastName, age, gender):
        fullName = firstName + ' '+ lastName
        self.fullName = fullName.title()
        self.age = age
        self.gender = gender

    def describeUser(self):
        print(self.fullName, 'is', self.age, 'y.o. Gender is', self.gender,'\n')

    def greetUser(self):
        print('Hi, ', self.fullName, '!')



class Privileges:
    def __init__(self):
        self.privileges = ['can add messages', 'can delete users', 'can ban users']

    def showPrivileges(self):
        for privileg in self.privileges:
            print(privileg, end="; ")

class Admin(User):
    def __init__(self, firstName, lastName, age, gender):
        super().__init__(firstName, lastName, age, gender)
        self.privileges = Privileges()



admin = Admin('pavel','vlasov',31,'male')

admin.privileges.showPrivileges()


