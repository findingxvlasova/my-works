class Restaurant:
    def __init__(self, restaurantName, cuisineType):
        self.restaurantName = restaurantName
        self.cuisineType = cuisineType

    def describeRestaurant(self):
        print('Our '+ self.restaurantName + ' restaurant!\n')
        print('Cuisine tyoe is '+ self.cuisineType)


    def openRestaurant(self):
        print("Restaurant is open.")


class IceCreamStand(Restaurant):

    def __init__(self, restaurantName, cuisineType, flavors):
        super().__init__(restaurantName, cuisineType)
        self.flavors = flavors

    def showFlavors(self):
        for flavor in self.flavors:
            print(flavor.title())



choko = IceCreamStand("ChokoPoko", "machine", ['choko', 'atrawberry', 'maliby', 'fackel'])

choko.showFlavors()
