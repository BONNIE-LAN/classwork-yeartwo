People_2020,People_2010=map(int,input().split())
Family_2020,familyPeople_2020,averagePeople_2010=input().split()
Family_2020=int(Family_2020)
familyPeople_2020=int(familyPeople_2020)
averagePeople_2010=float(averagePeople_2010)
Teenger,adult,older=map(int,input().split())
educate=eval(input())
a1=People_2020-People_2010
a2=(a1/People_2010)*100
a3=(a2/10)
b1=familyPeople_2020/Family_2020
b2=averagePeople_2010-b1
c1=(Teenger/People_2020)*100
c2=(adult/People_2020)*100
c3=(older/People_2020)*100
d1=(educate/People_2020)*100
print("{} {:.2f}% {:.2f}%".format(a1,a2,a3))
print("{:.2f} {:.2f}".format(b1,b2) )
print("{:.2f}% {:.2f}% {:.2f}%".format(c1,c2,c3))
print("{:.2f}%".format(d1))