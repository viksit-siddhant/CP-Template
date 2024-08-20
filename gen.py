import random
import shutil
import subprocess

def gen(n=-1,k=-1,path = "in1.txt"):
    if n == -1:
        n = random.randint(1,14)
    if k == -1:
        k = random.randint(1,n)
    a = random.sample(range(1,n+1),k)
    a = sorted(a)
    p = [random.randint(1,10**9) for i in range(n)]
    disc = [[random.randint(-10**9,10**9) for i in range(n)] for j in range(n)]
    with open(path,'w') as f:
        f.write(str(n)+" "+str(k)+"\n")
        f.write(" ".join(map(str,a))+"\n")
        f.write(" ".join(map(str,p))+"\n")
        for i in range(n):
            f.write(" ".join(map(str,disc[i]))+"\n")

tests = [[3,3],[5,3],[7,1],[10,4],[11,8],[14,6],[14,14],[14,13],[14,12]]

for i,test in enumerate(tests):
    inpath = f'tests/in{i}.txt'
    outpath = f'tests/out{i}.txt'
    gen(test[0],test[1],inpath)
    shutil.copyfile(inpath,'input.txt')
    subprocess.run(['./a.out'])
    shutil.copyfile('output.txt',outpath)
