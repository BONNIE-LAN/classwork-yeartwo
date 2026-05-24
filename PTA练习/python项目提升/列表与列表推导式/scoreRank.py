scores=[]
score_input=input().split(" ")
for s in score_input:
    scores.append(int(s))
ranks=[]
F_count=D_count=C_count=B_count=A_count=0
for score in scores:
    if(score>=0 and score<60):
        ranks.append("F")
        F_count+=1
    elif(score>=60 and score<70):
        ranks.append("D")
        D_count+=1
    elif(score>=70 and score<80):
        ranks.append("C")
        C_count+=1
    elif(score>=80 and score<90):
        ranks.append("B")
        B_count+=1
    elif(score>=90 and score<=100):
        ranks.append("A")
        A_count+=1

print("A: {}".format(A_count))
print("B: {}".format(B_count))
print("C: {}".format(C_count))
print("D: {}".format(D_count))
print("F: {}".format(F_count))
    
    
    
