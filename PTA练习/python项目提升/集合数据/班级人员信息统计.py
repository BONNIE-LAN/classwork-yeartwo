aClass=input().strip()
bClass=input().strip()
acm=input().strip()
english=input().strip()
transfer=input().strip()
aclass=set(aClass)
bclass=set(bClass.split())
Acm=list(acm.split())
English=list(english.split())
total=len(aclass)+len(bclass)
notInRace=[]
racers=[]
AcmAndEnglish=[]
OnlyAcm=[]
OnlyEnglish=[]
for student_b in sorted(bclass):
    if (student_b not in Acm and student_b not in English):
        notInRace.append(student_b)
    if(student_b in Acm or student_b in English):
        racers.append(student_b)
    if (student_b in Acm and student_b in English):
        AcmAndEnglish.append(student_b)
    if(student_b in Acm and student_b not in English):
        OnlyAcm.append(student_b)
    if(student_b not in Acm and student_b in English):
        OnlyEnglish.append(student_b)
for student_a in sorted(aclass):
    if (student_a not in Acm and student_a not in English):
        notInRace.append(student_a)
    if(student_a in Acm or student_a in English):
        racers.append(student_a)
    if (student_a in Acm and student_a in English):
        AcmAndEnglish.append(student_a)
    if(student_a in Acm and student_a not in English):
        OnlyAcm.append(student_a)
    if(student_a not in Acm and student_a in English):
        OnlyEnglish.append(student_a)
AcmorEngish=sorted(OnlyAcm+OnlyEnglish)
print("Total: {}".format(total))
print("Not in race: {}, num: {}".format(notInRace,len(notInRace)))
print("All racers: {}, num: {}".format(racers,len(racers)))
print("ACM + English: {}, num: {}".format(AcmAndEnglish,len(AcmAndEnglish)))
print("Only ACM: {}".format(OnlyAcm))
print("Only English: {}".format(OnlyEnglish))
print("ACM Or English: {}".format(AcmorEngish))
if transfer in aclass:
    aclass.remove(transfer)
    print("{}".format(sorted(aclass)))
else:
    if transfer in bclass:
        bclass.remove(transfer)
        print("{}".format(sorted(bclass)))
