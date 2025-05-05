MAX = 10

class Node:
    def __init__(self):
        self.name = "-----"
        self.mn = 0
        self.chain = -1

class Telephone:
    def __init__(self):
        self.ht = [Node() for _ in range(MAX)]
        self.count = 0

    def hashfun(self, num):
        return num % MAX

    def insert(self):
        if self.count == MAX - 1:
            print("Hash table full")
            return

        s = Node()
        s.name = input("Enter name: ")
        s.mn = int(input("Enter telephone number: "))
        ind = self.hashfun(s.mn)

        if self.ht[ind].mn == 0:
            self.ht[ind] = s
            self.count += 1
        else:
            prev = ind
            while self.ht[ind].mn != 0:
                if self.ht[ind].chain != -1:
                    ind = self.ht[ind].chain
                    prev = ind
                else:
                    ind = (ind + 1) % MAX
            self.ht[ind] = s
            self.ht[prev].chain = ind
            self.count += 1

    def find(self):
        num = int(input("Enter the telephone number to search: "))
        ind = self.hashfun(num)
        cnt = 0

        while ind != -1:
            cnt += 1
            if self.ht[ind].mn == num:
                print("Record Found!")
                print(f"Name: {self.ht[ind].name}\tPhone: {self.ht[ind].mn} found at index {ind} comparison {cnt}")
                return
            ind = self.ht[ind].chain
        print("Record Not Found!")

    def delno(self):
        num = int(input("Enter the telephone number to delete: "))
        ind = self.hashfun(num)

        while ind != -1:
            if self.ht[ind].mn == num:
                print("Record Deleted!")
                next_ind = self.ht[ind].chain

                if next_ind != -1:
                    self.ht[ind].mn = self.ht[next_ind].mn
                    self.ht[ind].name = self.ht[next_ind].name
                    self.ht[ind].chain = self.ht[next_ind].chain
                    ind = next_ind

                self.ht[ind].mn = 0
                self.ht[ind].name = "-----"
                self.ht[ind].chain = -1
                return
            ind = self.ht[ind].chain

        print("Record Not Found!")

    def display(self):
        print("Index\tName\t\tPhone\t\tChain")
        for i in range(MAX):
            print(f"{i}\t{self.ht[i].name}\t\t{self.ht[i].mn}\t\t{self.ht[i].chain}")

def main():
    t = Telephone()
    while True:
        print("\nEnter your choice")
        print("1. Insert")
        print("2. Display")
        print("3. Find")
        print("4. Delete")
        ch = input("Choice: ")

        if ch == '1':
            t.insert()
        elif ch == '2':
            t.display()
        elif ch == '3':
            t.find()
        elif ch == '4':
            t.delno()
        else:
            print("Invalid choice!")

        ans = input("Do you want to continue? (1/0): ")
        if ans != '1':
            break

if __name__ == "__main__":
    main()
