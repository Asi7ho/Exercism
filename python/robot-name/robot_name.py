import random
import string

class Robot(object):

    def __init__(self):
        self.usedName = []
        self.name = self.generateName()

    def generateName(self):
        # create name
        name = random.choice(string.ascii_uppercase) + random.choice(string.ascii_uppercase) + str(random.randint(0, 9)) + str(random.randint(0, 9)) + str(random.randint(0, 9))

        if self.verification(name) == True:
            name = self.generateName()

        self.usedName.append(name)
        return name


    # verify that the name is unique
    def verification(self, name):
        for i in range(len(self.usedName)):
            if name == self.usedName[i]:
                return True
        return False



    def reset(self):
        self.name = self.generateName()

