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

        name = input("Enter name: ")
        mn = int(input("Enter telephone number: "))
        s = Node()
        s.name = name
        s.mn = mn
        ind = self.hashfun(mn)

        if self.ht[ind].mn == 0:
            self.ht[ind] = s
            self.count += 1
        elif self.hashfun(self.ht[ind].mn) == ind:
            prev = ind
            while self.ht[ind].mn != 0:
                if self.ht[ind].chain != -1:
                    ind = self.ht[ind].chain
                    prev = ind
                else:
                    while self.ht[ind].mn != 0:
                        ind = (ind + 1) % MAX
                    self.ht[prev].chain = ind
            self.ht[ind] = s
            self.count += 1
        else:
            newIndex = ind
            while self.ht[newIndex].mn != 0:
                newIndex = (newIndex + 1) % MAX

            temp = self.ht[ind]
            self.ht[newIndex] = temp
            self.ht[ind] = s

            tempIndex = self.hashfun(temp.mn)
            while self.ht[tempIndex].chain != ind:
                tempIndex = self.ht[tempIndex].chain
            self.ht[tempIndex].chain = newIndex

            self.ht[ind].chain = -1
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
        prev = -1

        while ind != -1:
            if self.ht[ind].mn == num:
                print("Record Deleted!")
                self.ht[ind].mn = 0
                self.ht[ind].name = "-----"
                if prev != -1:
                    self.ht[prev].chain = self.ht[ind].chain
                self.ht[ind].chain = -1
                return
            prev = ind
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

        ans = input("Do you want to continue? (1 for yes / 0 for no): ")
        if ans != '1':
            break

if __name__ == "__main__":
    main()
