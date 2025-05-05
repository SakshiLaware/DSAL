class Detail:
    def __init__(self, name="NULL", number=0):
        self.name = name
        self.number = number

class Telp:
    def __init__(self):
        self.size = int(input("Enter size of Hash Table= "))
        self.A = [Detail() for _ in range(10)]
        self.B = [Detail() for _ in range(10)]
        self.initial()

    def initial(self):
        for i in range(self.size):
            self.A[i] = Detail()
            self.B[i] = Detail()

    def hashz(self):
        name = input("Enter Name of Client: ")
        number = int(input("Enter Telephone No of Client: "))
        sum_ascii = sum(ord(c) for c in name)
        homeaddress = sum_ascii % self.size

        # Linear probing
        j = homeaddress
        while True:
            if self.A[j].name == "NULL":
                self.A[j] = Detail(name, number)
                break
            j = (j + 1) % self.size
            if j == homeaddress:
                print("Hash table full for linear probing!")
                break

        # Quadratic probing
        o = 0
        for k in range((self.size - 1) // 2 + 1):
            h = (homeaddress + o * o) % self.size
            if self.B[h].name == "NULL":
                self.B[h] = Detail(name, number)
                break
            o += 1

    def display(self):
        print("\nLinear Probing\n")
        for i in range(self.size):
            print(f"{i}.  {self.A[i].name}    {self.A[i].number}")
        
        print("\nQuadratic Probing\n")
        for i in range(self.size):
            print(f"{i}.  {self.B[i].name}    {self.B[i].number}")

    def search(self):
        name = input("Enter Name of Client which Telephone you want to Search: ")
        t = sum(ord(c) for c in name) % self.size

        # Linear probing search
        l = 0
        j = t
        while True:
            l += 1
            if self.A[j].name == name:
                print(f"\nTelephone number of {name} is {self.A[j].number}")
                break
            j = (j + 1) % self.size
            if j == t:
                print("Client Detail Not Found in Linear Probing")
                break
        print(f"\nNumber of Comparisons in Linear Probing = {l}")

        # Quadratic probing search
        l = 0
        o = 0
        found = False
        for _ in range((self.size - 1) // 2 + 1):
            h = (t + o * o) % self.size
            l += 1
            if self.B[h].name == name:
                print(f"\nTelephone No of {name} is {self.B[h].number}")
                found = True
                break
            o += 1
        if not found:
            print("Client Detail Not Found in Quadratic Probing")
        print(f"Number of Comparisons in Quadratic Probing = {l}")

# Main
def main():
    ob = Telp()
    while True:
        print("\nWhich Operation do you want to Perform")
        print("1. Insert Client Data")
        print("2. Search Client Detail")
        print("3. Display Data of HashTable")
        print("4. Exit")
        ch = int(input("Enter your Choice: "))
        if ch == 1:
            ob.hashz()
        elif ch == 2:
            ob.search()
        elif ch == 3:
            ob.display()
        elif ch == 4:
            print("Program is Terminated...!!!")
            break
        else:
            print("Invalid Choice...")

if __name__ == "__main__":
    main()
