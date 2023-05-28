#Function to count number of palindromic substrings in a string
def palin_subs(s):
    count = 0
    a = set()
    for i in range(len(s)):
        for j in range(i+1, len(s)+1):
            if s[i:j] == s[i:j][::-1]:
                a.add(s[i:j])
    return len(a)

print(" ".join([str(i) for i in range(3,24)]))

while 1:
    s = input()
    print(palin_subs(s))
    print(len(s))