def is_nice(string:str) -> bool:
    vowels_count:int = 0
    duplicated:bool = False

    vowels = ['a', 'e', 'i', 'o', 'u']
    naughty_duos = ['ab', 'cd', 'pq', 'xy']
    
    length:int = len(string)
    for j in range(0, length):
        if string[j] in vowels:
            vowels_count += 1
        
        if j < length - 1:
            duo = string[j] + string[j+1]
            if duo in naughty_duos:
                return False
            if not duplicated and duo[0] == duo[1]:
                duplicated = True

    return (duplicated and vowels_count >= 3)


counter:int = 0
for i in range(0, 1000):
    string:str = str(input())
    if is_nice(string):
        counter += 1
print(counter) 
    